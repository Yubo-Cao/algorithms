import java.util.Scanner;

public class BringJohnGlennHome {
    // emm... This question seems hard,
    // but actually, it's not.
    public static void main(String[] args) {
        try (var scan = new Scanner(System.in)) {
            var numberOfTestCases = scan.nextInt();
            for (int j = 0; j < numberOfTestCases; j++) {
                double x = scan.nextDouble(), res = scan.nextDouble(), h = scan.nextDouble();
                int depth = scan.nextInt();

                for (int i = 0; i < depth; i++) {
                    res += h * Math.sin(x + h * i) / (x + h * i);
                }

                System.out.printf("%.3f%n", res);
            }
        }
    }
}
