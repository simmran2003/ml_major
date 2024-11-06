import java.util.*;
import java.io.*;
public class Main {
    static class Word implements Comparable<Word> {
        public String word;
        public Word(String w) {
            word = w;
        }

        public String getWord() {
            return word;
        }

        public int compareTo(Word o) {
            String a = this.word + o.word;
            String b = o.word + this.word;
            if (a.compareTo(b) < 0) {
                return -1;
            } else if (a.compareTo(b) == 0){
                return 0;
            } else {
                return 1;
            }
            /*if (this.word.length() == o.word.length()) {
                return (this.word).compareTo(o.word);
            } else {
                int x = Math.min(word.length(), o.word.length());
                if ((this.word.substring(0, x)).compareTo(o.word.substring(0, x)) != 0) {
                    return (this.word.substring(0, x)).compareTo(o.word.substring(0, x));
                } else {
                    Word w;
                    if (this.word.length() > o.word.length()) {
                        w = new Word(this.word.substring(x));
                        return w.compareTo(o);
                    } else {
                        w = new Word(o.word.substring(x));
                        return w.compareTo(this);
                    }
                }
            }*/
        }
    }
    public static void main(String[] args) throws Exception {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(in.readLine().trim());
        Word[] arr = new Word[n];
        for (int i = 0; i < n; i++) {
            String read = in.readLine().trim();
            Word w = new Word(read);
            arr[i] = w;
        }
        Arrays.sort(arr);
        for (int i = 0; i < n; i++) {
            System.out.print(arr[i].getWord());
        }
        System.out.println();
        /*String s1 = "aaabbaaabbabaacaccccbbccbbaabbaaccaacaacacbccbbbacacaaaacbcccaaacaacacbccbbbacacaaaacbcccacbbcacabbbbaacbabcaccabaccbaccabaabcacbbaabaacccbcabcbcabccaccaabaccbaccabaabcacbbabbbbbcabccbbbbbbcabbbbbcabccbbbbbbccaacbbcbaccaabbbbbcabccbbbbbbccaabbbcbbbbbbcccccbcbbbabbcacbcabacccbcbabaabcaabcabacbbbbbcaabbcacbcabacccbcbabaabcaabcabacbbbbbcaabcaaccabbcbbbcaabccaacaacacabbbcbbabcccccacabbaccbcacabcbbbacaabccaacaacacabbbcbbabcccccacabbaccbcacabcbbbacaacaababbabbaaabbabccbabcbacbcbbacacaaacbbcacbbaaaabbbbbccccbcbba";
        String s2 = "aaabbaaabbabaacaccccbbccbbaabbaaccaacaacacbccbbbacacaaaacbcccaaacaacacbccbbbacacaaaacbcccacbbcacabbbbaacbabcaccababaccbaccabaabcacbbaabaacccbcabcbcabccaccaabaccbaccabaabcacbbabbabbaaabbabccbabcbacbcbbacacaaacbbcacbbaaaabbabbbbbcabccbbbbbbcabbbbbcabccbbbbbbccaabbbbbcabccbbbbbbccaacbbcbaccaabbbbbccccbcbbabcacaabbabbbcbbbbbbcccccbcbbbabbbccaacbbaabacbacacbabcaaaabcbacccbabbacaabbcacaaababaabbcacaaababaccaaabbccabccaaaabacabbbcabcccbaaabaabbcacaaababbcacaaabaccbcaabbcabaaccacaaacabbcacbcabacccbcbabaabcaabcabac";
        System.out.println(s1.compareTo(s2));*/
    }
}
