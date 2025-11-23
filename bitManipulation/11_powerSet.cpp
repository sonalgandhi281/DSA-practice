#include <iostream>
using namespace std;

//11. given an array of integers, return the power set (set of all subsets of it) using bitwise operations

//we know that if array has n elements, there will be 2 to the power n possible subsets.
//we generate all possible 2 to the power n combinations of n bits and use them to decide which elements to include from array in the subset (0 means dont include, 1 means include).
//then put all subsets into a list and return it

//tc> O(2^n * n), sc-> O(2^n * n) near about (at most)

vector<vector<int>> powerSet(vector<int> &arr){
    int n=arr.size();
    int subsets=(1<<n); // 2 to the power n
    vector<vector<int>> ans;
    for(int num=0;num<subsets;num++){
        vector<int> temp;
        for(int i=0;i<n;i++){
            //check if ith bit is set or not
            if(num&(1<<i)) temp.push_back(arr[i]);
        }
        ans.push_back(temp);
    }
    return ans;
}

int main(){
    vector<int> nums = {5, 7, 8};
    vector<vector<int>> subsets = powerSet(nums);
    for(auto x:subsets){
        for(int y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    return 0;
}