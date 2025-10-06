#include <iostream>
#include<set>
using namespace std;

//9. union of 2 sorted arrays (take all unique elements from both)

//Brute : insert all elements from both arrays in a set(unique). now traverse set and put all elements in a union array.
//note: dont use unsorted set
//Tc-> O(n1logn+n2logn+n1+n2), SC-> O(n1+n2) (to solve) +O(n1+n2) (to return the ans)

vector<int> unionArr(vector<int> &a1, vector<int> &a2){
    vector<int> ans;
    set<int> st;
    int n1=a1.size(), n2=a2.size();
    for(int i=0;i<n1;i++){
        st.insert(a1[i]);
    }
    for(int i=0;i<n2;i++){
        st.insert(a2[i]);
    }
    for(auto it:st){
        ans.push_back(it);
    }
    return ans;
}

//Optimal : 2 pointer approach. i points to 1st element of a1, j points to 1st element of a2. take smaller of the two elements but check if it already exists or not.
//TC-> O(n1+n2), SC-> O(n1+n2) (for returning the ans)

vector<int> unionArrOptimal(vector<int> &a1, vector<int> &a2){
    int n1=a1.size(), n2=a2.size();
    int i=0, j=0;
    vector<int> ans;
    while(i<n1 && j<n2){
        if(a1[i]<=a2[j]){
            if(ans.size()==0 || ans.back()!=a1[i]){
                ans.push_back(a1[i]);
            }
            i++;
        }
        else{
            if(ans.size()==0 || ans.back()!=a2[j]){
                ans.push_back(a2[j]);
            }
            j++;
        }
    }
    while(j<n2){
        if(ans.size()==0 || ans.back()!=a2[j]){
                ans.push_back(a2[j]);
            }
            j++;
    }
    while(i<n1){
            if(ans.size()==0 || ans.back()!=a1[i]){
                ans.push_back(a1[i]);
            }
            i++;
    }
    return ans;
}

int main(){
    vector<int> v1={1,2,3,4,5};
    vector<int> v2={4,6,7,8};
    vector<int> u1=unionArr(v1,v2);
    vector<int> u2=unionArrOptimal(v1,v2);

    for(int x:u1) cout<<x<<" ";
    cout<<endl;
    for(int x:u2) cout<<x<<" ";
    return 0;
}