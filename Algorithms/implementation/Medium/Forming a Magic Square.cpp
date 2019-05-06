#include <bits/stdc++.h>

using namespace std;

vector<vector<vector<int>>> magic_squares;

void swap(int *x, int *y) {
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}

bool isMagic(vector<vector<int>> temp)
{
    int diagonal_sum = 0;
    int inverse_diagonal_sum = 0;
    for(int i=0;i<3;i++)
    {
        if(temp[i][0]+temp[i][1]+temp[i][2]!=15)
            return 0;
        if (temp[0][i] + temp[1][i] + temp[2][i] != 15)
          return 0;
        diagonal_sum += temp[i][i];
        inverse_diagonal_sum += temp[i][2-i];
    }
    if(diagonal_sum!=15 || inverse_diagonal_sum!=15)
        return 0;
    return 1;
}

void permute(int *a, int l, int r) {
  int i;
  if (l == r)
  {
      vector<vector<int>> temp;
      for(int i=0;i<3;i++)
      {
          vector<int> temp1;
          for(int j=0;j<3;j++)
          {
              temp1.push_back(a[i*3+j]);
          }
          temp.push_back(temp1);
          
      }
      if (isMagic(temp))
        magic_squares.push_back(temp);
  }
  else {
    for (i = l; i <= r; i++) {
      swap((a + l), (a + i));
      permute(a, l + 1, r);
      swap((a + l), (a + i)); // backtrack
    }
  }
}

int cost(vector<vector<int>> s,vector<vector<int>> k)
{
    int change = 0;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            change += abs(s[i][j] - k[i][j]);
    return change;
}

// Complete the formingMagicSquare function below.
int formingMagicSquare(vector<vector<int>> s) {
    int a[] = {1,2,3,4,5,6,7,8,9};
    permute(a,0,8);
    int min_cost = 1000000;
    for(auto k:magic_squares)
    {
        min_cost = min(min_cost,cost(s,k));
    }
        
    return min_cost;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> s(3);
    for (int i = 0; i < 3; i++) {
        s[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> s[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = formingMagicSquare(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
