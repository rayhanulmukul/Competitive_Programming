#include<stdio.h>
#include<string.h>

void printit(char arr[]){
    int len = strlen(arr);
    for(int i = 0; i < 5; i++){
        printf("%c ", arr[i]);
    }
    printf("\n");
}

int main(){
    char arr[] = "ashiq";
    printit(arr);
}