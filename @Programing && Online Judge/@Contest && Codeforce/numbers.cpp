#include <stdio.h>

int main(){
    freopen("input.txt","r",stdin); //take input from file
    freopen("output.txt", "w", stdout); //give output to file
    int arr[105];
    for(int i = 0; i < 100; i++){
        scanf("%d",&arr[i]);
    }
    int done[105] = {0};
    for(int i = 0; i < 100; i++){
        if(done[i] == 0){
            done[i] = 1;
            int cnt = 1;
            for(int j = i+1; j < 100; j++){
                if(arr[i] == arr[j]){
                    cnt++;
                    done[j] = 1; // j index count end and block
                }
            }
            printf("%d occured %d times\n", arr[i], cnt);
        }
    }
}