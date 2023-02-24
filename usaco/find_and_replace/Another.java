package find_and_replace;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Map;
import java.util.stream.Collectors;
import java.util.NavigableMap;
import java.util.TreeMap;

public class Another {
    private static int n = 0;

    public static void main(String... args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            n = Integer.parseInt(br.readLine());
            for (int i = 0; i < n; i++) {
                String src = br.readLine();
                String dst = br.readLine();
                System.out.println(solve(src, dst));
            }
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    private static int solve(String src, String dst) {
        Map<Character, Integer> srcChars = new TreeMap<>(src.codePoints().mapToObj(c -> (char) c)
                .collect(Collectors.toMap(c -> c, c -> 1, Integer::sum)));
        Map<Character, Integer> dstChars = new TreeMap<>(dst.codePoints().mapToObj(c -> (char) c)
                .collect(Collectors.toMap(c -> c, c -> 1, Integer::sum)));
        if (srcChars == dstChars)
            return 0;
        if (srcChars.size() != dstChars.size())
            return -1;
        int count = 0;
        while(!dstChars.isEmpty()) {
            
        }
        return -1;
    }
}
