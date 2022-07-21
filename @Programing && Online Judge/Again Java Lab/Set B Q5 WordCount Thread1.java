import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

class myThread1 implements Runnable{
    File filename;
    Scanner in;

    public myThread1(File a) throws FileNotFoundException {
        filename = a;
        in = new Scanner(filename);
    }
    @Override
    public void run() {
            int wCount = 0;
            String word;
            while (in.hasNext()){
                word = in.next();
                wCount++;
            }
            System.out.println(filename + ": "+ wCount);
    }
}
public class Count {
    public static void main(String[] args) throws FileNotFoundException {
        myThread1 m1 = new myThread1(new File("Name.txt"));
        myThread1 m2 = new myThread1(new File("Mukul.txt"));
        myThread1 m3 = new myThread1(new File("Hello.txt"));
        Thread my1 = new Thread(m1);
        Thread my2 = new Thread(m2);
        Thread my3 = new Thread(m3);
        my1.start();
        my2.start();
        my3.start();

    }
}
