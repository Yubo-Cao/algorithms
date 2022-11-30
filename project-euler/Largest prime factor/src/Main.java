// Largest prime factor; time complexity is O(N)^2 so runtime might take longer on slower PCs
public class Main {
	public static void main(String[] args) {
		for (long i = 60085147514L/2; i>0; i--) {
			if (600851475143L % i == 0) {
				System.out.println(i); // prints 8462696833
				getFactorsAndDeterminePrimity(i);
			}
		}
	}
	
	public static boolean getFactorsAndDeterminePrimity(long num1) {
		for (long i = num1-1; i>0; i--) {
			if (num1 % i == 0)
				return false;
		}
			return true;
	}
}
