// Highly divisible triangular number; more iterative approach with time complexity O(log(N)) by taking the prime factorization of the number up to its square root and doubling it
public class Main {
	public static void main(String[] args) {
		int triangleNum = 0;
		int nthTriangle = 0;
		int numberOfDivisors = 0;
		
		while (numberOfDivisors <= 500) {
			numberOfDivisors = 0;
			nthTriangle++;
			triangleNum = getNumFromNthTriangle(nthTriangle);
			
			for (int i = 1; i <= Math.sqrt(triangleNum); i++) {
				if (triangleNum % i == 0)
					numberOfDivisors++;
			}
			numberOfDivisors *= 2;
		}
		System.out.println(triangleNum); // prints 76576500
		}
	
	public static int getNumFromNthTriangle (int n) {
		int triangleNum = 0;
		for (int i = 1; i <= n; i++)
			triangleNum += i;
		return triangleNum;
	}
}
