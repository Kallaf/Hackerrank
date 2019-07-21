using System;

class Solution {

    static int len(long x)
    {
        int l = 0;
        while(x > 0)
        {
            l++;
            x /= 10;
        }
        return l;
    }

    static void Main(string[] args) {
        int t = Convert.ToInt32(Console.ReadLine());

        while(t-- > 0) {
            string s = Console.ReadLine();
            bool flag = false;long firstNumber =0;
            for(int i=1;i<=19;i++)
            {
                firstNumber = Convert.ToInt64(s.Substring(0, i));
                long previous = firstNumber;
                int currLen = len(previous+1),preLen = len(previous);
                //Console.WriteLine(i+" "+(s.Length-currLen));
                if(i > s.Length-currLen)
                {
                    flag = false;
                    break;
                }
                flag = true;
                for(int j=preLen;j<s.Length;j+=preLen)
                {
                    long current = Convert.ToInt64(s.Substring(j, currLen));
                    //Console.WriteLine(j+" "+currLen+" "+previous+" "+current);
                    if(previous+1 != current)
                    {
                        flag = false;
                        break;
                    }
                    preLen = currLen;
                    currLen = len(current+1);
                    previous = current;
                   // Console.WriteLine((j+preLen+currLen) + " " + s.Length);
                    if(j+preLen != s.Length && j+preLen+currLen>s.Length)
                    {
                        flag = false;
                        break;
                    }
                }
                if(flag)break;
            }
            if(flag)Console.WriteLine("YES "+firstNumber);
            else Console.WriteLine("NO");
        }
    }
}
