#include <iostream>
using namespace std;

//16. Divide two integers without using multiplication, division and mod operator

//note that if dividend=-2^31 and divisor=-1, on dividing we get 2^31 which cant be stored in int, so return INT_MAX

//Brute: keep on adding divisors until they dont exceed dividend, that count will be the ans
//tc-> O(dividend) in worst case
//if dividend = 2^31-1 and divisor=1, it will run around 2^31 times and give TLE

int divide(int dividend, int divisor){
    int sum=0, cnt=0;
    while(sum+divisor<=dividend){
        cnt++;
        sum+=divisor;
    }
    return cnt;
}

//Optimal: subtract powers of 2 multiples of divisor
//tc-> O((logn)^2), sc->O(1)

int divideOptimal(int dividend, int divisor){
    if(dividend==divisor) return 1;
    bool sign=true; //+ve 
    if(dividend>=0 && divisor<0) sign=false; //-ve
    if(dividend<0 && divisor>=0) sign=false; //-ve
    long n=abs(dividend); //use long bcz abs of -2^31 is 2^31 and cant be stored
    long d=abs(divisor);
    divisor=abs(divisor);
    long quotient=0;
    while(n>=d){
        int cnt=0;
        while(n>=(d<<(cnt+1))){
            cnt++;
        }
        quotient+=(1<<cnt);
        n-=(d<<cnt);
    }
    if(quotient == (1<<31) && sign){
        return INT_MAX;
    }
    if(quotient== (1<<31) && !sign){
        return INT_MIN;
    }
    return sign ? quotient : -quotient;
}

int main(){
    cout<<divide(22,7)<<endl;
    cout<<divideOptimal(22,7)<<endl;
    return 0;
}