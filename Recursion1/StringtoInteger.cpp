/*
String to Integer
Write a recursive function to convert a given string into the number it represents. That is input will be a numeric string that contains only numbers, you need to convert the string into corresponding integer and return the answer.
Input format :
Numeric string S (string, Eg. "1234")
Output format :
Corresponding integer N (int, Eg. 1234)
Constraints :
0 < |S| <= 9
where |S| represents length of string S.
Sample Input 1 :
00001231
Sample Output 1 :
1231
Sample Input 2 :
12567
Sample Output 2 :
12567
*/
int pow(int num,int len){
    if(len == 0)
        return 1;
    return num*pow(num,len-1);
}
int stringToNumber(char input[]) {
    // Write your code here

    int count=0;
    for(int j = 0;input[j]!='\0';j++){
        count++;
    }
	if(input[0]=='\0'){
        return 0;
    }

    return (input[0]-'0')*pow(10,count-1)+stringToNumber(input+1);


}


