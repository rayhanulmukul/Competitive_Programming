import java.util.Scanner;
class ComboLock{
    int secret1,secret2,secret3;
    int dial = 0, pass = 0, lastTime = -1;
    int[] sec = new int[3];
    public ComboLock(int secret1, int secret2, int secret3){
        this.secret1 = secret1;
        this.secret2 = secret2;
        this.secret3 = secret3;
    }
    public void reset(){
        dial = 0;
        pass = 0;
    }
    public void turnRight(int ticks){
        if(lastTime == 0){
            sec[pass] = dial;
            pass++;
        }
        dial += ticks;
        dial %= 40;
        lastTime = 1;
    }
    public void turnLeft(int ticks){
        if(lastTime == 1){
            sec[pass] = dial;
            pass++;
        }
        dial -= ticks;
        while(dial < 0) dial += 40;
        lastTime  = 0;
    }
    public boolean open(){
        sec[pass] = dial;
        System.out.println(sec[0] + " " + sec[1] + " " + sec[2]);
        if(secret1 == sec[0] && secret2 == sec[1] && secret3 == sec[2]){
            return true;
        }
        return false;
    }

}
public class ComboLockQ2 {
    public static void main(String[] args) {
        ComboLock ap = new ComboLock(10,15,10);
        ap.turnRight(10);
        ap.turnLeft(35);
        ap.turnRight(35);
        if(ap.open()){
            System.out.println("Password is Open");
        }
        else{
            System.out.println("Wrong PassWOrd");
        }

    }
}
