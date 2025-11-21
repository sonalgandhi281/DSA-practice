#include <iostream>
using namespace std;

//4. find peak element in 2D array. peak element is the one which is greater than its top, bottom, right, left neighbours. return index of any peak element.

//Brute: go through every element, check if its greater than its neighbours. O(n*m*4). we can make it better by just finding max element in matrix. O(n*m).

//Optimal: we apply binary search on cols. for mid col, we find max element in that col (it will be greater than top & bottom for sure), then compare with right and left. eliminate appropriate halves accordingly.

//tc-> O(n * logm), sc-> O(1)

int findMaxIndex(vector<vector<int>> &mat, int col){
    int n=mat.size(), m=mat[0].size();
    int maxVal=-1, ind=-1;
    for(int i=0;i<n;i++){
        if(mat[i][col]>maxVal){
            maxVal=mat[i][col];
            ind=i;
        }
    }
    return ind;
}

vector<int> peakElement(vector<vector<int>> &mat){
    int n=mat.size(), m=mat[0].size();
    int low=0, high=m-1;
    while(low<=high){
        int mid=(low+high)/2;
        int rowInd=findMaxIndex(mat,mid);
        int left= mid-1 >= 0 ? mat[rowInd][mid-1] : -1;
        int right= mid+1<m ? mat[rowInd][mid+1] : -1;
        if(mat[rowInd][mid]>left && mat[rowInd][mid]>right){
            return {rowInd,mid};
        }
        else if(mat[rowInd][mid]<left) high=mid-1;
        else low=mid+1;
    }
    return {-1,-1};
}

int main(){
    vector<vector<int>> mat = {
      {4, 2, 5, 1, 4, 5},
      {2, 9, 3, 2, 3, 2},
      {1, 7, 6, 0, 1, 3},
      {3, 6, 2, 3, 7, 2}
    };
    vector<int> ans=peakElement(mat);
    for(int x:ans) cout<<x<<" ";
    return 0;
}