/**
   Describes objects that can format integers. 
*/
interface NumberFormatter
{
   /**
      Converts an integer to the desired format.
      @param n the integer
      @return the integer as a formatted string 
   */
   String format(int n);
}

class AccountingFormatter implements NumberFormatter
{
   public String format(int n)
   {
      if (n >= 0) { return "" + n; }
      else { return "(" + n + ")"; } 
   }
}

class BaseFormatter implements NumberFormatter
{  
   private static final int LOWER_BOUND = 2;
   private static final int UPPER_BOUND = 36;
   
   private static final String[] digits = {
      "0", "1", "2", "3", "4", "5", "6", "7", "8", "9",
      "A", "B", "C", "D", "E", "F", "G", "H", "I", "J",
      "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T",
      "U", "V", "W", "X", "Y", "Z"
   };
   
   private int base;
   
   /**
      Constructor for an object that formats a number using a
      base between 2 - 36.
      @param aBase the base 
   */
   public BaseFormatter(int aBase)
   {
      base = aBase;
   }
   
   public String format(int n)
   {
      if (base < LOWER_BOUND || base > UPPER_BOUND)
      {
         System.out.println("Base ought to be between 2 - 36.");
         return null;
      }
      
      String out = "";
      String sign = (n < 0) ? "-" : "";
      if (n < 0) { n = -n; }
      while (n > 0)
      {
         int rem = n % base;
         out = digits[rem] + out;
         n = n / base;
      }
      
      return sign + out;
   }
}

class DecimalSeperatorFormatter implements NumberFormatter
{
   public String format(int n)
   {
      final int DIGITS_PRECEEDING_DECIMAL = 3;
      
      String out = "";
      
      String str;
      if (n < 0) 
      {
         str = new DefaultFormatter().format(-n);
      }
      else 
      {
         str = new DefaultFormatter().format(n);
      }
      
      for (int i = str.length() - 1; i >= 0; i--)
      {
         if (i % DIGITS_PRECEEDING_DECIMAL == 0 && i != str.length() - 1)
         {
            out = "," + out;
         }
         out = str.charAt(i) + out;
      }
      
      if (n < 0) { out = "-" + out; }
      return out;
   }
}

class DefaultFormatter implements NumberFormatter
{
   public String format(int n)
   {
      return "" + n;
   }
}


public class S1Q3FormatterDemo
{
   public static void main(String[] args)
   {
      NumberFormatter[] formatters = new NumberFormatter[]
         {
            new DefaultFormatter(),
            new DecimalSeperatorFormatter(),
            new AccountingFormatter(),
            new BaseFormatter(8)
         };
         
      for (NumberFormatter f : formatters)
      {
         System.out.println(f.format(-1000000));
      }
      System.out.println();
      
      for (NumberFormatter f : formatters)
      {
         System.out.println(f.format(1048576));
      }         
   }      
}