#include<bits/stdc++.h>
using namespace std;
int arr[9][9];
bool isSafe(int r, int c, int v, int arr[][9]){
    for(int i = 0; i<9; i++){
        if(arr[r][i] == v) return false;
        if(arr[i][c] == v) return false;
        if(arr[3*(r/3) + i/3][3*(c/3) + i%3] == v) return false;
    }
    return true;
}
bool solveSudoku(int arr[][9]){
    for(int i = 0; i<9; i++){
        for(int j = 0; j<9; j++){
            if(arr[i][j] == 0){
                for(int v = 1; v <= 9; v++){
                    if(isSafe(i,j,v,arr)){
                        arr[i][j] = v;
                        if(solveSudoku(arr) == true) return true;
                        else arr[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }
}
int main(){
    for(int i = 0; i<9; i++){
        for(int j = 0; j<9; j++){
            cin >> arr[i][j];
        }
    }
    if(solveSudoku(arr)) cout << "true";
    else cout << "false";
}