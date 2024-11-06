import tensorflow as tf
from sklearn.model_selection import train_test_split
import numpy as np
import os

class ImprovedCharRNN(tf.keras.Model):
    def __init__(self, vocab_size, hidden_size, num_layers, dropout=0.5):
        super(ImprovedCharRNN, self).__init__()
        self.embedding = tf.keras.layers.Embedding(vocab_size, hidden_size * 2)
        
        self.lstm_layers = [
            tf.keras.layers.Bidirectional(tf.keras.layers.LSTM(
                hidden_size,
                return_sequences=True,
                dropout=dropout
            )) for _ in range(num_layers)
        ]
        
        self.layer_norm = tf.keras.layers.LayerNormalization()
        self.dropout = tf.keras.layers.Dropout(dropout)
        self.fc = tf.keras.layers.Dense(vocab_size)

    def call(self, x, training=False):
        x = self.embedding(x)
        x = self.layer_norm(x)
        
        for lstm_layer in self.lstm_layers:
            x = lstm_layer(x, training=training)
        
        x = self.dropout(x, training=training)
        return self.fc(x)

def load_codeforces_data(folder_path):
    code_data = ""
    chars = set()

    for root, _, files in os.walk(folder_path):
        for file in files:
            if file.endswith(('.java', '.py', '.cpp')):
                file_path = os.path.join(root, file)
                try:
                    with open(file_path, 'r', encoding='utf-8') as f:
                        code = f.read()
                        code_data += code
                        chars.update(code)
                except UnicodeDecodeError:
                    continue

    chars = sorted(list(chars))
    char_to_idx = {char: idx for idx, char in enumerate(chars)}
    idx_to_char = {idx: char for idx, char in enumerate(chars)}
    encoded_data = [char_to_idx[c] for c in code_data if c in char_to_idx]

    return encoded_data, char_to_idx, idx_to_char

def create_sequences(encoded_data, sequence_length):
    sequences = []
    stride = sequence_length // 2
    for i in range(0, len(encoded_data) - sequence_length, stride):
        seq = encoded_data[i:i + sequence_length]
        sequences.append(seq)
    return sequences

def prepare_datasets(sequences, batch_size):
    tensor_sequences = tf.constant(sequences, dtype=tf.int32)
    inputs, targets = tensor_sequences[:, :-1], tensor_sequences[:, 1:]
    return tf.data.Dataset.from_tensor_slices((inputs, targets)).batch(batch_size, drop_remainder=True)

def main():
    # Hyperparameters
    hidden_size = 512
    num_layers = 2
    num_epochs = 5
    learning_rate = 0.001
    sequence_length = 100
    batch_size = 32
    test_size = 0.2
    val_size = 0.1  # Percentage of training data used for validation

    # Load and prepare data
    encoded_data, char_to_idx, idx_to_char = load_codeforces_data("/Users/Simmran/Desktop/major_ml/Major_ML/New_Db")
    vocab_size = len(char_to_idx)

    sequences = create_sequences(encoded_data, sequence_length)
    train_sequences, test_sequences = train_test_split(sequences, test_size=test_size, random_state=42)
    train_sequences, val_sequences = train_test_split(train_sequences, test_size=val_size, random_state=42)

    train_dataset = prepare_datasets(train_sequences, batch_size)
    val_dataset = prepare_datasets(val_sequences, batch_size)
    test_dataset = prepare_datasets(test_sequences, batch_size)

    # Initialize model
    model = ImprovedCharRNN(vocab_size, hidden_size, num_layers)
    model.compile(
        optimizer=tf.keras.optimizers.Adam(learning_rate),
        loss=tf.keras.losses.SparseCategoricalCrossentropy(from_logits=True),
        metrics=['accuracy']
    )

    # Train model with validation set and early stopping
    early_stopping = tf.keras.callbacks.EarlyStopping(
        monitor='val_accuracy', patience=5, restore_best_weights=True
    )
    
    model.fit(
        train_dataset,
        validation_data=val_dataset,
        epochs=num_epochs,
        callbacks=[early_stopping]
    )

    # Evaluate on test set
    test_loss, test_accuracy = model.evaluate(test_dataset)
    print(f"Test Loss: {test_loss:.4f}, Test Accuracy: {test_accuracy:.2f}%")

    # Save the model
    model.save("Major_ML/Saved_Path/best_char_rnn_model_tf")
    print(f"Model saved with test accuracy: {test_accuracy:.2f}%")

if __name__ == "__main__":
    main()