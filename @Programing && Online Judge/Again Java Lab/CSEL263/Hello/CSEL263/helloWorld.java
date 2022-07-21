import javax.lang.model.type.NullType;
import java.io.*;
import java.text.*;
import java.util.*;
public class StudentList {
    public static void main(String[] args) {
            if(args.length ==  0 || args.length != 1){
                System.out.println("Usage: a | r | c | +word | ?word");
                return;
            }
            if (args[0].equals(Constant.ShowAll)) {
                System.out.println("Loading data ...");
                try {
                    BufferedReader bufferedReader = new BufferedReader(
                            new InputStreamReader(
                                    new FileInputStream(Constant.StudentList)));
                    String Line = bufferedReader.readLine();
                    String studentsName[] = Line.split(", ");
                    for (String studList : studentsName) {
                        System.out.println(studList);
                    }
                } catch (Exception e) {

                }
                System.out.println("Data Loaded.");
            } else if (args[0].equals("r")) {
                System.out.println("Loading data ...");
                try {
                    BufferedReader s = new BufferedReader(
                            new InputStreamReader(
                                    new FileInputStream("students.txt")));
                    String stringReadLine = s.readLine();
                    // System.out.println(stringReadLine);
                    String studentsName[] = stringReadLine.split(", ");
                    Random randomNumber = new Random();
                    int indexStudent = (int) (randomNumber.nextInt(studentsName.length));
                    System.out.println(studentsName[indexStudent]);
                } catch (Exception e) {

                }
                System.out.println("Data Loaded.");
            } else if (args[0].contains("+")) {
                System.out.println("Loading data ...");
                try {
                    BufferedWriter bufferedWriter = new BufferedWriter(
                            new FileWriter("students.txt", true));
                    String studentsName = args[0].substring(1);
                    Date date = new Date();
                    String dateFormate = "dd/mm/yyyy-hh:mm:ss a";
                    DateFormat dateFormat = new SimpleDateFormat(dateFormate);
                    String finalDate = dateFormat.format(date);
                    bufferedWriter.write(", " + studentsName + "\nList last updated on " + finalDate);
                    bufferedWriter.close();
                } catch (Exception e) {

                }
                System.out.println("Data Loaded.");
            } else if (args[0].contains("?")) {
                System.out.println("Loading data ...");
                try {
                    BufferedReader bufferReader = new BufferedReader(
                            new InputStreamReader(
                                    new FileInputStream("students.txt")));
                    String stringLine = bufferReader.readLine();
                    String[] studentsName = stringLine.split(", ");
                    boolean done = false;
                    String subString = args[0].substring(1);
                    for (int index = 0; index < studentsName.length && !done; index++) {
                        if (studentsName[index].equals(subString)) {
                            System.out.println("We found it!");
                            done = true;
                        }
                    }
                } catch (Exception e) {

                }
                System.out.println("Data Loaded.");
            } else if (args[0].contains("c")) {
                System.out.println("Loading data ...");
                try {
                    BufferedReader bufferedReader = new BufferedReader(
                            new InputStreamReader(
                                    new FileInputStream("students.txt")));
                    String stringReadLine = bufferedReader.readLine();
                    char[] charArray = stringReadLine.toCharArray();
                    boolean in_word = false;
                    int count = 0;
                    for (char charWord : charArray) {
                        if (charWord == ' ') {
                            if (!in_word) {
                                count++;
                                in_word = true;
                            } else {
                                in_word = false;
                            }
                        }
                    }
                    System.out.println(count + " word(bufferedReader) found ");
                } catch (Exception e) {

                }
                System.out.println("Data Loaded.");
            }else{
                System.out.println("Dear Sir!, Wrong Arguments Are Passed, Please Try Another Input Character");
            }
    }
}























