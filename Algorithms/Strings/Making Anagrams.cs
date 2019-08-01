using System;
using System.IO;
class Solution {

    // Complete the makingAnagrams function below.
    static int makingAnagrams(string s1, string s2) {
        int[] count1 = new int[30];
        for(int i=0;i<s1.Length;i++)
            count1[s1[i]-'a']++;
        int[] count2 = new int[30];
        for(int i=0;i<s2.Length;i++)
            count2[s2[i]-'a']++;
        int deletions = 0;
        for(int i=0;i<26;i++)
            deletions += Math.Abs(count1[i]-count2[i]);
        return deletions;
    }

    static void Main(string[] args) {
        TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

        string s1 = Console.ReadLine();

        string s2 = Console.ReadLine();

        int result = makingAnagrams(s1, s2);

        textWriter.WriteLine(result);

        textWriter.Flush();
        textWriter.Close();
    }
}
