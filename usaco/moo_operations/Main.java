import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    private static Map<String, Integer> STRING2OPERATIONS = new HashMap<String, Integer>();

    static {
        f("M", -1);
        f("O", -1);
        f("MM", -1);
        f("MO", -1);
        f("OM", -1);
        f("OO", -1);
        f("MMM", -1);
        f("MMO", -1);
        f("MOM", 1); // replace last M with O
        f("MOO", 0); // already MOO
        f("OMM", -1);
        f("OMO", -1);
        f("OOM", 2); // replace first O with M, and then replace last M with O
        f("OOO", 1); // replace first O with M
    }

    private static void f(String s, int i) {
        STRING2OPERATIONS.put(s, i);
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        scan.nextLine();
        for (int i = 0; i < n; i++) {
            String s = scan.nextLine();
            System.out.println(solve(s));
        }
        scan.close();
    }

    private static int solve(String s) {
        int len = s.length();
        int result = -1;
        for (int i = 0; i <= len - 3; i++) {
            int operations = STRING2OPERATIONS.get(s.substring(i, i + 3));
            if (operations != -1) {
                if (result != -1)
                    result = Math.min(result, len - 3 + operations);
                else
                    result = len - 3 + operations;
            }
        }
        return result;
    }
}
