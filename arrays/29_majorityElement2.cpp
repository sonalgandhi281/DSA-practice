#include<iostream>
#include<unordered_map>
using namespace std;

//29. return majority element (all integers that occur > floor(n/3) times)

//how many integers can be there in the answer?
//at max, there will be 2 elements that appear >n/3 times

//Brute: for each element, count occurences of that element by nested loops. return elements>n/3 times.
//you can stop the iteration as soon as u find 2 elements.

//TC-> O(n^2), SC-> O(1)

vector<int> majElement2(vector<int> &arr){
    int n=arr.size();
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(find(ans.begin(), ans.end(), arr[i]) != ans.end()) continue;

        int cnt=0;
        for(int j=0;j<n;j++){
            if(arr[i]==arr[j]) cnt++;
        }

        if(cnt>n/3) ans.push_back(arr[i]);
        if(ans.size()==2) break;
    }
    return ans;
}

//Better: Hashing. take hashmap with (element, count). traverse array and keep storing in hashmap accordingly. iterate through hashmap, check for count>n/3.

//instead of 2 traversals, we can do it in a single traversal by checking if cnt>n/3 while increasing cnt.

//TC-> O(n) unordered avg and O(n^2) worst case or O(nlogn) for map, SC-> O(n)

vector <int> majElement2Better(vector<int> &arr){
    int n=arr.size();
    vector<int> ans;
    int mini=(int)(n/3) + 1;
    unordered_map<int,int> mpp;
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
        if(mpp[arr[i]]==mini){
            ans.push_back(arr[i]);
        }
        if(ans.size()==2) break;
    }
    //O(2log2) if u sort, its as good as constant
    //sort(ans.begin(),ans.end()) if asked in ques, sort it
    return ans;
}

//Optimal: intuition is similar to majority element 1 problem
//TC-> O(2n), SC-> O(1)

vector<int> majElement2Optimal(vector<int> &arr){
    int n=arr.size();
    vector<int> ans;
    int cnt1=0, cnt2=0;
    int el1=INT_MIN, el2=INT_MIN;
    for(int i=0;i<n;i++){
       if(cnt1==0 && arr[i]!=el2){
        cnt1=1;
        el1=arr[i];
       }
       else if(cnt2==0 && arr[i]!=el1){
        cnt2=1;
        el2=arr[i];
       }
       else if(el1==arr[i]) cnt1++;
       else if(el2==arr[i]) cnt2++;
       else{
        cnt1--;
        cnt2--;
       }
    }
    cnt1=0, cnt2=0;
    for(int i=0;i<n;i++){
        if(el1==arr[i]) cnt1++;
        if(el2==arr[i]) cnt2++;
    }
    int mini=(int)(n/3)+1;
    if(cnt1>=mini) ans.push_back(el1);
    if(cnt2>=mini) ans.push_back(el2);
    sort(ans.begin(),ans.end());
    return ans;
}

int main(){
    vector<int> v={1,1,1,3,3,2,2,2};
    
    vector<int> ans1=majElement2(v);
    vector<int> ans2=majElement2Better(v);
    vector<int> ans3=majElement2Optimal(v);

    for(int x: ans1) cout<<x<<" ";
    cout<<endl;
    for(int x: ans2) cout<<x<<" ";
    cout<<endl;
    for(int x: ans3) cout<<x<<" ";

    return 0;
}