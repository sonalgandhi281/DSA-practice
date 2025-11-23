#include <iostream>
#include<map>
using namespace std;

//14. given an array that contains every element twice except two distinct elements that appear once each. return both distinct elements that appear once.

//Brute: hashing. store freq of each element in map. return elements with one freq.
//tc-> O(nlogn(n/2+1)+(n/2+1)), sc-> O(n/2+1)

vector<int> singleNum3(vector<int> &arr){
    int n=arr.size();
    vector<int> ans;
    map<int,int> mpp;
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
    }
    for(auto it:mpp){
        if(it.second==1) ans.push_back(it.first);
    }
    return ans;
}

//Optimal: using buckets. take xor of all elements of array. since, there are 2 distinct elements, there will be atleast 1 bit difference in them. 
//now, lets say we use the rightmost set bit of the xor, to differentiate between the distinct elements. we calc number such that all bits are 0 except rightmost set bit.
//then, we traverse the array and put elements into bucket 1 if that bit is set, into bucket 0 if not set. by this, we can be sure that distinct elements will be in different buckets.
//xor both buckets to get single elements

//tc-> O(2n), sc-> O(1)

//note that in int, [-2^31, 2^31-1] is the range, if xorr=-2^31, xorr-1 cant be stored in int datatype, it will overflow. so make sure we use long for xorr

vector<int> singleNum3Optimal(vector<int> &arr){
    int n=arr.size();
    long xorr=0;
    for(int i=0;i<n;i++) xorr^=arr[i];
    int rightmost=(xorr&xorr-1)^xorr;
    int b1=0, b2=0;
    for(int i=0;i<n;i++){
        if(arr[i]&rightmost) b1^=arr[i];
        else b2^=arr[i];
    }
    return {b1,b2};
}

int main(){
    vector<int> v={1,2,2,1,3,14,5,5};
    vector<int> ans1=singleNum3(v);
    vector<int> ans2=singleNum3Optimal(v);
    for(int x:ans1) cout<<x<<" ";
    cout<<endl;
    for(int x:ans2) cout<<x<<" ";
    return 0;
}