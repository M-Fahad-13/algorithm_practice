#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(b == 0)
       return a;

    else{
        return (b, a %b);
    }
}
int main(){
    int a, b;
    cin >> a >> b;
    int s = gcd(a, b);
    cout << s << "\n";

    return 0;
}