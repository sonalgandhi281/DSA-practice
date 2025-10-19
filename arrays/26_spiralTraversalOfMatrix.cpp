#include<iostream>
using namespace std;

//26. spiral traversal of a matrix

//this problem has just one solution (directly optimal).
//implementation skills and clarity of code are focus here.

//Optimal: we are moving in the following way : right->bottom->left->top.
//we use left,right,top,bottom pointers.

//TC-> O(nxm), SC-> O(nxm) for storing the ans

vector<int> spiralTraversal(vector<vector<int>>&arr){
    int n=arr.size();
    int m=arr[0].size();
    int top=0, bottom=n-1, left=0, right=m-1;
    vector<int> ans;
    while(left<=right && top<=bottom){
        for(int i=left;i<=right;i++){
            ans.push_back(arr[top][i]);
        }
        top++;
        for(int i=top;i<=bottom;i++){
            ans.push_back(arr[i][right]);
        }
        right--;
        if(top<=bottom){
            for(int i=right;i>=left;i--){
                ans.push_back(arr[bottom][i]);
            }
            bottom--;
        }
        if(left<=right){
            for(int i=bottom;i>=top;i--){
                ans.push_back(arr[i][left]);
            }
            left++;
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> v={
        {1,2,3,4,5,6},
        {20,21,22,23,24,7},
        {19,32,33,34,25,8},
        {18,31,36,35,26,9},
        {17,30,29,28,27,10},
        {16,15,14,13,12,11}
    };
    vector<int> ans=spiralTraversal(v);
    for(int x:ans) cout<<x<<" ";
    return 0;
}