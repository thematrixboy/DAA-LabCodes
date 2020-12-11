#include <iostream>
#include <vector>
using namespace std;

int count = 0;
void print(vector<int> v)
{
  for(int i = 0; i < v.size(); i++)
      cout << v[i] << " ";
  cout << endl;
}

void max_heapify(vector<int>& arr, int i, int size)
{
    int largest, l = (2*i) + 1, r = (2*i) + 2;  

    if(l < size && arr[l] > arr[i])
     { 
        count++;
        largest = l;
     }
    else
     { 
        count++;
        largest = i;
     }

    if(r < size && arr[r] > arr[largest])
    { 
        count++;
        largest = r;
    }

    if(largest != i)
    {
        swap(arr[i], arr[largest]);
        max_heapify(arr, largest, size);
    }

}

void build_max_heap(vector<int>& arr)
{
   int i;
   for(i = (arr.size() / 2); i >= 0; i--)
   max_heapify(arr, i, arr.size());
   
   cout<<"\nMax-Heap- "<<endl;
   print(arr);
}

void heap_sort(vector<int>& arr)
{
   build_max_heap(arr);
   int size = arr.size();
   for(int i = arr.size() - 1; i > 0; i--)
   {
        swap(arr[0], arr[i]);
        size--;
        max_heapify(arr, 0, size);
    }
}

int main()
{

     vector<int> arr { 7,9,2,11,19,17,12,5,7,12 };

     cout<<"Array Initialisation- "<<endl;
     print(arr);
   
     heap_sort(arr);
     cout<<"\nAfter HeapSort- "<<endl;
     print(arr);
   
     cout<<"\nNo of comparisons- "<<count<<endl;
     return 0;
}