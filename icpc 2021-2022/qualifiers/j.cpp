#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int o,i;
    scanf("%u", &o);
    unordered_map<int, int> seen;
    for(int f=0; f<o; f++){
        scanf("%u", &i);
        if(seen.find(i)!=seen.end()){
            printf("%u\n", seen[i]);
            continue;
        }
        int k=0, n=i;
        vector<int> m;
        if(i==2){
            printf("1\n");
            continue;
        }
        while(n>1 && n%2==0){
            n/=2;
            k++;
        }
        if(k){
            m.push_back(k);
        }
        for(int j=3; j<=sqrt(n); j+=2){
            k=0;
            while(n>1 && n%j==0){
                n/=j;
                k++;
            }
            if(k){
                m.push_back(k);
            }
            if(n==1){
                break;
            }
        }
        int res=1;
        if(m.size()==0){
            printf("1\n");
        }
        else{
            if(n>1){
                m.push_back(1);
            }
            for(int j:m){
                res*=(j+1);
            }
            res=res-m.size();
            printf("%u\n", res);
        }
        seen[i]=res;
    }
    return 0;
}