import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the lilysHomework function below.
    static int lilysHomework(int[] arr) {
        int[] rev = reverse(arr);
        return Math.min(
            lilysHomework2(arr),
            lilysHomework2(rev)
        );
    }
    
    private static int[] reverse(int[] a) {
        int[] arr = a.clone();
        int n = arr.length;
        for (int i = 0; i < n / 2; i++) { 
            int t = arr[i]; 
            arr[i] = arr[n - i - 1]; 
            arr[n - i - 1] = t; 
        } 
        return arr;
    }
    
    private static int lilysHomework2(int[] arr)
    {
        int[] sorted = arr.clone();
        Arrays.sort(sorted);
        HashMap<Integer,Integer> idx = new HashMap<Integer,Integer>();
        for(int i=0;i<arr.length;i++)
            idx.put(arr[i],i);
        int count = 0;
        for(int i=0;i<arr.length;i++) {
            if(arr[i] != sorted[i])
            {
                int sortedIdx = idx.get(sorted[i]);
                idx.put(arr[i],sortedIdx);
                arr[sortedIdx] = arr[i];
                count++;
            }
        }
        return count;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        int[] arr = new int[n];

        String[] arrItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < n; i++) {
            int arrItem = Integer.parseInt(arrItems[i]);
            arr[i] = arrItem;
        }

        int result = lilysHomework(arr);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
