import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
import java.util.regex.*;

public class Solution {


    static ArrayList<Long> primes = new ArrayList<>();
    /*
     * Complete the primeCount function below.
     */
    static int primeCount(long n) {
        int ans=0;long product = 1;
        for(long prime : primes)
        {
            product *= prime;
            if(product == n){ans++;break;}
            if(product>n)break;
            ans++;
        }
        return ans;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {

        BigInteger product = BigInteger.ONE;
        for(long i=2l;;i++)
        {
            if(BigInteger.valueOf(i).isProbablePrime(10))
            {
                product = product.multiply(BigInteger.valueOf(i));
                if(product.compareTo(BigInteger.valueOf(1000000000000000000l)) > 0)break;
                primes.add(i);
            }
        }

        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int q = Integer.parseInt(scanner.nextLine().trim());

        for (int qItr = 0; qItr < q; qItr++) {
            long n = Long.parseLong(scanner.nextLine().trim());

            int result = primeCount(n);

            bufferedWriter.write(String.valueOf(result));
            bufferedWriter.newLine();
        }

        bufferedWriter.close();
    }
}
