using System;
using System.IO;
class Solution {

    // Complete the palindromeIndex function below.
    static int palindromeIndex(string s) {
        int lshift = 0,rshift = 0,ans =-1,n=s.Length,m=s.Length/2;
        for(int i=0,j=s.Length-1;i<m+lshift && j>=n-m-rshift;i++,j--)
        {
            if(s[i+lshift] != s[j-rshift])
            {
                if(lshift != 0 || rshift != 0)return -1;
                if((s[i] == s[j-1]) && (s[i+1] == s[j]))
                {
                    if(s[i] == s[i+2])
                    {
                        lshift = 1;
                        ans = i;
                    }else if(s[j] == s[j-2])
                    {
                        rshift = 1;
                        ans = j;
                    }else return -1;
                }
                else{
                    if(s[i] == s[j-1])
                    {
                        rshift = 1;
                        ans = j;
                    }else if(s[i+1] == s[j])
                    {
                        lshift = 1;
                        ans = i;
                    }else return -1;
                }
            }
        }
        return ans;
    }

    static void Main(string[] args) {
        TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

        int q = Convert.ToInt32(Console.ReadLine());

        for (int qItr = 0; qItr < q; qItr++) {
            string s = Console.ReadLine();

            int result = palindromeIndex(s);

            textWriter.WriteLine(result);
        }

        textWriter.Flush();
        textWriter.Close();
    }
}
