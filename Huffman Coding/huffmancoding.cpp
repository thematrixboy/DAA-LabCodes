#include <bits/stdc++.h> 
using namespace std; 

struct MinHeapNode { 
    char data; 
    unsigned int freq; 
    MinHeapNode *left, *right; 
    MinHeapNode(char data, unsigned freq) 
    { 
        left = right = NULL; 
        this->data = data; 
        this->freq = freq; 
    } 
}; 
struct compare { 
    bool operator()(MinHeapNode* l, MinHeapNode* r){ 
        return (l->freq > r->freq); 
    }
}; 
void printCodes(struct MinHeapNode* root, string str) 
{ 
    if (!root) 
        return; 

    if (root->data != 'N') 
        cout << root->data << ": " << str << " "; 
  
    printCodes(root->left, str + "0"); 
    printCodes(root->right, str + "1"); 
} 
void HuffmanCodes(char data[], int freq[], int size) 
{ 
    struct MinHeapNode *l, *r, *top; 
    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap; 
  
    for (int i = 0; i < size; ++i) 
        minHeap.push(new MinHeapNode(data[i], freq[i])); 
  
    while (minHeap.size() != 1) { 

        l = minHeap.top(); 
        minHeap.pop(); 
  
        r = minHeap.top(); 
        minHeap.pop(); 
  
        top = new MinHeapNode('N', l->freq + r->freq); 
  
        top->left = l; 
        top->right = r; 
  
        minHeap.push(top); 
    } 
    printCodes(minHeap.top(),""); 
} 
int main() 
{ 
    char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' }; 
    int freq[] = { 45, 13, 12, 16, 9, 5 }; 

    int size = sizeof(arr) / sizeof(arr[0]); 
  	cout<<"Huffman Codes- "<<endl;
    HuffmanCodes(arr, freq, size); 
    cout<<endl;
    return 0; 
} 