public class S1Q1TableTester
{
    public static void main(String[] args)
    {
        final int ROWS = 8;
        final int COLUMNS = 3;
        
        Table medals = new Table(ROWS, COLUMNS);
        
        int[][] counts = {
                { 0, 3, 0 },
                { 0, 0, 1 },
                { 0, 0, 1 },
                { 1, 0, 0 },
                { 0, 0, 1 },
                { 3, 1, 1 },
                { 0, 1, 0 },
                { 1, 0, 1 } 
            };
            
            for (int i = 0; i < ROWS; i++)
            {
                for (int j = 0; j < COLUMNS; j++)
                {
                    medals.set(i, j, counts[i][j]);
                }
            }
            
            // find the average of the neighbors
            System.out.println("Actual: " + medals.neighborAverage(0, 0));
            System.out.println("Expected: 1.0");
            System.out.println();
            
            System.out.println("Actual: " + medals.neighborAverage(7, 1));
            System.out.println("Expected: 0.6");
            System.out.println();
                        
            System.out.println("Actual: " + medals.neighborAverage(4, 0));
            System.out.println("Expected: 1.0");
            System.out.println();
                      
            System.out.println("Actual: " + medals.neighborAverage(2, 1));
            System.out.println("Expected: 0.375");
    }
}



class Table
{
    private int[][] values;
    
    public Table(int rows, int columns)
    {
        values = new int[rows][columns];
    }
    
    public void set(int i, int j, int n)
    {
        values[i][j] = n;
    }
    
    public double neighborAverage(int row, int column)
    {
        int total = 0;
        int neighbors = 0;
        int[] rowColumnOffset = { -1, 0, 1 };
        
        for (int deltaR : rowColumnOffset)
        {
            for (int deltaC: rowColumnOffset)
            {
                if (row + deltaR >= 0 
                    && row + deltaR < values.length
                    && column + deltaC >= 0
                    && column + deltaC < values[0].length)
                {
                    total = total + values[row + deltaR][column + deltaC];
                    neighbors++;
                }
            }
        }
        
        // remove the element at values[row + 0][column + 0]
        total = total - values[row][column];
        neighbors--;
       
        // calculate and return the average
        return total * 1.0 / neighbors;
    }
}