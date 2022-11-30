import java.util.*;
// Non-abundant sums
public class Main {
	public static final int MAX = 28123;
	
	public static void main(String[] args) {
		int sum = 0;
		ArrayList<Integer> abundantNumbers = new ArrayList<Integer>();
		ArrayList<Integer> abundantSums = new ArrayList<Integer>();
		
		for (int i=12; i<=MAX; i++) {
			if (isAbundant(i))
				abundantNumbers.add(i);
		}
		
		for (int i=0; i < abundantNumbers.size(); i++) {
			for (int j=i; j < abundantNumbers.size(); j++)
				abundantSums.add(abundantNumbers.get(i)+abundantNumbers.get(j));
		}
		
		for (int i=1; i <= MAX; i++) {
			if (abundantSums.contains(i) == false)
				sum += i;
		}
		
		System.out.println(sum); //prints 1239664
	}
	
	public static boolean isAbundant(int n) {
		int sum = 0;
		for (int i=1; i <= n/2; i++) {
			if (n % i == 0)
				sum += i;
		}
		if (sum > n)
			return true;
		else 
			return false;
		}
	}

