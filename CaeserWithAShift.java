import java.util.Arrays;
import java.util.Scanner;
import java.util.stream.Stream;

public class CaeserWithAShift {
    public static void main(String[] args) {
        try (var scanner = new Scanner(System.in)) {
            var testCaseCount = scanner.nextInt();
            scanner.nextLine();
            for (var testCase = 0; testCase < testCaseCount; testCase++) {
                var text = scanner.nextLine();
                var shift = Arrays.stream(scanner.nextLine().split("\\s")).mapToInt(Integer::parseInt).toArray();
                var sign = Arrays.stream(scanner.nextLine().split("\\s")).mapToInt(Integer::parseInt).toArray();
                System.out.println(new CaeserWithAShift().decrypt(text, shift, sign));
            }
        }
    }

    private String decrypt(String text, int[] shift, int[] sign) {
        var shiftIter = Stream.generate(() -> Arrays.stream(shift)).flatMapToInt(s -> s).iterator();
        var signIter = Stream.generate(() -> Arrays.stream(sign)).flatMapToInt(s -> s).iterator();

        return new String(text.codePoints().map(c -> {
            if (Character.isLetter(c)) {
                c = Character.toLowerCase(c);
                c -= 'a';
                c += (signIter.next() == 0) ? shiftIter.next() : -shiftIter.next();
                return c % 26 + 'a';
            } else {
                return c;
            }
        }).toArray(), 0, text.length());
    }
}
