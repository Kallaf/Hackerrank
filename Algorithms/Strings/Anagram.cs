using System.IO;
using System;

class Solution {

    // Complete the anagram function below.
    static int anagram(string s) {
        int n = s.Length;
        if(n%2 == 1)return -1;
        int[] count1 = new int[30];
        for(int i=0;i<n/2;i++)count1[s[i]-'a']++;
        int[] count2 = new int[30];
        for(int i=n/2;i<n;i++)count2[s[i]-'a']++;
        int ans = 0;
        for(int i=0;i<26;i++)ans += Math.Abs(count1[i]-count2[i]);
        return ans/2;
    }

    static void Main(string[] args) {
        TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

        int q = Convert.ToInt32(Console.ReadLine());

        for (int qItr = 0; qItr < q; qItr++) {
            string s = Console.ReadLine();

            int result = anagram(s);

            textWriter.WriteLine(result);
        }

        textWriter.Flush();
        textWriter.Close();
    }
}
