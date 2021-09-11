#include <bits/stdc++.h>
#define ll long long 

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t;
    while(t--) {
        int g1, s1, b1, g2, s2, b2;
        cin>>g1>>s1>>b1>>g2>>s2>>b2;
        if(g1 + s1 + b1 > g2 + s2 + b2) {
            cout<<"1\n";
        } else {
            cout<<"2\n";
        }
    }

}