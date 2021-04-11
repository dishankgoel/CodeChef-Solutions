#include<bits/stdc++.h>
using namespace std;

void lps(int* lps_arr, string str, int n){
    int j=1,i=0;
    while(j < n){
        if(str[i] == str[j]){
            lps_arr[j] = i+1;
            j++;
            i++;
        }else{
            if(i==0){
                lps_arr[j] = 0;
                j++;
            }else{
                i = lps_arr[i-1];
            }
        }
    }
}

int kmp(int* lps, string str, string m_troop, int n, int k){
    int ans = 0;
    int i=0,j=0;
    while(i < n){
        if(str[i] == m_troop[j]){
            i++;
            j++;
        }
        if(j == k){
            ans+=1;
            j = lps[j-1];
        }else{
            if((i < n)&&(str[i]!=m_troop[j])){
                if(j!=0){
                    j = lps[j-1];
                }else{
                    i++;
                }
            }
        }

    }
    return ans;
}

int main(){
    int t;cin>>t;
    for(int i=0;i<t;i++){
        int n,m,k;
        cin>>n>>m>>k;
        string sn, sm;
        cin>>sn;
        cin>>sm;
        string m_troops = sm.substr(0,k);
        int lps_arr[k];
        lps_arr[0] = 0;
        lps(lps_arr, m_troops, k);
        int a = kmp(lps_arr, sn, m_troops, n, k);
        if(a==0){
            cout<<-1<<"\n";
        }else{
            cout<<a<<"\n";
        }

    }
}