#include <iostream>
using namespace std;

//5. find median of row wise sorted matrix (given that m*n is odd)

//Brute: put all elements into a 1D array, sort it and return middle element
//tc-> O(n*m + n*mlog(n*m)), sc-> O(n*m)

int median2D(vector<vector<int>> &mat){
    int n=mat.size(), m=mat[0].size();
    vector<int> temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            temp.push_back(mat[i][j]);
        }
    }
    sort(temp.begin(),temp.end());
    return temp[temp.size()/2];
}

//Optimal: to optimize, i will have to skip through elements to reduce complexity.
//binary search range is from smallest element to largest element. for each value of mid, i will find no. of elements <= it. the first value that has n/2 elements <= it will be the ans.

//note: how many are lesser than or equal to x? we know that upper bound points to first element greater than x, so it will be the ans. we can do that on each row and add up to get total no. of elements <= x.

//tc-> O(n * log(max-min) * logm), sc-> O(1)

int countLessEqual(vector<int> &arr, int mid){
    return upper_bound(arr.begin(),arr.end(),mid)-arr.begin();
}

int median2DOptimal(vector<vector<int>> &mat){
    int n=mat.size(), m=mat[0].size();
    int low=mat[0][0], high=mat[0][m-1];
    for(int i=0;i<n;i++){
        low=min(low,mat[i][0]);
        high=max(high,mat[i][m-1]);
    }
    while(low<=high){
        int mid=(low+high)/2;
        int cnt=0;
        for(int i=0;i<n;i++){
            cnt+=countLessEqual(mat[i],mid);
        }
        if(cnt<(n*m+1)/2) low=mid+1;
        else high=mid-1;
    }
    return low;
}

int main(){
    vector<vector<int>> matrix = {
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9}
    };
    cout<<median2D(matrix)<<endl;
    cout<<median2DOptimal(matrix)<<endl;
    return 0;
}