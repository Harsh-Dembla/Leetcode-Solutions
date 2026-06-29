#include <iostream>
#include<unordered_map>
#include<list>
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

void solve() {
    
    int n,m;
    cin>>n>>m;

    Graph g;
 
    for(int i=0;i<m;++i){
        int u,v;
        cin>>u>>v;
        g.insert(u,v,true);
    }


    vector<int>indegree(n+1,0);

    for(auto i:g.adj){
        for(auto j:i.second){
            indegree[j]++;
        }
    }
    for(int i=1;i<=n;++i){
        int count=0;
        for(auto j:g.adj[i]){
            count++;
        }
        if(count==0 && indegree[i]==n-1){
           cout<<i<<endl;
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