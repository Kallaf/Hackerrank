using System;

class Solution{
    static void Main(string[] args)
    {
        string s = Console.ReadLine();
        bool[] arr = new bool[10000007];
        int weight = s[0]-'a'+1;
        arr[weight] = true;
        for(int i=1;i<s.Length;i++)
        {
            if(s[i] == s[i-1])
                weight += s[i]-'a'+1;
            else
                weight = s[i]-'a'+1;
            
            arr[weight] = true;
        }
        int n = Convert.ToInt32(Console.ReadLine());
        for(int i=0;i<n;i++)
        {
            int query = Convert.ToInt32(Console.ReadLine());
            if(arr[query])Console.WriteLine("Yes");
            else Console.WriteLine("No");     
        }
    }
}
