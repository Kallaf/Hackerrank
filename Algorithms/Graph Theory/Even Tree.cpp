#include<iostream>
#include<vector>
using namespace std;

int tn,te;
bool graph[105][105] = {0};
bool visited[105] = {0};
int deleted = 0;

int checkSubTree(int index)
{
    if(visited[index])return 0;
    visited[index] = 1;
    int numberOfNodes = 1;
    for(int i=1;i<=tn;i++)
    {
        if(!visited[i] && graph[index][i])
        {
            int subtreeNumberOfNodes = checkSubTree(i);
            if(!(subtreeNumberOfNodes%2))
                deleted++;
            else 
                numberOfNodes += subtreeNumberOfNodes;
        }
    }
    return numberOfNodes;
}

int main()
{
    
    cin >> tn >> te;
    for(int i=0;i<te;i++)
    {
        int v1,v2;
        cin >> v1 >> v2;
        graph[v1][v2] = 1;
        graph[v2][v1] = 1;
    }
    for(int i=1;i<=tn;i++)
        checkSubTree(i);
    cout << deleted << endl;
    return 0;
}
