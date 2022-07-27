/*
Code : No. of balanced BTs using DP
Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.
This number can be huge, so, return output modulus 10^9 + 7.
Time complexity should be O(h).
Input Format :
The first and only line of input contains an integer, that denotes the value of h. Here, h is the height of the tree.
Output Format :
The first and only line of output contains the count of balanced binary trees modulus 10^9 + 7.
Constraints :
1 <= h <= 10^6
Time Limit: 1 sec
Sample Input 1:
3
Sample Output 1:
15
*/


#include <iostream>
using namespace std;

#include<bits/stdc++.h>
int balancedBTs(int n) {
    // Write your code here
    int *arr = new int[n+1];
    arr[1] = 1;
    arr[2] = 3;

    int mod = (int)(pow(10,9))+7;
    for(int i = 3;i<=n;i++){
        arr[i]=(int)( ( (long)(arr[i-1])*arr[i-1] )%mod + (2*(long)(arr[i-1])*arr[i-2])%mod  ) % mod;
    }
    return arr[n];
}


int main() {
    int n;
    cin >> n;
    cout << balancedBTs(n);
}
