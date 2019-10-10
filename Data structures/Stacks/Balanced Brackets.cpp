#include <bits/stdc++.h>

using namespace std;

// Complete the isBalanced function below.
string isBalanced(string s) {
    stack<char> st;
    for(char c:s)
    {
        if(c == '(' | c == '{' || c == '[')
            st.push(c);
        else
        {
            if(st.empty())return "NO";
            if(st.top() != '(' && c == ')')return "NO";
            if(st.top() != '{' && c == '}')return "NO";
            if(st.top() != '[' && c == ']')return "NO";
            st.pop();
        }
    }
    return st.empty()?"YES":"NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
