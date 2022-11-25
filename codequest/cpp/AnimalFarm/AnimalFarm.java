package AnimalFarm;
import java.io.*;
import java.util.*;

public class AnimalFarm {
	public static void main(String[] args) {
		try {
			Scanner sc = new Scanner(System.in);
			var numCases = Integer.valueOf(sc.nextLine());
			for (int i = 0; i < numCases; i++) {
				String line = sc.nextLine();
				int[] arr = Arrays.stream(line.split("\\s+")).mapToInt(Integer::parseInt).toArray();
				System.out.println(arr[0]*2 + arr[1]*4 + arr[2]*4);
			}
		}
		
		catch(Exception e) {}
	}

}
