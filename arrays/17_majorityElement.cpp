#include <iostream>
#include <map>
using namespace std;

//17. given an array return the majority element (should occur > n/2 times)

//Brute: keep track of count of each element and if its >n/2 return that element
//TC-> O(n^2), SC-> O(1)

int majorityElement(vector<int> &arr){
    int n=arr.size();
    for(int i=0;i<n;i++){
        int count=0;
        for(int j=0;j<n;j++){
            if(arr[i]==arr[j]) count++;
        }
        if(count>n/2) return arr[i];
    }
    return -1; //wont run if correct inputs given
}

//Better: Hashing. use hashmap <element, count> to keep track of count of each element. then iterate through hashmap to find count>n/2.
//TC-> O(nlogn+n), SC-> O(n)

int majorityElementBetter(vector<int> &arr){
    int n=arr.size();
    map<int,int> mpp;
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
    }
    for(auto it: mpp){
        if(it.second>n/2) return it.first;
    }
    return -1;
}

//Optimal: Moore's Voting Algorithm

//based on the fact that up till a certain point in the array, majority and minority element count will remain same & they will cancel each other out. and then, in the end, majority element remains.

//we apply moore's voting algo, then we verify if element is majority.
//TC-> O(n+n(if verifying)), SC-> O(1)

int majorityElementOptimal(vector<int> &arr){
    int n=arr.size();
    int count=0;
    int element;
    for(int i=0;i<n;i++){
        if(count==0){
            count=1;
            element=arr[i];
        }
        else if(arr[i]==element){
            count++;
        }else{
            count--;
        }
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        if(arr[i]==element) cnt++;
    }
    if(cnt>n/2) return element;
    return -1;
}

int main(){
    vector<int> a={2,2,3,1,1,2,2,3,2,2};
    cout<<majorityElement(a)<<endl;
    cout<<majorityElementBetter(a)<<endl;
    cout<<majorityElementOptimal(a)<<endl;
    return 0;
}