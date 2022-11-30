import java.math.BigInteger;
import java.util.*;
public class DistinctPowers {
    public static void main(String[] args) {
        BigInteger temp;
        ArrayList<BigInteger> distinctPowers = new ArrayList<BigInteger>();
        for (int a = 2; a <= 100; a++) {
            for (int b = 2; b <= 100; b++) {
                temp = BigInteger.valueOf(a).pow(b);
                if (!distinctPowers.contains(temp))
                distinctPowers.add(temp);
            }
        }
        System.out.println(distinctPowers.size());
    }
}