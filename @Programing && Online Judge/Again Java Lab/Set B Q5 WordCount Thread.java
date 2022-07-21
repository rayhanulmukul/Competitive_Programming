import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.Scanner;

public class WordCount implements Runnable{
    File filename;
    Scanner in;
    public WordCount(String a) throws FileNotFoundException {
       filename = new File(a);
       in = new Scanner(filename);
    }
    public void run() {
            int wCount = 0;
            String word;
            while (in.hasNext()){
                word = in.next();
                wCount++;
            }
            System.out.println(filename + ": "+ wCount);
            in.close();
    }
    public static void main(String[] args) throws FileNotFoundException {
        WordCount w1 = new WordCount("Name.txt");
        WordCount w2 = new WordCount("Name.txt");
        WordCount w3 = new WordCount("Name.txt");
        Thread t1 = new Thread(w1);
        Thread t2 = new Thread(w2);
        Thread t3 = new Thread(w3);
        t1.run();
        t2.run();
        t3.run();
    }
}
