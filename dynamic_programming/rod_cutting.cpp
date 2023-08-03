#include<bits/stdc++.h>
using namespace std;

int main(){

    freopen("rod_cutting.txt", "r",stdin);
    int rod_size;
    cin>>rod_size;
    int size[rod_size+1];
    int value[rod_size+1];

    for (int i; i <= rod_size; i++){
        cin>>size[i]>>value[i];
    }
    int table[rod_size+1][rod_size+1];

    for(int i= 0; i <= rod_size; i++){
        for (int j= 0; j<= rod_size; j++){
            table[i][j]=0;
        }
        cout<<endl;
    }

    for(int i= 1; i <= rod_size; i++){
        for(int j= 1; j <= rod_size; j++){
            if(size[i]>j){
                table[i][j] = table[i-1][j];
            }
            else{
                table[i][j] = max(value[i]+table[i-1][j-size[i]], table[i-1][j]);
            }
        }
    }

    cout<<"Maximum value : "<<table[rod_size][rod_size];
}