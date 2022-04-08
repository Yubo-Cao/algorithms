import java.util.Arrays;
import java.util.Comparator;
import java.util.NoSuchElementException;
import java.util.Scanner;
import java.util.stream.Stream;

public class BiggerIsBetter {
    public static void main(String[] args) {
        try (var in = new Scanner(System.in)) {
            var limit = Long.valueOf(in.nextLine());
            Stream.<String>generate(in::nextLine).limit(limit).forEach(it -> {
                System.out.println(
                        Arrays.stream(it.split("\\s+")).map(its -> Integer.valueOf(its)).max(Comparator.naturalOrder())
                                .orElseThrow());
            });
        } catch (NoSuchElementException e) {

        } catch (NumberFormatException e) {

        }
    }
}
