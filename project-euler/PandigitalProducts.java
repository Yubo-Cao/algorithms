import java.util.*;
public class PandigitalProducts {
    public static void main(String[] args) {
        ArrayList<Long> products = new ArrayList<Long>();
        long product, compiled, sum = 0;
        for (int i = 2; i < 100; i++) {
            for (int j = ((i > 9) ? 123 : 1234); j < 10000 / i + 1; j++) {
                product = i * j;
                compiled = concat(concat(product, j), i);
                if (compiled >= 1E8 && isPandigital(compiled) && compiled < 1E9 && isPandigital(compiled)) {
                    if (!products.contains(product))
                        products.add(product);
        }
    }
    }
    for (int i = 0; i < products.size(); i++)
         sum += products.get(i);
    System.out.println(sum); // Prints 45228
    }

    public static boolean isPandigital(long n) {
        int tmp;
        int count = 0;
        int digits = 0;

        while (n > 0) {
            tmp = digits;
            digits = digits | 1 << (int)((n % 10) - 1);
            if (tmp == digits)
            return false;
            count++;
            n /= 10;
        }
        return digits == (1 << count) - 1;
    }

    public static long concat(long a, long b) {
        long c = b;
        while (c > 0) {
            a *= 10;
            c /= 10;
        }
        return a + b;
    }
}