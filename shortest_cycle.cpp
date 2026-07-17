#include <iostream>
#include<unordered_map>
#include<list>
#include<queue>
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

void bfs(unordered_map<int,list<int>>&adj,int node,int &ans,int n,vector<int>&dis){

    queue<int>q;

    unordered_map<int,int>parent;
    parent[node]=-1;

    vector<int>visited(n,0);
    visited[node]=1;
    dis[node]=0;
    q.push(node);
    
    
    while(!q.empty()){

        int front=q.front();
        q.pop();


        for(auto neigh:adj[front]){
            if(dis[neigh]==-1){
                q.push(neigh);
                dis[neigh]=dis[front]+1;
                
                parent[neigh]=front;
            }
            else if(parent[front]!=neigh && dis[neigh]>=dis[front]){
                ans=min(ans,dis[neigh]+dis[front]+1);
            }
        }
    }
  
    

}




void solve() {
    Graph g;

    int n,m;
    cin>>n>>m;

    for(int i=0;i<m;++i){
        int u,v;
        cin>>u>>v;

        g.insert(u,v,false);
    }

    
    int ans=INT_MAX;
    for(int i=0;i<n;++i){
        vector<int>dis(n,-1);

     bfs(g.adj,i,ans,n,dis);
    }
    cout<<ans<<endl;



}


    int main(){

        int i=1,t=0;
        cin>>t;

        while(t--){

            cout<<"Case #"<<i<<endl;
            solve();
            cout<<endl;
            ++i;
        }

    }