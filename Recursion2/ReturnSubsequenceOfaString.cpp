/*
INPUT : ABC

OUTPUT :  C B BC A AC AB ABC
*/
#include<iostream>
using namespace std;
int substr(string str,string output[]){
    if(str.empty()){
        output[0]="";
        return 1;
    }

    string smallstring = str.substr(1);
    int smalloutputsize = substr(smallstring,output);
    for(int i = 0;i<smalloutputsize;i++){
        output[i+smalloutputsize] = str[0]+output[i];
    }
    return 2*smalloutputsize;
}

int main(){
    string input;
    cin >> input;

    string *output = new string[1000];
    int count = substr(input,output);
    for(int i = 0;i<count;i++){
        cout<<output[i]<<" ";
    }
}
