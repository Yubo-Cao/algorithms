package codequest;
import mylib.Matrix;

import java.util.Scanner;
import java.util.stream.IntStream;

public class NormalMath {
    public static void main(String[] args) {
        var scan = new Scanner(System.in);
        var testCase = scan.nextInt();
        for (int i = 0; i < testCase; i++) {
            int m = scan.nextInt(), n = scan.nextInt();
            var mat = new double[m][n];
            IntStream.range(0, m * n).forEach(it -> mat[it / m][it % m] = scan.nextDouble());
            var matrix = new Matrix(mat);
            System.out.printf("%.2f%n", matrix.frobeniusNorm());
        }
    }
}
