import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

class SearchWord implements Runnable{
    String searchWord, filename;
    SearchWord(String one, String two){
        searchWord = one;
        filename = two;
    }
    public void run(){
        try{
            Scanner sc = new Scanner(new File(filename));
            while (sc.hasNextLine()){
                String searchW = sc.nextLine();
                if(searchW.contains(filename)){
                    System.out.println(filename + ": "+ searchW);
                }
            }
        }catch (FileNotFoundException e){
            e.printStackTrace();
        }
    }
}
public class FileInput {
    public static void main(String[] args) {
        String srcWord = args[0];
        for(int i = 0; i < args.length; i++){
            SearchWord src = new SearchWord(srcWord, args[i]);
            Thread t1 = new Thread((Runnable) src);
            t1.run();
        }
    }
}