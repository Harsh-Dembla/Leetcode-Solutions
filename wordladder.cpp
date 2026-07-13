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


class Graph{

    public:
    unordered_map<string,list<string>>adj;


    void insert(string u,string v,bool direction){

        adj[u].push_back(v);
        if(!direction){
            adj[v].push_back(u);
        }

    }

    void print(){

        for(auto i:adj){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<j<<",";
            }
            cout<<endl;
        }
    }

};

int bfs(unordered_map<string,list<string>>&adj,string &beginword,string &endword){

    unordered_map<string,bool>visited;

    queue<string>q;
    unordered_map<string,string>came_from;
    came_from[beginword]=" ";

    visited[beginword]=true;
    q.push(beginword);
    cout<<beginword<<" "<<endword<<endl;
    while(!q.empty()){
        
        string front=q.front();
        q.pop();
        cout<<front<<endl;

        if(front==endword){
            int count=0;
            string node=endword;
            while(node!=" "){
                count++;
                node=came_from[node];
            }
            cout<<"Worked"<<endl;
            
            return count;
        }


        for(auto neigh:adj[front]){
            if(!visited[neigh]){
                q.push(neigh);
                visited[neigh]=true;
                came_from[neigh]=front;
            }
        }
    }
    return 0;
}

void solve() {
    string beginword,endword;
    cin>>beginword;
    cin>>endword;


    int n;
    cin>>n;
    vector<string>wordlist(n,"");

    for(int i=0;i<n;++i){

        cin>>wordlist[i];
    }
    cout<<"-----------Words--------"<<endl;
    for(string s:wordlist){
        cout<<s<<" ";
    }
    cout<<endl<<endl;


    

    string temp=beginword;
    Graph g;
    for(int i=0;i<n;++i){
      
        
        for(int j=i;j<n;++j){
              int count=0;
            if(temp==wordlist[j]) continue;
            for(int k=0;k<temp.length();++k){
                if(temp[k]!=wordlist[j][k]) count++;
                if(count>1) break;
            }
            if(count==1) g.insert(temp,wordlist[j],false);
            
        }
        temp=wordlist[i];
      
    }
    cout<<"-------------"<<endl;
    g.print();
    cout<<"----------"<<endl;

    int count=bfs(g.adj,beginword,endword);
    cout<<count<<endl;

  


}
int main(){

     int t, i = 1;
    cin >> t;
    while(t--) {
        cout << "Case #" << i << ": ";
        solve();
        ++i;
    }
    return 0;
}