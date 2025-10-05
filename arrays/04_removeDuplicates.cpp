#include <iostream>
#include <set>
using namespace std;

//4. remove duplicates in-place from sorted array and return no. of unique elements

//Brute : traverse array, put all elements in set, set will have unique elements only, put them back in array, return no. of unique elements
//TC-> O(nlogn+n), SC-> O(n)

int removeDuplicates(vector<int> &arr){
    int n=arr.size();
    set<int> st;
    for(int i=0;i<n;i++){
        st.insert(arr[i]); //insertion in set takes logn time
    }
    int index=0;
    for(auto it:st){
        arr[index++]=it;
    }
    return index;
}

//Optimal : 2 pointer approach. 1st element will always be unique so place first pointer there. then traverse array with 2nd pointer to find element different than 1st pointer element.
//TC-> O(n), SC-> O(1)

int removeDuplicatesOptimal(vector<int>& arr){
    int n=arr.size();
    int i=0;
    for(int j=1;j<n;j++){
        if(arr[j]!=arr[i]){
            arr[i+1]=arr[j];
            i++;
        }
    }
    return (i+1);
}

int main(){
    vector<int> arr1={2,2,2,3,3,4,5,5};
    vector<int> arr2=arr1;
    cout<<"No. of unique elements: "<<removeDuplicates(arr1)<<endl;
    cout<<"No. of unique elements: "<<removeDuplicatesOptimal(arr2)<<endl;
    return 0;
}