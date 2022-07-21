import javax.sound.midi.Sequence;
import java.util.ArrayList;
import java.util.Scanner;
class Sequence1{
    private ArrayList<Integer> values;
    public Sequence1(){
        values = new ArrayList<>();
    }
    public void add(int n){
        values.add(n);
    }
    public Sequence1 append(Sequence1 other){
        Sequence1 both = new Sequence1();
        both.values = new ArrayList<>(values);
        for(int element: other.values){
            both.add(element);
        }
        return both;
    }
    public String toString(){
        return values.toString();
    }
}
public class arraySequnce {
    public static void main(String[] args) {
        Sequence1 arrA = new Sequence1();
        Sequence1 arrB = new Sequence1();
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the numbers of elements : ");
        int n = sc.nextInt();
        System.out.println("Please Enter the A array input : ");
        for(int i = 0; i < n; i++) arrA.add(sc.nextInt());
        System.out.println("Array B Elements Are : ");
        for(int i = 0; i < n; i++) arrB.add(sc.nextInt());

        Sequence1 bothSequence = arrA.append(arrB);
        System.out.println("Sequence1 arrA : " + arrA);
        System.out.println("Sequence1 arrB : " + arrA);
        System.out.println("Sequence1 bothSequence: " + bothSequence);

    }
}

