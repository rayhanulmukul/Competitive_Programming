#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int main(){
    int A1 = 0, B1 = 0, C1 = 0;
    int A[3][3], B[3][3], C[3][3];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            scanf("%d", &A[i][j]);
            if(i == 0){
                A1 = max(A1, A[i][j]);
            }
            else if(i == 1){
                B1 = max(B1, A[i][j]);
            }
            else{
                C1 = max(C1, A[i][j]);
            }
            
        }
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            scanf("%d", &B[i][j]);
            if(i == 0){
                A1 = max(A1, B[i][j]);
            }
            else if(i == 1){
                B1 = max(B1, B[i][j]);
            }
            else{
                C1 = max(C1, B[i][j]);
            }
        }
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            scanf("%d", &C[i][j]);
            if(i == 0){
                A1 = max(A1, C[i][j]);
            }
            else if(i == 1){
                B1 = max(B1, C[i][j]);
            }
            else{
                C1 = max(C1, C[i][j]);
            }
        }
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(i == 0){
                printf("%d",A1);
                printf(" ");
            }
            else if(i == 1){
                printf("%d",B1);
                printf(" ");
            }
            else{
                printf("%d",C1);
                printf(" ");
            }
        }
        printf("\n");
    }
}