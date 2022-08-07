#include<stdio.h>

int main() {
    int n;
    printf("Enter the size of the array : ");
    scanf("%d", &n);
    int a[n];
    printf("Enter elements: ");
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    int flag = 0;
    // for finding duplicates...
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(a[i] == a[j] && i != j) {
                flag = 1;
                printf("Duplicates found at %d and %d index.\n", i, j);
                break;
            }
        }
        if(flag == 1) break;
    }
    if(flag == 0) printf("Duplicate Elements not found!\n");
    return 0;
}
