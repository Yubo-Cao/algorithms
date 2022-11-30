import java.util.*;
import java.math.BigInteger;
public class Main {
// Reciprocal cycles
	public static void main(String[] args) {
		BigInteger max = new BigInteger(String.valueOf(Integer.MIN_VALUE));
		int[] temp = new int[1];
		for (int i = 2; i < 1000; i++) {
			BigInteger recurringDecimal = new BigInteger((String)recurringDecimal(i));
			if (recurringDecimal.compareTo(max) > 0) {
				max = recurringDecimal;
				temp[0]=i;
			}
		}
		System.out.println(temp[0]); // prints 983
	}
	
	public static String recurringDecimal(int num) {
		HashMap<Integer, Integer> remainderIndexMap = new HashMap<>();
		List<Integer> values = new ArrayList<>();
		int value;
		int remainder = 1;
		while (!remainderIndexMap.containsKey(remainder)) {
			remainderIndexMap.put(remainder, values.size());
			remainder *= 10;
			value = remainder / num;
			remainder %= num;
			values.add(value);
			
		}
		int index = remainderIndexMap.get(remainder);
		StringBuilder result = new StringBuilder();
		for (int i = 0; i < index; i ++)
			result.append(values.get(i));
		for (int i = index; i < values.size(); i++)
			result.append(values.get(i));
		if (result.toString().substring(0,1).equals("0"))
			result.deleteCharAt(0);
		return result.toString();
	}

}
