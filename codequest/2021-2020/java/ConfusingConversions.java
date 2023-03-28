package codequest;
import java.util.Arrays;
import java.util.Scanner;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.regex.*;
import java.util.stream.Collectors;

public class ConfusingConversions {
    private static Pattern regex = Pattern.compile("^(formatDate|formatHeight|concatenate)\\s*(.*)$", Pattern.MULTILINE);

    public static void main(String[] args) {
        var scan = new Scanner(System.in);
        var testCaseCount = scan.nextInt();
        scan.nextLine();
        for (int i = 0; i < testCaseCount; i++) {
            System.out.println(solve(scan.nextLine()));
        }
    }

    private static String solve(String line) {
        var match = regex.matcher(line);
        if(!match.find()){
            throw new IllegalArgumentException("Input must match regex " + regex.toString());
        }
        var args = Arrays.stream(match.group(2).split("\\s"));
        switch (match.group(1)) {
            case "formatDate" -> {
                var count = new AtomicInteger();
                return args.map(Integer::valueOf).map(it -> switch (count.incrementAndGet()) {
                    case 1 -> String.format("%04d", it);
                    case 2 -> String.format("%02d", it);
                    case 3 -> String.format("%02d", it);
                    default -> throw new IllegalArgumentException("Unknown internal error.");
                }).collect(Collectors.joining(""));
            }
            case "formatHeight" -> {
                var list = args.collect(Collectors.toList());
                return list.get(0) + "'" + list.get(1) + "''";
            }
            case "concatenate" -> {
                return args.collect(Collectors.joining(","));
            }
            default -> throw new RuntimeException("Unknown internal error.");
        }
    }
}
