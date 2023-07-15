#include<bits/stdc++.h>
using namespace std;

bool sieveOfEratosthenes(int n){
    bool prime[n+1] = {true};

    for(int i = 2; i < sqrt(n); i++){
        int j;
        if (prime[i] == true){
            j = i*i;
            while (j<=n){
                prime[j] = false;
                j = j+i;
            }
            
        }
    }
    prime[0]=false;
    prime[1]=false;
}
    

int main(){
    int n;
    cin >> n;
    bool a = sieveOfEratosthenes(n);
    
    if(a == true){
        cout << "prime";
    }

    else
        cout << "Not Prime!";
}