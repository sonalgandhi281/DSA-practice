#include <iostream>
using namespace std;

//8. linear search
//TC-> O(n), SC-> O(1)

int linearSearch(vector<int>&arr, int target){
    int n=arr.size();
    for(int i=0;i<n;i++){
        if(arr[i]==target){
            return i;
        }
    }
    return -1;
}

int main(){
    vector<int> arr1={1,2,5,3,7,4};
    cout<<linearSearch(arr1,5)<<endl;
    cout<<linearSearch(arr1,12);
    return 0;
}