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


int height(int &ans,vector<int>&visited,unordered_map<int,list<int>>&adj,int node,int val){
    visited[node]=1;
   

    for(int i:adj[node]){
        if(!visited[i])
        ans=max(ans,height(ans,visited,adj,i,val+1));
    }

    return val;

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


    queue<int>q;

    vector<int>indegree(n,0);

    for(int i=0;i<n;++i){
        for(int j:g.adj[i]){
            indegree[j]++;
        }
    
    }
    int remaining=0,count=0;
    vector<int>ans(2);
    for(int i=0;i<n;++i){
        if(indegree[i]==1) {
            q.push(i);
           

        }
    }

    
    remaining=n;
  
    
    while(remaining>2){


        remaining-=q.size();
        int size=q.size();
        

        while(size>0){
            int front=q.front();
            q.pop();
            size--;
        for(int neigh:g.adj[front]){
            indegree[neigh]--;
            if(indegree[neigh]==1){
                q.push(neigh);
            }
        }
    }

        
         
      
    }


    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
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