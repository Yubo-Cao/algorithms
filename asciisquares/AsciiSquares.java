package asciisquares;


import java.util.*;
import java.util.regex.Pattern;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class AsciiSquares {
    private static Scanner scan = new Scanner(System.in);

    public static void main(String[] args) {
        int testCaseCounts = scan.nextInt();
        IntStream.range(0, testCaseCounts).forEach(i -> {
            var squareLineCount = scan.nextInt();
            scan.nextLine();
            // Point width/height
            NavigableSet<Line> horizontalLines = new TreeSet<>(Comparator.comparing(Line::getStart, Point.yOrder)),
                    verticalLines = new TreeSet<>(Comparator.comparing(Line::getStart, Point.xOrder));

            Pattern horizontalLinePattern = Pattern.compile("(_ |^_|_$){1,}");
            IntStream.range(0, squareLineCount)
                    .forEach(y -> {
                        var line = scan.nextLine();
                        var xStart = line.indexOf("_");
                        if (xStart != -1) {
                            var matcher = horizontalLinePattern.matcher(line);
                            while (matcher.find(xStart)) {
                                var xEnd = matcher.end();
                                horizontalLines.put(new Point(xStart, y), xEnd - xStart);
                                xStart = xEnd;
                            }
                        }
                        xStart = line.indexOf("|");
                        while (xStart != -1) {
                            var prevVerticalLine = verticalLines.getOrDefault(new Point(xStart, y), 0);

                        }
                    });

        })
    }

    private static class Line implements Comparable<Line> {
        public static final Comparator<Line> naturalOrder = Comparator.comparing(Line::getStart).thenComparing(Line::getEnd);

        Point start;
        Point end;

        public Point getStart() {
            return start;
        }

        public void setStart(Point start) {
            this.start = start;
        }

        public Point getEnd() {
            return end;
        }

        public void setEnd(Point end) {
            this.end = end;
        }

        public Line(Point start, Point end) {
            this.start = start;
            this.end = end;
        }

        public int compareTo(Line o) {
            return start.compareTo(o.start);
        }
    }

    private static class Point implements Comparable<Point> {
        public static final Comparator<Point> naturalOrder = Comparator.comparing(Point::getX).thenComparing(Point::getY);
        public static final Comparator<Point> xOrder = Comparator.comparing(Point::getX);
        public static final Comparator<Point> yOrder = Comparator.comparing(Point::getY);

        int x;
        int y;

        public int getX() {
            return x;
        }

        public void setX(int x) {
            this.x = x;
        }

        public int getY() {
            return y;
        }

        public void setY(int y) {
            this.y = y;
        }

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public int compareTo(Point o) {
            return Integer.compare(x, o.x);
        }
    }
}
