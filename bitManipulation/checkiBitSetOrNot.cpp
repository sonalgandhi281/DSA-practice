#include <iostream>
using namespace std;

//1. check if ith bit is set or not

// Given two integers n and i, return true if the ith bit in the binary representation of n (counting from the least significant bit, 0-indexed) is set (i.e., equal to 1). Otherwise, return false.

//Brute: convert to binary and then check
//tc-> O(logn) to convert, sc-> O(logn) to store conversion

bool checkIthBit(int n, int i){
    string bin="";
    while(n>0){
        bin+=(n%2==0 ? '0' : '1');
        n/=2;
    }
    if(i>=bin.size()) return false;
    return bin[i]=='1';
}

//Optimal: left shift 1 by i places, this will give 1 at ith place and 0 at all other places. do AND operation with number, if ith place is 1, it will give a no. greater than 0.

bool checkIthBitOptimal(int n, int i){
    return (n & (1<<i)) != 0;
}