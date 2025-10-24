#include<iostream>
#include<set>
using namespace std;

//31. 4 sum
//given an array of integers, find 4 different indexes such that if u some up the no.s at those indexes, it should give value target.

//we have to find unique quads.

//Brute: find all quads using 4 loops. out of them we consider only the ones that sum up to give target. and we find unique quads using set ds.

//TC-> O(n^4), SC-> O(no. of quads x 2)

vector<vector<int>> fourSum(vector<int> &arr, int target){
    int n=arr.size();
    set<vector<int>> st;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                for(int l=k+1;l<n;l++){
                    long long sum = arr[i]+arr[j];
                    sum+=arr[k];
                    sum+=arr[l];
                    if(sum==target){
                        vector<int> temp={arr[i],arr[j],arr[k],arr[l]};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>>ans(st.begin(),st.end());
    return ans;
}

//Better: we try to reduce to 3 loops.
//using arr[l]=target-(arr[i]+arr[j]+arr[k])
//and we find this fourth element by hashing

//note that while searching for fourth element we have to make sure that its not arr[i] or arr[j] or arr[k] bcz we cant have duplicate elements

//so instead of searching entire array, we only search bw j and k using hashset.

//TC-> O(n^3*log(no. of elements in set)), SC-> O(2*no. of quads)+O(n)

vector<vector<int>> fourSumBetter(vector<int> &arr, int target){
    int n=arr.size();
    set<vector<int>> st;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            set<long long> hashset;
            for(int k=j+1;k<n;k++){
                long long sum=arr[i]+arr[j];
                sum+=arr[k];
                long long fourth=target-sum;
                if(hashset.find(fourth)!=hashset.end()){
                    vector<int> temp={arr[i],arr[j],arr[k],(int)fourth};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
                hashset.insert(arr[k]);
            }
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}

//Optimal: we want to get rid of hashset that we used to look up in the array and the set ds used to stpre unique quads.

//sort arr initially.
//fix i and j. keep k and l moving. 

//TC-> O(n^3), SC-> O(no. of quads) only to store the ans not to solve the problem


vector<vector<int>> fourSumOptimal(vector<int> &arr, int target){
    int n=arr.size();
    vector<vector<int>> ans;
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        if(i>0 && arr[i]==arr[i-1]) continue;
        for(int j=i+1;j<n;j++){
            if(j!=i+1 && arr[j]==arr[j-1]) continue;
            int k=j+1;
            int l=n-1;
            while(k<l){
                long long sum=arr[i];
                sum+=arr[j];
                sum+=arr[k];
                sum+=arr[l];
                if(sum==target){
                    vector<int> temp={arr[i],arr[j],arr[k],arr[l]};
                    ans.push_back(temp);
                    k++;
                    l--;
                    while(k<l && arr[k]==arr[k-1]) k++;
                    while(k<l && arr[l]==arr[l+1]) l--;
                }
                else if(sum<target) k++;
                else l--;
            }
        }
    }
    return ans;
}

int main(){
     vector<int> v={1,0,-1,0,-2,2};
    vector<vector<int>> ans1=fourSum(v,0);
    vector<vector<int>> ans2=fourSumBetter(v,0);
    vector<vector<int>> ans3=fourSumOptimal(v,0);

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