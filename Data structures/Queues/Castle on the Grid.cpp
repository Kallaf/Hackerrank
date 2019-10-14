#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the minimumMoves function below.
int minimumMoves(vector<string> grid, int startX, int startY, int goalX, int goalY) {
    bool visited[grid.size()+3][grid[0].size()+3] = {0};
    queue<tuple<int,int,int>> q;
    q.push({startX,startY,0});
    visited[startX][startY] = 1;
    while(!q.empty())
    {
        tuple<int,int,int> head = q.front();
        q.pop();
        if(get<0>(head) == goalX && get<1>(head) == goalY)return get<2>(head);
        for(int i=get<0>(head)+1;i<grid.size()&&grid[i][get<1>(head)]!='X';i++)
            if(!visited[i][get<1>(head)])
            {
                q.push({i,get<1>(head),get<2>(head)+1});
                visited[i][get<1>(head)] = 1;
            }
        
        for(int i=get<0>(head)-1;i>-1&&grid[i][get<1>(head)]!='X';i--)
            if(!visited[i][get<1>(head)])
            {
                q.push({i,get<1>(head),get<2>(head)+1});
                visited[i][get<1>(head)] = 1;
            }
        
        for(int i=get<1>(head)+1;i<grid[0].size()&&grid[get<0>(head)][i]!='X';i++)
            if(!visited[get<0>(head)][i])
            {
                q.push({get<0>(head),i,get<2>(head)+1});
                visited[get<0>(head)][i] = 1;
            }
        
        
        for(int i=get<1>(head)-1;i>-1&&grid[get<0>(head)][i]!='X';i--)
            if(!visited[get<0>(head)][i])
            {
                q.push({get<0>(head),i,get<2>(head)+1});
                visited[get<0>(head)][i] = 1;
            }
    }
    return 0;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    string startXStartY_temp;
    getline(cin, startXStartY_temp);

    vector<string> startXStartY = split_string(startXStartY_temp);

    int startX = stoi(startXStartY[0]);

    int startY = stoi(startXStartY[1]);

    int goalX = stoi(startXStartY[2]);

    int goalY = stoi(startXStartY[3]);

    int result = minimumMoves(grid, startX, startY, goalX, goalY);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
