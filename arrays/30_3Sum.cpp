#include<iostream>
#include<set>
using namespace std;

//30. 3 Sum
//given an array of integers, find out all triplets that sum up to give value 0.
//you cant take same elements more than once.
//only return unique triplets (no duplicates)

//Brute: try out all triplets using 3 loops. consider the ones whose sum is 0. then only consider unique ones.
//TC-> O(n^3 * log(no. of unique elements)), SC-> O(2*no. of unique triplets)

vector<vector<int>> threeSum(vector<int> &arr){
    int n=arr.size();
    set<vector<int>>st;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(arr[i]+arr[j]+arr[k]==0){
                    vector<int> temp={arr[i],arr[j],arr[k]};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}

//Better: reduce it to 2 loops.
//we know that arr[i]+arr[j]+arr[k]=0
//so, arr[k]=-(arr[i]+arr[j])
//and we find this third element by hashing

//note that while searching for third element we have to make sure that its not arr[i] or arr[j] bcz we cant have duplicate elements

//so we store elements bw i and j in hashset and then search for third element in hashset

//TC-> O(n^2 * log(no. of unique triplets)), SC-> O(2*no. of unique triplets)+O(n)

vector<vector<int>> threeSumBetter(vector<int> &arr){
    int n=arr.size();
    set<vector<int>> st;
    for(int i=0;i<n;i++){
        set<int> hashset;
        for(int j=i+1;j<n;j++){
            int third=-(arr[i]+arr[j]);
            if(hashset.find(third)!=hashset.end()){
                vector<int>temp={arr[i],arr[j],third};
                sort(temp.begin(),temp.end());
                st.insert(temp);
            }
            hashset.insert(arr[j]);
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}

//Optimal: we want to get rid of hashset and set ds used to store unique triplets.
//we sort the array initially only.

//2 pointer approach. fix pointer i first, keep j and k moving. to get unique triplets, just skip duplicate no.s while moving pointers.

//TC-> O(nlogn)+O(n^2), SC-> O(no. of triplets) only to return the ans so, sc can be considered O(1)

vector<vector<int>> threeSumOptimal(vector<int> &arr){
    int n=arr.size();
    vector<vector<int>> ans;
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        if(i!=0 && arr[i]==arr[i-1]) continue;

        int j=i+1;
        int k=n-1;
        while(j<k){
            int sum=arr[i]+arr[j]+arr[k];
            if(sum<0) j++;
            else if(sum>0) k--;
            else{
                vector<int> temp={arr[i],arr[j],arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                while(j<k && arr[j]==arr[j-1]) j++;
                while(j<k && arr[k]==arr[k+1]) k--;
            }
        }
    }
    return ans;
}

int main(){
    vector<int> v={-1,0,1,2,-1,4};
    vector<vector<int>> ans1=threeSum(v);
    vector<vector<int>> ans2=threeSumBetter(v);
    vector<vector<int>> ans3=threeSumOptimal(v);

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
    cout<<endl;

    for(auto x:ans3){
        for(int y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    return 0;
}