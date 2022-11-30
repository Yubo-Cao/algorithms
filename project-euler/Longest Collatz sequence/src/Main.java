// Longest Collatz sequence
public class Main {
	public static void main(String[] args) {
		int max = Integer.MIN_VALUE;
		for (long i = 2; i < 1000000; i++) {
			if (max < collatz(i)) {
				max = collatz(i);
			System.out.println(i); // prints 837799
			}
		}
	}
	
	public static int collatz(long num) {
		int collatzTimes = 0;
		while (num >= 1) {
			if (num % 2 == 0)
				num /= 2;
			else if (num != 1)
				num = 3*num + 1;
			else
				return collatzTimes;
			collatzTimes++;
		}
		return 0;
	}
}
