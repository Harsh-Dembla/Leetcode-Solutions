#include <iostream>
#include <iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<utility>
#include<set>
using namespace std;

class Graph{

    public:
    unordered_map<int,list<int>>adj;


    void insert(int u,int v,bool direction){

        adj[u].push_back(v);
        if(!direction){
            adj[v].push_back(u);
        }

    }

   
};


void dfs(int i,int j,int prevheight,vector<vector<int>>&visited,vector<vector<int>>&height,int n,int m){

    if(i>=0 && i<n && j>=0 && j<m && height[i][j]>=prevheight && visited[i][j]!=1){
       

        visited[i][j]=1;

        dfs(i+1,j,height[i][j],visited,height,n,m);
        dfs(i-1,j,height[i][j],visited,height,n,m);
        dfs(i,j+1,height[i][j],visited,height,n,m);
        dfs(i,j-1,height[i][j],visited,height,n,m);


    }

}




using namespace std;

void solve() {
    
    int n,m;
    cin>>n>>m;


    vector<vector<int>>grid(n,vector<int>(m,0));
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>grid[i][j];
        }
    }

    vector<vector<int>>pacific(n,vector<int>(m,0));

    vector<vector<int>>atlantic(n,vector<int>(m,0));

    for(int j=0;j<m;++j){
        dfs(0,j,grid[0][j],pacific,grid,n,m);
        dfs(n-1,j,grid[n-1][j],atlantic,grid,n,m);
    }

    for(int i=0;i<n;++i){
        dfs(i,0,grid[i][0],pacific,grid,n,m);
        dfs(i,m-1,grid[i][m-1],atlantic,grid,n,m);
    }
    vector<vector<int>>ans;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(pacific[i][j]==1 && pacific[i][j]==atlantic[i][j]){
                ans.push_back({i,j});
               
            }
        }
    }

    for(auto rows:ans){
        for(int i:rows){
            cout<<i<<" "; 
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