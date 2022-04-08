import java.util.NoSuchElementException;
import java.util.Scanner;
import java.util.stream.Stream;
import java.lang.Math;
import java.util.Comparator;

public class AntiAsteriodWeapon {
    public static void main(String[] args) {
        try (var in = new Scanner(System.in)) {
            var limit = Long.valueOf(in.nextLine());
            for (int i = 0; i < limit; i++) {
                var numOfAsteriod = Integer.valueOf(in.nextLine());
                Stream.<String>generate(in::nextLine).limit(numOfAsteriod).map(coordinate -> {
                    var temp = coordinate.split("\\s+");
                    return new int[] { Integer.valueOf(temp[0]), Integer.valueOf(temp[1]) };
                })
                        .sorted(Comparator.comparing(coordinate -> Math.hypot(coordinate[0], coordinate[1])))
                        .forEach(coordinate -> {
                            System.out.printf("%d %d%n", coordinate[0], coordinate[1]);
                        });
            }
        } catch (NoSuchElementException e) {

        } catch (NumberFormatException e) {

        }
    }
}
