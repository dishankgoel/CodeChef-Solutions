#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct indexes{
    vector<int> val;
};

int main(){
    int t;cin>>t;
    for(int i=0;i<t;i++){
        int n;cin>>n;
        vector<int> A;
        for(int a=0;a<n;a++){
            int tmp;cin>>tmp;
            A.push_back(tmp);
        }
        vector<int> pre_xor;
        pre_xor.push_back(A[0]);
        for(int a=1;a<n;a++){
            pre_xor.push_back(pre_xor[a-1]^A[a]);
        }
        int ans = 0;
        map<int, vector<int>> dp;
        for(int c=0;c<n;c++){
            if(dp.find(pre_xor[c]) != dp.end()){
                for(int d=0;d < dp[pre_xor[c]].size();d++){
                    ans += c-dp[pre_xor[c]][d]-1;
                }
            }
            if(pre_xor[c] == 0){
                ans += c;
            }
            dp[pre_xor[i]].push_back(c);
        }
        cout<<ans<<"\n";
    }
    return 0;
}