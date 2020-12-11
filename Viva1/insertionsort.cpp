#include <bits/stdc++.h>
using namespace std;

long c=0;
void printArray(vector<int>values) {
  for (int i = 0; i < values.size(); i++) {
    cout << values[i] << " ";
  }
  cout << endl;
}

void insertionSort(vector<int> &values, int size) {
  for (int step = 1; step < size; step++) {
    int key = values[step];
    int j = step - 1;

    while (key < values[j] && j >= 0) {
      values[j + 1] = values[j];
      --j;
      ++c;
    }
    ++c;
    values[j + 1] = key;
  }
}

int main() {
  vector<int> values;
  for(int i = 0; i < 10000; i++) {
    values.push_back(rand() % 100);
  }
  sort(values.begin(),values.end());
//   for(int i = 0; i < 10000; i++) {
//     values[i] = - values[i]; 
//   }
  insertionSort(values,values.size());
//   cout << "Sorted array in ascending order:\n";
//   printArray(values);
  cout<<"Comparisons \t"<<c<<endl;
}