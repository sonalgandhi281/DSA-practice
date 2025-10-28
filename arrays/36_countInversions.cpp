#include<iostream>
using namespace std;

//36. Count Inversions in an array
//given an array of integers, find no. of pairs such that 
// i<j & a[i]<a[j]
//(left element should be greater than right element)

//Brute: for each element, go across all right elements and if they can be a valid pair, cnt++

//TC-> O(n^2), SC-> O(1)

int countInversions(vector<int> &arr){
    int n=arr.size();
    int cnt=0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]) cnt++;
        }
    }
    return cnt;
}

//Optimal: i want to reduce n^2, so it can be reduced to nlogn or n

//to understand the approach, lets take another ques

//if i have 2 sorted arrays, how many pairs can i form such that left element is from left array and right element is from right array and left element > right element?

//eg
//[2,3,5,6], [2,2,4,4,8]
//valid pairs will be (3,2),(3,2),(5,2),(5,2),(5,4),(5,4),(6,2) and so on.

//this can be done optimally by taking 2 pointers, one in left array, another in right array and check if left element>right element and move pointers accordingly (similar to merge sort approach)

//note that if any element from left array can form valid pair with a specific val from right array, then all elements in left array from right of it will also form pair. (kyuki sorted h dono array)


//hum original ques ki array ko merge sort lgake split karte jayenge until we get 2 sorted arrays. fir uspe ye upr mentioned algo lgayenge. while merging, we keep counting valid pairs.

//TC-> O(nlogn), SC-> O(n)

//note: explicitly mention to interviewer that this will distort the array. if u dont want me to alter original array, i can make a copy of it.

int merge(vector<int> &arr, int low, int mid, int high){
    vector<int> temp;
    int left=low;
    int right=mid+1;

    int cnt=0;

    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            //if right val is smaller we increase cnt accordingly
            cnt+=(mid-left+1);
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

    return cnt;
}

int mergeSort(vector<int> &arr, int low, int high){
    int cnt=0;
    if(low>=high) return cnt;
    int mid=(low+high)/2;
    cnt+=mergeSort(arr,low,mid);
    cnt+=mergeSort(arr,mid+1,high);
    cnt+=merge(arr,low,mid,high);
    return cnt;
}

int countInversionsOptimal(vector<int>&arr){
    int n=arr.size();
    return mergeSort(arr,0,n-1);
}

int main(){
    vector<int> v={5,3,2,4,1};
    cout<<countInversions(v)<<endl;
    cout<<countInversionsOptimal(v)<<endl;

    return 0;
}