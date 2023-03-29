package codequest;
import java.util.Arrays;
import java.util.Scanner;

public class EnterTheMatrix {
    public static void main(String[] args) {
        var scan = new Scanner(System.in);
        var n = scan.nextInt(); // Number of test cases
        for (int k = 0; k < n; k++) {
            // Matrix operation.
            var C = new double[2][2];
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    C[i][j] = scan.nextInt();
                }
            }
            // Fuel consumption Matrix.
            var F = new double[1][2];
            for (int i = 0; i < 1; i++) {
                for (int j = 0; j < 2; j++) {
                    F[i][j] = scan.nextInt();
                }
            }
            // Determinant of C
            var detC = C[0][0] * C[1][1] - C[0][1] * C[1][0];
            // Inverse of C
            // Swap
            var temp = C[0][0];
            C[0][0] = C[1][1];
            C[1][1] = temp;
            // Negative 1
            C[0][1] = -C[0][1];
            C[1][0] = -C[1][0];
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    C[i][j] = C[i][j] / detC;
                }
            }
            // Multiply C and F
            var result = new double[1][2];
            // F * C
            result[0][0] = C[0][0] * F[0][0] + C[1][0] * F[0][1];
            result[0][1] = C[0][1] * F[0][0] + C[1][1] * F[0][1];
            // Print result
            Arrays.stream(result).forEach(row -> Arrays.stream(row).forEach(it -> System.out.print(Math.round(it) + " ")));
        }
    }
}
