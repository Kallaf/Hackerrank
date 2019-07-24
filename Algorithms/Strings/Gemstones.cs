using System;
using System.IO;
class Solution {

    // Complete the gemstones function below.
    static int gemstones(string[] arr) {
        int[] count = new int[30]; 
        for(int i=0;i<arr.Length;i++)
        {
            bool[] flag= new bool[30];
            for(int j=0;j<arr[i].Length;j++)flag[arr[i][j]-'a'] = true;
            for(int j=0;j<26;j++)if(flag[j])count[j]++;
        }
        int ans = 0;
        for(int i=0;i<26;i++)if(count[i]==arr.Length)ans++;
        return ans;
    }

    static void Main(string[] args) {
        TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

        int n = Convert.ToInt32(Console.ReadLine());

        string[] arr = new string [n];

        for (int i = 0; i < n; i++) {
            string arrItem = Console.ReadLine();
            arr[i] = arrItem;
        }

        int result = gemstones(arr);

        textWriter.WriteLine(result);

        textWriter.Flush();
        textWriter.Close();
    }
}
