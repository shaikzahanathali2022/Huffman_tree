#include <iostream> 
#include <queue> 
#include <vector> 
using namespace std; 
  
// A Huffman Tree node 	
struct MinHeapNode { 
    char data; 
    unsigned freq; 
    MinHeapNode* left, *right; 
  
    MinHeapNode(char data, unsigned freq) 
    { 
        left = right = NULL; 
        this->data = data; 
        this->freq = freq; 
    } 
}; 
  
// For comparison of two heap nodes (needed in min heap) 
struct compare { 
    bool operator()(MinHeapNode* l, MinHeapNode* r) 
    { 
        return (l->freq > r->freq); 
    } 
}; 
  
// Prints huffman codes from the root of Huffman Tree. 
void printCodes(struct MinHeapNode* root, string str) 
{ 
    if (!root) 
        return; 
    if (root->data != '$') 
        cout << root->data << ": " << str << "\n"; 
    printCodes(root->left, str + "0"); 
    printCodes(root->right, str + "1"); 
} 
  
// building a Huffman Tree and 

void Huff_man_Codes(char data[], int freq[], int size) 
{ 
    struct MinHeapNode* left, *right, *top; 
  
    // Create a min heap & inserts all characters of data[] 
    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap; 
    for (int i = 0; i < size; ++i) 
        minHeap.push(new MinHeapNode(data[i], freq[i])); 
  
    while (minHeap.size() != 1) { 
        
        left = minHeap.top(); 
        minHeap.pop(); 
  
        right = minHeap.top(); 
        minHeap.pop(); 
  
        top = new MinHeapNode('$', left->freq + right->freq); 
        top->left = left; 
        top->right = right; 
        minHeap.push(top); 
    } 
  
    // Prints Huffman codes using the Huffman tree built above 
    printCodes(minHeap.top(), ""); 
} 
  

int main() 
{ 
    char array[] = { 'a', 'b', 'c', 'd', 'e', 'f' }; 
    int freq[] = { 5, 9, 12, 13, 16, 45 }; 
    int size = sizeof(array) / sizeof(array[0]); 
  
    Huff_man_Codes(array, freq, size); 
  
    return 0; 
}
