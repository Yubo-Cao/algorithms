package AnagramChecker;
import java.util.*;
import java.io.*;

public class AnagramChecker {
	public static void main(String[] args) {
		try {
			var sc = new Scanner(System.in);
			var numCases = Integer.valueOf(sc.nextLine());
			for (int i = 0; i < numCases; i++) {
				var line = sc.nextLine();
				char word1[] = line.substring(0, line.indexOf("|")).trim().toCharArray();
				char word2[] = line.substring(line.indexOf("|")+1).trim().toCharArray();
				if (isEqual(word1, word2))
				System.out.println(line + " = NOT AN ANAGRAM");
				else {
				Arrays.sort(word1); 
				Arrays.sort(word2);
				if (isEqual(word1, word2))
					System.out.println(line + " = ANAGRAM");
				else
					System.out.println(line + " = NOT AN ANAGRAM");
			}
			}
		}
		
		catch(Exception E) {}
	}
	
	public static boolean isEqual(char[] word1, char[] word2) {
		if (word1.length != word2.length)
			return false; 
		for (int i = 0; i < word1.length; i++) {
			if (word1[i] != word2[i])
				return false;
		}
		return true;
	}
}
