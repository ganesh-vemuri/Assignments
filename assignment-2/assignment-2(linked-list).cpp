#include <iostream>
using namespace std;

class Node
{
public:
    int row;
    int column;
    int data;
    Node *next;
};

void newNode(Node **p, int i, int j, int value)
{
    Node *temp = *p;
    Node *r;

    if (temp == NULL)
    {
        temp = new Node();
        temp->row = i;
        temp->column = j;
        temp->data = value;
        temp->next = NULL;
        *p = temp;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        r = new Node();
        r->row = i;
        r->column = j;
        r->data = value;
        r->next = NULL;
        temp->next = r;
    }
}

void PrintLinkedList(Node **start)
{
    Node *ptr1 = *start;
    std::cout << "row  "
            << "column  "
            << "data  "
            << "\n";
    while (ptr1 != NULL)
    {
        std::cout << ptr1->row << "\t" << ptr1->column << "\t" << ptr1->data << "\n";
        ptr1 = ptr1->next;
    }
}

int main()
{

    int sparseMatrix[4][5] = {
        {0, 0, 3, 0, 4},
        {0, 0, 5, 7, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 6, 0, 0}};

    Node *firstNode = NULL;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (sparseMatrix[i][j] != 0)
            {
                newNode(&firstNode, i, j, sparseMatrix[i][j]);
            }
        }
    }
    PrintLinkedList(&firstNode);
    return 0;
}
