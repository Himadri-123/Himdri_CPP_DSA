/*
Quick Sort Code
Sort an array A using Quick Sort.
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
1 5 2 7 3
Sample Output 2 :
1 2 3 5 7
*/
#include<iostream>
using namespace std;

/*
	To apply the method explained in the hint video, we have to add two more parameters in the function call. This can be done by calling a helper function from given function. The helper function can have three parameters: array, start index, end index.

	Skeleton code to achieve this:
	#include <iostream>
	using namespace std;

	void quickSort(int input[], int start, int end)
	{
    		// your code goes here
	}
	void quickSort(int input[], int size)
	{
    		quickSort(input, 0, size - 1);
	}

*/
void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}
int partition(int input[],int start,int end){
    int count = 0;
    int pivot = input[start];
    for(int i = start+1;i<=end;i++){
        if(input[i] <= pivot)
            count++;
    }
    int pivotPosition = start+count;
    swap(input[start],input[pivotPosition]);

    int i = start;
    int j = end;

    while(i<pivotPosition && j>pivotPosition){
        if(input[i] <= pivot){
            i++;
        }
        else if(input[j] > pivot){
            j--;
        }
        else{
            swap(input[i],input[j]);

            	i++;
            	j--;
        }
    }
    return pivotPosition;
}
void quickSort(int input[], int start, int end)
	{
    	/// Base Case
    	if(start>=end)
            return;

    		int c = partition(input,start,end);

    		quickSort(input,start,c-1);
    		quickSort(input,c+1,end);
    return;
	}
void quickSort(int input[], int size) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Change in the given array itself.
     Taking input and printing output is handled automatically.
  */
	quickSort(input, 0, size - 1);
}


int main(){
    int n;
    cin >> n;

    int *input = new int[n];

    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }

    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }

    delete [] input;

}


