#include <iostream>
#include<list>
#include<unordered_map>
#include<vector>
#include<utility>
#include<set>
using namespace std;

class Graph{

    public:
    unordered_map<int,list<pair<int,int>>>adj;


    void insert(int u,int v,int distance){

        adj[u].push_back({v,distance});
         adj[v].push_back({u,distance});
       

    }
};


void dfs(unordered_map<int,list<pair<int,int>>>&adj,unordered_map<int,bool>&visited,int node,int &min){

    visited[node]=true;
    for(auto i:adj[node]){
        if(i.second<min) min=i.second;
        if(!visited[i.first]){
        
        dfs(adj,visited,i.first,min);
    }
    }   
}



void solve() {
    

    int n,m;
    cin>>n>>m;


    Graph g;
    for(int i=0;i<m;++i){
        int u,v,weight;
        cin>>u>>v>>weight;

        g.insert(u,v,weight);
    }



    int min=INT_MAX;
    unordered_map<int,bool>visited;
    dfs(g.adj,visited,1,min);
    cout<<min<<endl;

    
    
    







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