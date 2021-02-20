// Example program
#include<bits/stdc++.h>
using namespace std;


int coinChanging(vector<int> coins, int sum){
    
    int coin_size = coins.size();
    int T[coin_size][sum+1];
    for (int i = 0; i < coin_size; i++) {
            T[i][0] = 1;
	}
    
    for (int j = 1; j <=sum; j++){
            T[0][j] = j%coins[0] == 0? 1 : 0;
    }
    
    for (int i = 1; i < coin_size;  i++) {
        for (int j = 1; j <=sum; j++) {
            if (coins[i] <= j)
                T[i][j] = T[i-1][j]+ T[i][j-coins[i]];
            else
                T[i][j] = T[i-1][j];
        }
    }
    for (int i = 0; i < coin_size; i++) {
        for (int j = 0; j <=sum; j++) {
            cout << T[i][j] << " ";
        }
    cout << endl;    
    }
    return T[coin_size-1][sum];
}

int main() 
{ 
    vector<int> coins = {1, 2 ,3};
    int sum = 5;
    int ans = coinChanging(coins, sum);
    cout <<ans<< endl;
	return 0; 
} 
