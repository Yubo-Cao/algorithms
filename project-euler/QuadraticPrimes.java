public class QuadraticPrimes {
    public static void main (String[] args) {
        int maxChain = 0, max = 1000, maxA = 0, maxB = 0;
        for (int a = -max+1; a < max; a++) {
            for (int b = -max+1; b < max; b++) {
                int n = 0;
                    while (Math.pow(n, 2)+(a*n)+b > 1 && isPrime((int)Math.pow(n, 2)+(a*n)+b))
                        n++;
                if (n > maxChain) {
                    maxChain = n;
                    maxA = a;
                    maxB = b;
                }
            }
        }
        System.out.println(maxA * maxB); // Prints -59231
    }

    public static boolean isPrime(int n) {
        boolean[] sieve = new boolean[n];
        sieve[0] = true;
        for (int i = 1; i < n-1; i++) {
		for (int j= i; j < sieve.length; j += i+1)
			sieve[j] = true;
		}
        if (sieve[n-1] == true)
        return false;
        return true;
    }
}