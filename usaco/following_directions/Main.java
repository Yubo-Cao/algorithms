import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Main {
    private static int n;
    private static int[][] grid;
    private static int[] rprice;
    private static int[] dprice;
    private static int q;
    private static Point[] flips;
    private static Map<Point, Integer> costCache = new HashMap<>();

    public static void main(String[] args) {
        input();
        solve();
    }

    private static void solve() {
        System.out.println(getSum());
        for (int i = 0; i < q; i++) {
            costCache.clear();
            Point p = flips[i];
            grid[p.y][p.x] = 1 - grid[p.y][p.x];
            System.out.println(getSum());
        }
    }

    private static void printGrid() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(grid[i][j] == 1 ? "R" : "D");
                System.out.print(" ");
            }
            System.out.println();
        }
    }

    private static int getSum() {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += traceVertical(i) * rprice[i];
        }
        for (int i = 0; i < n; i++) {
            sum += traceHorizontal(i) * dprice[i];
        }
        return sum;
    }

    private static int traceHorizontal(int i) {
        int x = i, y = n - 1;
        int count = 0;
        while (x >= 0 && y >= 0) {
            if (grid[y][x] == 1) {
                x--;
            } else {
                y--;
            }
            count++;
        }
        return count;
    }

    private static int traceVertical(int i) {
        int x = n - 1, y = i;
        int count = 0;
        while (x >= 0 && y >= 0) {
            if (grid[y][x] == 1) {
                x--;
            } else {
                y--;
            }
            count++;
        }
        return count;
    }

    private static void input() {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            n = Integer.parseInt(br.readLine());
            grid = new int[n][n];
            rprice = new int[n];
            dprice = new int[n];
            for (int i = 0; i < n; i++) {
                String[] line = br.readLine().split(" ");
                int price = Integer.parseInt(line[1]);
                rprice[i] = price;
                for (int j = 0; j < n; j++) {
                    // 1 represents right price, 0 represents down price
                    grid[i][j] = line[0].charAt(i) == 'R' ? 1 : 0;
                }
            }
            String[] rawDprice = br.readLine().split(" ");
            for (int i = 0; i < n; i++) {
                dprice[i] = Integer.parseInt(rawDprice[i]);
            }

            q = Integer.parseInt(br.readLine());
            flips = new Point[q];
            for (int i = 0; i < q; i++) {
                String[] line = br.readLine().split(" ");
                int x = Integer.parseInt(line[1]) - 1;
                int y = Integer.parseInt(line[0]) - 1;
                flips[i] = new Point(x, y);
            }
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    private static class Point {
        final int x;
        final int y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public Point down() {
            return new Point(x, y + 1);
        }

        public Point right() {
            return new Point(x + 1, y);
        }

        public List<Point> path() {
            List<Point> path = new ArrayList<>();
            Point p = this;
            while (p.inBounds()) {
                path.add(p);
                if (grid[p.y][p.x] == 1) {
                    p = p.right();
                } else {
                    p = p.down();
                }
            }
            path.add(p);
            return path;
        }

        public boolean inBounds() {
            return x >= 0 && x < n && y >= 0 && y < n;
        }

        @Override
        public int hashCode() {
            final int prime = 31;
            int result = 1;
            result = prime * result + x;
            result = prime * result + y;
            return result;
        }

        @Override
        public boolean equals(Object obj) {
            if (this == obj)
                return true;
            if (obj == null)
                return false;
            if (getClass() != obj.getClass())
                return false;
            Point other = (Point) obj;
            if (x != other.x)
                return false;
            if (y != other.y)
                return false;
            return true;
        }

        @Override
        public String toString() {
            return "Point [x=" + x + ", y=" + y + "]";
        }
    }
}
