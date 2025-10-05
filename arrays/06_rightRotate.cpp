#include <iostream>
using namespace std;

//6.a) right rotate array by one place

//store last element in temp, shift all elements to right, put value of temp at first index
//TC-> O(n), SC-> O(1)

void rightRotate(vector<int> &arr){
    int n=arr.size();
    int temp=arr[n-1];
    for(int i=n-2;i>=0;i--){
        arr[i+1]=arr[i];
    }
    arr[0]=temp;
}

//6.b) right rotate array by k places

//Brute : k=k%n, store last k elements in temp array, shift first n-k elements right by k, put back from temp in front of array
//TC-> O(n+k), SC-> O(k)

void rightRotateByK(vector<int> &arr, int k){
    int n=arr.size();
    k=k%n;
    if(n==0) return;
    if(k>n) return;
    int temp[k];
    for(int i=n-k;i<n;i++){
        temp[i-n+k]=arr[i];
    }
    for(int i=n-k-1;i>=0;i--){
        arr[i+k]=arr[i];
    }
    for(int i=0;i<k;i++){
        arr[i]=temp[i];
    }
}

//Optimal : reverse last k elements, reverse first n-k elements, reverse entire array
//TC-> O(2n), SC-> O(1)

void rightRotateByKOptimal(vector<int> &arr, int k){
    int n=arr.size();
    reverse(arr.begin(),arr.begin()+n-k);
    reverse(arr.begin()+n-k,arr.end());
    reverse(arr.begin(),arr.end());
}

int main(){
    vector<int> arr1={1,2,3,4,5};
    vector<int> arr2={1,2,3,4,5};
    vector<int> arr3={1,2,3,4,5};

    cout<<"right shift by 1: "<<endl;
    rightRotate(arr1);
    for(int x:arr1) cout<<x<<" ";
    cout<<endl;

    cout<<"right shift by k: "<<endl;
    rightRotateByK(arr2,2);
    for(int x:arr2) cout<<x<<" ";
    cout<<endl;

    cout<<"right shift by k optimal: "<<endl;
    rightRotateByKOptimal(arr3,2);
    for(int x:arr3) cout<<x<<" ";
    cout<<endl;

    return 0;
}