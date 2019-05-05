import java.util.*;
import java.io.*;

class Solution{
    public static void main(String []argh){
        Scanner in = new Scanner(System.in);
        int t=in.nextInt();
        for(int i=0;i<t;i++){
            int a = in.nextInt();
            int b = in.nextInt();
            int n = in.nextInt();
            for(int k=0;k<n;k++)
            {
                int ans = a;
                for(int j=0;j<=k;j++)
                    ans += b * (1<<j);
                System.out.print(ans+" ");
            }
            System.out.println();
        }
        in.close();
    }
}

