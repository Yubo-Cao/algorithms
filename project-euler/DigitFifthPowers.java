import java.util.HashMap;
public class DigitFifthPowers {
    public static HashMap<Integer, Double> key = new HashMap<Integer, Double>();

    public static void main(String[] args) {
        int sum = 0;
        for (int i = 0; i < 10; i++)
        key.put(i, Math.pow(i, 5));
        for (int i = 0; i < 1000000; i++) {
            if (isASum(i))
                sum += i;
        }
        System.out.println(sum); //prints 443839
    }

    public static boolean isASum(int i) {
        if (i == 1)
        return false;
        int sum = 0;
        for (int num = i; num > 0; num /= 10)
            sum += key.get(num%10);
        return (sum == i);
        
    }
}