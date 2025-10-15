#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

//13. find the number that appears once in an array, when all other no.s appear twice

//Brute: pick up every no. one by one and count its occurences (by nested loops), return the element with occurence 1.
//TC-> O(n^2), SC-> O(1)

int once(vector<int>&arr){
    int n=arr.size();
    for(int i=0;i<n;i++){
        int count=0, num=arr[i];
        for(int j=0;j<n;j++){
            if(arr[j]==num){
                count++;
            }
        }
        if(count==1) return num;
    }
    return -1; //wont run if inputs are correct
}

//Better: Hashing. find max value in array and create hash array of size maxElement+1. then traverse array and update values of hash array. then traverse to find index at which value is 1.
//TC-> O(3n), SC-> O(max element)

//Note: wont work for -ve elements since we cant have -ve hash index. also, not appropriate if array has very large elements.

//Incase of large elements, we have to use map data structure, with a bigger datatype as a key.

int onceBetter(vector<int>&arr){
    int n=arr.size();
    int maxElement=arr[0];
    for(int i=0;i<n;i++){
        maxElement=max(maxElement,arr[i]);
    }
    vector<int> hash(maxElement+1,0);
    for(int i=0;i<n;i++){
        hash[arr[i]]++;
    }
    //depending on input, we can either iterate through array or through 0 to n in this step
    for(int i=0;i<n;i++){
        if(hash[arr[i]]==1) return arr[i];
    }
    return -1; //wont run if inputs are correct
}


int onceBetterMap(vector<int>&arr){
    int n=arr.size();
    unordered_map<long long, int> mpp;
    for(int i=0;i<n;i++){
        mpp[arr[i]]++; //ordered map: O(nlogm), n is length of array, m is size of map
        //unordered map: best case is O(n) worst is O(n^2) but v rare
    }
    for(auto it: mpp){ //O(n/2+1) bcz all except one appear twice and in map we store just single occurences of all 
        if(it.second==1) return it.first;
    }
    return -1; //just to prevent warning
    
    //so, overall TC-> O(nlog(n/2+1)+(n/2+1)) if ordered map, SC-> (n/2+1)
}

//Optimal: take xor of all elements
//TC-> O(n), SC-> O(1)

int onceOptimal(vector<int>&arr){
    int n=arr.size();
    int XOR=0;
    for(int i=0;i<n;i++){
        XOR^=arr[i];
    }
    return XOR;
}

int main(){
    vector<int> a={1,1,2,3,3,4,4};
    cout<<once(a)<<endl;
    cout<<onceBetter(a)<<endl;
    cout<<onceBetterMap(a)<<endl;
    cout<<onceOptimal(a)<<endl;
    return 0;
}