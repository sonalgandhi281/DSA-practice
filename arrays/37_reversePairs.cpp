#include<iostream>
using namespace std;

//37. Reverse Pairs

//return no. of pairs such that i<j && a[i]>2&a[j]

//any left element should be greater than twice of right element, to be a valid pair.

//Brute: generate all pairs. for each element, go through all no.s on right and check condition.

//TC-> O(n^2), SC-> O(1)

int reversePairs(vector<int>&arr){
    int n=arr.size();
    int cnt=0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>2*arr[j]) cnt++;
        }
    }
    return cnt;
}

//Optimal: isme we cant just make changes in merge, kyuki jo hum 2 se multiply kr rhe h usse sorting ka logic affect ho jayega. so, we need a separate function to count pairs.

//TC-> O(2n*logn), SC-> O(n)

void merge(vector<int>&arr, int low, int mid, int high){
    int left=low, right=mid+1;
    vector<int> temp;
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }
}

//this is for finding no. of pair, each time before merging
int countPairs(vector<int>&arr, int low, int mid, int high){
    int cnt=0;
    int right=mid+1;
    for(int i=low;i<=mid;i++){
        while(right<=high && arr[i]>2*arr[right]){
            right++;
        }
        cnt+=(right-(mid+1));
    }
    return cnt;
}


int mergeSort(vector<int> &arr, int low, int high){
    int cnt=0;
    if(low>=high) return cnt;
    int mid=(low+high)/2;
    cnt+=mergeSort(arr,low,mid);
    cnt+=mergeSort(arr,mid+1,high);
    cnt+=countPairs(arr,low,mid,high);
    merge(arr,low,mid,high);
    return cnt;
}

int reversePairsOptimal(vector<int> &arr){
    int n=arr.size();
    return mergeSort(arr,0,n-1); 
}



int main(){
    vector<int> v={40,25,19,12,9,6,2};

    cout<<reversePairs(v)<<endl;
    cout<<reversePairsOptimal(v)<<endl;

    return 0;
}