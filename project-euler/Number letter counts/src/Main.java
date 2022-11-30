// Number letter counts
import java.util.*;
public class Main {
	public static void main(String[] args) {
		HashMap<Integer, String> digitsList = new HashMap<Integer, String>();
		HashMap<Integer, String> tensList = new HashMap<Integer, String>();
		HashMap<String, String> elevenToNineteen = new HashMap<String, String>();
		digitsList.put(0, ""); digitsList.put(1, "one"); digitsList.put(2, "two"); digitsList.put(3, "three"); digitsList.put(4, "four"); digitsList.put(5, "five");
		digitsList.put(6, "six"); digitsList.put(7, "seven"); digitsList.put(8, "eight"); digitsList.put(9, "nine"); 
		tensList.put(0, ""); tensList.put(1, "ten"); tensList.put(2, "twenty"); tensList.put(3, "thirty"); tensList.put(4, "forty"); tensList.put(5, "fifty");
		tensList.put(6, "sixty"); tensList.put(7, "seventy"); tensList.put(8, "eighty"); tensList.put(9, "ninety");
		elevenToNineteen.put("1one", "eleven"); elevenToNineteen.put("1two", "twelve"); elevenToNineteen.put("1three", "thirteen"); elevenToNineteen.put("1four", "fourteen"); elevenToNineteen.put("1five", "fifteen");
		elevenToNineteen.put("1six", "sixteen"); elevenToNineteen.put("1seven", "seventeen"); elevenToNineteen.put("1eight", "eighteen"); elevenToNineteen.put("1nine", "nineteen"); 
		String numericList = "";
		for (int i = 1; i <= 1000; i++) {
			if (i == 1000)
			numericList += "onethousand";
			int j = i;
			while (j > 0) {
				if (i==1000)
					break;
					if (j >= 100) {
						String onesPlace = digitsList.get(j%10);
						j /= 10;
						String tensPlace = tensList.get(j%10);
						j /= 10;
						String hundredsPlace = digitsList.get(j%10);
						j /= 10;
						if (tensPlace == "" && onesPlace == "")
							numericList += hundredsPlace+"hundred";
						else if (tensPlace =="ten" && onesPlace == "")
						numericList += hundredsPlace+"hundredand"+tensPlace;
						else if (tensPlace == "ten") 
							numericList += hundredsPlace+"hundredand"+elevenToNineteen.get("1"+onesPlace);
						else
							numericList += hundredsPlace+"hundredand"+tensPlace+onesPlace;
						}
							else {
								String onesPlace = digitsList.get(j%10);
								j /= 10;
								String tensPlace = tensList.get(j%10);
								j /= 10;
								if (tensPlace == "ten" && onesPlace == "")
									numericList += tensPlace;
								else if (tensPlace == "ten") {
									numericList += elevenToNineteen.get("1"+onesPlace);
								}
								else
									numericList += tensPlace+onesPlace;
							}	
							}
					}
		System.out.println(numericList.length()); //prints 21124
			}
		}