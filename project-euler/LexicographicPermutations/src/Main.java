// LexicographicPermutations
public class Main {
	public static void main(String[] args) {
		int[] arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		for (int i = 0; i < 999999; i++)
			nextPermutation(arr);
		String answer = "";
		for (int i = 0; i < arr.length; i++)
			answer += arr[i];
		System.out.println(answer); // prints 2783915460
	}
	
	public static boolean nextPermutation(int[] arr) {
		int i = arr.length-1;
		while (i > 0 && arr[i-1] > arr[i])
			i--;
		if (i <= 0)
			return false;
		int j = arr.length-1;
		while (arr[j] <= arr[j-1])
			j--;
		int temp = arr[i-1];
		arr[i-1] = arr[j];
		arr[j] = temp;
		
		j = arr.length-1;
		while (i < j) {
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}
		return true;
	}
}
