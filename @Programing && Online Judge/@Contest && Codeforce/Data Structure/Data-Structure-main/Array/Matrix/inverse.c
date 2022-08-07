#include<stdio.h>

int main(){

  int a[3][3];
  float determinant=0;

  printf("Enter a 3x3 matrix : ");
  for(int i = 0; i < 3; i++)
      for(int j = 0 ; j < 3; j++)
           scanf("%d",&a[i][j]);

  printf("\nEntered Matrix : ");
  for(int i = 0; i < 3; i++){
      printf("\n");
      for(int j=0;j<3;j++)
           printf("%d  ",a[i][j]);
  }

  for(int i = 0;i < 3;i++)
      determinant = determinant + (a[0][i]*(a[1][(i+1)%3]*a[2][(i+2)%3] - a[1][(i+2)%3]*a[2][(i+1)%3]));

   printf("\n\nInverse Matrix :\n");
   for(int i = 0;i < 3;i++){
      for(int j = 0;j < 3;j++)
           printf("%.2f\t",((a[(i+1)%3][(j+1)%3] * a[(i+2)%3][(j+2)%3]) - (a[(i+1)%3][(j+2)%3]*a[(i+2)%3][(j+1)%3]))/ determinant);
       printf("\n");
   }

   return 0;
}


/*

Output:

Enter a 3x3 matrix : 
100 33 31
45 77 14
70 47 75

Entered Matrix : 
100  33  31  
45  77  14  
70  47  75  

Inverse Matrix :
0.02	-0.01	-0.01	
-0.00	0.02	-0.01	
-0.01	-0.00	0.02

*/
