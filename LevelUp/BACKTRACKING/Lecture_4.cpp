#include<bits/stdc++.h>
using namespace std;
vector<string>ans;
void ratinmaze(vector<vector<int>> &maze,int n,int i,int j,string &path){
    if(i<0 || i>n || j<0 || j<n || maze[i][j] == 0){
        return;
    }
    if(i == n-1 && j == n-1){
        ans.push_back(path);
        return;
    }
    maze[i][j] = 0;
    path.push_back('D');
    ratinmaze(maze,n,i+1,j,path);
    path.pop_back();
    path.push_back('R');
    ratinmaze(maze,n,i,j+1,path);
    path.pop_back();
    path.push_back('U');
    ratinmaze(maze,n,i-1,j,path);
    path.pop_back();
    path.push_back('L');
    ratinmaze(maze,n,i,j-1,path);
    path.pop_back();

    maze[i][j] = 1;

}
vector<string> findPath(vector<vector<int>> &maze, int n)
{
   string path = "";
ratinmaze(maze,n,0,0,path);
return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> maze(n, vector<int>(n));

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> maze[i][j];
        }
    }

    vector<string> ans = findPath(maze, n);

    if(ans.size() == 0)
    {
        cout << "No Path";
    }
    else
    {
        for(string &path : ans)
            cout << path << endl;
    }

    return 0;
}