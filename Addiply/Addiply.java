package Addiply;
import java.util.Scanner;

public class Addiply {
	public static void main(String[] args) {
		try {
			var sc = new Scanner(System.in); 
			int numCases = Integer.valueOf(sc.nextLine());
			for (int i = 0; i < numCases; i++) {
				String nextLine = sc.nextLine();
				int num1 = Integer.valueOf(nextLine.substring(0, nextLine.indexOf(" ")).trim());
				int num2 = Integer.valueOf(nextLine.substring(nextLine.indexOf(" ")+1).trim());
				System.out.print(num1+num2 + " "  + num1*num2 + "\n");
			}
		}
		catch (Exception e) {}
	}

}
