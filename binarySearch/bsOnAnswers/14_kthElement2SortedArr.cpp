#include <iostream>
using namespace std;

//14. Kth element of 2 sorted arrays
// Given two sorted arrays of size m and n respectively, you are tasked with finding the element that would be at the kth position of the final sorted array.

//Brute: merge using merge sort, return kth element
//tc-> O(n1+n2), sc-> O(n1+n2)

int kthElement(vector<int> &a1, vector<int> &a2, int k){
    int n1=a1.size(), n2=a2.size();
    int i=0, j=0;
    vector<int> temp;
    while(i<n1 && j<n2){
        if(a1[i]<=a2[j]){
            temp.push_back(a1[i]);
            i++;
        }else{
            temp.push_back(a2[j]);
            j++;
        }
    }
    while(i<n1){
        temp.push_back(a1[i]);
        i++;
    }
    while(j<n2){
        temp.push_back(a2[j]);
        j++;
    }
    return temp[k-1];
}

//Better: we dont need to store entire array, we just need kth element
//tc-> O(n1+n2), sc-> O(1)

int kthElementBetter(vector<int> &a1, vector<int> &a2, int k){
    int n1=a1.size(), n2=a2.size();
    int i=0, j=0, cnt=0;
    int el=-1;
    while(i<n1 && j<n2){
        if(a1[i]<=a2[j]){
            if(cnt==k-1) el=a1[i];
            i++;
            cnt++;
        }else{
            if(cnt==k-1) el=a2[j];
            j++;
            cnt++;
        }
    }
    while(i<n1){
        if(cnt==k-1) el=a1[i];
        i++;
        cnt++;
    }
    while(j<n2){
        if(cnt==k-1) el=a2[j];
        j++;
        cnt++;
    }
    return el;
}

//Optimal: split array like k elements on left and remaining on right. we formulate correct left half using binary search
//tc-> O(log(min(n1,n2))), sc-> O(1)

int kthElementOptimal(vector<int> &a1, vector<int> &a2, int k){
    int n1=a1.size(), n2=a2.size();
    if(n1>n2) return kthElementOptimal(a2,a1,k);
    int left=k;
    int low=max(0,k-n2), high=min(k,n1);
    while(low<=high){
        int mid1=(low+high) >> 1;
        int mid2=left-mid1;
        int l1=INT_MIN, l2=INT_MIN;
        int r1=INT_MAX, r2=INT_MAX;
        if(mid1<n1) r1=a1[mid1];
        if(mid2<n2) r2=a2[mid2];
        if(mid1-1 >= 0) l1=a1[mid1-1];
        if(mid2-1 >= 0) l2=a2[mid2-1];
        if(l1<=r2 && l2<=r1){
           return max(l1,l2);
        }
        else if(l1>r2) high=mid1-1;
        else low=mid1+1;
    }
    return 0;//dummy
}

int main(){
    vector<int> a = {2, 3, 6, 7, 9};
    vector<int> b = {1, 4, 8, 10};
    int k=5;
    cout<<kthElement(a,b,k)<<endl;
    cout<<kthElementBetter(a,b,k)<<endl;
    cout<<kthElementOptimal(a,b,k)<<endl;
}