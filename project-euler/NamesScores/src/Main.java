import java.io.*;
import java.util.Arrays;

public class Main
{
	public static long getNameValue (String name)
	{
		long total = 0;
		for (int loop = 0; loop < name.length (); loop++)
			total += (int) name.charAt (loop) - 64;
		return total;
	}

	public static void main (String args []) {	
		BufferedReader br = new BufferedReader(new FileReader("C:\\Users\\anish\\eclipse-workspace\\NamesScores\\names.txt"));
		String [] nameList = br.readLine().replaceAll ("\"", "").split(",");
		Arrays.sort (nameList);
		long total = 0;
		for (int loop = 0; loop < nameList.length; loop++)
		{
			total += getNameValue (nameList [loop]) * (loop + 1);
		}
		System.out.println ("Total value: " + total);
	}
}

