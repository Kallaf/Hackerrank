using System;

class Solution {

    static void Main(string[] args) {
        int t = Convert.ToInt32(Console.ReadLine());
        while(t-- > 0)
        {
            string s = Console.ReadLine();bool notFunny = false;
            for(int i=0,j=s.Length-1;i<s.Length-1;i++,j--)
            if(Math.Abs(s[i]-s[i+1]) != Math.Abs(s[j]-s[j-1]))
            {
                notFunny = true;
                break;
            }
            Console.WriteLine("{0}",notFunny?"Not Funny":"Funny");  
        }
    }
}
