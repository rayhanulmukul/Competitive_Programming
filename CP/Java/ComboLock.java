public class ComboLock{
    private int secret1, secret2, secret3;
    private int tiknow = 0;
    private int last = -1;
    private int[] mysecret = new int[3];
    private int indx;
    public ComboLock(int secret1, int secret2, int secret3){
        this.secret1 = secret1;
        this.secret2 = secret2;
        this.secret3 = secret3;
    }
    public void reset(){
        indx = 0;
        tiknow = 0;
    }
    public void turnLeft(int ticks){
        //for this last will be 0
        if(last == 1){
            if(indx >= 3){
                System.out.println("You are turning the dial more then 3 times\n, Start again");
                indx = 0;
                return;
            }
            mysecret[indx] = tiknow;
            indx++;
        }
        tiknow-= ticks;
        while(tiknow < 0) tiknow += 40;
        last = 0;
    }
    public void turnRight(int ticks){
        //for this last will be 1
        if(last == 0){
            if(indx >= 3){
                System.out.println("You are turning the dial more then 3 times\n, Start again");
                indx = 0;
                return;
            }
            mysecret[indx] = tiknow;
            indx++;
        }
        tiknow += ticks;
        tiknow %= 40;
        last = 1;
    }
    public boolean open(){
        mysecret[indx] = tiknow;
        if(secret1 == mysecret[0] && secret2 == mysecret[1] && secret3 == mysecret[2]){
            return true;
        }
        return false;
    }
}