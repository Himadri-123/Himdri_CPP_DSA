/*
Remove X
Given a string, compute recursively a new string where all 'x' chars have been removed.
Input format :
String S
Output format :
Modified String
Constraints :
1 <= |S| <= 10^3
where |S| represents the length of string S.
Sample Input 1 :
xaxb
Sample Output 1:
ab
Sample Input 2 :
abc
Sample Output 2:
abc
Sample Input 3 :
xx
Sample Output 3:
*/

// Change in the given string itself. So no need to return or print anything

void removeX(char input[]) {
    int count = 0;
    for(int i = 0;input[i]!='\0';i++){
        count++;
    }

    if(input[0] == '\0'){
        return;
    }

    if(input[0] == 'x'){
        for(int i=0;i<count-1;i++){
            input[i] = input[i+1];
        }
        input[count-1] = '\0';
        removeX(input);
    }
    else{
        removeX(input+1);
    }

}
