#include <iostream>
using namespace std;

//24. set matrix zeros.

//given an nxm binary matrix, we have to find out all zeros, and mark everything as 0 in that particular row and column.

//but dont do this for zeros that we have marked

//Brute: iterate through the matrix, find 0, mark everything in that row and col as -1 (dont change the 0s to -1). iterate again and convert all -1 to 0.

//TC-> O((nxm)x(n+m)+(nxm)) equivalent to O(n^3), SC-> O(1)

void markRow(vector<vector<int>> &arr, int m, int i){
    for(int j=0;j<m;j++){
        if(arr[i][j]!=0) arr[i][j]=-1;
    }
}

void markCol(vector<vector<int>> &arr, int n, int j){
    for(int i=0;i<n;i++){
        if(arr[i][j]!=0) arr[i][j]=-1;
    }
}

void setMatrix0(vector<vector<int>> &arr){
    int n=arr.size();
    int m=arr[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==0){
                markRow(arr,m,i);
                markCol(arr,n,j);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==-1) arr[i][j]=0;
        }
    }
}

//Better: in brute, we marked -1 within traversal. now, we use 2 arrays called row and col to indicate the presence of a 0 in a particular row or col, and then after traversal, we change values.

//TC-> O(2xnxm), SC-> O(n+m)

void setMatrix0Better(vector<vector<int>>&arr){
    int n=arr.size();
    int m=arr[0].size();
    vector<int> row(n,0);
    vector<int> col(m,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==0){
                row[i]=1;
                col[j]=1;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(row[i]==1 || col[j]==1){
                arr[i][j]=0;
            }
        }
    }
}

//Optimal: i want to reduce space complexity now. instead of using 2 separate arrays, we will just keep track in the matrix itself. we try to use a[0][] as col array and a[][0] as row array.

//but a[0][0] is overlapping element so i start col array from 2nd element and keep separate col0 variable.

//TC-> O(2xnxm), SC-> O(1)

void setMatrix0Optimal(vector<vector<int>>&arr){
    int n=arr.size();
    int m=arr[0].size();
    int col0=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==0){
                arr[i][0]=0;
                if(j!=0) arr[0][j]=0;
                else col0=0;
            }
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(arr[i][0]==0 || arr[0][j]==0){
                arr[i][j]=0;
            }
        }
    }
    if(arr[0][0]==0){
        for(int j=0;j<m;j++){
            arr[0][j]=0;
        }
    }
    if(col0==0){
        for(int i=0;i<n;i++){
            arr[i][0]=0;
        }
    }
}

int main(){
    vector<vector<int>> v1={
        {1,1,1,1},
        {1,0,1,1},
        {1,1,0,1},
        {0,1,1,1}
    };
    vector<vector<int>> v2={
        {1,1,1,1},
        {1,0,1,1},
        {1,1,0,1},
        {0,1,1,1}
    };
    vector<vector<int>> v3={
        {1,1,1,1},
        {1,0,1,1},
        {1,1,0,1},
        {0,1,1,1}
    };

    setMatrix0(v1);
    setMatrix0Better(v2);
    setMatrix0Optimal(v3);

    for(auto x:v1){
        for(int y:x){
             cout<<y<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for(auto x:v2){
        for(int y:x){
             cout<<y<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for(auto x:v3){
        for(int y:x){
             cout<<y<<" ";
        }
        cout<<endl;
    }

    return 0;
}