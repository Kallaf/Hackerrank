using System;

class Solution {

    static void Main(string[] args) {
        int t = Convert.ToInt32(Console.ReadLine());

        while(t-- > 0) {
            string s = Console.ReadLine();

            int deletions = 0;
            for(int i=1;i<s.Length;i++)if(s[i]==s[i-1])deletions++;
            Console.WriteLine(deletions);
        }
    }
}
