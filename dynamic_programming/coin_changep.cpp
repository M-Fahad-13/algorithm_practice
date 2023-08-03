#include<bits/stdc++.h>
using namespace std;

int main(){
    
    freopen("coinchange.txt", "r", stdin);
    int number_of_coin;
    int amount;
    cin>>amount>>number_of_coin;
    int value[number_of_coin];
    for(int i = 1; i <= number_of_coin; i++){
        cin>>value[i];
    
    }
    int table[number_of_coin + 1] [amount + 1];
    for(int i = 0; i <= amount; i++){
         table[0][i] = INT_MAX;
    }
    for(int i = 1; i <= number_of_coin; i++){
        table[i][0] = 0;
    }
    
    for(int i = 1; i <= number_of_coin; i++){
        for(int j = 1; j <= amount; j++){
            if(value[i] > j){
                table[i][j] = table[i-1][j];
            }

            else{          
                table[i][j] = min(1 + table[i][j - value[i]], table[i-1][j]);
            }
        }
    }
    
    cout<<"Minimum number of coin needed: "<<table[number_of_coin][amount]<<endl;
       
    while(table[number_of_coin][amount] == table[number_of_coin - 1][amount]){
        number_of_coin--;
    }
    cout<<value[number_of_coin]<<endl;
    cout<<amount - value[number_of_coin]<<endl;
    return 0;

}