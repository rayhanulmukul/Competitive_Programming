public class three {
    public static void main(String arg[]){
        ComboLock lock = new ComboLock(2, 3, 4);
        lock.reset();
        lock.turnRight(2);
        lock.turnLeft(39);
        lock.turnRight(1);
        if(lock.open() == true){
            System.out.println("Lock Opened");
        }else{
            System.out.println("Wrong Password");
        }
    }
}
