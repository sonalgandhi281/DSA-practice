#include<iostream>
using namespace std;

//33. Merge Overlapping Subintervals

//we are given an array of n subintervals

//eg [ (1,3), (2,6), (8,9), (9,11), (8,10), (2,4), (15,18), (16,17) ]

//we have to merge all overlapping subintervals into one and find out how many minimum subintervals can i give

//overlapping subintervals will be : eg 1,3 and 2,6 can be merged into 1,6. each coordinate withing that interval should be covered by some interval and no empty spaces should be there.



//Brute: sort it to get all overlapping intervals close to each other. iterate over it and for each element compare if starting of a pair is smaller than ending of selected interval. update ending of selected interval with max value out of the 2.

//TC-> O(nlogn+2n), SC-> O(n) to store ans

vector<vector<int>> mergeInterval(vector<vector<int>> &arr){
    sort(arr.begin(),arr.end());
    int n=arr.size();
    vector<vector<int>> ans;
    for(int i=0;i<n;i++){
        int start=arr[i][0];
        int end=arr[i][1];
        if(!ans.empty() && end<=ans.back()[1]){
            continue;
        }
        for(int j=i+1;j<n;j++){
            if(arr[j][0]<=end){
                end=max(end,arr[j][1]);
            }else{
                break;
            }
        }
        ans.push_back({start,end});
    }
    return ans;
}

//Optimal: i want to do it in a single iteration instead of checking twice

//TC-> O(nlogn+n), SC-> O(n) to store ans

vector<vector<int>> mergeIntervalOptimal(vector<vector<int>>&arr){
    int n=arr.size();
    sort(arr.begin(),arr.end());
    vector<vector<int>>ans;
    for(int i=0;i<n;i++){
        if(ans.empty() || arr[i][0]>ans.back()[1]){
            ans.push_back(arr[i]);
        }else{
            ans.back()[1]=max(ans.back()[1],arr[i][1]);
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> v={{1,3}, {2,6}, {8,9}, {9,11}, {8,10}, {2,4}, {15,18}, {16,17} };
    vector<vector<int>>ans1=mergeInterval(v);
    vector<vector<int>>ans2=mergeIntervalOptimal(v);

    for(vector<int> x : ans1){
        for(int y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for(vector<int> x : ans2){
        for(int y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }

    return 0;
}