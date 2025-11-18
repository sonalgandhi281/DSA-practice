#include <iostream>
using namespace std;

//9. Allocate minimum no. of pages
// Given an array ‘arr of integer numbers, ‘ar[i]’ represents the number of pages in the ‘i-th’ book. There are a ‘m’ number of students, and the task is to allocate all the books to the students.
// Allocate books in such a way that:

// Each student gets at least one book.
// Each book should be allocated to only one student.
// Book allocation should be in a contiguous manner.
// You have to allocate the book to ‘m’ students such that the maximum number of pages assigned to a student is minimum. If the allocation of books is not possible. return -1

int countStud(vector<int> &arr, int pages){
    int n=arr.size();
    int student=1, totPages=0;
    for(int i=0;i<n;i++){
        if(totPages+arr[i] <= pages){
            totPages+=arr[i];
        }
        else{
            student++;
            totPages=arr[i];
        }
    }
    return student;
}

//Brute:
//O(n * (sum-max+1))

int allocate(vector<int> &arr, int m){
    int n=arr.size();
    if(m>n) return -1;
    //what can be starting of range (minimum possible maximum pages someone has? -> it will be max element of the array)
    int maxi=*max_element(arr.begin(),arr.end()); //we start from this

    //ending of range will be summation of entire array
    int sum=0;
    for(int x:arr) sum+=x;

    //for each value, we keep checking that are we able to allocate books without exceeding the max pages we assumed
    //if i keep exceeding students, i increase the value
    for(int i=maxi;i<=sum;i++){
        if(countStud(arr,i)==m){
            return i;
        }
    }
    return maxi;
}

//Optimal:
//O(n * log(sum-max+1))

int allocateOptimal(vector<int> &arr, int m){
    int n=arr.size();
    if(m>n) return -1;
    int low=*max_element(arr.begin(),arr.end());
    int high=0;
    for(int x:arr) high+=x;
    while(low<=high){
        int mid=(low+high)/2;
        if(countStud(arr,mid)>m) low=mid+1;
        else high=mid-1;
    }
    return low;
}

int main(){
    vector<int> arr = {25, 46, 28, 49, 24};
    int m = 4;
    cout<<allocate(arr,m)<<endl;
    cout<<allocateOptimal(arr,m)<<endl;
    return 0;
}