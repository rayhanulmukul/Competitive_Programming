import javax.lang.model.type.NullType;
import java.io.*;
import java.text.*;
import java.util.*;
public class StudentList {
    public static void main(String[] args) {
        try {
            if (args[0].equals(Constant.ShowAll)) {
                System.out.println(Constant.loadingMessage);
                try {
                    String Line = getString();
                    String studentsName[] = Line.split(Constant.Delimator);
                    for (String studList : studentsName) {
                        System.out.println(studList);
                    }
                } catch (Exception e) {

                }
                System.out.println(Constant.DataLoadedMessage);
            } else if (args[0].equals(Constant.ShowRandom)) {
                System.out.println(Constant.loadingMessage);
                try {
                    String Line = getString();
                    // System.out.println(stringReadLine);
                    String studentsName[] = Line.split(Constant.Delimator);
                    Random randomNumber = new Random();
                    int indexStudent = (int) (randomNumber.nextInt(studentsName.length));
                    System.out.println(studentsName[indexStudent]);
                } catch (Exception e) {

                }
                System.out.println(Constant.DataLoadedMessage);
            } else if (args[0].contains(Constant.addEntry)) {
                System.out.println(Constant.loadingMessage);
                try {
                    BufferedWriter bufferedWriter = getBufferedWriter();
                    String studentsName = args[0].substring(1);
                    String dateFormate = Constant.DateFormate;
                    String dateFormat = new SimpleDateFormat(dateFormate).format(new Date());
                    bufferedWriter.write(Constant.Delimator + studentsName + Constant.UpdateList + dateFormat);
                    bufferedWriter.close();
                } catch (Exception e) {

                }
                System.out.println(Constant.DataLoadedMessage);
            } else if (args[0].contains(Constant.findEntry)) {
                System.out.println(Constant.loadingMessage);
                try {
                    String Line = getString();
                    String[] studentsName = Line.split(Constant.Delimator);
                    boolean done = false;
                    String subString = args[0].substring(1);
                    for (int index = 0; index < studentsName.length && !done; index++) {
                        if (studentsName[index].equals(subString)) {
                            System.out.println(Constant.findUpdate);
                            done = true;
                        }
                    }
                } catch (Exception e) {

                }
                System.out.println(Constant.DataLoadedMessage);
            } else if (args[0].contains(Constant.ShowCount)) {
                System.out.println(Constant.loadingMessage);
                try {
                    String Line = getString();
                    char[] charArray = Line.toCharArray();
                    boolean in_word = false;
                    int count = 0;
                    for (char charWord : charArray) {
                        if (charWord == Constant.ConstantSpace) {
                            if (!in_word) {
                                count++;
                                in_word = true;
                            } else {
                                in_word = false;
                            }
                        }
                    }
                    System.out.println(count + Constant.WordFound);
                } catch (Exception e) {

                }
                System.out.println(Constant.DataLoadedMessage);
            } else{

                System.out.println(Constant.ArgumentPassed);
            }
        } catch (Exception e) {
            System.out.println(Constant.NoArgumentPassed);
        }
    }

    private static BufferedWriter getBufferedWriter() throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(
                new FileWriter(Constant.StudentList, true));
        return bufferedWriter;
    }
    private static String getString() throws IOException {
        BufferedReader bufferedReader = new BufferedReader(
                new InputStreamReader(
                        new FileInputStream(Constant.StudentList)));
        String Line = bufferedReader.readLine();
        return Line;
    }
}
