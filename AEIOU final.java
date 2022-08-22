package AEIOU;
import java.io.*;
import java.util.*;

public class AEIOU {
	public static void main(String[] args) {
		try {
			var sc = new Scanner(System.in);
			int numCases = Integer.valueOf(sc.nextLine());
			for (int i = 0; i < numCases; i++)
				System.out.println(sc.nextLine().replaceAll("[^aeiouAEIOU]","").length());
	}
		catch (Exception e) {}

}
}