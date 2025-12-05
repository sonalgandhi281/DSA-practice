#include <iostream>
using namespace std;

//not based on monotonic stack

//Given an array of non-negative integers representation elevation of ground. Your task is to find the water that can be trapped after rain .

//Brute: for every index(building), water trapped would be min of max heights on left and right - height of the index

//tc-> O(n^2), sc-> O(1)

int trap(vector<int> &arr){
    int n=arr.size();
    int tot=0;
    for(int i=0;i<n;i++){
        int maxLeft=0, maxRight=0;
        for(int j=0;j<=i;j++){
            if(arr[j]>maxLeft){
                maxLeft=arr[j];
            }
        }
        for(int j=i;j<n;j++){
            if(arr[j]>maxRight){
                maxRight=arr[j];
            }
        }
        tot+=min(maxLeft,maxRight)-arr[i];
    }
    return tot;
}

//Better:

//the soln above takes n^2 time. the loop i from 0 to n cant be reduced bcz water trapped is to be calculated for every building. 
//so, we try to reduce the calc of maxleft and maxright.

//instead of calculating using nested loops, we calculate prefixMax and suffixMax and store them.

//tc-> O(3n), sc-> O(2n)

int trapBetter(vector<int> &arr){
    int n=arr.size();
    vector<int> prefixMax(n), suffixMax(n);
    prefixMax[0]=arr[0];
    suffixMax[n-1]=arr[n-1];
    for(int i=1;i<n;i++){ //O(n)
        prefixMax[i]=max(prefixMax[i-1],arr[i]);
    }
    for(int i=n-2;i>=0;i--){ //O(n)
        suffixMax[i]=max(suffixMax[i+1],arr[i]);
    }
    int water=0;
    for(int i=0;i<n;i++){ //O(n)
        int leftmax=prefixMax[i], rightmax=suffixMax[i];
        if(arr[i]<leftmax && arr[i]<rightmax){
            water+=min(leftmax,rightmax)-arr[i];
        }
    }
    return water;
}

//we can reduce above sc to O(n) by taking only suffixMax array, and we can calculate prefixMax while traversing array
//tc-> O(2n), sc-> O(n)

int trapBetter2(vector<int>& height) {
    int n=height.size();
    int water=0;
    vector<int> suffixMax(n);
    suffixMax[n-1]=height[n-1];
    for(int i=n-2;i>=0;i--){
        suffixMax[i]=max(suffixMax[i+1],height[i]);
    }
    int leftmax=height[0];
    for(int i=0;i<n;i++){
        leftmax=max(leftmax,height[i]);
        int rightmax=suffixMax[i];
        if(height[i]<leftmax && height[i]<rightmax){
            water+=min(leftmax,rightmax)-height[i];
        }
    }
    return water;
}

//Optimal: we want to optimize the space. 

//note that to calculate the water trapped, i either need leftmax or rightmax, depending on whose value is smaller

//do a two way traversal, take leftmax=0, rightmax=0, total=0, initially. then take l pointer at beginning of array and r pointer at last element of array.

//we traverse smaller side first

//if l<=r (water depends on left side's max) bcz i have taller building on right. water stored will be leftmax-arr[l]

//otherwise, depends on right side's max

//l==r wale case ko kisi me bhi include kar skte h

//tc-> O(n), sc-> O(1)

int trapOptimal(vector<int> &height){
    int n=height.size();
    int l=0, r=n-1;
    int leftmax=0, rightmax=0, total=0;
    while(l<r){
        if(height[l]<=height[r]){
            if(leftmax>height[l]) total+=leftmax-height[l];
            else leftmax=height[l];
            l++;
        }
        else{
            if(rightmax>height[r]) total+=rightmax-height[r];
            else rightmax=height[r];
            r--;
        }
    }
    return total;
}

int main(){
    vector<int> v={0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<trap(v)<<endl;
    cout<<trapBetter(v)<<endl;
    cout<<trapBetter2(v)<<endl;
    cout<<trapOptimal(v)<<endl;
}
    

