#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

void solve() {
    
    int n;
    cin>>n;

    vector<int>height(n);

    for(int i=0;i<n;++i){
        cin>>height[i];
    }
    

    int left=0,right=height.size()-1,maxl=height[left],maxr=height[right],ans=0;

    while(left<right){
        if(maxl<=maxr){

            left++;
            maxl=max(maxl,height[left]);
            ans+=maxl-height[left];
        }
        else{
            right--;
            maxr=max(maxr,height[right]);
            ans+=maxr-height[right];
        }
    }

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