#include<bits/stdc++.h>
using namespace std;

#define ll long long 

ll bsearch(ll a[], ll to_search, ll n){
    ll b = 0, e = n-1;
    ll count =0;
    while(b<=e){
        ll mid = (b+e)/2;
        if(a[mid] <= to_search){
            count = mid+1;
            b = mid+1;
        }else{
            e = mid-1;
        }
    }
    return count;
}

int main(){
    int t; cin>>t;
    while(t--){
        ll n,l;
        cin>>n>>l;
        ll x[n];
        for(int i=0;i<n;i++){cin>>x[i];}
        sort(x, x+n);
        ll max_stars = 0, x_cord = 0;
        for(int i=0;i<n;i++){
            int ans = bsearch(x, x[i] + l, n) - i;
            if(ans >= max_stars){
                max_stars = ans;
                x_cord = x[i];
            }
        }
        cout<<max_stars<<" "<<x_cord<<"\n";
    }
}