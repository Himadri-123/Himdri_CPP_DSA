/*
Code : Staircase using Dp
A child is running up a staircase with n steps and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count how many possible ways the child can run up to the stairs. You need to return all possible number of ways.
Time complexity of your code should be O(n).
Since the answer can be pretty large print the answer % mod(10^9 +7)
Input Format:
First line will contain T (number of test case).
Each test case is consists of a single line containing an integer N.
Output Format:
For each test case print the answer in new line
*/
#include<bits/stdc++.h>
using namespace std;
// int helper(int *arr,int n){
//     if(n == 0){
//         return 1;
//     }
//     else if(n < 0)
//         return 0;
//     if(arr[n]!=-1){
//         return arr[n];
//     }

//     arr[n] =helper(arr,n-3)+helper(arr,n-2)+helper(arr,n-1);
//     return arr[n];
// }
long long mod = pow(10,9) + 7;
int staircase(int n){
     long *arr = new long[n+1];
    // for(int i = 0;i<=n;i++){
    //     arr[i] = -1;
    // }
        arr[0] = 1;
        arr[1] = 1;
        arr[2] = 2;
    for(int i = 3;i<=n;i++){
        arr[i] = (arr[i-1] % mod +arr[i-2]%mod+arr[i-3]%mod)%mod;
    }
    return arr[n];
    //return helper(arr,n);
}
int main(){

    // write your code here
    int t;
    cin >> t;
    while(t--){
        int n ;
        cin >> n;
        cout << staircase(n)<<endl;
    }
    return 0;
}
