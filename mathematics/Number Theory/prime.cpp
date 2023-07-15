#include<bits/stdc++.h>
using namespace std;

int isPrime(int n){
    if(n <= 1)
    return 0;

    for (int i = 2; i < n; i++){
        if(n % i == 0)
            return 0;
    }
    
    return 1;
}

int main(){
    int n;
    cin >> n;
    
    int returnedValue = isPrime(n);

    if(returnedValue == 1){
        cout << "The Number is Prime\n";
    }

    else
        cout << "The Number is not Prime";
    
    return 0;
}