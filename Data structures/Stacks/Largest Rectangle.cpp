#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the largestRectangle function below.
long largestRectangle(vector<int> heights) {
    int n = heights.size();
    long maxArea = 0;
    stack<pair<int,int>> st;
    for(int i=0;i<n;i++)
    {
        if(st.empty())
            st.push({heights[i],1});
        else
        {
            if(heights[i] == st.top().first)
                st.top().second++;
            else if(heights[i] > st.top().first)
                st.push({heights[i],1});
            else 
            {
                int previousWidth = 0;
                while(heights[i] < st.top().first)
                {
                    previousWidth = st.top().second;
                    st.pop();
                    if(st.empty() || heights[i] > st.top().first)
                        break;
                    st.top().second += previousWidth;
                    maxArea = max(maxArea,(long)st.top().first*(long)st.top().second);
                }
                if((!st.empty()) && heights[i] == st.top().first)
                    st.top().second++;
                else 
                    st.push({heights[i],previousWidth+1});
            }
        }
        maxArea = max(maxArea,(long)st.top().first*(long)st.top().second);
    }
    while(!st.empty())
    {
        pair<int,int> temp = st.top();
        st.pop();
        if(st.empty())
            break;
        st.top().second += temp.second;
        maxArea = max(maxArea,(long)st.top().first*(long)st.top().second);
    }
    return maxArea;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string h_temp_temp;
    getline(cin, h_temp_temp);

    vector<string> h_temp = split_string(h_temp_temp);

    vector<int> h(n);

    for (int i = 0; i < n; i++) {
        int h_item = stoi(h_temp[i]);

        h[i] = h_item;
    }

    long result = largestRectangle(h);

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
