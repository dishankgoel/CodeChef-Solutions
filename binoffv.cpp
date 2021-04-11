#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 100001;

ll fnuminv[N+1];
ll nnuminv[N+1];
ll f[N+1];

void invnum(ll p){
    nnuminv[0] = nnuminv[1] = 1;
    for(int i=2;i<N+1;i++){
        nnuminv[i] = nnuminv[p%i]*(p - p/i)%p;
    }
}

void invfact(ll p){
    fnuminv[0] = fnuminv[1] = 1;
    for(int i=2;i<N+1;i++){
        fnuminv[i] = (nnuminv[i]*fnuminv[i-1])%p;
    } 
}

void fact(ll p){
    f[0] = 1;
    for(int i=1;i<N+1;i++){
        f[i] = (f[i-1]*i)%p;
    }
}

ll nCr(ll n, ll r, ll p){
    ll ans = ((f[n]*fnuminv[r])%p*fnuminv[n-r])%p;
    return ans;
}

int main{
    int t;scanf("%d", &t);
    while(t--){
        
    }
}