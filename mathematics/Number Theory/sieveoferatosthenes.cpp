#include<bits/stdc++.h>
using namespace std;

void sieveOfEratosthenes(int n){
    
    bool prime[n+1] = {false};
    for (int i = 2; i <= sqrt(n); i++){
        int j = i*i;
        if(prime[i] == false){
            int j = i*i;
            while(j <= n){
                prime[j] = true;
                j = j+i;
            }
        }
    }
    prime[0] = true;
    prime[1] = true;

    for (int i = 2; i <= n; i++){
        if (prime[i] == false){
            cout << i <<" ";
        }
    }
}
int main(){
    int n;
    cout << "Enter the range : ";
    cin>>n;
    sieveOfEratosthenes(n);
}