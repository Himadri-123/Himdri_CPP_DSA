/*
Code : Minimum Count
Send Feedback
Given an integer N, find and return the count of minimum numbers required to represent N as a sum of squares.
That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. The output will be 1, as 1 is the minimum count of numbers required to represent N as sum of squares.
Input format :
The first and the only line of input contains an integer value, 'N'.
 Output format :
Print the minimum count of numbers required
*/
#include <bits/stdc++.h>
using namespace std;

int minCount(int n)
{
	int *arr = new int[n+1];

    arr[0] = 0;
    arr[1] = 1;

    for(int i = 2;i<=n;i++){
        arr[i] = INT_MAX;
        for(int j = 1; i-(j*j) >= 0 ;++j){
            arr[i] = min(arr[i],arr[i -j*j]);
        }

        arr[i] += 1;
    }
    return arr[n];
}

/*
Memorization
int helper(int *arr,int n){
    if(sqrt(n) - floor(sqrt(n)) == 0){
        arr[n] = 1;
        return arr[n];
    }

    if(n <= 3){
        arr[n]=n;
        return n;
    }
    int ans = n;
    if(arr[n] != 0) return arr[n];
    for(int i = 1;i*i<n;i++){
        arr[n]=ans = min(ans,1+helper(arr,n-i*i));
    }
    return arr[n];
}
int minCount(int n)
{
	int *arr = new int[n+1];
    for(int i = 0;i<=n;i++){
        arr[i]= 0;
    }
    return helper(arr,n);
} */

int main()
{
	int n;
	cin >> n;
	cout << minCount(n);
}
