#include<iostream>
#include<map>
using namespace std;

//32. count no. of subarrays with xor as k.

//Brute: generate all subarrays by specifying start and end and looping through it. then find the ones that give xor k and increase count accordingly.

//TC-> O(n^3), SC-> O(1)

int subArrXor(vector<int> &arr, int target){
    int n=arr.size();
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int xorr=0;
            for(int k=i;k<=j;k++){
                xorr^=arr[k];
            }
            if(xorr==target) count++;
        }
    }
    return count;
}

//Better: we can reduce it to 2 loops bcz as j is moving, the next subarray includes one more element. so, we keep applying operation xor while moving j.

//TC-> O(n^2), SC-> O(1)

int subArrXorBetter(vector<int> &arr, int target){
    int n=arr.size();
    int cnt=0;
    for(int i=0;i<n;i++){
        int xorr=0;
        for(int j=i;j<n;j++){
            xorr^=arr[j];
            if(xorr==target) cnt++;
        }
    }
    return cnt;
}

//Optimal: we focus on ending point of every subarray. till every index, we find xor of all elements. 
//if x^k=XR
//taking ^k on both sides
//x^k^k=XR^k
//x=XR^k

//so if i want to find, is there any subarray ending at an index say ind, and having xor of k?
//this is possible if i can find prefix xor x such that x=XR^k where XR is prefix xor till ind.

//so i just have to find how many x are there, and increase cnt accordingly. to keep a track we use hashmap of (frontxor, cnt)

//TC-> O(n) or O(nlogn) depending on which map, SC-> O(n)

int subArrXorOptimal(vector<int> &arr,int target){
    int n=arr.size();
    map<int,int>mpp;
    mpp[0]=1; //initially, in empty arr we dont have anything
    int xr=0;
    int cnt=0;
    for(int i=0;i<n;i++){
        xr^=arr[i];
        int rem=xr^target;
        cnt+=mpp[rem];
        mpp[xr]++;
    }
    return cnt;
}

int main(){
    vector<int> v={4,2,2,6,4};
    int target=6;
    cout<<subArrXor(v,target)<<endl;
    cout<<subArrXorBetter(v,target)<<endl;
    cout<<subArrXorOptimal(v,target)<<endl;

    return 0;
}