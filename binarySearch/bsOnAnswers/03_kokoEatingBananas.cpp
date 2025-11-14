#include <iostream>
using namespace std;

//3. Koko Eating Bananas

// given n piles of bananas, where ith pile has a[i] bananas, and given "h" time in hrs for all bananas to be eaten
// find "k" where k is minimum no. of bananas that can be eaten each hour so that koko eats all bananas within h time

//Brute: k ki value can range from 1 to max element of array. bcz he can eat from 1 banana/hr to max bananas pile / hr.
//so, for each element in this range, we calc hours taken to eat all bananas and when it exceeds h, we break and return prev value.

// O(n + n*max(arr))

int minBanana(vector<int> &arr, int h){
    int n=arr.size();
    int maxPile=arr[0];
    for(int i=0;i<n;i++){
        maxPile=max(maxPile,arr[i]);
    }
    for(int i=1;i<=maxPile;i++){
        int hours=0;
        for(int j=0;j<n;j++){
            hours+=(arr[j]/i)+(arr[j]%i==0 ? 0 : 1);
        }
        if(hours<=h){
            return i;
        }
    }
    return maxPile;
}

//Optimal
//note: jab bhi aisa pattern dikhe ki min ya max cheez nikalni hai aur ans ek certain value tak possible hai aur fir possible nahi hai, we can apply binary search
//tc-> O(n + nlog(max(arr)))

int calcHours(vector<int> &arr, int mid){
    int hours=0;
    int n=arr.size();
    for(int i=0;i<n;i++){
        hours+= (arr[i]/mid)+(arr[i]%mid==0 ? 0 : 1);
        //hours+= ceil((double)arr[i]/(double)mid); aise bhi kr skte
    }
    return hours;
}

int minBananaOptimal(vector<int> &arr, int h){
    int n=arr.size();
    int maxPile=arr[0];
    for(int i=0;i<n;i++){
        maxPile=max(maxPile,arr[i]);
    }
    int ans=maxPile;
    int low=1, high=maxPile;
    while(low<=high){
        int mid=(low+high)/2;
        int tothours=calcHours(arr,mid);
        if(tothours<=h){
            ans=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return ans;
}

//note: yaha pe when we started low pointed to a not possible ans and high pointed to a possible ans.
//after binary search, when low and high cross, they end up on opposite polarities, with low pointing to possible and high to not possible.
//so, we actually dont need ans variable, we can just return low.

int main(){
    vector<int> v={7,15,6,3};
    int h=8;
    cout<<minBanana(v,h)<<endl;
    cout<<minBananaOptimal(v,h);
    return 0;
}