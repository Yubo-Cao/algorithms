// Sum square difference
public class Main {
	public static void main(String[] args) {
		int sumOfSquares = 0;
		int sumSquared = 0;
		for (int i = 1; i < 101; i++) {
			sumOfSquares += Math.pow(i, 2);
			sumSquared += i;
		}
		sumSquared = (int) Math.pow(sumSquared, 2);
		System.out.println(Math.abs(sumOfSquares-sumSquared)); // prints 25164150
	}
}
