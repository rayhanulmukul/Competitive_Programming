import javafx.scene.control.Tab;

import java.util.Scanner;

class Table{
    private int[][] values;
    public Table(int rows, int columns){
        values = new int[rows][columns];
    }
    public void set(int i,int j, int n){
        values[i][j] = n;
    }
    public boolean valid(int i, int j){
        //this will return true if cell i,j is valid
        //for example -1, 2 is invalid
        //1,2 is valid when n= 3, m =4;
        //when n = 2, m =3 (that means the table is 2*3) i = 5,j= 1 is invalid
        int n = values.length;
        int m = values[0].length;
        if(i >= 0 && i <= n-1 && j >= 0 && j <= m-1) return true;
        return false;
    }
    public double nighborAverage(int i,int j){
        double sum = 0.0;
        int cnt = 0;
        if(valid(i-1,j-1)){
            sum += values[i-1][j-1];
            cnt++;
        }
        if(valid(i-1,j+1)){
            sum += values[i-1][j+1];
            cnt++;
        }if(valid(i-1,j)){
            sum += values[i-1][j];
            cnt++;
        }if(valid(i,j-1)){
            sum += values[i][j-1];
            cnt++;
        }if(valid(i,j+1)){
            sum += values[i][j+1];
            cnt++;
        }if(valid(i+1,j-1)){
            sum += values[i+1][j-1];
            cnt++;
        }if(valid(i+1,j)){
            sum += values[i+1][j];
            cnt++;
        }if(valid(i+1,j+1)) {
            sum += values[i + 1][j + 1];
            cnt++;
        }
        return sum/cnt;
    }
}

public class Ques1 {
    public static void main(String[] args) {
        System.out.println("Enter row number and column number");
        Scanner in = new Scanner(System.in);
        int row = in.nextInt();
        int col = in.nextInt();
        System.out.println("Enter the numbers: ");
        Table a = new Table(row,col);
        for(int i = 0;i < row; i++){
            for(int j = 0; j <col; j++){
                a.set(i,j, in.nextInt());
            }
        }
        System.out.println("Enter the index for average");
        int x = in.nextInt(), y = in.nextInt();
        System.out.println("Neighbore average is "+ a.nighborAverage(x,y));
    }
}