#include <iostream>
#include<unordered_set>
using namespace std;

//23. find the longest consecutive sequence in an array

//eg: [102,4,100,1,101,3,2,1,1], we have 1,2,3,4 so length=4, 100,101,102 length=3, longest consecutive sequence = 4

//Brute: for each element x i try to find x+1, x+2 and so on to find longest seq possible for every element. and out of them i will return longest consecutive seq.

//TC-> O(n^2), SC-> O(1)

bool linearSearch(vector<int> &arr, int num){
    int n=arr.size();
    for(int i=0;i<n;i++){
        if(arr[i]==num) return true;
    }
    return false;
}

int lcs(vector<int> &arr){
    int n=arr.size();
    int longest=1;
    for(int i=0;i<n;i++){
        int el=arr[i];
        int count=1;
        while(linearSearch(arr,el+1)==true){
            el+=1;
            count++;
        }
        longest=max(longest,count);
    }
    return longest;
}

//Better: sort the array, keep track of last smaller. iterate, check if element can be part of seq by checking last smaller. find lcs.
//TC-> O(nlogn+n), SC-> O(1)

int lcsBetter(vector<int>&arr){
    int n=arr.size();
    sort(arr.begin(),arr.end());
    int longest=1, count=0, last_smallest=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]-1==last_smallest){
            last_smallest=arr[i];
            count++;
        }else if(arr[i]!=last_smallest){
            last_smallest=arr[i];
            count=1;
        }
        longest=max(longest,count);
    }
    return longest;
}
//here, in the better soln, we are distorting the array, which the interviewer might not like. so, he might ask to get rid of nlogn or not distort the array. this is where optimal soln comes in.

//Optimal: (only optimal under some constraints)

//iterate and put everything into unordered set ds. 
//for each element x check if we have x-1, if yes, we dont check sequence for x since it cant be 1st element.
//this narrows down search and improves efficiency 

//TC-> O(3n), SC-> O(n)

int lcsOptimal(vector<int> &arr){
    int n=arr.size();
    if(n==0) return 0;
    int longest=1;
    unordered_set<int>st;
    for(int i=0;i<n;i++){
        st.insert(arr[i]);
    }
    for(auto it:st){
        if(st.find(it-1)==st.end()){
            int x=it;
            int count=1;
            while(st.find(x+1)!=st.end()){
                x+=1;
                count++;
            }
            longest=max(longest,count);
        }
    }
    return longest;
}

int main(){
    vector<int> v={102,4,100,1,101,3,2,1,1};
    cout<<lcs(v)<<endl;
    cout<<lcsBetter(v)<<endl;
    cout<<lcsOptimal(v)<<endl;

    return 0;
}