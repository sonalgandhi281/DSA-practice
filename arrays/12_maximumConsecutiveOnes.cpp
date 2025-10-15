#include <iostream>
using namespace std;

//12. maximum consecutive ones in an array

//Optimal: traverse, maintain count that increases when 1 is found. if not 1, falls back to 0. keep updating maxlen accordingly.

//TC-> O(n), SC-> O(1)

int maxConsecutiveOnes(vector<int> &arr){
    int count=0, maxlen=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==1){
            count++;
            maxlen=max(maxlen,count);
        }else{
            count=0;
        }
    }
    return maxlen;
}

int main(){
    vector<int> a={1,1,1,0,1,1,1,1,0,0,1,1};
    cout<<maxConsecutiveOnes(a);
    return 0;
}