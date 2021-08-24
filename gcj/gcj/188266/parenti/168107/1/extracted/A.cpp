#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <cmath>
#include <queue>
#include <stack>
#include <bitset>
#include <cassert>
#include <sstream>

using namespace std;

vector<int> bases;
set<int> limits[11];
vector<int>::iterator it;
int caso = 1;
char numbers[1500];
int read(){
    bases.clear();
    gets(numbers);
    istringstream is(numbers);
    int num;
    while(is >> num){
        bases.push_back(num);
    }
    return 1;
}
void pre(){
    set<int> marked;
    for(int j = 2; j <= 10; j++){
        fprintf(stderr, "%d\n", j);
        
        for(int i = 2; i <= 100000; i++){
            marked.clear();
            int tt = i;
            int nb = 0;
            int tt2;
            do{
                nb = 0;
                tt2 = tt;
                while(tt2){
                    nb += (tt2%j)*(tt2%j);
                    tt2 /= j;
                }
                
                if(marked.find(nb) != marked.end())break;
                else marked.insert(nb);
                if(limits[j].find(nb) != limits[j].end()){
                    tt = 1;
                }else tt = nb;
            }while(tt-1);
            if(tt == 1){
                limits[j].insert(i);
            }
        }
        /*for(set<int>::iterator it = limits[j].begin(); it != limits[j].end(); it++){
            printf("&& %d\n", *it);
        }
        printf("\n");*/
    }
}
void process(){
    set<int> answ(limits[bases[0]].begin(), limits[bases[0]].end());
    vector<int> toRemove;
    for(int i = 1; i < bases.size(); i++){
        toRemove.clear();
        set<int>::iterator itS;
        for(itS = answ.begin(); itS != answ.end(); itS++){
            if(limits[bases[i]].find(*itS) == limits[bases[i]].end()){
                toRemove.push_back(*itS);
            }
        }
        for(int k = 0; k < toRemove.size(); k++){
            //printf("&& %d\n", toRemove[k]);
            answ.erase(answ.find(toRemove[k]));
        }
    }
    printf("Case #%d: %d\n", caso++, *(answ.begin()));
}
int main(){
    freopen("big-A.out", "w", stdout);
    pre();
    int casos;
    scanf("%d\n", &casos);
    while(casos-- && read())process();
    return 0;
}
