#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>

#define maxn 10000
using namespace std;

int n;
int budget;

int price[maxn];
int repulsive[maxn][maxn];
int bought[maxn];
void input(){
    cin>>budget;
    cin>>n;
    for(int i=0;i<n;++i){
        int id;
        cin>>id>>price[i];
    }
    while(true){
        int f1,f2;
        cin>>f1>>f2;
        if(f1==0&&f2==0) break;
        repulsive[f1][f2]=1;
        repulsive[f2][f1]=1;
    }
}

bool conflict(int *bought,int cur_fish){
    for(int i=0;i<n;++i){
        if(repulsive[cur_fish][bought[i]]) return true;
    }
    return false;
}
void buy_fish(int i,int money_left){
    if(i>n){
        return ;
    }
    bought[i] = 0;
    buy_fish(i+1,money_left);
    if(!conflict(bought,i)&&money_left>price[i]){
        bought[i]=1;
        buy_fish(i+1,money_left-price[i]);
    }
}
int main(){
    memset(repulsive,0,sizeof(repulsive));
    input();
    buy_fish(0,budget);
    for(int i=0;i<n;++i){
        cout<<bought[i]<<" ";
    }
    cout<<endl;
    return 0;
}


