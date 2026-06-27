#include <iostream>
#include<vector>
using namespace std;

void solve() {
    int size;
    cin>>size;
    vector<int>nums(size);
    for(int i=0;i<size;++i){
        cin>>nums[i];
    }
    vector<vector<int>>ans;

    for(int i=0;i<nums.size();++i){
        if(i>0 && nums[i]==nums[i-1]) continue;

        
            int j=i+1,k=nums.size()-1;
            while(j<k){

                if(nums[j]+nums[k]==(-nums[i])){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                }
                else if(nums[j]+nums[k]<(-nums[i])){
                    ++j;
                }
                else{
                    --k;
                }
            }
            
            

        
    }

   for(const auto& row : ans) {
    for(int x : row) {
        cout << x << " ";
    }
    cout << endl;
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