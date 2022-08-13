/*
Merge Sort Code
Sort an array A using Merge Sort.
Change in the input array itself. So no need to return or print anything.
Input format :
Line 1 : Integer n i.e. Array size
Line 2 : Array elements (separated by space)
Output format :
Array elements in increasing order (separated by space)
Constraints :
1 <= n <= 10^3
Sample Input 1 :
6
2 6 8 5 4 3
Sample Output 1 :
2 3 4 5 6 8
Sample Input 2 :
5
2 1 5 2 3
Sample Output 2 :
1 2 2 3 5
*/



#include <iostream>
using namespace std;

void merge(int input[], int const start, int const mid, int const end)
{
    /// Declearing size
    auto const subArrayOneSize = mid-start+1;
    auto const subArrayTwoSize = end-mid;

    /// Creating two array
    auto *leftarray = new int[subArrayOneSize];
	auto *rightarray = new int[subArrayTwoSize];

    /// Copy left array element
    for(int i = 0;i<subArrayOneSize;i++)
        leftarray[i] = input[start+i];

    /// Copy rfight array element
    for(int j=0;j<subArrayTwoSize;j++)
        rightarray[j] = input[mid+1+j];

    auto indexSubArrayOne = 0;
    auto indexSubArrayTwo = 0;
    int indexMargeArray = start;

    while(indexSubArrayOne < subArrayOneSize && indexSubArrayTwo < subArrayTwoSize){
        if(leftarray[indexSubArrayOne]<=rightarray[indexSubArrayTwo]){
            input[indexMargeArray] = leftarray[indexSubArrayOne];
            indexSubArrayOne++;
        }
        else{
            input[indexMargeArray] = rightarray[indexSubArrayTwo];
            indexSubArrayTwo++;
        }
        indexMargeArray++;
    }

    while(indexSubArrayOne < subArrayOneSize){
            input[indexMargeArray] = leftarray[indexSubArrayOne];
            indexSubArrayOne++;
        	indexMargeArray++;
    }

    while(subArrayTwoSize < indexSubArrayTwo){
        input[indexMargeArray] = rightarray[indexSubArrayTwo];
        indexSubArrayTwo++;
        indexMargeArray++;
    }

}

void mergeSort(int input[],int start,int end){
    if(start >= end)
        return ;
    int mid =(start+end)/2;
    /// FOr First Half
    mergeSort(input,start,mid);
    ///For Second Half
    mergeSort(input,mid+1,end);


    merge(input,start,mid,end);


}
void mergeSort(int input[], int size){
	// Write your code here
       mergeSort(input,0,size-1);
}



int main() {
  int length;
  cin >> length;
  int* input = new int[length];
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}
