#include <iostream>
#include<list>
#include<unordered_map>
#include<algorithm>
#include<vector>
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

    bool iscycle(int node,unordered_map<int,bool>&visited,unordered_map<int,bool>&dfsvisited,unordered_map<int,list<int>>&adj){


        dfsvisited[node]=true;
        visited[node]=true;

        for(int i:adj[node]){
            if(!visited[i]){
            bool ans= iscycle(i,visited,dfsvisited,adj);
            if(ans==true) return true;
            }
            else{
                if(dfsvisited[i]){
                    return true;
                }
            }
        }

        dfsvisited[node]=false;
        return false;
    }

    void topologicalsort(unordered_map<int,bool>&visited,int node,vector<int>&ans,unordered_map<int,list<int>>&adj){

            
            
            visited[node]=true;
            

            for(auto i:adj[node]){
                if(!visited[i])
                topologicalsort(visited,i,ans,adj);
            }
            
            ans.push_back(node);


        }




void solve() {
    

     
    int n,m;
    cin>>n>>m;
    Graph g;

    for(int i=0;i<m;++i){
        int u,v;
        cin>>u>>v;
        g.insert(u,v,true);

    }
    
  
    
    unordered_map<int,bool>dfsvisited(false);
    unordered_map<int,bool>visited(false);
    bool found=false;
    for(int i=0;i<m;++i){
    
    if(!visited[i]){
     found=iscycle(i,visited,dfsvisited,g.adj);
     
     if(found){ 
        break;

    }
    }
    if(!found){
        cout<<",,"<<endl;
        vector<int>ans;
        unordered_map<int,bool>visited(false);
         
         for(int i=0;i<n;++i){

         if(!visited[i]){
        topologicalsort(visited,i,ans,g.adj);
         }
        }
        reverse(ans.begin(),ans.end());
        for(int i:ans){
            cout<<i<<" ";
        }
        cout<<endl;
         
         }
         else{
            cout<<" "<<endl;
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