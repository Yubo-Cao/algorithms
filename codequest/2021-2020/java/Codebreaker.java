package codequest;
import java.util.Map;
import java.util.Scanner;
import java.util.stream.Collectors;

public class Codebreaker {
    // Aka, use hashmap to count letters.
    public static void main(String[] args) {
        var scan = new Scanner(System.in);
        var testCaseCount = scan.nextInt();
        for (int i = 0; i < testCaseCount; i++) {
            var lineCount = scan.nextInt();
            scan.nextLine();
            var res = new StringBuilder(2000);
            for (int j = 0; j < lineCount; j++) {
                res.append(scan.nextLine());
            }
            String str = res.toString();
            var total = str.codePoints().filter(it -> 65 <= it && it <= 90 || 97 <= it && it <= 122).count();
            solve(str).entrySet().stream().sorted(Map.Entry.comparingByKey()).forEach(entry -> {
                System.out.printf("%s: %.2f%%%n", new String(new int[]{entry.getKey()}, 0, 1), ((double) entry.getValue() / total) * 100);
            });
        }
    }

    private static Map<Integer, Long> solve(String lines) {
        /**
         * Map<Integer(CodePoint),Long(Count)>
         */
        return lines.codePoints().filter(it -> 65 <= it && it <= 90 || 97 <= it && it <= 122).boxed().collect(Collectors.groupingBy(it -> (it >= 97) ? it - 32 : it, Collectors.counting()));
    }
}
