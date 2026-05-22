#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int Submatrixsum(vector<vector<int>> &mat){
    int ans = 0;
    int n = mat.size();
    int m = mat[0].size();
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            int occ = (i+1)*(j+1)*(n-i)*(m-j);
            ans += occ*mat[i][j];
     }
    }
    return ans;
}
int main() {
int n,m;  
cin>>n>>m;
vector<vector<int>> mat(n,vector<int>(m));
for(int i = 0; i<n; i++){
    for(int j = 0; j<m; j++){
        cin>>mat[i][j];
}
}
int ans = Submatrixsum(mat);
cout<<ans<<endl;
return 0;
}