import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

class myThread implements Runnable{
    String filename, keyword;
    myThread(String one, String two){
        filename = one;
        keyword = two;
    }
    public void run() {
        try {
            Scanner searchWord = new Scanner(new File(filename));
            while (searchWord.hasNextLine()){
                String word = searchWord.nextLine();
                if(word.contains(keyword)){
                    System.out.println(filename + ": " + word);
                }
            }
        } catch (FileNotFoundException e) {
            System.out.println(e);
        }
    }
}
public class FileInput {
    public static void main(String[] args) {
        for(int i = 1; i < args.length; i++){
            myThread src = new myThread(args[i], args[0]);
            Thread my = new Thread(src);
            my.start();
        }
    }
}