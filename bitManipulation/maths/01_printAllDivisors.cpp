#include <iostream>
using namespace std;

//1. print all divisors of a given number n

//Brute: iterate from 1 to n, and check if n%i==0, if yes, it is a factor
//tc-> O(n), sc-> O(no. of divisor) only to return the ans, not solve

vector<int> divisors(int n){
    vector<int> ans;
    for(int i=1;i<=n;i++){
        if(n%i==0) ans.push_back(i);
    }
    return ans;
}

//Optimal: we know that if i is a factor, n/i will also be a factor, so we can just loop till sqrt(n) and find all factors
//tc-> O(sqrt(n)), sc-> O(no. of divisor) only to return the ans

vector<int> divisorsOptimal(int n){
    vector<int> ans;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            ans.push_back(i);
            if(n/i != i) ans.push_back(n/i);
        }
    }
    return ans;
}

int main(){
    vector<int> ans1=divisors(36);
    vector<int> ans2=divisorsOptimal(36);
    for(int x:ans1) cout<<x<<" ";
    cout<<endl;
    for(int x:ans2) cout<<x<<" ";
}