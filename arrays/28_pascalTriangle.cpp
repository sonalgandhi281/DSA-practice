#include<iostream>
using namespace std;

//28. Pascal Triangle

//types of problems can be :

//1. given row and col no., tell element at that place.

//note that: (R-1) C (C-1) gives element at R and C.
//nCr = n!/(r! x (n-r)!)
// but if we notice num and den get cancelled to some extent, so we apply shortcut. 

//eg for 10C3 = 10x9x8 / 3x2x1
//we implement these by for loops
//10/1 x 9/2 x 8/3

//TC-> O(r), SC-> O(1)
int findPascalElement(int row, int col){
    int n=row-1;
    int r=col-1;
    int result=1;
    for(int i=0;i<r;i++){
        result*=(n-i);
        result/=(i+1);
    }
    return result;
}

//2. print any nth row of the pascal triangle

//Brute: note that nth row will always have n elements. we know that every element has formula (R-1)C(C-1). so extreme brute force can be that we iterate col n times and print each element using this formula.
//TC-> O(nxr)

//Optimize: on observing pattern, we derive formula.
//TC-> O(N), SC-> O(1)

vector<int> getNthRow(int N){
    vector<int> row;
    int ans=1;
    row.push_back(ans);
    for(int i=1;i<N;i++){
        ans*=(N-i);
        ans/=i;
        //note: (N-i)/i dont do this directly bcz it does integer division and truncates decimals and gives wrong result
        row.push_back(ans);
    }
    return row;
} 


//3. given n, print entire pascal triangle
//not pattern printing. we just have to return nested list.

//Brute: using (R-1)C(C-1)
//TC-> O(nxnxr) equivalent to O(n^3)

vector<vector<int>> generatePascalTriangle(int N){
    vector<vector<int>> triangle;
    for(int row=1;row<=N;row++){
        vector<int> temp;
        for(int col=1;col<=row;col++){
            temp.push_back(findPascalElement(row,col));
        }
        triangle.push_back(temp);
    }
    return triangle;
}

//Optimize: using the method to generate row
//TC-> O(n^2)

vector<vector<int>> pascalTriangle(int N){
    vector<vector<int>> triangle;
    for(int i=1;i<=N;i++){
        vector<int> temp = getNthRow(i);
        triangle.push_back(temp);
    }
    return triangle;
}

//note: maintain good code quality by breaking problem into functions

int main(){
    int N=6;
    vector<vector<int>> ans1=generatePascalTriangle(N);
    vector<vector<int>> ans2=pascalTriangle(N);

    for(auto x: ans2){
        for(int y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    vector<int> row=getNthRow(5);
    for(int x:row) cout<<x<<" ";

    cout<<endl;

    cout<<findPascalElement(3,2);

    return 0;

}