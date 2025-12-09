#include <iostream>
using namespace std;

// A celebrity is the person everyone knows but who doesnt know anyone
//given nxn matrix, m[i][j]=1 if i knows j, otherwise 0.
//determine the celebrity, return its index. if no celebrity, return -1.

//Brute: i can maintain two arrays that store count of how many people know someone and how many people that person knows. then if for anyone it matches with knows 0 and known by n-1, return.

//tc-> O(n^2), sc-> O(2n)

int celeb(vector<vector<int>> &mat){
    int n=mat.size();
    vector<int> knows(n,0);
    vector<int> known(n,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]==1){
                knows[i]++;
                known[j]++;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(knows[i]==0 && known[i]==n-1) return i;
    }
    return -1;
}

//Optimal: each comparison can help us in eliminating a candidate. if a knows b, a cant be the candidate and if a doesnt know b, b cant be the candidate.
//so, with n-1 comparisons, we can get the ans

//tc-> O(2n), sc-> O(1)

int celebOptimal(vector<vector<int>> &mat){
    int n=mat.size();
    int top=0, down=n-1;
    while(top<down){
        if(mat[top][down]==1) top++;
        else if(mat[down][top]==1) down--;
        else{
            top++;
            down--;
        }
    }
    if(top>down) return -1;
    for(int i=0;i<n;i++){
        if(i==top) continue;
        if(mat[top][i]==1 || mat[i][top]==0) return -1;
    }
    return top;
}

int main(){
    vector<vector<int>> M = {
         {0, 1, 1, 0}, 
         {0, 0, 0, 0}, 
         {1, 1, 0, 0}, 
         {0, 1, 1, 0}
    };
    cout<<celeb(M)<<endl;
    cout<<celebOptimal(M);
}