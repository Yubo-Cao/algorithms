package AroundAndAround;
import java.util.*;
import java.io.*;
import java.text.DecimalFormat;

public class AroundAndAround {
    public static void main(String[] args) {
        try {
        Scanner sc = new Scanner(System.in);
        int numCases = Integer.valueOf(sc.nextLine());
        DecimalFormat df1 = new DecimalFormat("0.0");
        for (int i = 0; i < numCases; i++) {
            int distance = Integer.valueOf(sc.nextLine());
            System.out.println(df1.format(((40075/(2*Math.PI))+distance) * 2 * Math.PI));
        }
    }
        catch (Exception e) {}
    }

}
