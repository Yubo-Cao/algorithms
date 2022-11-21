package codequest;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.NavigableMap;
import java.util.Scanner;
import java.util.TreeMap;
import java.util.stream.IntStream;

public class RescheduleIt {
    private static NavigableMap<LocalDate, Integer> productionSchedule = new TreeMap<>();
    private static NavigableMap<LocalDate, Integer> purchaseOrder = new TreeMap<>();
    private static DateTimeFormatter parser = DateTimeFormatter.ofPattern("yyyy-MM-dd");
    private static final Scanner scan = new Scanner(System.in);

    public static void main(String[] args) {
        var testCaseCount = scan.nextInt();
        for (int i = 0; i < testCaseCount; i++) {
            parse();
            System.out.println(eval() ? "OK" : "NOT OK");
        }
    }

    private static void parse() {
        var P = scan.nextInt();
        var Q = scan.nextInt();
        scan.nextLine();
        putToMap(P, productionSchedule);
        putToMap(Q, purchaseOrder);
    }

    private static void putToMap(int q, NavigableMap<LocalDate, Integer> purchaseOrder) {
        IntStream.range(0, q).forEach(i -> {
            var line = scan.nextLine();
            var res = line.split("\\s+");
            var date = LocalDate.parse(res[0], parser);
            var quantity = Integer.parseInt(res[1]);
            purchaseOrder.put(date, quantity);
        });
    }

    private static boolean eval() {
        // See if any air craft will be:
        // Put in stock for more than 28 days
        // Sell within 1 day
        // Run out of stock within.
        // If so, return false.
        while (!productionSchedule.isEmpty() && !purchaseOrder.isEmpty()) {
            var prod = productionSchedule.pollFirstEntry();
            var ord = purchaseOrder.pollFirstEntry();
            if (prod.getKey().isAfter(ord.getKey())) {
                // If early, by no mean it would fulfill it.
                return false;
            }
            if (prod.getKey().isBefore(ord.getKey().minusDays(28))) {
                // 28 days before and haven't sold, failed
                return false;
            }
            if (prod.getValue() < ord.getValue()) {
                purchaseOrder.put(ord.getKey(), ord.getValue() - prod.getValue()); // Prod is already consumed.
                var succeed = false;
                while (!productionSchedule.isEmpty() && productionSchedule.firstEntry().getKey().compareTo(ord.getKey().minusDays(1)) <= 0) { // 1 Day before it could be sold
                    prod = productionSchedule.pollFirstEntry();
                    if (prod.getValue() < ord.getValue()) {
                        purchaseOrder.put(ord.getKey(), ord.getValue() - prod.getValue());
                    } else {
                        // Ord is fulfilled
                        productionSchedule.put(prod.getKey(), prod.getValue() - ord.getValue());
                        succeed = true;
                        break;
                    }
                }
                if (!succeed) {
                    return false;
                }
            } else if (prod.getValue() != ord.getValue()) { // if equal, then already done. Do nothing.
                productionSchedule.put(prod.getKey(), prod.getValue() - ord.getValue()); // Ord is fulfilled
            }
        }
        return true;
    }
}
