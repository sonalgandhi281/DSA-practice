#include<iostream>
using namespace std;

//34. Merge 2 sorted arrays without extra space

//Brute: merge sort lgake ek temp array me elements daldo fir vapis original array me sorted elements

//TC-> O(2*(n1+n2)), SC-> O(n1+n2)

void merge(vector<int> &a1, vector<int> &a2){
    int n1=a1.size(), n2=a2.size();
    vector<int> temp;
    int left=0, right=0;
    while(left<n1 && right<n2){
        if(a1[left]<=a2[right]){
            temp.push_back(a1[left]);
            left++;
        }else{
            temp.push_back(a2[right]);
            right++;
        }
    }
    while(left<n1){
        temp.push_back(a1[left]);
        left++;
    }
    while(right<n2){
        temp.push_back(a2[right]);
        right++;
    }
    for(int i=0;i<n1+n2;i++){
        if(i<n1) a1[i]=temp[i];
        else a2[i-n1]=temp[i];
    }
}

//Optimal soln 1 
//since we know everyting is sorted, we know last element of a1 is largest in a1, and, first element of a2 is smallest in a2. we compare and swap accordingly. then sort both arrays.

//TC-> O(min(n1,n2))+O(n1logn1+n2logn2), SC-> O(1)

void mergeOptimal1(vector<int> &a1, vector<int> &a2){
    int n1=a1.size();
    int n2=a2.size();
    int left=n1-1;
    int right=0;
    while(left>=0 && right<n2){
        if(a1[left]>a2[right]){
            swap(a1[left],a2[right]);
            left--;
            right++;
        }else{
            break;
        }
    }
    sort(a1.begin(),a1.end());
    sort(a2.begin(),a2.end());
}

//Optimal soln 2
//based on gap method in shell sort

//sum up size of both arrays and divide by 2, take ceiling value of it and take it as the initial gap.
//keep 2 pointers gap distance away & compare elements.

//whenever right pointer moves out of boundary, we divide gap by 2 and take ceil value and repeat the process.

//TC-> O(log2(n1+n2))+O(n1+n2), SC-> O(1)


void swapIfGreater(vector<int>&a1, vector<int>&a2, int ind1, int ind2){
    if(a1[ind1]>a2[ind2]){
        swap(a1[ind1],a2[ind2]);
    }
}

void mergeOptimal2(vector<int> &a1, vector<int> &a2){
    int n1=a1.size();
    int n2=a2.size();
    int len=n1+n2;
    int gap=(len/2)+(len%2);
    while(gap>0){
        int left=0;
        int right=left+gap;
        while(right<len){
            //comparing a1 and a2 elements
            if(left<n1 && right>=n1){
                swapIfGreater(a1,a2,left,right-n1);
            }
            //comparing a2 and a2 elements
            else if(left>=n1){
                swapIfGreater(a2,a2,left-n1,right-n1);
            }
            //comparing a1 and a1 elements
            else{
                swapIfGreater(a1,a1,left,right);
            }
            left++;
            right++;
        }
        if(gap==1) break;
        gap=(gap/2)+(gap%2);
    }
}


int main(){
    vector<int> v1={1,3,5,7};
    vector<int> v2={0,2,6,8,9};

    merge(v1,v2);
    for(int x:v1) cout<<x<<" ";
    for(int x:v2) cout<<x<<" ";
    cout<<endl;

    vector<int> v3={1,3,5,7};
    vector<int> v4={0,2,6,8,9};

    mergeOptimal1(v3,v4);
    for(int x:v3) cout<<x<<" ";
    for(int x:v4) cout<<x<<" ";
    cout<<endl;

    vector<int> v5={1,3,5,7};
    vector<int> v6={0,2,6,8,9};

    mergeOptimal2(v5,v6);
    for(int x:v5) cout<<x<<" ";
    for(int x:v6) cout<<x<<" ";
    cout<<endl;

    return 0;
}
