#include <bits/stdc++.h>

using namespace std;

int BFS(int a,int b,int n) 
{ 
    // Mark all the vertices as not visited
    vector<bool> visitedRow(n,0); 
    vector<vector<bool>> visited(n,visitedRow); 
  
    // Create a queue for BFS 
    list<tuple<int,int,int>> queue; 
  
    // Mark the current node as visited and enqueue it 
    visited[0][0] = true; 
    queue.push_back({0,0,0}); 
    
    // Pointer to an array containing adjacency 
    // lists 
    list<pair<int,int>> adj; 

    adj.push_back({a,b});
    adj.push_back({-a,b});
    adj.push_back({a,-b});
    adj.push_back({-a,-b});
    adj.push_back({b,a});
    adj.push_back({-b,a});
    adj.push_back({b,-a});
    adj.push_back({-b,-a});

    // 'i' will be used to get all adjacent 
    // vertices of a vertex 
    list<pair<int,int>>::iterator i;

    while(!queue.empty()) 
    { 
        // Dequeue a vertex from queue and print it 
        tuple<int,int,int> curr = queue.front();  
        queue.pop_front(); 
  
        if(get<0>(curr) == n-1 && get<1>(curr) == n-1)return get<2>(curr);

        // Get all adjacent vertices of the dequeued 
        // vertex s. If a adjacent has not been visited,  
        // then mark it visited and enqueue it 
        for (i = adj.begin(); i != adj.end(); ++i) 
        {
            int x2 = get<0>(curr) + i->first;
            int y2 = get<1>(curr) + i->second;

            if(x2<0||n<=x2 || y2<0||n<=y2 || visited[x2][y2])continue;

            visited[x2][y2] = true; 
            queue.push_back({x2,y2,get<2>(curr)+1});  
        } 
    }
    return -1; 
} 


// Complete the knightlOnAChessboard function below.
vector<vector<int>> knightlOnAChessboard(int n) {
    vector<vector<int>> row;
    for(int i=1;i<n;i++)
    {
        vector<int> col;
        for(int j=1;j<n;j++)
            col.push_back(BFS(i,j,n));
        row.push_back(col);
    }
    return row;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> result = knightlOnAChessboard(n);

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            fout << result[i][j];

            if (j != result[i].size() - 1) {
                fout << " ";
            }
        }

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
