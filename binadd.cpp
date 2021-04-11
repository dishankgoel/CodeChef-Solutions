#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;scanf("%d", &t);
    while(t--){
        string a,b;
        cin>>a>>b;
        int ans = 0;
        if(b != "0"){
            int n1 = a.length();
            int n2 = b.length();
            if(n1 > n2){
                string to_append(n1-n2, '0');
                b = to_append + b;
            }else if(n2 > n1){
                string to_append(n2-n1, '0');
                a = to_append + a;
            }
            int n = max(n1,n2);
            int ans = 0;
            int curr = 0;int carry_on = 0;
            for(int i=n-1;i>-1;i--){
                if((a[i] == '1' && b[i] == '1' && carry_on == 1) || (a[i] == '0' && b[i] == '0' && carry_on == 1) ){
                    carry_on = 0;
                    ans = max(ans, curr);
                    curr = 0;
                }else if( (a[i] == '1' && b[i] == '0' && carry_on == 1) || (a[i] == '0' && b[i] == '1' && carry_on == 1) ){
                    curr++;
                }
                if(a[i] == '1' && b[i] == '1' && carry_on == 0){
                    carry_on = 1;curr++;
                }
            }
            ans = max(ans, curr);
            cout<<ans+1<<"\n";
        }else{
            cout<<"0"<<"\n";
        }
    }
}