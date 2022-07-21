import javax.sound.midi.Sequence;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

class Sequence1{
    private ArrayList<Integer> values;
    public Sequence1(){
        values = new ArrayList<Integer>();
    }
    public void add(int n){
        values.add(n);
    }
    public Sequence1 append(Sequence1 other){
        Sequence1 both = new Sequence1();
        both.values = new ArrayList<>(values);
        for(int element : other.values){
            both.add(element);
        }
        return both;
    }
    public String toString(){
        return values.toString();
    }
}
public class arraySequnce {
    public static void main(String[] args) throws FileNotFoundException {
        Sequence1 arrA = new Sequence1();
        Sequence1 arrB = new Sequence1();
        Scanner sc = new Scanner(System.in);
        System.out.println("Please Enter the Element arrA or q to quit : ");
        while(sc.hasNextInt()){
            arrA.add(sc.nextInt());
        }
        System.out.println("Please Enter the Element arrB or q to quit : ");
        sc = new Scanner(System.in);
        while(sc.hasNextInt()){
            arrB.add(sc.nextInt());
        }
        Sequence1 bothOther = arrA.append(arrB);
        System.out.println("Array A elements : " + arrA);
        System.out.println("Array B elements : " + arrB);
        System.out.println("Array BothOthers elements : " + bothOther);
    }
}
