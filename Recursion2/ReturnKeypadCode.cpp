/*
Return Keypad Code
Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
Return empty string for numbers 0 and 1.
Note : 1. The order of strings are not important.
2. Input and output has already been managed for you. You just have to populate the output array and return the count of elements populated in the output array.
Input Format :
Integer n
Output Format :
All possible strings in different lines
Constraints :
1 <= n <= 10^6
Sample Input:
23
Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf
*/
#include <string>
using namespace std;
string mapping[10]= {" "," ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
int keypad(int num, string output[]){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */

    if(num == 0 || num == 1){
        output[0]="";
        return 1;
    }

    int rem =num%10;
    int smallproblemsize = keypad(num/10,output);

    string cpy[smallproblemsize*mapping[rem].size()];
    int k = 0;
    for(int i = 0;i<smallproblemsize;i++){
        for(int j = 0;j<mapping[rem].size();j++){
            cpy[k++] = output[i]+mapping[rem][j];
        }
    }
    for(int i=0;i<k;i++){
        output[i]=cpy[i];
    }
    return smallproblemsize*mapping[rem].size();
}

