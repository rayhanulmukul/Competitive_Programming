class Balloon{
    private int radias;
    public void inflate(double incr){
        radias += incr;
    }
    public double getVolume(){
        double ans = Math.PI*4.00*radias*radias*radias;
        ans /= 3.00;
        return ans;
    }
    Balloon(){
        radias = 0;
    }
}


public class one {
    
    public static void main(String arg[]){
        Balloon asif = new Balloon();
        asif.inflate(50);
        System.out.println(asif.getVolume());
    }   
}
