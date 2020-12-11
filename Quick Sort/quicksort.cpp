#include <bits/stdc++.h>
using namespace std;

int c=0;
int partition(vector<int> &values, int left, int right) {
    int pivotIndex = left + (right - left) / 2;
    int pivotValue = values[pivotIndex];
    int i = left, j = right;
    int temp;
    while(i <= j) {
        while(values[i] < pivotValue) {
            i++;
            c++;
        }
        while(values[j] > pivotValue) {
            j--;
            c++; 
        }
        if(i <= j) {
            temp = values[i];
            values[i] = values[j];
            values[j] = temp;
            i++;
            j--;
        }
    }
    return i;
}

void quicksort(vector<int> &values, int left, int right) {
    if(left < right) {
        int pivotIndex = partition(values, left, right);
        quicksort(values, left, pivotIndex - 1);
        quicksort(values, pivotIndex, right);
    }
}

int main()
{
	vector<int> values { 7,9,2,11,19,17,12,5,7,12 };

	cout<<"Array Initialisation- "<<endl;

	for(vector<int>::iterator it = values.begin(); it != values.end(); it++){
    	cout <<" "<< *it;
	}
	cout<<endl;

	quicksort(values, 0, values.size() - 1);

	cout<<"After QuickSort- "<<endl;

	for(vector<int>::iterator it = values.begin(); it != values.end(); it++){
    	cout <<" "<< *it;
	}
	cout<<endl;
	cout<<"Number of comparison "<<c<<endl;

	return 0;
}