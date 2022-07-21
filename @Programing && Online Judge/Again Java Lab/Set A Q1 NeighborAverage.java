class Table{
    private int[][] values;
    public Table(int rows, int columns){
        values = new int[rows][columns];
    }
    public void set(int i, int j, int n){
        values[i][j] = n;
    }
    public boolean valid(int i, int j){
        int n = values.length;
        int m = values[0].length;
        if(i >= 0 && i < n && j >= 0 && j < m) return true;
        return false;
    }
    public double neighborAverage(int i, int j){
        double sum = 0.0;
        int n = values.length;
        //System.out.println("NeighborAverage n : "+ n);
        int m = values[0].length;
       // System.out.println("NeighborAverage m : "+ m);
        int cnt = 0;
        if(valid(i-1, j-1)){
            sum += values[i-1][j-1];
            cnt++;
        }
        if(valid(i-1, j+1)){
            sum += values[i-1][j+1];
            cnt++;
        }
        if(valid(i-1, j)){
            sum += values[i-1][j];
            cnt++;
        }if(valid(i, j-1)){
            sum += values[i][j-1];
            cnt++;
        }
        if(valid(i, j+1)){
            sum += values[i][j+1];
            cnt++;
        }
        if(valid(i+1, j-1)){
            sum += values[i+1][j-1];
            cnt++;
        }
        if(valid(i+1, j)){
            sum += values[i+1][j];
            cnt++;
        }
        if(valid(i+1, j+1)){
            sum += values[i+1][j+1];
            cnt++;
        }
        //System.out.println("Sum : "+ sum);
        //System.out.println("Count : "+ cnt);
        return sum/cnt;
    }
}
public class neighborAverage {
    public static void main(String[] args) {
        int rows = 8;
        int colums = 3;
        Table medals = new Table(rows, colums);
        int[][] arr = {
                {0, 3, 0},
                {0, 0, 1},
                {0, 0, 1},
                {1, 0, 0},
                {0, 0, 1},
                {3, 1, 1},
                {0, 1, 0},
                {1, 0, 1}};
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < colums; j++){
                medals.set(i, j, arr[i][j]);
            }
        }
        System.out.println("Actual: " + medals.neighborAverage(0, 1));
        System.out.println("Expected: 0.2");
        System.out.println();
        System.out.println("Actual: " + medals.neighborAverage(7, 1));
        System.out.println("Expected: 0.6");
        System.out.println();
        System.out.println("Actual: " + medals.neighborAverage(4, 0));
        System.out.println("Expected: 1.0");
        System.out.println();
        System.out.println("Actual: " + medals.neighborAverage(2, 1));
        System.out.println("Expected: 0.375");
        System.out.println();
    }
}
