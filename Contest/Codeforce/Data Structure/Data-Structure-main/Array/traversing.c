#include<stdio.h>
#include<math.h>

void max_value(int a[], int n) {
    int max = a[0];
    for(int i = 1; i < n; i++) 
        if(a[i] > max) max = a[i];
    printf("Maximum value of the array is : %d\n", max);
}

void min_value(int a[], int n) {
    int min = a[0];
    for(int i = 1; i < n; i++) 
        if(a[i] < min) min = a[i];
    printf("Minimum value of the array is : %d\n", min);
}

void avg_value(int a[], int n) {
    int sum = 0;
    for(int i = 0; i < n; i++) sum += a[i];
    double avg = sum * 1.0 / n;
    printf("Average : %0.3lf\n", avg);
}

void total_value(int a[], int n) {
    int total = 0;
    for(int i = 0; i < n; i++) total += a[i];
    printf("Total : %d\n", total);
}

void sin_value(int a[], int n) {
    for(int i = 0; i < n; i++) {
        printf("Sin value of %d is : %0.3lf\n", a[i], sin(a[i]));  // in radian
    }
} 

int main()
{
    printf("Enter the size of the array: ");
    int n;
    scanf("%d",&n);
    int a[n];
    printf("Enter Elements: ");
    for(int i = 0; i < n; i++) {
        scanf("%d",&a[i]);
    }
    max_value(a, n);
    min_value(a, n);
    avg_value(a, n);
    total_value(a, n);
    sin_value(a, n);
    return 0;

}
