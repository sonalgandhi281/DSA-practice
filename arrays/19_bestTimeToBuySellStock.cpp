#include <iostream>
using namespace std;

//19. best time to buy and sell stock: given the stock prices on n no. of days, decide when to buy and then sell to make maximum profit

//Optimal: if you are selling on ith day, you buy on the minimum price from 1st to (i-1)th day, to make max profit
//TC-> O(n), SC-> O(1)

int maxProfitOptimal(vector<int> &prices){
    int n=prices.size();
    int mini=prices[0], maxProfit=0;
    for(int i=0;i<n;i++){
        int cost=prices[i]-mini;
        maxProfit=max(maxProfit,cost);
        mini=min(mini,prices[i]);
    }
    return maxProfit;
}

int main(){
    vector<int> v={7,1,5,3,6,4};
    cout<<maxProfitOptimal(v);
    return 0;
}