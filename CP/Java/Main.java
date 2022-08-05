import java.io.*;
import java.util.*;

public class Main{

    public static void solve(FastScanner sc, FastWriter wr) throws Exception {
        GreetingRunnable r1 = new GreetingRunnable("Hello");
        GreetingRunnable r2 = new GreetingRunnable("Goodbye");
        r1.run();
        r2.run();
    }    
    
    public static void main(String[] args) throws Exception{
        FastScanner sc = new FastScanner();
        FastWriter wr = new FastWriter();
        int tc = 1;
      //  tc =  sc.nextInt();
        for(int i = 0; i < tc; i++){
            solve(sc, wr);
        }
        sc.close();
        wr.close();
    }
    static class FastScanner {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st=new StringTokenizer("");
        String next() {
        while (!st.hasMoreTokens())
            try {
                st=new StringTokenizer(br.readLine());
            } catch (IOException e) {
                e.printStackTrace();
            }
            return st.nextToken();
        }   
        int nextInt() {
        return Integer.parseInt(next());
        }
        int[] readArray(int n) {
            int[] a=new int[n];
            for (int i=0; i<n; i++) a[i]=nextInt();
            return a;
        }
        long nextLong() {
            return Long.parseLong(next());
        }
        String nextLine(){
            String str = "";
            try {
                    str = br.readLine().trim();
            } catch (Exception e) {
                    e.printStackTrace();
            }
            return str;
        }
        public void close() throws Exception{
            br.close();
        }
    }
    static class FastWriter {
        private final BufferedWriter bw;

        public FastWriter() {
                this.bw = new BufferedWriter(new OutputStreamWriter(System.out));
        }

        public void print(Object ...object) throws IOException {
                for(Object a: object) bw.append(a+" ");
        }

        public void println(Object ...object) throws IOException {
                print(object);
                bw.append("\n");
        }

        public void close() throws IOException {
                bw.close();
        }
    }
    static void sort(int[] a) {
        ArrayList<Integer> q = new ArrayList<>();
        for (int i : a) q.add(i);
        Collections.sort(q);
        for (int i = 0; i < a.length; i++) a[i] = q.get(i);
    }
     
    static void sort(long[] a) {
        ArrayList<Long> q = new ArrayList<>();
        for (long i : a) q.add(i);
        Collections.sort(q);
        for (int i = 0; i < a.length; i++) a[i] = q.get(i);
    }

}

