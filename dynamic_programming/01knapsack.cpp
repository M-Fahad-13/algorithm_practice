#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("knapsack.txt","r", stdin);
    int bag_size, number_of_items;
    cin>>bag_size>>number_of_items;
    int value[number_of_items], weight[number_of_items+1];

    for(int i = 1; i <= number_of_items;i++){
        cin>>value[i]>>weight[i];
    }
    int table[number_of_items+1][bag_size+1];
    for(int i= 0; i <= number_of_items; i++){
        for (int j= 0; j<= bag_size; j++){
            table[i][j]=0;
        }
    }

    for(int i= 1; i <= number_of_items; i++){
        for(int j= 1; j <= bag_size; j++){
            if(weight[i]>j){
                table[i][j] = table[i-1][j];
            }
            else{
                table[i][j] = max(value[i]+table[i-1][j-weight[i]], table[i-1][j]);
            }
        }
    }

    cout<<"Maximum profit : "<<table[number_of_items][bag_size]<<endl;

    return 0;
}