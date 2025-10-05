#include <iostream>
using namespace std;

//7. move all zeros to the end of the array

//Brute : traverse array, store all non-zero no.s somewhere. then put them back in front of the array, fill all remaining positions w 0
//TC-> O(2n), SC-> O(nz)

void moveZeros(vector<int> &arr){
    int n=arr.size();
    vector<int> temp;
    for(int i=0;i<n;i++){
        if(arr[i]!=0) temp.push_back(arr[i]);
    }

    int nz=temp.size();
    for(int i=0;i<nz;i++){
        arr[i]=temp[i];
    }

    for(int i=nz;i<n;i++){
        arr[i]=0;
    }
}

//Optimal : 2 pointer approach. j points to first zero. i points to first non zero no. after j. swap i and j.
//TC-> O(n), SC-> O(1)

void moveZerosOptimal(vector<int> &arr){
    int n=arr.size();
    int j=-1;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            j=i;
            break;
        }
    }
    if(j==-1) return;
    for(int i=j+1;i<n;i++){
        if(arr[i]!=0){
            swap(arr[i],arr[j]);
            j++;
        }
    }
}

int main(){
    vector<int> arr1={1,2,0,5,3,0};
    vector<int> arr2={1,2,0,5,3,0};
    moveZeros(arr1);
    moveZerosOptimal(arr2);
    for(int x:arr1) cout<<x<<" ";
    cout<<endl;
    for(int x:arr2) cout<<x<<" ";
    return 0;
}