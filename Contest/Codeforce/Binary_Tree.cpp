#include <bits/stdc++.h>
using namespace std;

void insert(int arr[], int value){
    if(arr[value] == 0) arr[value] = value;
    else if(arr[value] > value){
        insert()
    }
}
int main(){
    int arr[MX];
    memset (arr, -1, sizeof(arr));
    while (true){
        int value;
        cin >> value;
        if(value == -1) break;
        insert(arr, value);
    }
    
}