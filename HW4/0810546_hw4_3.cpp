#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

// A Huffman tree node
struct Node
{
    char ch;
    int freq;
    Node *left, *right;
    Node(char c, int f) : ch(c), freq(f), left(NULL), right(NULL) {}
    ~Node()
    {
        delete left;
        delete right;
    }
};

// Comparison function for priority queue
struct Compare
{
    bool operator()(Node *a, Node *b)
    {
        return a->freq > b->freq;
    }
};

// Build a Huffman tree from the frequency map
Node *buildHuffmanTree(const unordered_map<char, int> &freq)
{
    priority_queue<Node *, vector<Node *>, Compare> pq;
    for (auto it = freq.begin(); it != freq.end(); ++it)
    {
        pq.push(new Node(it->first, it->second));
    }
    while (pq.size() > 1)
    {
        Node *left = pq.top();
        pq.pop();
        Node *right = pq.top();
        pq.pop();
        Node *parent = new Node('\0', left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        pq.push(parent);
    }
    return pq.top();
}

// Traverse the Huffman tree to generate the codes for each character
void traverseHuffmanTree(Node *root, string code, unordered_map<char, string> &codes)
{
    if (root->left == NULL && root->right == NULL)
    {
        codes[root->ch] = code;
    }
    else
    {
        traverseHuffmanTree(root->left, code + "0", codes);
        traverseHuffmanTree(root->right, code + "1", codes);
    }
}

int main()
{
    // Step 1: Calculate the frequency of each character in the message
    string message;
    getline(cin, message, '#');
    unordered_map<char, int> freq;
    for (char ch : message)
    {
        freq[ch]++;
    }

    // Step 2-3: Build the Huffman tree
    Node *root = buildHuffmanTree(freq);

    // Step 4: Traverse the tree to generate the codes for each character
    unordered_map<char, string> codes;
    traverseHuffmanTree(root, "", codes);

    // Step 5-7: Calculate the size of the compressed message and print the compression rate
    int compressed_size = 0;
    for (char ch : message)
    {
        compressed_size += codes[ch].size();
    }
    int original_size = message.size() * 8;
    double compression_rate = 100.0 * compressed_size / original_size;
    cout << compressed_size << " / " << original_size << endl;
    return 0;
}
