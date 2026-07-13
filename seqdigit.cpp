#include <iostream>
#include<unordered_map>
#include<bits/stdc++.h>
using namespace std;

int digit(int n){

   int count=0;
   while(n>0){
    n/=10;
    count++;
   }
   return count;

}


void fun(int &n,int sum,unordered_map<int,long long int>&map,int &count,vector<int>&ans,int &low,int &high){


    if(count==9){
        return;
    }
    if(n%10==0){

     n-=sum;
     sum*=10;
     sum+=1;
     count+=1;
     n=map[count];
    }
    if(n>=low && n<=high) ans.push_back(n);
    
    n+=sum;

    fun(n,sum,map,count,ans,low,high);
   

}

void solve() {
    int low,high;
    cin>>low>>high;


    int n=12;

    unordered_map<int,long long int>map;
    map[2]=12;
    map[3]=123;
    map[4]=1234;
    map[5]=12345;
    map[6]=123456;
    map[7]=1234567;
    map[8]=12345678;
    map[9]=123456789;

    int sum=11,count=2;
    vector<int>ans;
    fun(n,sum,map,count,ans,low,high);


    for(int i:ans){
        cout<<i<<" ";
    }
    cout<<endl;

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