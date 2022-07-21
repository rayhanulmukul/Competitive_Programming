import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Question4 {
    public static void main(String[] args) throws FileNotFoundException {
        String senLine;
        Scanner in = new Scanner(new File("Name.txt"));
        int i = 1;
        while(in.hasNextLine()){
            senLine = in.nextLine();
            System.out.println("/*"+i+"*/"+ senLine);
            i++;
        }
    }
}
