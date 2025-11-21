#include <iostream>
using namespace std;

//3. search in a row and col wise sorted 2d array. each col and row is sorted in itself but the entire 2d array is not necessarily sorted

//Brute: traverse each element
//tc- >O(n*m), sc-> O(1)

bool search(vector<vector<int>> &mat, int target){
    int n=mat.size(), m=mat[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==target) return true;
        }
    }
    return false;
}

//Better: iterate through each row and apply binary search on each row, or, iterate and apply binary search on each col
//tc-> O(nlogm) or O(mlogn), sc-> O(1)

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

bool searchBetter(vector<vector<int>> &mat, int target){
    int n=mat.size(), m=mat[0].size();
    for(int i=0;i<n;i++){
        if(binarySearch(mat[i],target)) return true;
    }
    return false;
}

//Optimal: notice that on mat[0][m-1] or on mat[n-1][0], there are 2 possible directions to go and one is increasing and other is decreasing.
//so, say we start from mat[0][m-1], compare with target and if target is greater, move down, if its less, move left.
//tc-> O(n+m), sc-> O(1)

bool searchOptimal(vector<vector<int>> &mat, int target){
    int n=mat.size(), m=mat[0].size();
    int row=0, col=m-1;
    while(row<n && col>=0){
        if(mat[row][col]==target) return true;
        else if(mat[row][col]<target) row++;
        else col--;
    }
    return false;
}

int main(){
    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    cout<<search(matrix,8)<<endl;
    cout<<searchBetter(matrix,8)<<endl;
    cout<<searchOptimal(matrix,8)<<endl;
    return 0;
}