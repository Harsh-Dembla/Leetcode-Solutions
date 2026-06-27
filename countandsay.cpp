#include <iostream>
#include<string>
using namespace std;


int helper(string &s,int index,int &count,char  c){

    if(index==s.length() || s[index]!=c){
        return count;
    }

    if(s[index]==c){
        count+=1;
        s[index]='#';
    }
    return helper(s,index+1,count,c);
}

string makestring(int n,string &s,string &temp){
    if(n==1){
        return s;
    }

    for(int i=0;i<s.length();++i){
        char c=s[i];
        if(c=='#') continue;
        int count=0;
        helper(s,i,count,s[i]);
        string result=to_string(count);
        temp+=result;
        temp+=c;
        
        
        
    }
    
    s=temp;
    temp="";
   
    return makestring(n-1,s,temp);
}

void solve() {
   

    int n;
    cin>>n;
   
   string s="1",temp="";
   string ans=makestring(n,s,temp);
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