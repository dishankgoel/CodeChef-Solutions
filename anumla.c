#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int compare(const void * a, const void * b){
    return (*(int*)a - *(int*)b);
}

bool check_subset(int* arr, int t, int s){
    bool dp[s+1][t+1];
    for(int i=1;i<=t;i++){
        dp[0][i] = false;
    }
    for(int i=0;i<=s;i++){
        dp[i][0] = true;
    }
    for(int i=1;i<=s;i++){
        for(int j=1;j<=t;j++){
            if( j < arr[i-1]){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = ((dp[i-1][j-arr[i-1]]) || (dp[i-1][j]));
            }
        }
    }
    return dp[s][t];
}

int main(){
    int t;scanf("%d", &t);
    for(int i=0;i<t;i++){
        int n;scanf("%d", &n);
        long ex = pow(2,n);
        int a[(int)ex];
        for(int i=0;i<ex;i++){
            scanf("%d", &a[i]);
        }
        qsort(a, ex, sizeof(int), compare);
        int* ans = (int*)malloc(n*sizeof(int));
        ans[0] = a[1];
        ans[1] = a[2];
        int s=2;
        for(int i=3;i<(int)ex;i++){
            if(s==n){
                break;
            }
            if(a[i] == a[i-1]){
                ans[s] = a[i]; 
                s++;
            }
            if(!check_subset(ans, a[i], s)){
                ans[s] = a[i];
                s++;
            }
        }
        for(int i=0;i<n;i++){
            printf("%d ",ans[i]);
        }
        printf("\n");

    }

}