#include <bits/stdc++.h>
using namespace std;

// Complete the timeInWords function below.
string timeInWords(int h, int m) {
    vector<string> numbers(25);
    numbers[1] ="one";numbers[2] = "two";numbers[3]="three";
    numbers[4]="four";numbers[5]="five";numbers[6]="six";
    numbers[7]="seven";numbers[8]="eight";numbers[9]= "nine";
    numbers[10]="ten";numbers[11]="eleven";numbers[12]="twelve";
    numbers[13]="thirteen";numbers[14]="fourteen";numbers[15]="fifteen";
    numbers[16]="sixteen";numbers[17]="seventeen";numbers[18]="eighteen";
    numbers[19]="nineteen";numbers[20]="twenty";
    if(m == 0)
      return numbers[h] + " o' clock";
    if (m < 30) {
        if(m == 1)
            return "one minute past "+ numbers[h]; 
        if(m == 15)
          return "quarter past " + numbers[h];
        if(m > 20)
            return "twenty "+numbers[m-20]+" minutes past "+numbers[h];
        return numbers[m]+" minutes past "+numbers[h];
      }
    if(m>30)
    {
        h = h+1 == 13?1:h+1;
        m = 60 - m;
        if (m == 1)
          return "one minute to " + numbers[h];
        if (m == 15)
          return "quarter to " + numbers[h];
        if (m > 20)
          return "twenty " + numbers[m - 20] + " minutes to " + numbers[h];
        return numbers[m] + " minutes to " + numbers[h];
    }
    return "half past "+numbers[h];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int h;
    cin >> h;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = timeInWords(h, m);

    fout << result << "\n";

    fout.close();

    return 0;
}
