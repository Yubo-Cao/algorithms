package codequest;
import java.util.NoSuchElementException;
import java.util.Scanner;
import java.util.stream.Stream;

public class DotDotDot {
    public static void main(String[] args) {
        try (var in = new Scanner(System.in)) {
            var limit = Long.valueOf(in.nextLine());
            Stream.<String>generate(in::nextLine).limit(limit).forEach(it -> {
                System.out.println(it.codePoints().filter(e -> e >= 97 && e <= 122).map(e -> e - 96).sum());
            });
        } catch (NoSuchElementException e) {

        } catch (NumberFormatException e) {

        }
    }
}
