#include<iostream>
using namespace std;

//25. rotate matrix/image by 90 degrees

//Brute: create an ans matrix of same size. iterate through matrix and place each element in correct position in ans matrix.

//TC-> O(n^2), SC-> O(n^2)

vector<vector<int>> rotateMatrix(vector<vector<int>>&arr){
    int n=arr.size();
    vector<vector<int>> ans(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans[j][n-i-1]=arr[i][j];
        }
    }
    return ans;
}

//Optimal: solve in place: first transpose the matrix, then reverse every row.

//TC-> O(n/2*n/2 + n*n/2), SC-> O(1)

vector<vector<int>> rotateMatrixOptimal(vector<vector<int>>&arr){
    int n=arr.size();
    for(int i=0;i<=n-2;i++){
        for(int j=i+1;j<n;j++){
            swap(arr[i][j],arr[j][i]);
        }
    }
    for(int i=0;i<n;i++){
        reverse(arr[i].begin(),arr[i].end());
    }
    return arr;
}

int main(){
    vector<vector<int>> v={
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };
    vector<vector<int>>ans1=rotateMatrix(v);
    vector<vector<int>>ans2=rotateMatrixOptimal(v);

    for(auto x:ans1){
        for(int y:x){
             cout<<y<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for(auto x:ans2){
        for(int y:x){
             cout<<y<<" ";
        }
        cout<<endl;
    }

    return 0;
}