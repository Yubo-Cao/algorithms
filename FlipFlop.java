import java.util.Arrays;
import java.util.Scanner;
import java.util.stream.IntStream;

public class FlipFlop {
    public static void main(String[] args) {
        try (var scan = new Scanner(System.in)) {
            int testCases = scan.nextInt();
            for (int i = 0; i < testCases; i++) {
                int row = scan.nextInt(), col = scan.nextInt();
                scan.nextLine();
                var mat = IntStream
                        .range(0, row)
                        .mapToObj(rowIndex -> Arrays.stream(scan.nextLine().split(",", -1)).map(e -> (e.isEmpty()) ? null : Integer.valueOf(e)).toArray(Integer[]::new))
                        .toArray(it -> new Integer[it][col]);
                for (int j = 0; j < mat[0].length; j++) {
                    for (int k = 0; k < mat.length; k++) {
                        if (mat[k][j] == null) {
                            System.out.print(",");
                        } else if (mat[k][j] != null && k != mat.length - 1) {
                            System.out.print(mat[k][j] + ",");
                        } else if (mat[k][j] != null) {
                            System.out.print(mat[k][j]);
                        }
                    }
                    System.out.println();
                }
            }
        }
    }
}
