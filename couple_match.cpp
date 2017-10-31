#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#define maxn 10000
#define NIL -1
using namespace std;

int n;
int man_rank[maxn][maxn];
int lady_rank[maxn][maxn];
int man_choice[maxn];
int lady_choice[maxn];
int man_satisfaction[maxn];
bool single_man[maxn];

void initialize(){
    for(int i=0;i<n;++i){
        single_man[i]=true;
        man_choice[i]=NIL;
        lady_choice[i]=NIL;
        man_satisfaction[i]=0;
    }


}

int find_single_man(){
    for(int i=0;i<n;++i){
        if(single_man[i])
            return i;
    }
    return NIL;
}

void input(){
    cout<<"enter the couple numbers"<<endl;
    cin>>n;
    cout<<"enter the rank of men"<<endl;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cin>>man_rank[i][j];
        }
    }
    cout<<"enter the rank of ladies"<<endl;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cin>>lady_rank[i][j];
        }
    }
}

int get_rank(int lady,int man){
    for(int i=0;i<n;++i){
        if(lady_rank[lady][i]==man){
            return i;
        }
    }
    return NIL;
}

void match(int proposing_man){
    int best_lady = man_rank[proposing_man][man_satisfaction[proposing_man]];
    if(lady_choice[best_lady]==NIL){
        lady_choice[best_lady]=proposing_man;
        man_choice[proposing_man]=best_lady;
        single_man[proposing_man]=false;
    }
    else{
        int cur_one = get_rank(best_lady,lady_choice[best_lady]);
        int new_one = get_rank(best_lady,proposing_man);

        if(new_one<cur_one){
            single_man[lady_choice[best_lady]]=true;
            single_man[proposing_man]=false;
            man_satisfaction[lady_choice[best_lady]]++;
            man_choice[proposing_man] = best_lady;
            lady_choice[best_lady] = proposing_man;
        }
        else{
            single_man[proposing_man] = true;
            man_satisfaction[proposing_man]++;
        }
    }
}
int main(){
    input();
    initialize();
    for(int i=0;i<n;++i){
        match(i);
    }
    while(true){
        int proposing_man = find_single_man();
        if(proposing_man==-1) break;
        match(proposing_man);
    }

    for(int i=0;i<n;++i){
        cout<<"man "<<i<<" match lady "<<man_choice[i]<<endl;
    }
    return 0;
}
