package countdowntolaunch;

import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.Comparator;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.util.stream.IntStream;

public class CountdownToLaunch {
    // YYYY-MM-DD HH:MM CloudThickNessInMeter DecimalValueOfWindSpeed DirectionInDegrees
    private static Pattern regex = Pattern.compile("(?<dateTime>\\d{4}-\\d{2}-\\d{2} \\d{2}:\\d{2}) (?<cloudThick>\\d+) (?<windSpeed>\\d+\\.\\d+) (?<direction>\\d+)");

    private static DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm");

    public static void main(String[] args) {
        try (var scanner = new Scanner(System.in)) {
            var testCaseCount = scanner.nextInt();
            for (int i = 0; i < testCaseCount; i++) {
                var possibleLaunchTimesCount = scanner.nextInt();
                IntStream.range(0, possibleLaunchTimesCount)
                        .mapToObj(lp -> scanner.nextLine())
                        .map(regex::matcher)
                        .filter(Matcher::find)
                        .filter(m -> {
                            double windSpeed = Double.parseDouble(m.group("windSpeed"));
                            double direction = (360 - Double.parseDouble(m.group("direction")) + 90) * Math.PI / 180;
                            return Integer.parseInt(m.group("cloudThick")) <= 1000 && Math.abs(windSpeed * Math.sin(direction)) <= 20 && Math.abs(windSpeed * Math.cos(direction)) <= 40;
                        })
                        .min(Comparator.comparing(m -> formatter.parse(m.group("dateTime"), LocalDateTime::from)))
                        .ifPresentOrElse(
                                m -> System.out.println(m.group("dateTime")),
                                () -> System.out.println("ABORT LAUNCH")
                        );
                if (i < testCaseCount - 1) {
                    scanner.nextLine();
                }
            }
        }
    }
}
