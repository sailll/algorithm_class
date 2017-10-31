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


int bag_bruteforce(){
    int numberofCase = int(pow(2,n));
    int maxValue = 0;
    for(int i=0;i<numberofCase;++i){
        int cur_case = i;
        int cur_weight = 0;
        int cur_value = 0;
        for(int j=0;j<n;++j){
            if(cur_case&1){
                cur_weight += weight[j];
                cur_value += value[j];
            }
            if(cur_weight>capacity) {
                break;
            }
            cur_case>>=1;
        }
        if(cur_weight<=capacity) {
            maxValue = max(maxValue, cur_value);
        }
    }
    return maxValue;
}

int main(){
    input();
    int ans = bag_bruteforce();
    cout<<"the biggest value could be carried is "<<ans<<endl;
    return 0;
}