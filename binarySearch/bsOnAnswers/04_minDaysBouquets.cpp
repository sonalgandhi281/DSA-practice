#include<iostream>
using namespace std;

//4. find the minimum no. of days to make m bouquets.

//given an array of n roses, where ith rose blooms on a[i]th day, and given integers m and k where k is no. of roses in each bouquet and you have to make atleast m such bouquets.
//bouqets can be made from adjacent roses that have bloomed

//Brute:
//min days is smallest element of array and max days is largest element of array. this will be range in which ans is there.
//for each day, we calculate no. of bouquets we can make.

//O(n*(max(arr)-min(arr)+1))

int calcBouquets(vector<int> &arr, int day, int k){
    int cnt=0;
    int bouqNo=0;
    int n=arr.size();
    for(int i=0;i<n;i++){
        if(arr[i]<=day) cnt++;
        else{
            bouqNo+=cnt/k;
            cnt=0;
        }
    }
    bouqNo+=(cnt/k);
    return bouqNo;
}

int minDays(vector<int>&arr, int m, int k){
    int n=arr.size();
    if(m*k>n) return -1;
    int minDay=*min_element(arr.begin(),arr.end());
    int maxDay=*max_element(arr.begin(),arr.end());
    int ans=maxDay;
    for(int i=minDay;i<=maxDay;i++){
        int bouq=calcBouquets(arr,i,k);
        if(bouq>=m){
            ans=i;
            break;
        }
    }
    return ans;
}

//Optimal: binary search
//O(n * log(max(arr)-min(arr)+1))

int minDaysOptimal(vector<int> &arr, int m, int k){
    int n=arr.size();
    if(m*k>n) return -1;
    int minDay=*min_element(arr.begin(),arr.end());
    int maxDay=*max_element(arr.begin(),arr.end());
    int ans=maxDay;
    int low=minDay, high=maxDay;
    while(low<=high){
        int mid=(low+high)/2;
        int bouq=calcBouquets(arr,mid,k);
        if(bouq>=m){
            ans=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return ans; //or just return low
}

int main(){
    vector<int> v={7,7,7,7,13,11,12,7};
    int m=2, k=3;
    cout<<minDays(v,m,k)<<endl;
    cout<<minDaysOptimal(v,m,k);
    return 0;
}