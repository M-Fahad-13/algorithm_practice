#include<bits/stdc++.h>
using namespace std;
void numberofdiv(int n){
    int count = 0;
    for (int i = 1; i <= sqrt(n);i++){
        if(n % i== 0){
            if(n/i == i)
            count++;
            else
            count += 2;
        }
    }
    cout<<count ;
}
int main(){
    numberofdiv(16);
}