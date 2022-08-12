/*
Pair Star
Given a string S, compute recursively a new string where identical chars that are adjacent in the original string are separated from each other by a "*".
Input format :
String S
Output format :
Modified string
Constraints :
0 <= |S| <= 1000
where |S| represents length of string S.
Sample Input 1 :
hello
Sample Output 1:
hel*lo
Sample Input 2 :
aaaa
Sample Output 2 :
a*a*a*a
*/
// Change in the given string itself. So no need to return or print the changed string.

void pairStar(char input[]) {
    // Write your code here
	if(input[0]=='\0'){
        return ;
    }

    int count = 0;
    for(int i = 0;input[i]!='\0';i++){
        count++;
    }

	if(input[0] == input[1]){
        for(int i = count -1;i>=1;i--){
            input[i+1] = input[i];
        }
        input[count+1] = '\0';
        input[1] = '*';
    }

    pairStar(input+1);
}
