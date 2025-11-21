#include <iostream>
using namespace std;

//13. median of 2 sorted arrays

//Brute: merge 2 sorted arrays by merge sort and then find median
//tc-> O(n1+n2), sc-> O(n1+n2)

double medianSortedArr(vector<int> &a1, vector<int> &a2){
    int n1=a1.size(), n2=a2.size();
    vector<int> temp;
    int i=0, j=0;
    while(i<n1 && j<n2){
        if(a1[i]<=a2[j]){
            temp.push_back(a1[i]);
            i++;
        }
        else{
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
    int n=temp.size();
    if(n%2==0){
        return (temp[n/2-1]+temp[n/2])/2.0;
    }else{
        return temp[n/2];
    }
}

//Better: instead of storing entire sorted array, we just store elements we need to calc median
//tc-> O(n1+n2), sc-> O(1)

double medianSortedArrBetter(vector<int> &a1, vector<int> &a2){
    int n1=a1.size(), n2=a2.size();
    int cnt=0;
    int n=(n1+n2);
    int i=0, j=0;
    int ind2=n/2;
    int ind1=ind2-1;
    int ind1el=-1, ind2el=-1;
    while(i<n1 && j<n2){
        if(a1[i]<=a2[j]){
            if(cnt==ind1) ind1el=a1[i];
            if(cnt==ind2) ind2el=a1[i];
            cnt++;
            i++;
        }else{
            if(cnt==ind1) ind1el=a2[j];
            if(cnt==ind2) ind2el=a2[j];
            cnt++;
            j++;
        }
    }
    while(i<n1){
        if(cnt==ind1) ind1el=a1[i];
        if(cnt==ind2) ind2el=a1[i];
        cnt++;
        i++;
    }
    while(j<n2){
        if(cnt==ind1) ind1el=a2[j];
        if(cnt==ind2) ind2el=a2[j];
        cnt++;
        j++;
    }
    if(n%2==1) return ind2el;
    return (double)((double)(ind1el+ind2el))/2.0;
}

//Optimal: formuate the correct left half by finding how many elements u need from smaller array (by using binary search)
//tc-> O(log(min(n1,n2)), sc-> O(1)

double medianSortedArrOptimal(vector<int> &a1, vector<int> &a2){
    int n1=a1.size(), n2=a2.size();
    int n=(n1+n2);
    if(n1>n2) return medianSortedArrOptimal(a2,a1);
    int low=0, high=n1;
    int left=(n1+n2+1)/2;
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
            if(n%2==1) return max(l1,l2);
            return ((double)(max(l1,l2)+min(r1,r2)))/2.0;
        }
        else if(l1>r2) high=mid1-1;
        else low=mid1+1;
    }
    return 0;//dummy
}

int main(){
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    cout<<medianSortedArr(nums1,nums2)<<endl;
    cout<<medianSortedArrBetter(nums1,nums2)<<endl;
    cout<<medianSortedArrOptimal(nums1,nums2)<<endl;

    return 0;
}