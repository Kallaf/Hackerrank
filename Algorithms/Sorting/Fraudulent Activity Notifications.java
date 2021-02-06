import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the activityNotifications function below.
    static int activityNotifications(int[] expenditure, int d) {
        int[] count = new int[210];
        int j1 = (int)Math.floor((d-1)/2.0);
        int j2 = (int)Math.ceil((d-1)/2.0);
        for(int i=0;i<d;i++)
            count[expenditure[i]]++;
        int ans = 0;
        for(int i=d;i<expenditure.length;i++)
        {
            int m1=0,m2=0,j=0,m=0;
            for(;j<=j1;j+=count[m],m++)m1 = m;
            for(m--,j-=count[m];j<=j2;j+=count[m],m++)m2 = m;
            double med = (m1+m2)/2.0;
            if (expenditure[i] >= med * 2) ans++;
            count[expenditure[i]]++;
            count[expenditure[i-d]]--;
        }
        return ans;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] nd = scanner.nextLine().split(" ");

        int n = Integer.parseInt(nd[0]);

        int d = Integer.parseInt(nd[1]);

        int[] expenditure = new int[n];

        String[] expenditureItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < n; i++) {
            int expenditureItem = Integer.parseInt(expenditureItems[i]);
            expenditure[i] = expenditureItem;
        }

        int result = activityNotifications(expenditure, d);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
