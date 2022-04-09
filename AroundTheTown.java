import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class AroundTheTown {
    private static final Set<Point> landMarks = new HashSet<>();
    private static final Set<Point> centroids = new HashSet<>();
    private static final Scanner scan = new Scanner(System.in);

    public static void main(String[] args) {
        var testCaseCounts = scan.nextInt();
        IntStream.range(0, testCaseCounts).forEach(i -> {
            parse();
            kMeansAlgorithm();
            centroids.stream().forEach(System.out::println);
        });
    }

    private static void parse() {
        int L = scan.nextInt(), S = scan.nextInt();
        IntStream.range(0, L).forEach(i -> addPoints(i, landMarks));
        IntStream.range(0, S).forEach(i -> addPoints(i, centroids));
    }

    private static void addPoints(int index, Set<Point> points) {
        Point p = new Point(scan.nextInt(), scan.nextInt());
        points.add(p);
    }

    private static void kMeansAlgorithm() {
        while (true) {
            var clusters = landMarks.stream()
                    .collect(Collectors.groupingBy(pt -> centroids.stream()
                            .min(Comparator.comparing(pt::distance))));
            var oldCentroids = new HashSet<>(centroids);
            centroids.clear();
            clusters.values().forEach(cluster -> {
                var centroid = Point.average(cluster.toArray(Point[]::new));
                centroids.add(centroid);
            });
            if (oldCentroids.containsAll(centroids)) {
                break;
            }
        }
    }

}

record Point(double x, double y) implements Comparable<Point> {
    public double distance(Point p) {
        return Math.sqrt(Math.pow(x - p.x, 2) + Math.pow(y - p.y, 2));
    }

    public static Point average(Point... points) {
        var avgX = Arrays.stream(points).collect(Collectors.summarizingDouble(Point::x)).getAverage();
        var avgY = Arrays.stream(points).collect(Collectors.summarizingDouble(Point::y)).getAverage();
        return new Point(avgX, avgY);
    }

    @Override
    public String toString() {
        return String.format("%.1f %.1f", x, y);
    }

    @Override
    public int compareTo(Point o) {
        var res = Double.compare(x, o.x);
        if (res == 0) {
            return Double.compare(y, o.y);
        }
        return res;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Point point = (Point) o;
        return Double.compare(point.x, x) == 0 && Double.compare(point.y, y) == 0;
    }

    @Override
    public int hashCode() {
        // HashSet will use this method to check if two points are equal
        return Objects.hash(x, y);
    }
}

