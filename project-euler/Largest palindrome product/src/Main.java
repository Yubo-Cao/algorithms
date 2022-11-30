// Largest palindrome product
public class Main {
	public static void main(String[] args) {
		int max = Integer.MIN_VALUE;
		for (int num1 = 1; num1 < 1000; num1++) {
			for (int num2 = 1; num2 < 1000; num2++) {
					int product = num1 * num2;
					String productString = String.valueOf(product);
					if (productString.equals(new StringBuilder(productString).reverse().toString())) {
						if (product > max)
							max = product;
					}
				}
		}
		System.out.println(max); // prints 906609
	}
}
