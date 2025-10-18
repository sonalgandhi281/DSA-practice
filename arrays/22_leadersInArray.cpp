#include <iostream>
using namespace std;

//22. find leaders in an array

//leader: an element is a leader if everything on its right is smaller than it

//note: last element is always a leader

//Brute: for each element, check if there is any element greater than it on the right, if so, its not a leader.
//TC-> O(n^2), SC-> O(n) for returning the ans

vector<int> leadersInArray(vector<int> &arr){
    int n=arr.size();
    vector<int> ans;
    for(int i=0;i<n;i++){
        bool leader=true;
        for(int j=i+1;j<n;j++){
            if(arr[j]>arr[i]){
                leader=false;
                break;
            }
        }
        if(leader==true){
            ans.push_back(arr[i]);
        }
    }
    return ans;
}

//Optimal: if an element is greater than the maximum element on its right, then its a leader.
//iterate from the back, keep updating max and keep checking if next element greater than max

//TC-> O(n), SC-> O(n) for returning the ans

vector<int> leadersInArrayOptimal(vector<int> &arr){
    int n=arr.size();
    vector<int> ans;
    int maxNum=INT_MIN;
    for(int i=n-1;i>=0;i--){
        if(arr[i]>maxNum){
            ans.push_back(arr[i]);
        }
        maxNum=max(maxNum,arr[i]);
    }
    //sort(ans.begin(),ans.end()); if asked in ques
    return ans;
}

int main(){
    vector<int> v={10,22,12,3,0,6};
    vector<int>ans1=leadersInArray(v);
    vector<int>ans2=leadersInArrayOptimal(v);

    for(int x:ans1) cout<<x<<" ";
    cout<<endl;
    for(int x:ans2) cout<<x<<" ";
    return 0;
}