#include <iostream>
using namespace std;

// return maximum consecutive days for which the stock price was less than or equal to current day

//stockspanner starts the day (intitialises object)

//next function takes an int arg that represents current day, you have to return span of that day

//Brute: 
//we have a list which is dynamic in nature. each time i get next fn, i put value in list and start checking backwards.

//tc-> every next fn takes O(no. of days)
//sc-> O(total no. of next calls)

class StockSpanner{
    vector<int> arr;
    int next(int val){
        arr.push_back(val);
        int cnt=1;
        for(int i=arr.size()-2;i>=0;i--){
            if(arr[i]<=val) cnt++;
            else break;
        }
        return cnt;
    }
};

//Optimal: (current index - pge index) will give no. of consecutive days.
//we store pair of value and index in stack

//overall tc-> O(2n) where n is no. of calls
//overall sc-> O(n)

class StockSpan{
    stack<pair<int,int>> st;
    int ind=-1;
    int next(int val){
        ind++;
        while(!st.empty() && st.top().first<=val) st.pop();
        int ans=ind-(st.empty() ? -1 : st.top().second);
        st.push({val,ind});
        return ans;
    }
};
