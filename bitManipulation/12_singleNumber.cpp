#include <iostream>
#include <map>
using namespace std;

//12. given an array in which every number except one appears twice, find the single element

//Brute: store occurrences of every element in a map and traverse the map to find element that appears once
//tc-> O(nlogm + m) where m is size of map and m=n/2+1, sc-> O(m)=O(n/2+1)

int singleNum(vector<int> &arr){
    int n=arr.size();
    map<int,int> mpp;
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
    }
    for(auto it:mpp){
        if(it.second==1) return it.first;
    }
    return -1;//dummy
}

//Optimal: take xor of entire array
//tc-> O(n), sc-> O(1)

int singleNumOptimal(vector<int> &arr){
    int n=arr.size();
    int XOR=0;
    for(int i=0;i<n;i++){
        XOR^=arr[i];
    }
    return XOR;
}

int main(){
    vector<int> v={1,1,2,3,2,4,4};
    cout<<singleNum(v)<<endl;
    cout<<singleNumOptimal(v)<<endl;
    return 0;
}