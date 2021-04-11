#include<bits/stdc++.h>
using namespace std;

#define ll long long 


int main(){
    int t;cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        ll a[n];
        ll div_by_m = 0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i]%m == 0){
                div_by_m++;
            }
        }
        cout<<((1 << div_by_m ) - 1)<<"\n";

    }
}