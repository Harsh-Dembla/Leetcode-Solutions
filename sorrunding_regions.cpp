#include <iostream>
#include <iostream>
#include<list>
#include<unordered_map>
#include<queue>
#include<vector>
#include<stack>
#include<algorithm>
#include<utility>
using namespace std;

bool isvalid(vector<vector<char>>&board,int i,int j,int m,int n,vector<vector<int>>&visited){


    if(i>=0 && i<m && j>=0 && j<n  && board[i][j]=='O' && visited[i][j]!=1){
        return true;
    }
    
    return false;
}



void dfs(vector<vector<int>>&visited,vector<vector<char>>&board,int i,int j,int m,int n){
    
    if(isvalid(board,i,j,m,n,visited)){
        
        visited[i][j]=1;

        dfs(visited,board,i+1,j,m,n);
        dfs(visited,board,i-1,j,m,n);
        dfs(visited,board,i,j+1,m,n);
        dfs(visited,board,i,j-1,m,n);

    
    }
}
void solve() {
        int m,n;
    cin>>m>>n;

    vector<vector<char>>board(m,vector<char>(n,'#'));

    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            cin>>board[i][j];
        }
    }

    vector<vector<int>>visited(m,vector<int>(n,0));

    for(int i=0;i<m;++i){
        

        if(board[i][0]=='O'){
            dfs(visited,board,i,0,m,n);
        }
       
          if(board[i][n-1]=='O'){
            dfs(visited,board,i,n-1,m,n);
        }
    }

    for(int i=0;i<n;++i){
         if(board[0][i]=='O'){
            dfs(visited,board,0,i,m,n);
        }
          if(board[m-1][i]=='O'){
            dfs(visited,board,m-1,i,m,n);
        }
    }


    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            if(visited[i][j]) cout<<i<<" "<<j<<endl;
            if(visited[i][j]==0 && board[i][j]=='O'){
                cout<<i<<" "<<j<<endl;
                board[i][j]='X';
            }
        }
    }
  
       


        for (int  i = 0; i < m; i++)
        {
            for (int j  = 0; j < n; j++)
            {
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
            
        }
        

}

int main() {
    int t, i = 1;
    cin >> t;
    while(t--) {
        cout << "Case #" << i << ": ";
        solve();
        ++i;
    }
    return 0;
}