import java.util.Arrays;
import java.util.NavigableMap;
import java.util.Scanner;
import java.util.TreeMap;
import java.util.stream.IntStream;

public class DiveTime {
    // Goal: find decompression stops
    private static NavigableMap<Integer, NavigableMap<Integer, NavigableMap<Integer, Integer>>> data = new TreeMap<>();
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int numberOfTestCases = scanner.nextInt();
        for (int i = 0; i < numberOfTestCases; i++) {
            int X = scanner.nextInt(), D = scanner.nextInt();
            scanner.nextLine(); // Weird bug.
            parse(X);
            solve(D);
        }
    }

    private static void parse(int numberOfEntries) {
        IntStream.range(0, numberOfEntries).forEach(i -> {
            int[] input = Arrays.stream(scanner.nextLine().split("\\s+")).mapToInt(Integer::parseInt).toArray();
            int maxDepth = input[0], maxBottomTime = input[1], depthOfCompressionStop = input[2], timeOfStop = input[3];
            data.computeIfAbsent(maxDepth, k -> new TreeMap<>());
            var decompressionSchedules = data.get(maxDepth);
            decompressionSchedules.computeIfAbsent(maxBottomTime, k -> new TreeMap<>((a, b) -> -Integer.compare(a, b))); // descending
            var stopSchedule = decompressionSchedules.get(maxBottomTime);
            stopSchedule.put(depthOfCompressionStop, timeOfStop);
        });
    }

    private static void solve(int numberOfTestCases) {
        IntStream.range(0, numberOfTestCases).forEach(i -> {
            int[] input = Arrays.stream(scanner.nextLine().split("\\s+")).mapToInt(Integer::parseInt).toArray();
            int maxDepth = input[0], bottomTime = input[1];
            var scheduleKey = data.ceilingKey(maxDepth);
            var schedule = data.get(scheduleKey);
            var bottomTimeKey = schedule.ceilingKey(bottomTime);
            var res = schedule.get(bottomTimeKey);
            if (res.containsKey(0)) {
                System.out.println("No Stop");
            } else {
                res.entrySet().stream().forEach(e -> System.out.println(e.getKey() + " " + e.getValue()));
            }
        });

    }
}
