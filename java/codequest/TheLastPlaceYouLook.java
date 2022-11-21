package codequest;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;
import java.util.function.BiPredicate;
import java.util.stream.IntStream;

public class TheLastPlaceYouLook {

    // I don't know how to solve absolute value function.
    // e.g., for input 10 10 20 -5 -5 10 8 -8 16
    // Following function occur
    // |x - 10| + |y - 10| = 20
    // |x + 5| + |y + 5| = 8
    // |x - 8| + |y + 8| = 16
    // However, since they limit the solution to one,
    // especially, only integer solution, I shall be a little bit brutal here.

    private static Set<BiPredicate<Integer, Integer>> predicates;
    private static Scanner scanner = new Scanner(System.in);
    private static int[] domain = new int[2];
    private static int[] range = new int[2];

    public static void main(String[] args) {
        var testCaseCounts = scanner.nextInt();
        IntStream.range(0, testCaseCounts).forEach(i -> {
            parse();
            solve();
        });
    }

    private static void parse() {
        // Set<BiPredicate<Integer, Integer>>
        predicates = new HashSet<>();
        IntStream.range(0, 3).forEach(i -> {
            int xPred = scanner.nextInt();
            int yPred = scanner.nextInt();
            int taxicabDist = scanner.nextInt();
            predicates.add((x, y) -> Math.abs(x - xPred) + Math.abs(y - yPred) == taxicabDist);
            domain[0] = Math.min(domain[0], xPred - taxicabDist);
            domain[1] = Math.max(domain[0], xPred + taxicabDist);
            range[0] = Math.min(range[0], yPred - taxicabDist);
            range[1] = Math.max(range[0], yPred + taxicabDist);
        });
    }

    private static void solve() {
        IntStream.range(domain[0], domain[1] + 1)
                .mapToObj(x -> IntStream.range(range[0], range[1] + 1).mapToObj(y -> new int[]{x, y}))
                .flatMap(x -> x)
                .filter(xy -> predicates.stream().allMatch(p -> p.test(xy[0], xy[1])))
                .forEach(xy -> System.out.println("(" + xy[0] + "," + xy[1] + ")"));
    }
}
