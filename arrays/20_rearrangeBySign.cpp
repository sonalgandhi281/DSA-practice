#include <iostream>
using namespace std;

//20. Rearrange array elements by sign. (alternating +ve and -ve order)

//variety 1 : array has equal no. of +ve and -ve elements.

//Brute: traverse, create two arrays pos and neg to store +ve and -ve elements. traverse from 0 to n/2 and add from pos at even indices and from neg at odd indices.
//TC-> O(n+n/2), SC-> O(n)

vector<int> rearrangeArr(vector<int> &arr){
    int n=arr.size();
    vector<int> pos;
    vector<int> neg;
    for(int i=0;i<n;i++){
        if(arr[i]<0){
            neg.push_back(arr[i]);
        }else{
            pos.push_back(arr[i]);
        }
    }
    for(int i=0;i<n/2;i++){
        arr[2*i]=pos[i];
        arr[2*i+1]=neg[i];
    }
    return arr;
}

//Optimal: we cant reduce space but we can reduce time by doing this in a single traversal
//TC-> O(n), SC-> O(n)

vector<int> rearrangeArrOptimal(vector<int> &arr){
    int n=arr.size();
    int posIndex=0, negIndex=1;
    vector<int> ans(n,0);
    for(int i=0;i<n;i++){
        if(arr[i]<0){
            ans[negIndex]=arr[i];
            negIndex+=2;
        }else{
            ans[posIndex]=arr[i];
            posIndex+=2;
        }
    }
    return ans;
}

//variety 2 : no. of +ves and -ves are not necessarily equal in the array

//we fall back to the brute solution
//TC-> O(2n) in worst case, SC-> O(n)

vector<int> rearrangeArr2(vector<int> &arr){
    int n=arr.size();
    vector<int> pos;
    vector<int> neg;
    for(int i=0;i<n;i++){
        if(arr[i]<0){
            neg.push_back(arr[i]);
        }else{
            pos.push_back(arr[i]);
        }
    }
    if(pos.size()<neg.size()){
        for(int i=0;i<pos.size();i++){
            arr[2*i]=pos[i];
            arr[2*i+1]=neg[i];
        }
        int index=pos.size()*2;
        for(int i=pos.size();i<neg.size();i++){
            arr[index]=neg[i];
            index++;
        }
    }
    else{
        for(int i=0;i<neg.size();i++){
            arr[2*i]=pos[i];
            arr[2*i+1]=neg[i];
        }
        int index=neg.size()*2;
        for(int i=neg.size();i<pos.size();i++){
            arr[index]=pos[i];
            index++;
        }
    }
    return arr;
}

int main(){
    vector<int> v1={1,2,-4,5,-2,-9};
    vector<int> v2={1,2,-4,5,-2,-9};
    vector<int> v3={1,2,-4,5,-2,-9,12,7,4};

    vector<int> ans1=rearrangeArr(v1);
    vector<int> ans2=rearrangeArrOptimal(v2);
    vector<int> ans3=rearrangeArr2(v3);

    for(int x:ans1) cout<<x<<" ";
    cout<<endl;
    for(int x:ans2) cout<<x<<" ";
    cout<<endl;
    for(int x:ans3) cout<<x<<" ";

    return 0;
}


