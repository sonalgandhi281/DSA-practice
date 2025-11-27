#include <iostream>
using namespace std;

//3. print prime factors of a number

bool prime(int n){
    for(int i=2;i*i<=n;i++){
        if((n%i)==0) return false;
    }
    return true;
}

//Brute:
//tc-> O(n * sqrt(n)), sc-> O(no. of prime factors) (variable) (only to return ans)

vector<int> primeFactors(int n){
    vector<int> ans;
    for(int i=2;i<=n;i++){
        if(n%i==0){
            if(prime(i)){
                ans.push_back(i);
            }
        }
    }
    return ans;
}

//Better:
//tc-> O(sqrt(n) * 2 * sqrt(n)) note that we cant exactly predict tc bcz there is if condition and we are not checking prime for every integer

vector<int> primeFactorsBetter(int n){
    vector<int> ans;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            if(prime(i)){
                ans.push_back(i);
            }
            if((n/i)!=i){
                if(prime(n/i)){
                    ans.push_back(n/i);
                }
            }
        }
    }
    return ans;
}

//Optimal: 
//tc-> O(sqrt(n) * logn) , logn for division, sc-> O(no. of prime factors)

vector<int> primeFactorsOptimal(int n){
    vector<int> ans;
    for(int i=2;i*i<=n;i++){ 
        if(n%i==0){
            ans.push_back(i);
            while(n%i==0){
                n=n/i;
            }
        }
    }
    if(n!=1) ans.push_back(n); //incase no. itself is prime
    return ans;
}

int main(){
    vector<int> ans1=primeFactors(12);
    vector<int> ans2=primeFactors(12);
    vector<int> ans3=primeFactors(12);
    for(int x:ans1) cout<<x<<" ";
    cout<<endl;
    for(int x:ans2) cout<<x<<" ";
    cout<<endl;
    for(int x:ans3) cout<<x<<" ";
}