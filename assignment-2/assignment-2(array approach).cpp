#include <iostream>
#include <vector>

using namespace std;
void solution1(int sparse[4][4])
{
    vector<vector<int>> mat;
    int k = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (sparse[i][j] != 0)
            {
                vector<int> v1;
                v1.push_back(i);
                v1.push_back(j);
                v1.push_back(sparse[i][j]);
                mat.push_back(v1);
            }
        }
    }

    cout<<"row"<<" column"<<"   value"<<"\n";
    for (auto i : mat)
    {
        for (auto j : i)
        {
            cout << j << "\t";
        }
        cout << "\n";
    }
}

void solution2(int sparse[4][4])
{
    int size = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (sparse[i][j] != 0)
            {
                size++;
            }
        }
    }
    int mat[3][size];
    int k = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (sparse[i][j] != 0)
            {
                mat[0][k] = i;
                mat[1][k] = j;
                mat[2][k] = sparse[i][j];
                k++;
            }
        }
    }
    string arr[3] = {"row", "column", "value"};
    for (int i = 0; i < 3; i++)
    {
        cout << arr[i] << " ";
        for (int j = 0; j < size; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    int sparse[4][4] = {
        {0, 0, 3, 4},
        {5, 0, 0, 2},
        {0, 0, 0, 0},
        {1, 0, 3, 0}};
    cout<<"solution 1 using vector:\n";
    solution1(sparse);
    cout<<"\nsoultion 2 using array:\n";
    solution2(sparse);
    return 0;
}