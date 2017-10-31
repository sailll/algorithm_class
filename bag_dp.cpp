#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#define maxn 10000
using namespace std;

int n;  //the quantity of the items
int capacity;

int weight[maxn];
int value[maxn];
int dp[maxn][maxn];

void input(){
    cin>>n;
    cin>>capacity;
    for(int i=0;i<n;++i){
        cin>>weight[i]>>value[i];
    }
}

void output(){
    cout<<"n: " <<n<< " capacity: "<<capacity<<endl;
    for(int i=0;i<n;++i){
        cout<<"weight: "<<weight[i]<<" value: "<<value[i]<<endl;
    }
}


int bag_dp(){
    for(int i=0;i<=n;++i){
        for(int j=0;j<=capacity;++j){
            dp[i][j] = i==0?0:dp[i-1][j];
            if(i>0&&j>=weight[i-1]){
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-weight[i-1]]+value[i-1]);
            }
        }
    }
    return dp[n][capacity];
}

int main(){
    input();
    int ans = bag_dp();
    cout<<"the biggest value could be carried is "<<ans<<endl;
    return 0;
}