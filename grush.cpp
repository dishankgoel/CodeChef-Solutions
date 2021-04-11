#include<bits/stdc++.h>
using namespace std;
#define ll long long 

bool compare(pair<ll, ll> p1, pair<ll,ll> p2){
    if(p1.first == p2.first){
        return (p1.second < p2.second);
    }
    return (p1.first < p2.first);
}

ll binary_search_add(ll starts[],int n, ll val){
    int left = 0;
    int right = n - 1;
    ll count = 0;
    while(left <= right){
        int mid = (right + left)/2;
        if(starts[mid] <= val){
            count = mid + 1;
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    return count;
}



int main(){
    ll m;
    cin>>m;
    ll a[m];
    for(int i=0;i<m;i++){
        cin>>a[i];
    }
    int t;cin>>t;
    while(t--){
        ll n,p;
        cin>>n>>p;
        ll starts[n];
        ll ends[n];
        for(int i=0;i<n;i++){
            ll l,r;cin>>l>>r;
            // ranges.push_back(pair<ll, ll>(l,r));
            starts[i] = l;
            ends[i] = r;
        }
        sort(starts, starts + n);
        sort(ends, ends + n);
        

    }
}