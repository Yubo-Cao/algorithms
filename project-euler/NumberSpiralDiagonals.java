import java.math.BigInteger;
// Number Spiral Diagonals
public class NumberSpiralDiagonals {
    public static void main(String[] args) {
        BigInteger sum = BigInteger.ONE;
        for (int n = 1; n <= 500; n++) {
            int topRight=(int)Math.pow(n*2+1, 2);
            int topLeft=topRight-(n*2);
            int bottomLeft=topLeft-(n*2);
            int bottomRight=bottomLeft-(n*2);
            sum = sum.addD(BigInteger.valueOf(topRight+topLeft+bottomLeft+bottomRight));
            System.out.println("Box " + n + ": " + topRight + " " + topLeft + " " + bottomLeft + " " + bottomRight + "\n Sum: " + sum);
        }
        System.out.println("Sum: " + sum);
    }
}