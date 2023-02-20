import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class IntervalPoint {
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            int n = Integer.parseInt(br.readLine());
            int[][] intervals = new int[n][2];
            for (int i = 0; i < n; i++) {
                String[] line = br.readLine().split(" ");
                intervals[i][0] = Integer.parseInt(line[0]);
                intervals[i][1] = Integer.parseInt(line[1]);
            }
            Arrays.sort(intervals, (a, b) -> a[1] - b[1]);
            long count = 0, end = Long.MIN_VALUE;
            for (int i = 0; i < n; i++) {
                if (intervals[i][0] > end) {
                    count++;
                    end = intervals[i][1];
                }
            }
            System.out.println(count);
        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}