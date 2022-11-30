import java.util.*;
// Counting sundays
public class Main {
	public static void main(String[] args) {
		int numDays = 0;
		for (int year = 1901; year < 2001; year++) {
			for (int month = 0; month < 12; month++) {
				if (dayOfWeek(year, month, 1) == 1)
					numDays++;
			}
		}
		System.out.println(numDays); //prints 171
	}
	
	public static int dayOfWeek(int year, int month, int day) {
		Calendar myCalendar = new GregorianCalendar(year, month, day);
		return(myCalendar.get(Calendar.DAY_OF_WEEK));
	}
}
