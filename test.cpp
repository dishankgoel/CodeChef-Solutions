#include<bits/stdc++.h>
using namespace std;


int UpperBound(int A[],int N,int K){
    int low , high , mid ;
    low = 1 ;
    high = N ;
    while(low <= high){
        mid = ( low + high ) / 2 ; // finding middle element 
        if(A[mid] > K && ( mid == 1 || A[mid-1] <= K )) // checking conditions for upperbound
            return mid ;
        else if(A[mid] > K) // answer should be in left part 
            high = mid - 1 ;
        else                // answer should in right part if it exists
            low = mid + 1 ;
    }
    return mid ; // this will execute when there is no element in the given array which > K
}

int LowerBound(int A[],int N,int K){
    int low , high , mid ;
    low = 1 ;
    high = N ;
    while(low <= high){
        mid = ( low + high ) / 2 ; // finding middle element 
        if(A[mid] >= K && ( mid == 1 || A[mid-1] < K )) // checking conditions for lowerbound
            return mid ;
        else if(A[mid] >= K) // answer should be in left part 
            high = mid - 1 ;
        else                // answer should in right part if it exists
            low = mid + 1 ;
    }
    return mid ; // this will execute when there is no element in the given array which >= K
}


int main(){
    int a[] = {2,2,2,2,2,3,3,3,4,5,5,5};
    int n = sizeof(a)/sizeof(int);
    float t;cin>>t;
    // cout<<LowerBound(a,n,10)<<endl;
    // cout<<UpperBound(a,n,10)<<endl;
    cout<<lower_bound(a, a+n, t) - a;


return 0;
}


