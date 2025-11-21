#include <iostream>
using namespace std;

//1. find the row with maximum no. of 1s

// You have been given a non-empty grid ‘mat’ with 'n' rows and 'm' columns consisting of only 0s and 1s. All the rows are sorted in ascending order. Your task is to find the index of the row with the maximum number of ones. Note: If two rows have the same number of ones, consider the one with a smaller index. If there's no row with at least 1, return -1

//Brute: iterate through each row, maintain cnt to store no. of 1s in that row, return index of highest cnt
//tc-> O(n*m), sc-> O(1)

int max1(vector<vector<int>> &mat){
    int n=mat.size();
    int m=mat[0].size();
    int maxcnt=0;
    int rowind=-1;
    for(int i=0;i<n;i++){
        int cnt=0;
        for(int j=0;j<m;j++){
            cnt+=mat[i][j];
        }
        if(cnt>maxcnt){
            maxcnt=cnt;
            rowind=i;
        }
    }
    return rowind;
}

//Optimal: we know that each row is sorted, we find first occurrence of 1 for each row and subtract it with m(no. of col) to get cnt of 1s in that row. then return index of maxcnt
//tc-> O(n*logm), sc-> O(1)

int lowerBound(vector<int> &arr, int x){ //finds first occurence of x (returns first index where value>=x)
    int low=0, high=arr.size()-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]>=x) high=mid-1;
        else low=mid+1;
    }
    return low;
}

int max1Optimal(vector<vector<int>> &mat){
    int n=mat.size();
    int m=mat[0].size();
    int maxcnt=0, rowind=-1;
    for(int i=0;i<n;i++){
        int cnt=m-lowerBound(mat[i],1);
        if(cnt>maxcnt){
            maxcnt=cnt;
            rowind=i;
        }
    }
    return rowind;
}

int main(){
    vector<vector<int>> matrix = {{0, 0, 0}, {0, 0, 1}, {0, 0, 0}};
    cout<<max1(matrix)<<endl;
    cout<<max1Optimal(matrix)<<endl;
    return 0;
}