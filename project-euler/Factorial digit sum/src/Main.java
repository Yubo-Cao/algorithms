import java.math.BigInteger;
// Factorial digit sum
public class Main {
	public static void main(String[] args) {
		BigInteger number = new BigInteger("1");
		for (int i = 100; i>0; i--)
			number = number.multiply(BigInteger.valueOf(i));
		int answer = 0;
		for (int i = 0; i < number.toString().length(); i++)
			answer += Integer.parseInt(number.toString().substring(i, i+1));
		System.out.println(answer); //print 648
			}
	}


