/*
Code : Min Steps to 1 using DP
Given a positive integer 'n', find and return the minimum number of steps that 'n' has to take to get reduced to 1. You can perform any one of the following 3 steps:
1.) Subtract 1 from it. (n = n - ­1) ,
2.) If n is divisible by 2, divide by 2.( if n % 2 == 0, then n = n / 2 ) ,
3.) If n is divisible by 3, divide by 3. (if n % 3 == 0, then n = n / 3 ).
Input format :
The first and the only line of input contains an integer value, 'n'.
Output format :
Print the minimum number of steps.
Constraints :
1 <= n <= 10 ^ 6
Time Limit: 1 sec
*/

#include <bits/stdc++.h>
using namespace std;
int helper(int *arr,int n){
     int x = 2424563,y = 2424563,z =2424563;
    if(n <=1)
        arr[n] = 0;

    if( arr[n] != - 1){
        return arr[n];
    }


    if(n%3 == 0)
        x = helper(arr,n / 3);
    if(n%2 == 0)
    	y = helper(arr,n / 2);

    z = helper(arr,n-1);

    int count1 = min(x,y);
    int count2 = min(count1,z);

    arr[n] = count2+1;
    return arr[n];

}
int countStepsToOne(int n)
{
	//Write your code here
    int *arr= new int[n+1];
    for(int i = 0;i<=n;i++){
        arr[i] = -1;
    }
	return helper(arr,n);
}

int main()
{
	int n;
	cin >> n;
	cout << countStepsToOne(n);
}
