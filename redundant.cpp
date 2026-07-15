#include <iostream>
#include<vector>
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




void solve() {
    
        Graph g;

    int n,m;
    cin>>n>>m;

    for(int i=0;i<m;++i){
        int u,v;
        cin>>u>>v;

        g.insert(u,v,false);
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