#include<stdio.h>

int main() {
    int n;
    printf("Enter how many number to be hashed : ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements : ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int hash_0[n], hash_1[n], hash_2[n];
    int h0 = 0, h1 = 0, h2 = 0;
    printf("Elements hashed by using mod-3\n");
    for(int i = 0; i < n; i++) {
        int temp = a[i]%3;
        if(temp == 0) {
            hash_0[h0++] = a[i];
        }
        else if(temp == 1) {
            hash_1[h1++] = a[i];
        }
        else {
            hash_2[h2++] = a[i];
        }
    }

    printf("Mod 0 : ");
    for(int i = 0; i < h0; i++) printf("%d ", hash_0[i]);
    printf("\n");

    printf("Mod 1 : ");
    for(int i = 0; i < h1; i++) printf("%d ", hash_1[i]);
    printf("\n");

    printf("Mod 2 : ");
    for(int i = 0; i < h2; i++) printf("%d ", hash_2[i]);
    printf("\n");
    
    return 0;
}
