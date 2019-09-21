import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    private static final Scanner scanner = new Scanner(System.in);
    private static BigInteger t1;
    private static BigInteger t2;
    private static final BigInteger[] memo = new BigInteger[22];
    // Complete the fibonacciModified function below.
    static BigInteger fibonacciModified(int n) {
        if(n == 3)return t1.add(t2.multiply(t2));
        if(n==2)return t2;
        if(memo[n-2].equals(BigInteger.valueOf(-1)))
            memo[n-2] = fibonacciModified(n-2);
            
        if(memo[n-1].equals(BigInteger.valueOf(-1)))
            memo[n-1] = fibonacciModified(n-1);
        return memo[n-2].add(memo[n-1].multiply(memo[n-1]));
    }


    public static void main(String[] args) throws IOException {
        t1 = BigInteger.valueOf(scanner.nextInt());
        t2 = BigInteger.valueOf(scanner.nextInt());
        int n = scanner.nextInt();
        Arrays.fill(memo, BigInteger.valueOf(-1));
        System.out.println(fibonacciModified(n));
    }
}
