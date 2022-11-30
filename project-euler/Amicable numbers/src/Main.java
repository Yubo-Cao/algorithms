// Amicable numbers
import java.util.*;
import java.math.BigInteger;
public class Main {
	public static void main(String[] args) {
		int answer = 0;
		for (int i = 2; i < 10000; i++) {
			int sum = 0;
			int sum2 = 0;
			ArrayList<Integer> divisors = getDivisors(i);
			for (int j=0; j < divisors.size(); j++)
				sum += divisors.get(j);
			if (sum == i)
				continue;
			ArrayList<Integer> divisors2 = getDivisors(sum);
			for (int j=0; j < divisors2.size(); j++)
				sum2 += divisors2.get(j);
			if (sum2 == i)
				answer += i;
			}
		System.out.println(answer); //prints 31626
	}

	public static ArrayList<Integer> getDivisors(int i) {
		ArrayList<Integer> divisors = new ArrayList<Integer>();
		for (int j = 1; j < i; j++) {
			if (i % j == 0)
				divisors.add(j);
	}
		return(divisors);
	}
}