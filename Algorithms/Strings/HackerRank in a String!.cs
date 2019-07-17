using System;

class Solution
{
    static string hackerrankInString(string s) {
        string hackerrank = "hackerrank";
        int index = 0;
        for (int i = 0; i < s.Length; i++)
        {
            if (s[i] == hackerrank[index])
                index++;
            if (index == 9) return "YES";
        }
        return "NO";

    }
    public static void Main(string[] args)
    {
        
        int t = Convert.ToInt32(Console.ReadLine());
        while(t-- > 0)
        {
            string s = Console.ReadLine();
            Console.WriteLine(hackerrankInString(s));     
        }
    }
}
