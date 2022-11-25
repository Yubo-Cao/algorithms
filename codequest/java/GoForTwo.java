package codequest;
import java.util.Arrays;
import java.util.Map;
import java.util.NoSuchElementException;
import java.util.Scanner;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class GoForTwo {
    public final static Map<Integer, Integer> RECOMMENDATIONS = Map.<Integer, Integer>ofEntries(
            Map.entry(-15, 2),
            Map.entry(-14, 1),
            Map.entry(-13, 2),
            Map.entry(-12, 1),
            Map.entry(-11, 2),
            Map.entry(-10, 2),
            Map.entry(-9, 1),
            Map.entry(-8, 2),
            Map.entry(-7, 1),
            Map.entry(-6, 1),
            Map.entry(-5, 2),
            Map.entry(-4, 2),
            Map.entry(-3, 1),
            Map.entry(-2, 2),
            Map.entry(-1, 1),
            Map.entry(0, 1),
            Map.entry(1, 2),
            Map.entry(2, 1),
            Map.entry(3, 1),
            Map.entry(4, 1),
            Map.entry(5, 2),
            Map.entry(6, 1),
            Map.entry(7, 1),
            Map.entry(8, 1),
            Map.entry(9, 1),
            Map.entry(10, 1),
            Map.entry(11, 1),
            Map.entry(12, 2));

    public static void main(String[] args) {
        try (var in = new Scanner(System.in)) {
            var limit = Long.valueOf(in.nextLine());
            Stream.<String>generate(in::nextLine).limit(limit).forEach(it -> {
                var temp = Arrays.stream(it.split("\\s+")).map(Integer::valueOf).collect(Collectors.toList());
                System.out.println(RECOMMENDATIONS.getOrDefault(temp.get(0) - temp.get(1), 1));
            });
        } catch (NoSuchElementException e) {

        } catch (NumberFormatException e) {

        }
    }
}
