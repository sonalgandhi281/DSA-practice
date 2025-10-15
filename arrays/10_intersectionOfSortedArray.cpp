#include<iostream>
using namespace std;

//10. intersection of 2 sorted arrays (for every element in a1 there should be corresponding element in a2)

//Brute: pick up elements one by one from a1, check if corresponding exists in a2, while keeping track if its been used before
//TC-> O(n1xn2), SC-> O(n1) or O(n2)

vector <int> intersection(vector<int> &a1, vector<int> &a2){
    if(a1.size() < a2.size()) swap(a1, a2);
    int n1=a1.size(), n2=a2.size();
    vector<int> ans;
    vector<int> vis(n1, 0);
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            if(a1[i]==a2[j] && vis[j]==0){
                ans.push_back(a1[i]);
                vis[j]=1;
                break;
            }
            if(a2[j]>a1[i]) break;
        }
    }
    return ans;
}

//Optimal: 2 pointer approach 
//TC->O(n1+n2), SC-> O(1)

vector<int> intersectionOpimal(vector<int> &a1, vector<int> &a2){
    int n1=a1.size(), n2=a2.size();
    int i=0, j=0;
    vector<int> ans;
    while(i<n1 && j<n2){
        if(a1[i]<a2[j]) i++;
        else if(a1[i]>a2[j]) j++;
        else{
            ans.push_back(a1[i]);
            i++;
            j++;
        }
    }
    return ans;
}

int main(){
    vector<int> a1={1,2,2,3,4};
    vector<int> a2={2,2,4,5};
    vector<int> ans1=intersection(a1,a2);
    vector<int> ans2=intersectionOpimal(a1,a2);
    for(int x: ans1) cout<<x<<" ";
    cout<<endl;
    for(int x: ans2) cout<<x<<" ";
    return 0;
}