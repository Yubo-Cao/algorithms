// Even fibonacci numbers
public class Main {
	public static void main(String[] args) {
		int sum = 0;
		int num1 = 0;
		int num2 = 1;
		while (sum < 4000000) {
			int num3 = num1 + num2;
			num1=num2;
			num2=num3;
			if (num3 % 2 == 0)
				sum += num3;
		}
		System.out.println(sum); // prints 4613732
	}
}
