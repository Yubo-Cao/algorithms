package find_and_replace;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

public class Main {
    private static final String ALPHABET = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            int n = Integer.parseInt(br.readLine());
            while (n-- > 0) {
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
        int n = src.length(), m = dst.length();
        if (n != m)
            return -1;
        if (src.equals(dst))
            return 0;
        int dp[][] = new int[n + 1][n + 1];
        // transform first i-th of src to j-th of dst, for dp[i][j]
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                dp[i][j] = Integer.MAX_VALUE;
            }
        }
        // first 0-th of src to 0-th of dst
        dp[0][0] = 0;
        char[] sc = src.toCharArray();
        char[] dc = dst.toCharArray();

        Map<Character, Integer> usedSource = new HashMap<>();
        for (int i = 1; i <= n; i++) {
            usedSource.put(sc[i - 1], usedSource.getOrDefault(sc[i - 1], 0) + 1);
        }
        // dp
        /*
         * Min-replace for i, j =
         * min(
         * - dp[i - 1][j - 1] for sc[i] == dc[j]
         * - dp[i - 1][j - 1] + 1 for sc[i] != dc[j], and sc[i] not in sc[0..i - 1]
         * - dp[i - 1][j - 1] + 2 for sc[i] != dc[j], but there are some k in alphabet
         * such that k not in sc[0..i - 1]
         * )
         */
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (sc[i - 1] == dc[j - 1])
                    // equal, advance
                    dp[i][j] = dp[i - 1][j - 1];
                else if (usedSource.getOrDefault(sc[i - 1], 0) == 1 &&
                        usedSource.getOrDefault(dc[i - 1], 0) == 0)
                    // not equal, but can be replaced directly
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else if (usedSource.getOrDefault(sc[i - 1], 0) == 1
                        && ALPHABET.codePoints().anyMatch(c -> usedSource.getOrDefault((char) c, 0) == 0))
                    // not equal, but can be replaced with some other char
                    dp[i][j] = dp[i - 1][j - 1] + 2;
                else
                    // no way
                    dp[i][j] = Integer.MAX_VALUE;
            }
        }
        return dp[n][m] == Integer.MAX_VALUE ? -1 : dp[n][m];
    }
}
