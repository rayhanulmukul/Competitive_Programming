#include <stdio.h>

int fibonacci(int n) {
  if(n == 0) return 0;
  if(n == 1) return 1;
  return (fibonacci(n-1) + fibonacci(n-2));
}

int main()
{
    int number;
    scanf("%d", &number);
    int fib;
    printf("Fibonacci sequence for %d : ", number);
    for(int i = 0; i <= number; i++) {
      fib = fibonacci(i);
      printf("%d ", fib);
    }
    printf("\n");
    
    printf("%dth fibonacci number : %d\n", number, fib);
    
    return 0;
}


/*

Output:

Fibonacci sequence for 15 : 0 1 1 2 3 5 8 13 21 34 55 89 144 233 377 610 
15th fibonacci number : 610
  */
