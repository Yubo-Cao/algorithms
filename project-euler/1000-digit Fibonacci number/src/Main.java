import java.math.BigInteger;
// 1000-digit Fibonacci number
public class Main {
	public static void main(String[] args) {
		int i = 0;
	    int cnt = 2;
	    BigInteger limit = (new BigInteger("10")).pow(999);
	    BigInteger[] fib = new BigInteger[3];

	    fib[0] = new BigInteger("1");
	    fib[2] = new BigInteger("1");

	    while ((fib[i]).compareTo(limit) < 0) {
	        i = (i + 1) % 3;
	        cnt++;
	        fib[i] = fib[(i + 1) % 3].add(fib[(i + 2) % 3]);
	    }
	    System.out.printf(" %d is the fist Fibonacci number with 1000 digits\n", cnt);
	  }
}
