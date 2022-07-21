import java.util.ArrayList;

interface NumberFormatter{
    String format(int n);
}
class DefaultFormatter implements NumberFormatter{
    @Override
    public String format(int n) {
        return Integer.toString(n);
    }
}
class DecimalSeparatorFormatter implements NumberFormatter{

    @Override
    public String format(int n) {
        String num = Integer.toString(n);
        StringBuilder newnum = new StringBuilder();
        int cnt = 0;
        for(int i = num.length()-1; i >= 0; i--){
            if(cnt == 3) {
                newnum.append(',');
                cnt= 0;
            }
            newnum.append(num.charAt(i));
            cnt++;

        }
        newnum.reverse();
        return newnum.toString();
    }
}
class AccountingFormatter implements NumberFormatter{
    @Override
    public String format(int n) {
        String num = Integer.toString(Math.abs(n));
        if(n < 0) {
            num = "(" +num + ")";
        }
        return num;
    }
}
class BaseFormatter implements NumberFormatter{
    Integer base ;
    String[] digits = {
            "0", "1", "2", "3", "4", "5", "6", "7", "8", "9",
            "A", "B", "C", "D", "E", "F", "G", "H", "I", "J",
            "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T",
            "U", "V", "W", "X", "Y", "Z"
    };
    BaseFormatter(int base){
        this.base = base;
    }
    @Override
    public String format(int n) {
        ArrayList<Integer> newnum = new ArrayList<Integer>();
        while(n > 0){
            newnum.add(n%base);
            n /= base;
        }
        String ans = "";
        for(int i = newnum.size()-1; i >= 0;i--){
            ans += digits[newnum.get(i)];
        }
        return ans;
    }
}

public class Ques2 {
    public static void main(String[] args) {
        DefaultFormatter sv = new DefaultFormatter();
        System.out.println(sv.format(100));

        DecimalSeparatorFormatter ap = new DecimalSeparatorFormatter();
        System.out.println(ap.format(100304200));

        AccountingFormatter ep = new AccountingFormatter();
        System.out.println(ep.format(100));
        System.out.println(ep.format(-100));

        BaseFormatter cv = new BaseFormatter(36);
        System.out.println(cv.format(30));
    }
}
