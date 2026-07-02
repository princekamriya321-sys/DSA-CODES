#include<bits/stdc++.h>
using namespace std;
bool check(vector<vector<int>> &mat,int n,int i,int j){
    for(int r = 0; r<i; r++){
        if(mat[r][j] == 1){return false;}
    }
    int r= i;
    int c = j;
    // left digaonal
    while(r>= 0 && c>=0){
        if(mat[r][c] == 1) return false;
        r--;
        c--;
    }
    //right diagonal
    r = i;
    c = j;
    while(r>=0 && c<=n-1){
        if(mat[r][c] == 1) return false;
        r--;
        c++;
    }
    return true;
}
void solver(vector<vector<int>> &mat,int n,int i){
    if(i == n){
    for(int i =0; i<n; i++){
        for(int j = 0; j<n; j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
        return;
    }
    for(int j = 0; j<n; j++){
        if(check(mat,n,i,j) == true){
         mat[i][j] = 1;
         solver(mat,n,i+1);
         mat[i][j] = 0;
        }
    }
}
void solveNQueens(int n){
vector<vector<int>>mat(n,vector<int>(n,0));
solver(mat,n,0);
}


int main()
{
    int n;
    cin >> n;

    solveNQueens(n);

    return 0;
}