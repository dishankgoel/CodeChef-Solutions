#include <bits/stdc++.h>
#define ll long long 

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t;
    while(t--) {
        int n = 4; 
        int a[n];
        unordered_map<int, int> m;
        int uniq = 0;
        for(int i = 0; i < n; i++) {
            cin>>a[i];
            if(m.find(a[i]) == m.end()) {
                m[a[i]] = 1;
                uniq++;
            } else {
                m[a[i]]++;
            }
        }
        int ans;
        if(uniq == 1) {
            ans = 0;
        } else if(uniq == 2) {
            if(m[a[0]] == 1 || m[a[0]] == 3) {
                ans = 1;
            } else {
                ans = 2;
            }
        } else {
            ans = 2;
        }
        cout<<ans<<"\n";
    
    }

}