#include <bits/stdc++.h>
using namespace std;

struct Node
{
    char character;
    unsigned frequency;
    Node *leftPointer, *rightPointer;
    Node(char character, unsigned frequency)
    {
        leftPointer = rightPointer = NULL;
        this->character = character;
        this->frequency = frequency;
    }
};

struct heapObjCompare
{
    bool operator()(Node *l, Node *r){return (l->frequency > r->frequency);}
};

void printHuffman(struct Node *root, string s)
{
    if (!root)
        return;

    if (root->character != '$')
        cout << root->character << ": " << s << "\n";

    printHuffman(root->leftPointer, s + "0");
    printHuffman(root->rightPointer, s + "1");
}

void createHeap(char character[], int frequency[], int size)
{
    struct Node *leftPointer, *rightPointer, *top;
    priority_queue<Node *, vector<Node *>, heapObjCompare> minHeap;
    for (int i = 0; i < size; ++i)
        minHeap.push(new Node(character[i], frequency[i]));

    while (minHeap.size() != 1)
    {
        leftPointer = minHeap.top();
        minHeap.pop();
        rightPointer = minHeap.top();
        minHeap.pop();
        top = new Node('$', leftPointer->frequency + rightPointer->frequency);
        top->leftPointer = leftPointer;
        top->rightPointer = rightPointer;
        minHeap.push(top);
    }
    printHuffman(minHeap.top(), "");
}

int main()
{
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int frequency[] = {5, 9, 12, 13, 16, 45};
    createHeap(arr, frequency, (int)(sizeof(arr) / sizeof(arr[0])));
    return 0;
}