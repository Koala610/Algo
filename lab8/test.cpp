#include <iostream>
#include <windows.h>
 
using namespace std;
const int n = 4;
int i, j;
//матрица смежности графа
int GM[n][n] =
{
    { 0, 1, 1, 0 },
    { 1, 0, 0, 1 },
    { 1, 0, 0, 0 },
    { 0, 1, 0, 0 }
};
 
bool is_tree;
 
//поиск в ширину
void BFS()
{
    int *queue = new int[n];
    bool *visited = new bool[n];
 
    int count, head;
    for (i = 0; i<n; i++) queue[i] = 0;
    count = 0;
    head = 0;
    queue[count++] = 0;
    visited[0] = true;
    is_tree = true;
    while (head<count)
    {
        int unit = queue[head++];
        cout << unit + 1 << " ";
        for (i = 0; i<n; i++)
        {
 
            if (GM[unit][i])
            {
                if (!visited[i])
                {
                    queue[count++] = i;
                    visited[i] = true;
                }
                else
                {
                    if (!GM[i][unit])
                        is_tree = false;//!!!!!
                }
            }
        }
 
    }
    delete[]queue;
    delete[]visited;
}
//главная функция
int main()
{
    BFS();
    cout << is_tree;
}