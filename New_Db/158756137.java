

import java.io.*;
import java.util.*;

/**
 *
 * @author eslam
 */
public class IceCave {

    static class Kattio extends PrintWriter {

        private BufferedReader r;
        private StringTokenizer st;
        // standard input

        public Kattio() {
            this(System.in, System.out);
        }

        public Kattio(InputStream i, OutputStream o) {
            super(o);
            r = new BufferedReader(new InputStreamReader(i));
        }
        // USACO-style file input

        public Kattio(String problemName) throws IOException {
            super(problemName + ".out");
            r = new BufferedReader(new FileReader(problemName + ".in"));
        }
        // returns null if no more input

        String nextLine() {
            String str = "";
            try {
                str = r.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }

        public String next() {
            try {
                while (st == null || !st.hasMoreTokens()) {
                    st = new StringTokenizer(r.readLine());
                }
                return st.nextToken();
            } catch (Exception e) {
            }
            return null;
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }
    }

    // Beginning of the solution
    static Kattio input = new Kattio();
    static BufferedWriter log = new BufferedWriter(new OutputStreamWriter(System.out));
    static ArrayList<ArrayList<Long>> powerSet = new ArrayList<>();
    static long mod = (long) (Math.pow(10, 9) + 7);
    static int dp[];

    public static void main(String[] args) throws IOException {
        int n = input.nextInt();
        String w[] = new String[n];
        for (int i = 0; i < n; i++) {
            w[i] = input.next();
        }
        Comparator<String> c = new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                if((o1+o2).compareTo(o2+o1)<0){
                    return -1;
                }else if((o1+o2).compareTo(o2+o1)>0){
                    return 1;
                }
                return 0;
            }
        };
        Arrays.sort(w, c);
        for (int i = 0;
                i < n;
                i++) {
            log.write(w[i] + "");
        }

        log.write(
                "\n");
        log.flush();
    }

    public static void graphRepresintionWithCycle(ArrayList<Integer>[] a, int q) {
        for (int i = 0; i < a.length; i++) {
            a[i] = new ArrayList<>();
        }
        while (q-- > 0) {
            int x = input.nextInt();
            int y = input.nextInt();
            a[x].add(y);
            a[y].add(x);
        }
    }

    public static int[] bfs(int node, ArrayList<Integer> a[]) {
        Queue<Integer> q = new LinkedList<>();
        q.add(node);
        int distances[] = new int[a.length];
        Arrays.fill(distances, -1);
        distances[node] = 0;
        while (!q.isEmpty()) {
            int parent = q.poll();
            ArrayList<Integer> nodes = a[parent];

            int cost = distances[parent];
            for (Integer node1 : nodes) {
                if (distances[node1] == -1) {

                    q.add(node1);
                    distances[node1] = cost + 1;
                }
            }
        }
        return distances;
    }

    public static int get(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    public static long primeFactors(int n) {
        long sum = 0;
        while (n % 2 == 0) {
            sum += 2l;
            n /= 2;
        }
        for (int i = 3; i <= Math.sqrt(n); i += 2) {
            while (n % i == 0) {
                sum += (long) i;
                n /= i;
            }
            if (n < i) {
                break;
            }
        }
        if (n > 2) {
            sum += n;
        }
        return sum;
    }

    public static ArrayList<Integer> printPrimeFactoriztion(int n) {
        ArrayList<Integer> a = new ArrayList<>();
        for (int i = 1; i < Math.sqrt(n) + 1; i++) {
            if (n % i == 0) {
                if (isPrime(i)) {
                    a.add(i);
                    n /= i;
                    i = 0;
                } else if (isPrime(n / i)) {
                    a.add(n / i);
                    n = i;
                    i = 0;
                }
            }
        }
        return a;
    }

// end of solution
    public static void genrate(int ind, long[] a, ArrayList<Long> sub) {
        if (ind == a.length) {
            powerSet.add(sub);
            return;
        }
        ArrayList<Long> have = new ArrayList<>();
        ArrayList<Long> less = new ArrayList<>();
        for (int i = 0; i < sub.size(); i++) {
            have.add(sub.get(i));
            less.add(sub.get(i));
        }
        have.add(a[ind]);
        genrate(ind + 1, a, have);
        genrate(ind + 1, a, less);
    }

    public static long factorial(long n) {
        if (n <= 1) {
            return 1;
        }
        long t = n - 1;
        while (t > 1) {
            n *= t;
            t--;
        }
        return n;
    }

    public static boolean isPalindrome(int n) {
        int t = n;
        int ans = 0;
        while (t > 0) {
            ans = ans * 10 + t % 10;
            t /= 10;
        }
        return ans == n;

    }

    static class tri {

        int x, y, z;

        public tri(int x, int y, int z) {
            this.x = x;
            this.y = y;
            this.z = z;
        }

    }

    static boolean isPrime(long num) {
        if (num == 1) {
            return false;
        }
        if (num == 2) {
            return true;
        }
        if (num % 2 == 0) {
            return false;
        }
        if (num == 3) {
            return true;
        }
        for (int i = 3; i <= Math.sqrt(num) + 1; i += 2) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }

    public static void prefixSum(int[] a) {
        for (int i = 1; i < a.length; i++) {
            a[i] = a[i] + a[i - 1];
        }
    }

    public static void suffixSum(long[] a) {
        for (int i = a.length - 2; i > -1; i--) {
            a[i] = a[i] + a[i + 1];
        }
    }

    static long mod(long a, long b) {
        long r = a % b;
        return r < 0 ? r + b : r;
    }

    public static long binaryToDecimal(String w) {
        long r = 0;
        long l = 0;
        for (int i = w.length() - 1; i > -1; i--) {
            long x = (w.charAt(i) - '0') * (long) Math.pow(2, l);
            r = r + x;
            l++;
        }
        return r;
    }

    public static String decimalToBinary(long n) {
        String w = "";
        while (n > 0) {
            w = n % 2 + w;
            n /= 2;
        }
        return w;
    }

    public static boolean isSorted(int[] a) {
        for (int i = 0; i < a.length - 1; i++) {
            if (a[i] > a[i + 1]) {
                return false;
            }
        }
        return true;
    }

    public static void print(int a[]) throws IOException {
        for (int i = 0; i < a.length; i++) {
            log.write(a[i] + " ");
        }
        log.write("\n");
    }

    public static void read(long[] a) {
        for (int i = 0; i < a.length; i++) {
            a[i] = input.nextInt();

        }
    }

    static class pair {

        long x;
        long y;

        public pair(long x, long y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public String toString() {
            return x + " " + y;
        }
    }

    public static long LCM(long x, long y) {
        return x / GCD(x, y) * y;
    }

    public static long GCD(long x, long y) {
        if (y == 0) {
            return x;
        }
        return GCD(y, x % y);
    }

    public static void simplifyTheFraction(long a, long b) {
        long GCD = GCD(a, b);
        System.out.println(a / GCD + " " + b / GCD);

    }

    /**
     */ // class RedBlackNode
    static class RedBlackNode<T extends Comparable<T>> {

        /**
         * Possible color for this node
         */
        public static final int BLACK = 0;
        /**
         * Possible color for this node
         */
        public static final int RED = 1;
        // the key of each node
        public T key;

        /**
         * Parent of node
         */
        RedBlackNode<T> parent;
        /**
         * Left child
         */
        RedBlackNode<T> left;
        /**
         * Right child
         */
        RedBlackNode<T> right;
        // the number of elements to the left of each node
        public int numLeft = 0;
        // the number of elements to the right of each node
        public int numRight = 0;
        // the color of a node
        public int color;

        RedBlackNode() {
            color = BLACK;
            numLeft = 0;
            numRight = 0;
            parent = null;
            left = null;
            right = null;
        }

        // Constructor which sets key to the argument.
        RedBlackNode(T key) {
            this();
            this.key = key;
        }
    }// end class RedBlackNode

    static class RedBlackTree<T extends Comparable<T>> {

        // Root initialized to nil.
        private RedBlackNode<T> nil = new RedBlackNode<T>();
        private RedBlackNode<T> root = nil;

        public RedBlackTree() {
            root.left = nil;
            root.right = nil;
            root.parent = nil;
        }

        // @param: x, The node which the lefRotate is to be performed on.
        // Performs a leftRotate around x.
        private void leftRotate(RedBlackNode<T> x) {

            // Call leftRotateFixup() which updates the numLeft
            // and numRight values.
            leftRotateFixup(x);

            // Perform the left rotate as described in the algorithm
            // in the course text.
            RedBlackNode<T> y;
            y = x.right;
            x.right = y.left;

            // Check for existence of y.left and make pointer changes
            if (!isNil(y.left)) {
                y.left.parent = x;
            }
            y.parent = x.parent;

            // x's parent is nul
            if (isNil(x.parent)) {
                root = y;
            } // x is the left child of it's parent
            else if (x.parent.left == x) {
                x.parent.left = y;
            } // x is the right child of it's parent.
            else {
                x.parent.right = y;
            }

            // Finish of the leftRotate
            y.left = x;
            x.parent = y;
        }// end leftRotate(RedBlackNode x)

        // @param: x, The node which the leftRotate is to be performed on.
        // Updates the numLeft & numRight values affected by leftRotate.
        private void leftRotateFixup(RedBlackNode x) {

            // Case 1: Only x, x.right and x.right.right always are not nil.
            if (isNil(x.left) && isNil(x.right.left)) {
                x.numLeft = 0;
                x.numRight = 0;
                x.right.numLeft = 1;
            } // Case 2: x.right.left also exists in addition to Case 1
            else if (isNil(x.left) && !isNil(x.right.left)) {
                x.numLeft = 0;
                x.numRight = 1 + x.right.left.numLeft
                        + x.right.left.numRight;
                x.right.numLeft = 2 + x.right.left.numLeft
                        + x.right.left.numRight;
            } // Case 3: x.left also exists in addition to Case 1
            else if (!isNil(x.left) && isNil(x.right.left)) {
                x.numRight = 0;
                x.right.numLeft = 2 + x.left.numLeft + x.left.numRight;

            } // Case 4: x.left and x.right.left both exist in addtion to Case 1
            else {
                x.numRight = 1 + x.right.left.numLeft
                        + x.right.left.numRight;
                x.right.numLeft = 3 + x.left.numLeft + x.left.numRight
                        + x.right.left.numLeft + x.right.left.numRight;
            }

        }// end leftRotateFixup(RedBlackNode x)

        // @param: x, The node which the rightRotate is to be performed on.
        // Updates the numLeft and numRight values affected by the Rotate.
        private void rightRotate(RedBlackNode<T> y) {

            // Call rightRotateFixup to adjust numRight and numLeft values
            rightRotateFixup(y);

            // Perform the rotate as described in the course text.
            RedBlackNode<T> x = y.left;
            y.left = x.right;

            // Check for existence of x.right
            if (!isNil(x.right)) {
                x.right.parent = y;
            }
            x.parent = y.parent;

            // y.parent is nil
            if (isNil(y.parent)) {
                root = x;
            } // y is a right child of it's parent.
            else if (y.parent.right == y) {
                y.parent.right = x;
            } // y is a left child of it's parent.
            else {
                y.parent.left = x;
            }
            x.right = y;

            y.parent = x;

        }// end rightRotate(RedBlackNode y)

        // @param: y, the node around which the righRotate is to be performed.
        // Updates the numLeft and numRight values affected by the rotate
        private void rightRotateFixup(RedBlackNode y) {

            // Case 1: Only y, y.left and y.left.left exists.
            if (isNil(y.right) && isNil(y.left.right)) {
                y.numRight = 0;
                y.numLeft = 0;
                y.left.numRight = 1;
            } // Case 2: y.left.right also exists in addition to Case 1
            else if (isNil(y.right) && !isNil(y.left.right)) {
                y.numRight = 0;
                y.numLeft = 1 + y.left.right.numRight
                        + y.left.right.numLeft;
                y.left.numRight = 2 + y.left.right.numRight
                        + y.left.right.numLeft;
            } // Case 3: y.right also exists in addition to Case 1
            else if (!isNil(y.right) && isNil(y.left.right)) {
                y.numLeft = 0;
                y.left.numRight = 2 + y.right.numRight + y.right.numLeft;

            } // Case 4: y.right & y.left.right exist in addition to Case 1
            else {
                y.numLeft = 1 + y.left.right.numRight
                        + y.left.right.numLeft;
                y.left.numRight = 3 + y.right.numRight
                        + y.right.numLeft
                        + y.left.right.numRight + y.left.right.numLeft;
            }

        }// end rightRotateFixup(RedBlackNode y)

        public void insert(T key) {
            insert(new RedBlackNode<T>(key));
        }

        // @param: z, the node to be inserted into the Tree rooted at root
        // Inserts z into the appropriate position in the RedBlackTree while
        // updating numLeft and numRight values.
        private void insert(RedBlackNode<T> z) {

            // Create a reference to root & initialize a node to nil
            RedBlackNode<T> y = nil;
            RedBlackNode<T> x = root;

            // While we haven't reached a the end of the tree keep
            // tryint to figure out where z should go
            while (!isNil(x)) {
                y = x;

                // if z.key is < than the current key, go left
                if (z.key.compareTo(x.key) < 0) {

                    // Update x.numLeft as z is < than x
                    x.numLeft++;
                    x = x.left;
                } // else z.key >= x.key so go right.
                else {

                    // Update x.numGreater as z is => x
                    x.numRight++;
                    x = x.right;
                }
            }
            // y will hold z's parent
            z.parent = y;

            // Depending on the value of y.key, put z as the left or
            // right child of y
            if (isNil(y)) {
                root = z;
            } else if (z.key.compareTo(y.key) < 0) {
                y.left = z;
            } else {
                y.right = z;
            }

            // Initialize z's children to nil and z's color to red
            z.left = nil;
            z.right = nil;
            z.color = RedBlackNode.RED;

            // Call insertFixup(z)
            insertFixup(z);

        }// end insert(RedBlackNode z)

        // @param: z, the node which was inserted and may have caused a violation
        // of the RedBlackTree properties
        // Fixes up the violation of the RedBlackTree properties that may have
        // been caused during insert(z)
        private void insertFixup(RedBlackNode<T> z) {

            RedBlackNode<T> y = nil;
            // While there is a violation of the RedBlackTree properties..
            while (z.parent.color == RedBlackNode.RED) {

                // If z's parent is the the left child of it's parent.
                if (z.parent == z.parent.parent.left) {

                    // Initialize y to z 's cousin
                    y = z.parent.parent.right;

                    // Case 1: if y is red...recolor
                    if (y.color == RedBlackNode.RED) {
                        z.parent.color = RedBlackNode.BLACK;
                        y.color = RedBlackNode.BLACK;
                        z.parent.parent.color = RedBlackNode.RED;
                        z = z.parent.parent;
                    } // Case 2: if y is black & z is a right child
                    else if (z == z.parent.right) {

                        // leftRotaet around z's parent
                        z = z.parent;
                        leftRotate(z);
                    } // Case 3: else y is black & z is a left child
                    else {
                        // recolor and rotate round z's grandpa
                        z.parent.color = RedBlackNode.BLACK;
                        z.parent.parent.color = RedBlackNode.RED;
                        rightRotate(z.parent.parent);
                    }
                } // If z's parent is the right child of it's parent.
                else {

                    // Initialize y to z's cousin
                    y = z.parent.parent.left;

                    // Case 1: if y is red...recolor
                    if (y.color == RedBlackNode.RED) {
                        z.parent.color = RedBlackNode.BLACK;
                        y.color = RedBlackNode.BLACK;
                        z.parent.parent.color = RedBlackNode.RED;
                        z = z.parent.parent;
                    } // Case 2: if y is black and z is a left child
                    else if (z == z.parent.left) {
                        // rightRotate around z's parent
                        z = z.parent;
                        rightRotate(z);
                    } // Case 3: if y  is black and z is a right child
                    else {
                        // recolor and rotate around z's grandpa
                        z.parent.color = RedBlackNode.BLACK;
                        z.parent.parent.color = RedBlackNode.RED;
                        leftRotate(z.parent.parent);
                    }
                }
            }
            // Color root black at all times
            root.color = RedBlackNode.BLACK;

        }// end insertFixup(RedBlackNode z)

        // @param: node, a RedBlackNode
        // @param: node, the node with the smallest key rooted at node
        public RedBlackNode<T> treeMinimum(RedBlackNode<T> node) {

            // while there is a smaller key, keep going left
            while (!isNil(node.left)) {
                node = node.left;
            }
            return node;
        }// end treeMinimum(RedBlackNode node)

        // @param: x, a RedBlackNode whose successor we must find
        // @return: return's the node the with the next largest key
        // from x.key
        public RedBlackNode<T> treeSuccessor(RedBlackNode<T> x) {

            // if x.left is not nil, call treeMinimum(x.right) and
            // return it's value
            if (!isNil(x.left)) {
                return treeMinimum(x.right);
            }

            RedBlackNode<T> y = x.parent;

            // while x is it's parent's right child...
            while (!isNil(y) && x == y.right) {
                // Keep moving up in the tree
                x = y;
                y = y.parent;
            }
            // Return successor
            return y;
        }// end treeMinimum(RedBlackNode x)

        // @param: z, the RedBlackNode which is to be removed from the the tree
        // Remove's z from the RedBlackTree rooted at root
        public void remove(RedBlackNode<T> v) {

            RedBlackNode<T> z = search(v.key);

            // Declare variables
            RedBlackNode<T> x = nil;
            RedBlackNode<T> y = nil;

            // if either one of z's children is nil, then we must remove z
            if (isNil(z.left) || isNil(z.right)) {
                y = z;
            } // else we must remove the successor of z
            else {
                y = treeSuccessor(z);
            }

            // Let x be the left or right child of y (y can only have one child)
            if (!isNil(y.left)) {
                x = y.left;
            } else {
                x = y.right;
            }

            // link x's parent to y's parent
            x.parent = y.parent;

            // If y's parent is nil, then x is the root
            if (isNil(y.parent)) {
                root = x;
            } // else if y is a left child, set x to be y's left sibling
            else if (!isNil(y.parent.left) && y.parent.left == y) {
                y.parent.left = x;
            } // else if y is a right child, set x to be y's right sibling
            else if (!isNil(y.parent.right) && y.parent.right == y) {
                y.parent.right = x;
            }

            // if y != z, trasfer y's satellite data into z.
            if (y != z) {
                z.key = y.key;
            }

            // Update the numLeft and numRight numbers which might need
            // updating due to the deletion of z.key.
            fixNodeData(x, y);

            // If y's color is black, it is a violation of the
            // RedBlackTree properties so call removeFixup()
            if (y.color == RedBlackNode.BLACK) {
                removeFixup(x);
            }
        }// end remove(RedBlackNode z)

        // @param: y, the RedBlackNode which was actually deleted from the tree
        // @param: key, the value of the key that used to be in y
        private void fixNodeData(RedBlackNode<T> x, RedBlackNode<T> y) {

            // Initialize two variables which will help us traverse the tree
            RedBlackNode<T> current = nil;
            RedBlackNode<T> track = nil;

            // if x is nil, then we will start updating at y.parent
            // Set track to y, y.parent's child
            if (isNil(x)) {
                current = y.parent;
                track = y;
            } // if x is not nil, then we start updating at x.parent
            // Set track to x, x.parent's child
            else {
                current = x.parent;
                track = x;
            }

            // while we haven't reached the root
            while (!isNil(current)) {
                // if the node we deleted has a different key than
                // the current node
                if (y.key != current.key) {

                    // if the node we deleted is greater than
                    // current.key then decrement current.numRight
                    if (y.key.compareTo(current.key) > 0) {
                        current.numRight--;
                    }

                    // if the node we deleted is less than
                    // current.key thendecrement current.numLeft
                    if (y.key.compareTo(current.key) < 0) {
                        current.numLeft--;
                    }
                } // if the node we deleted has the same key as the
                // current node we are checking
                else {
                    // the cases where the current node has any nil
                    // children and update appropriately
                    if (isNil(current.left)) {
                        current.numLeft--;
                    } else if (isNil(current.right)) {
                        current.numRight--;
                    } // the cases where current has two children and
                    // we must determine whether track is it's left
                    // or right child and update appropriately
                    else if (track == current.right) {
                        current.numRight--;
                    } else if (track == current.left) {
                        current.numLeft--;
                    }
                }

                // update track and current
                track = current;
                current = current.parent;

            }

        }//end fixNodeData()

        // @param: x, the child of the deleted node from remove(RedBlackNode v)
        // Restores the Red Black properties that may have been violated during
        // the removal of a node in remove(RedBlackNode v)
        private void removeFixup(RedBlackNode<T> x) {

            RedBlackNode<T> w;

            // While we haven't fixed the tree completely...
            while (x != root && x.color == RedBlackNode.BLACK) {

                // if x is it's parent's left child
                if (x == x.parent.left) {

                    // set w = x's sibling
                    w = x.parent.right;

                    // Case 1, w's color is red.
                    if (w.color == RedBlackNode.RED) {
                        w.color = RedBlackNode.BLACK;
                        x.parent.color = RedBlackNode.RED;
                        leftRotate(x.parent);
                        w = x.parent.right;
                    }

                    // Case 2, both of w's children are black
                    if (w.left.color == RedBlackNode.BLACK
                            && w.right.color == RedBlackNode.BLACK) {
                        w.color = RedBlackNode.RED;
                        x = x.parent;
                    } // Case 3 / Case 4
                    else {
                        // Case 3, w's right child is black
                        if (w.right.color == RedBlackNode.BLACK) {
                            w.left.color = RedBlackNode.BLACK;
                            w.color = RedBlackNode.RED;
                            rightRotate(w);
                            w = x.parent.right;
                        }
                        // Case 4, w = black, w.right = red
                        w.color = x.parent.color;
                        x.parent.color = RedBlackNode.BLACK;
                        w.right.color = RedBlackNode.BLACK;
                        leftRotate(x.parent);
                        x = root;
                    }
                } // if x is it's parent's right child
                else {

                    // set w to x's sibling
                    w = x.parent.left;

                    // Case 1, w's color is red
                    if (w.color == RedBlackNode.RED) {
                        w.color = RedBlackNode.BLACK;
                        x.parent.color = RedBlackNode.RED;
                        rightRotate(x.parent);
                        w = x.parent.left;
                    }

                    // Case 2, both of w's children are black
                    if (w.right.color == RedBlackNode.BLACK
                            && w.left.color == RedBlackNode.BLACK) {
                        w.color = RedBlackNode.RED;
                        x = x.parent;
                    } // Case 3 / Case 4
                    else {
                        // Case 3, w's left child is black
                        if (w.left.color == RedBlackNode.BLACK) {
                            w.right.color = RedBlackNode.BLACK;
                            w.color = RedBlackNode.RED;
                            leftRotate(w);
                            w = x.parent.left;
                        }

                        // Case 4, w = black, and w.left = red
                        w.color = x.parent.color;
                        x.parent.color = RedBlackNode.BLACK;
                        w.left.color = RedBlackNode.BLACK;
                        rightRotate(x.parent);
                        x = root;
                    }
                }
            }// end while

            // set x to black to ensure there is no violation of
            // RedBlack tree Properties
            x.color = RedBlackNode.BLACK;
        }// end removeFixup(RedBlackNode x)

        // @param: key, the key whose node we want to search for
        // @return: returns a node with the key, key, if not found, returns null
        // Searches for a node with key k and returns the first such node, if no
        // such node is found returns null
        public RedBlackNode<T> search(T key) {

            // Initialize a pointer to the root to traverse the tree
            RedBlackNode<T> current = root;

            // While we haven't reached the end of the tree
            while (!isNil(current)) {

                // If we have found a node with a key equal to key
                if (current.key.equals(key)) // return that node and exit search(int)
                {
                    return current;
                } // go left or right based on value of current and key
                else if (current.key.compareTo(key) < 0) {
                    current = current.right;
                } // go left or right based on value of current and key
                else {
                    current = current.left;
                }
            }

            // we have not found a node whose key is "key"
            return null;

        }// end search(int key)

        // @param: key, any Comparable object
        // @return: return's the number of elements greater than key
        public int numGreater(T key) {

            // Call findNumGreater(root, key) which will return the number
            // of nodes whose key is greater than key
            return findNumGreater(root, key);

        }// end numGreater(int key)

        // @param: key, any Comparable object
        // @return: return's teh number of elements smaller than key
        public int numSmaller(T key) {

            // Call findNumSmaller(root,key) which will return
            // the number of nodes whose key is greater than key
            return findNumSmaller(root, key);

        }// end numSmaller(int key)

        // @param: node, the root of the tree, the key who we must
        // compare other node key's to.
        // @return: the number of nodes greater than key.
        public int findNumGreater(RedBlackNode<T> node, T key) {

            // Base Case: if node is nil, return 0
            if (isNil(node)) {
                return 0;
            } // If key is less than node.key, all elements right of node are
            // greater than key, add this to our total and look to the left
            else if (key.compareTo(node.key) < 0) {
                return 1 + node.numRight + findNumGreater(node.left, key);
            } // If key is greater than node.key, then look to the right as
            // all elements to the left of node are smaller than key
            else {
                return findNumGreater(node.right, key);
            }

        }// end findNumGreater(RedBlackNode, int key)

        /**
         * Returns sorted list of keys greater than key. Size of list will not
         * exceed maxReturned
         *
         * @param key Key to search for
         * @param maxReturned Maximum number of results to return
         * @return List of keys greater than key. List may not exceed
         * maxReturned
         */
        public List<T> getGreaterThan(T key, Integer maxReturned) {
            List<T> list = new ArrayList<T>();
            getGreaterThan(root, key, list);
            return list.subList(0, Math.min(maxReturned, list.size()));
        }

        private void getGreaterThan(RedBlackNode<T> node, T key,
                List<T> list) {
            if (isNil(node)) {
                return;
            } else if (node.key.compareTo(key) > 0) {
                getGreaterThan(node.left, key, list);
                list.add(node.key);
                getGreaterThan(node.right, key, list);
            } else {
                getGreaterThan(node.right, key, list);
            }
        }

        // @param: node, the root of the tree, the key who we must compare other
        // node key's to.
        // @return: the number of nodes smaller than key.
        public int findNumSmaller(RedBlackNode<T> node, T key) {

            // Base Case: if node is nil, return 0
            if (isNil(node)) {
                return 0;
            } // If key is less than node.key, look to the left as all
            // elements on the right of node are greater than key
            else if (key.compareTo(node.key) <= 0) {
                return findNumSmaller(node.left, key);
            } // If key is larger than node.key, all elements to the left of
            // node are smaller than key, add this to our total and look
            // to the right.
            else {
                return 1 + node.numLeft + findNumSmaller(node.right, key);
            }

        }// end findNumSmaller(RedBlackNode nod, int key)

        // @param: node, the RedBlackNode we must check to see whether it's nil
        // @return: return's true of node is nil and false otherwise
        private boolean isNil(RedBlackNode node) {

            // return appropriate value
            return node == nil;

        }// end isNil(RedBlackNode node)

        // @return: return's the size of the tree
        // Return's the # of nodes including the root which the RedBlackTree
        // rooted at root has.
        public int size() {

            // Return the number of nodes to the root's left + the number of
            // nodes on the root's right + the root itself.
            return root.numLeft + root.numRight + 1;
        }// end size()

    }// end class RedBlackTree
}
