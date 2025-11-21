#include <iostream>
using namespace std;

//2. Search element in a 2D sorted array. return true if it exists.

//Brute: iterate through each element
//tc-> O(n*m), sc-> O(1)

bool search2D(vector<vector<int>> &mat, int target){
    int n=mat.size(), m=mat[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==target) return true;
        }
    }
    return false;
}

//Better: we know that each row is sorted. so, we iterate through rows and check if that row might contain target, then apply binary search on that row.
//tc-> O(n + logm) bcz we're not applying bs on all rows (only on 1 row), sc-> O(1)

bool binarySearch(vector<int> &arr, int target){
    int low=0, high=arr.size()-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==target) return true;
        else if(arr[mid]<target) low=mid+1;
        else high=mid-1;
    }
    return false;
}

bool search2DBetter(vector<vector<int>> &mat, int target){
    int n=mat.size(), m=mat[0].size();
    for(int i=0;i<n;i++){
        if(mat[i][0]<=target && target<=mat[i][m-1]){
            return binarySearch(mat[i],target);
        }
    }
    return false;
}

//Optimal: apply binary search on entire matrix bcz its sorted
//tc-> O(log(n*m)), sc-> O(1)

bool search2DOptimal(vector<vector<int>> &mat, int target){
    int n=mat.size(), m=mat[0].size();
    int low=0, high=n*m - 1;
    while(low<=high){
        int mid=(low+high)/2;
        int row=mid/m;
        int col=mid%m;
        if(mat[row][col]==target) return true;
        else if(mat[row][col]<target) low=mid+1;
        else high=mid-1;
    }
    return false;
}

int main(){
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    int target=8;
    cout<<search2D(matrix,target)<<endl;
    cout<<search2DBetter(matrix,target)<<endl;
    cout<<search2DOptimal(matrix,target)<<endl;

    return 0;
}