#include <iostream>
using namespace std;

//5.a) left rotate array by one place

//store first element in temp, shift all elements to left, put value of temp at last index
//TC-> O(n), SC-> O(1)

void leftRotate(vector<int> &arr){
    int n=arr.size();
    int temp=arr[0];
    for(int i=1;i<n;i++){
        arr[i-1]=arr[i];
    }
    arr[n-1]=temp;
}

//5. b) left rotate array by k places

//Brute : k=k%n, store k elements in temp array, shift all elements left by k, put back elements from temp
//TC-> O(k+n), SC-> O(k)

void leftRotateByK(vector<int> &arr, int k){
    int n=arr.size();
    if(n==0) return;
    k=k%n;
    if(k>n) return;
    int temp[k];
    for(int i=0;i<k;i++){
        temp[i]=arr[i];
    }
    for(int i=k;i<n;i++){
        arr[i-k]=arr[i];
    }
    int index=0;
    for(int i=n-k;i<n;i++){
        arr[i]=temp[index++];
    }
}

//Optimal : reverse first k elements, reverse last n-k elements, reverse entire array
//TC-> O(2n), SC-> O(1)

void leftRotateByKOptimal(vector<int> &arr, int k){
    int n=arr.size();
    reverse(arr.begin(),arr.begin()+k);
    reverse(arr.begin()+k,arr.end());
    reverse(arr.begin(),arr.end());
}

int main(){
    vector<int> arr1={1,2,3,4,5};
    vector<int> arr2={1,2,3,4,5};
    vector<int> arr3={1,2,3,4,5};

    cout<<"left shift by 1: "<<endl;
    leftRotate(arr1);
    for(int x:arr1) cout<<x<<" ";
    cout<<endl;

    cout<<"left shift by k: "<<endl;
    leftRotateByK(arr2,2);
    for(int x:arr2) cout<<x<<" ";
    cout<<endl;

    cout<<"left shift by k optimal: "<<endl;
    leftRotateByK(arr3,2);
    for(int x:arr3) cout<<x<<" ";
    cout<<endl;

    return 0;
}
