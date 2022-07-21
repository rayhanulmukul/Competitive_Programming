import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class S2Q4Find
{
   public static void main(String[] args) throws FileNotFoundException
   {
      int fileCount = 0;
      
      for (int i = 0; i < args.length; i++)
      {
         String target = args[0];
         if (i > 0)
         {
            String filename = args[i];
            fileCount++;
            Scanner in = new Scanner(new File(filename));
            TextFinder finder = new TextFinder();
            while (in.hasNextLine())
            {
               String line = finder.readLine(in, target);
               if (line != null)
               {
                  System.out.print(filename + ": ");
                  System.out.println(line.trim());
               }
            }
            
            in.close();
         }
      }
      
      if (fileCount == 0)
      {
         System.out.println("Usage: java Find target file1 [file2, ...]");
      }
   }
}


/**
   This class determines whether there is a match of a substring
   within a larger a string.
*/
class TextFinder
{   

   /**
      Reads the lines of a file and searches for the occurence
      of a substring
      @param in scanner object of the input file
      @param text the target substring
      @return the line containing the matched substring
   */
   public String readLine(Scanner in, String text)
   {
      String line = in.nextLine();
      
      if (contains(line, text)) { return line; }
      else { return null; }
   }
   
   /**
      Searches the line for an occurence of the given text
      @param line the searched string
      @param text the target substring
      @return true if the line contains text, otherwise false 
   */
   private boolean contains(String line, String text)
   {
      int pos = find(line, text);
      
      boolean matchFound = false;
      if (pos > 0) { matchFound = true; }
      
      return matchFound;
   }
   
   /**
      Finds the position of a substring within a string
      @param line the string searched
      @param text target substring
      @return beginning index of the target substring
      or -1 if no match is found
   */
   private int find(String line, String text)
   {  
      int i = 0;
      int j = line.length() - text.length();
      boolean found = false;
      
      while (i <= j && !found)
      {
         int end = i + text.length();
         if (line.substring(i, end).equals(text))
         {
            found = true;
         }
         else
         {
            i++;
         }
      }
      
      if (found) { return i; }
      else { return -1; }
   }
}

