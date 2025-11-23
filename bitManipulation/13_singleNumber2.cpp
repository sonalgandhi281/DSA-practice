#include <iostream>
#include <map>
using namespace std;

//13. given an array in which every element appears thrice, except one element, find the single occuring element

//Brute: store occurrences of each element in map and return the one with single occurrence
//tc-> O(nlog(n/3+1)), sc-> O(n/3+1)

int singleNum2(vector<int> &arr){
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

//Better: for each bit that represent an integer (32 bits), traverse the array and count no. of set bits for that bit, if its not a multiple of 3, then that means at that bit position, the bit is set for the ans
//tc-> O(n*32), sc-> O(1)

int singleNum2Better(vector<int> &arr){
    int n=arr.size();
    int ans=0;
    for(int bitIndex=0;bitIndex<32;bitIndex++){
        int cnt=0;
        for(int i=0;i<n;i++){
            if(arr[i]&(1<<bitIndex)) cnt++;
        }
        if(cnt%3==1) ans=(ans|(1<<bitIndex)); //set the bitIndex in ans if not a multiple of 3
    }
    return ans;
}

//Optimal: sort all elements, now all groups with 3 elements are together and single element is somewhere.
//keep a pointer on 1st index, check if its equal to prev element, then move 3 places and do the same, if at any point not same, i-1 is your ans. edge case, if single element is last element, pointer moves out of array.

//tc-> O(nlogn + n/3), sc-> O(1)
//disadvantage: we are distorting the given input
//this is better than prev bcz earlier it was taking n*32 no matter what (in all cases), but now, logn will have smaller values generally (bcz for logn to be 32, n would have to be 2^32)

int singleNum2Optimal(vector<int> &arr){
    int n=arr.size();
    sort(arr.begin(),arr.end());
    for(int i=1;i<n;i+=3){
        if(arr[i]!=arr[i-1]) return arr[i-1];
    }
    return arr[n-1];
}

//Best Soln: uses concept of buckets.
//while traversing, add nums[i] to ones if its not in twos. add nums[i] to twos if its in ones. in the end, return the element in ones. we just keep adding or deleting
//tc-> O(n), sc-> O(1)

int singleNum2Best(vector<int> &arr){
    int n=arr.size();
    int ones=0, twos=0;
    for(int i=0;i<n;i++){
        ones=(ones^arr[i])&(~twos);
        twos=(twos^arr[i])&(~ones);
    }
    return ones;
}

int main(){
    vector<int> v={1,2,1,1,3,4,3,4,4,3};
    cout<<singleNum2(v)<<endl;
    cout<<singleNum2Better(v)<<endl;
    cout<<singleNum2Optimal(v)<<endl;
    cout<<singleNum2Best(v)<<endl;
    return 0;
}