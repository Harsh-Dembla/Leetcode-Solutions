#include <iostream>
#include <iostream>
#include<list>
#include<unordered_map>
#include<queue>
#include<vector>
#include<algorithm>
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


void dfs(unordered_map<int,list<int>>&adj,int node,vector<int>&visited,int &m,int &edges){

    visited[node]=1;
    m++;
    for(int i:adj[node]){
        if(!visited[i]){
            dfs(adj,i,visited,m,edges);

        }
        cout<<"Parent: "<<node<<" "<<"Child: "<<i<<endl;
        edges++;
    }
}


void solve() {
     
    int n,m;
    cin>>n>>m;
    Graph g;

    for(int i=0;i<m;++i){
        int u,v;
        cin>>u>>v;
        g.insert(u,v,false);

    }
    int degree=0;
   

    vector<int>visited(n,0);
    int ans=0;
    for(int i=0;i<n;++i){
        int m=0,edges=0;
        if(!visited[i]){

          dfs(g.adj,i,visited,m,edges);
          edges/=2;
            if(edges==((m*(m-1)))/2){
                ans++;
            }
         
        }
    }   

    cout<<ans<<endl;




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