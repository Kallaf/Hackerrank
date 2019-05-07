using System.CodeDom.Compiler;
using System.Collections.Generic;
using System.Collections;
using System.ComponentModel;
using System.Diagnostics.CodeAnalysis;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Runtime.Serialization;
using System.Text.RegularExpressions;
using System.Text;
using System;

class Solution {

    // Complete the permutationEquation function below.
    static int[] permutationEquation(int[] p) {
        int[] ans = new int[p.Length];
        for(int x=1;x<=p.Length;x++)
            for(int j=0;j<p.Length;j++)
                if(p[j] == x)
                    for(int y=0;y<p.Length;y++)
                        if(p[y] == j+1)
                            ans[x-1] = y+1;
                
        return ans;
    }

    static void Main(string[] args) {
        TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

        int n = Convert.ToInt32(Console.ReadLine());

        int[] p = Array.ConvertAll(Console.ReadLine().Split(' '), pTemp => Convert.ToInt32(pTemp))
        ;
        int[] result = permutationEquation(p);

        textWriter.WriteLine(string.Join("\n", result));

        textWriter.Flush();
        textWriter.Close();
    }
}
