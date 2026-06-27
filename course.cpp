#include <iostream>
#include<unordered_map>
#include<list>
#include<stack>
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

bool dfs(int node,unordered_map<int,bool>&visited,unordered_map<int,bool>&dfsvisited,unordered_map<int,list<int>>&adj){

    visited[node]=true;
    dfsvisited[node]=true;

    for(int i:adj[node]){
        if(!visited[i]){
            bool ans=dfs(i,visited,dfsvisited,adj);
            if(ans==false) return false;
        }
        else{
            if(visited[node]==true && dfsvisited[node]==true){
                cout<<node<<endl;
                return false;
            }
        }
    }
    dfsvisited[node]=false;
    return true;
}

void solve() {
    Graph g;

    int m;
    cin>>m;

    for(int i=0;i<m;++i){
        int u,v;
        cin>>u>>v;

        g.insert(u,v,true);
    }

    
        for(auto i:g.adj){
        unordered_map<int,bool>visited(false);
        unordered_map<int,bool>dfsvisited(false);
            bool ans=dfs(i.first,visited,dfsvisited,g.adj);
            if(ans==false){
                cout<<"Cycle"<<endl;
            }
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