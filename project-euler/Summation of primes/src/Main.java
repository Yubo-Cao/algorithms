// Summation of primes; uses Sieve of Eratosthenes recursively
public class Main {
	public static void main(String[] args) {
		int limit = 2000000;
		long sum = 0;
		boolean[] sieve = new boolean[limit];
		for (int i=2; i<limit; i++) {
			if (sieve[i] == true) 
				continue;
			sum += i;
			
		for (int j= i+i; j < limit; j += i)
			sieve[j] = true;
		}
		System.out.println(sum); // prints 142913828922
	}
}
