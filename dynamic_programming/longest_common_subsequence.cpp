#include<bits/stdc++.h>
using namespace std;
char a[6];
int main(){
    freopen("longest_common_subsequence.txt", "r", stdin);
    int row_size;
    int column_size;
    cin>>row_size;
    cin>>column_size;
    char row[row_size];
    char column[column_size];
    for(int i = 1; i <= row_size; i++){
        cin>>row[i];
    }
    for(int i = 1; i <= column_size; i++){
        cin>>column[i];
    }
    int table[row_size+1][column_size+1];
    for(int i = 0; i <= row_size; i++){
        for(int j = 0; j <= column_size; j++){
            table[i][j]= 0;
        }
    }

    for(int i = 1; i <= row_size; i++){
        for(int j = 1; j <= column_size; j++){
            if(row[i] == column[j]){
                table[i][j] = table[i-1][j-1] + 1;
            }

            else{
                table[i][j] = max (table[i][j-1], table[i- 1][j]);
            }
            cout<<table[i][j]<<" ";
        }
        cout<<endl;
        
    }
    cout<< "Longest common subsequence is: "<<table[row_size][column_size]<<endl;
    
    
    string lcs = "";
    while(row_size != 0 || column_size != 0){
        if(table[row_size][column_size] == table [row_size][column_size-1]){
            column_size --;
        }
        else if(table[row_size][column_size] == table[row_size-1][column_size]){
            row_size --;
            
        }
        else if (table [row_size][column_size] == table[row_size-1][column_size-1]+1){
            lcs += row[row_size];
            row_size --;
            column_size --;
        }
 
    }
    reverse(lcs.begin(), lcs.end());
    cout<<lcs<<endl;
    
}