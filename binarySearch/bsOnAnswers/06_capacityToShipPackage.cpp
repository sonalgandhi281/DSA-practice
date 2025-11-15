#include <iostream>
using namespace std;

//6. capacity to ship packages within d days

//given an array of weights that will be loaded onto conveyer belt in this order only, and given d days
//find least weighted capacity so that i can ship all packages within d days

//eg

//[5,4,5,2,3,4,5,6] , d=5
//ans=9

//Brute:
//search range will be from max element of array to sum of all elements of array
//O(n * (sumOfElements(arr) - maxElement(arr) + 1))

int calcDays(vector<int> &arr, int cap){
    int wt=0;
    int days=1;
    int n=arr.size();
    for(int i=0;i<n;i++){
        if((wt+arr[i])>cap){
            wt=0;
            days++;
        }
        wt+=arr[i];
    }
    return days;
}

int capacity(vector<int> &arr, int d){
    int n=arr.size();
    int maxi=*max_element(arr.begin(),arr.end());
    int sum=0;
    for(int x:arr) sum+=x;
    //int sum = accumulate(arr.begin(), arr.end(), 0); or by this
    for(int i=maxi;i<=sum;i++){
        int days=calcDays(arr,i);
        if(days<=d) return i;
    }
    return -1; //dummy return
}

//Optimal: binary search from max element to sum of all elements

//O(n * log(sum(arr)-max(arr)+1))

int capacityOptimal(vector<int> &arr, int d){
    int low=*max_element(arr.begin(),arr.end());
    int sum=0;
    for(int x:arr) sum+=x;
    int high=sum;
    while(low<=high){
        int mid=(low+high)/2;
        int days=calcDays(arr,mid);
        if(days<=d){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return low;
}

int main(){
    vector<int> v={5,4,5,2,3,4,5,6};
    int d=5;
    cout<<capacity(v,d)<<endl;
    cout<<capacityOptimal(v,d)<<endl;
    return 0;
}