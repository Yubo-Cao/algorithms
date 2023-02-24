package find_and_replace;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.SocketTimeoutException;
import java.util.Map;

import javax.swing.plaf.metal.MetalIconFactory.FolderIcon16;

import java.util.HashMap;

public class Final {

    public static final String ALPHABETS = "ABCDGHKLNOPQRSTUWVXYZabcdefghijklmnopqrstuvwxyz";

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
            System.exit(1); // wth
        }
    }

    private static int solve(String src, String dst) {
        int i = 0, j = 0;
        Map<Character, Character> modifications = initializedModification();
        
        return 0;
    }

    private static Map<Character, Character> initializedModification() {
        Map<Character, Character> modifications = new HashMap<>();
        for (char c : ALPHABETS.toCharArray()) {
            modifications.put(c, c);
        }
        return modifications;
    }
}
