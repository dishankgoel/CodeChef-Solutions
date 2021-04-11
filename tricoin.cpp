#include<bits/stdc++.h>
using namespace std;

#define ll long long 

int main(){
    int t;cin>>t;
    while(t--){
        ll n; cin>>n;
        cout<<((int)(sqrt(8*n + 1) - 1)/2)<<"\n";
    }

}