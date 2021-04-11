#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int t;cin>>t;
    ll lookup[19] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000, 100000000000, 1000000000000, 10000000000000, 100000000000000, 1000000000000000, 10000000000000000, 100000000000000000, 1000000000000000000};
    while(t--){
        int n;cin>>n;
        ll a;
        cin>>a;
        cout<<(2*lookup[n]+a)<<"\n";
        fflush(stdout);
        ll b;
        cin>>b;
        cout<<(lookup[n] -  b)<<"\n";
        fflush(stdout);
        ll d;
        cin>>d;
        cout<<(lookup[n] - d)<<"\n";
        fflush(stdout);
        int ver;
        cin>>ver;
    }
}