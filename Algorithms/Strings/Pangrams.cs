using System;

class Solution{
    static void Main(string[] args)
    {
        string s = Console.ReadLine();
        int[] count = new int[30];
        for(int i=0;i<s.Length;i++)
        {
            if('a' <= s[i] && s[i] <= 'z')
                count[s[i]-'a']++;
            if('A' <= s[i] && s[i] <= 'Z')
                count[s[i]-'A']++;
            
        }
        for(int i=0;i<26;i++)
            if(count[i] == 0)
            {
                Console.WriteLine("not pangram");
                return;
            }
        Console.WriteLine("pangram");
    }
}
