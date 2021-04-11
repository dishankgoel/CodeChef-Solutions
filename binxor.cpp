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

int main(){
    ll p = 1000000007;
    invnum(p);
    invfact(p);
    fact(p);
    int t;
    scanf("%d", &t);
    while(t--){
        int n;scanf("%d", &n);
        string A,B;
        cin>>A>>B;
        int x1=0,x2=0;
        for(int i=0;i<n;i++){
            if(A[i] == '1'){x1++;}
            if(B[i] == '1'){x2++;}
        }
        ll ans = 0;
        if(x2 > x1){int tmp = x1; x1 = x2; x2 = tmp;}
        ll curr = x1-x2;
        ans = nCr(n, curr, p);
        for(int i = 0 ; i < min(x2, n-x1); i++){
            curr += 2;
            ans = (ans%p + nCr(n,curr, p))%p;
        }
        cout<<ans<<"\n";

    }
}