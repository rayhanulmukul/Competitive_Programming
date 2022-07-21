import java.util.Scanner;
import java.util.ArrayList;

public class S2Q1SequenceDemo
{
    public static void main(String[] args)
    {
        Sequence sequenceA = new Sequence();
        Sequence sequenceB = new Sequence();
        
        System.out.println("Enter sequence of values, Q to quit:");
        Scanner in = new Scanner(System.in);
        while (in.hasNextInt())
        {
            sequenceA.add(in.nextInt()); 
        }
        
        System.out.println("Enter another sequence of values, Q to quit:");
        in = new Scanner(System.in);
        while (in.hasNextInt())
        {
            sequenceB.add(in.nextInt());
        }
        
        Sequence bothSequence = sequenceA.append(sequenceB);
        
        System.out.println();
        System.out.println("Sequence A: " + sequenceA);
        System.out.println("Sequence B: " + sequenceB);
        System.out.println("Both: " + bothSequence);
    }
}



class Sequence
{
    private ArrayList<Integer> values;
    
    public Sequence()
    {
        values = new ArrayList<Integer>();
    }
    
    public void add(int n)
    {
        values.add(n);
    }
    
    public Sequence append(Sequence other)
    {
        Sequence both = new Sequence();
        
        // Copy values from this Sequence to the Sequence both
        
        both.values = new ArrayList<Integer>(values);
        
        // Append elements from other Sequence to Sequence both
        
        for (int element : other.values)
        {
            both.add(element);
        }
        
        return both;
    }
    
    public String toString()
    {
        return values.toString();
    }
}