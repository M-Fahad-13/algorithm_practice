#include <bits/stdc++.h>
using namespace std;

void primeFactorization(int n){
    while (n % 2 == 0){
        cout << 2<<endl;
        n = n / 2;
    }
    for (int i = 3; i <= sqrt(n); i += 2){
        while(n % i == 0){
            cout << i << endl;
            n = n / i;
        }
    }
    if (n > 2)
    cout<<n;
}

int main(){
    int n;
    cout<<"Enter a number : ";
    cin>>n;
    primeFactorization(n);
}