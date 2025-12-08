#include <iostream>
using namespace std;

//we can visualise matrix as histogram heights row by row. create prefixsum matrix to store histogram heights. then compute largest rect area for each row.

//tc->O(n*m)+O(n*2m), sc-> O(n*m)+O(n)

int largestRect(vector<int> &arr){
    int n=arr.size();
    stack<int> st;
    int maxArea=0;
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()]>arr[i]){
            int element=st.top();
            st.pop();
            int nse=i;
            int pse=st.empty() ? -1 : st.top();
            maxArea=max(maxArea,arr[element]*(nse-pse-1));
        }
        st.push(i);
    }
    while(!st.empty()){
            int nse=n;
            int element=st.top();
            st.pop();
            int pse=st.empty() ? -1 : st.top();
            maxArea=max(maxArea,arr[element]*(nse-pse-1));
        }
    return maxArea;
}

int maximalRect(vector<vector<int>>&mat){
    int n=mat.size(), m=mat[0].size();
    int maxArea=0;
    vector<vector<int>> prefixSum(n,vector<int>(m));
    for(int j=0;j<m;j++){
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=mat[i][j];
            if(mat[i][j]==0){
                sum=0;
                prefixSum[i][j]=0;
            }
            prefixSum[i][j]=sum;
        }
    }
    for(int i=0;i<n;i++){
        maxArea=max(maxArea,largestRect(prefixSum[i]));
    }
    return maxArea;
}

int main(){
    vector<vector<int>> matrix = {
        {1, 0, 1, 0, 0}, 
        {1, 0, 1, 1, 1}, 
        {1, 1, 1, 1, 1}, 
        {1, 0, 0, 1, 0}
    };
    cout<<maximalRect(matrix);
}