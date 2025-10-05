#include <iostream>
using namespace std;

//3. check if array is sorted

//start traversing from 2nd element and compare with prev element to check if order is correct
//TC-> O(n), SC-> O(1)

bool isSorted(vector<int> &arr){
    int n=arr.size();
    for(int i=1;i<n;i++){
        if(arr[i]<arr[i-1]) return false;
    }
    return true;
}

int main(){
    vector<int> arr1={2,4,6,7,8};
    vector<int> arr2={4,5,2,3,1};
    cout<<isSorted(arr1)<<endl;
    cout<<isSorted(arr2)<<endl;
    return 0;
}