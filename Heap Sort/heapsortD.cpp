#include <bits/stdc++.h> 
using namespace std; 

int main() 
{ 
    vector<int> v { 7,9,2,11,19,17,12,5,7,12 };
   
    make_heap(v.begin(), v.end(),greater<int>());               // MIN HEAP
   
    cout << "Heap Initialisation- "; 
    for (auto i : v) { 
     cout << i << ' '; 
    }    
   
    sort_heap(v.begin(), v.end(),greater<int>());                              
   
    cout <<endl<< "Reverse Sorted Heap- ";
    for (auto i : v) {                                                    
        cout << i << ' '; 
    }    
    cout <<endl; 
} 