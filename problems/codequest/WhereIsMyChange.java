package codequest;
import java.math.BigDecimal;
import java.util.*;
import java.util.stream.Collectors;

public class WhereIsMyChange {
    public static void main(String[] args) {
        var scanner = new Scanner(System.in);
        var testCaseCount = scanner.nextInt();
        var instance = new WhereIsMyChange();
        for (int i = 0; i < testCaseCount; i++) {
            // BigDecimal is used here,
            // sadly, due to java don't store 0.1, 0.01 accurately double
            // and cause NullPointerException for "0.009999999" as no face value could
            // possibly bring it to 0.
            var change = scanner.nextBigDecimal();
            instance.solve(change);
        }
    }

    private void solve(BigDecimal change) {
        Map<PossibleFaceValue, Integer> changeMap = new HashMap<>();
        PriorityQueue<PossibleFaceValue> changeQueue = Arrays.stream(PossibleFaceValue.values()).collect(Collectors.toCollection(PriorityQueue::new));
        // Just a quicker way compare to Arrays.stream(xxx).skip(xxx).max();
        // Binary heap is great!
        while (change.compareTo(BigDecimal.ZERO) > 0) {
            PossibleFaceValue possibleFaceValue = changeQueue.poll();
            if (possibleFaceValue.faceValue.compareTo(change) > 0) {
                continue;
            }
            changeMap.put(possibleFaceValue, changeMap.getOrDefault(possibleFaceValue, 0) + 1);
            change = change.subtract(possibleFaceValue.faceValue);
            changeQueue.add(possibleFaceValue);
        }
        Arrays.stream(PossibleFaceValue.values()).map(it -> changeMap.getOrDefault(it, 0)).forEach(System.out::print);
    }

    enum PossibleFaceValue {
        HUNDRED(BigDecimal.valueOf(100)),
        FIFTY(BigDecimal.valueOf(50)),
        TWENTY(BigDecimal.valueOf(20)),
        TEN(BigDecimal.TEN),
        FIVE(BigDecimal.valueOf(5)),
        TWO(BigDecimal.valueOf(2)),
        ONE(BigDecimal.ONE),
        QUARTER(BigDecimal.valueOf(0.25)),
        DIffME(BigDecimal.valueOf(0.1)),
        NICKEL(BigDecimal.valueOf(0.05)),
        PENNY(BigDecimal.valueOf(0.01));

        public final BigDecimal faceValue;
        // By default, ordinal number of
        // enum values is used as its comparator.
        // Hence, we don't implement a compareTo(PossibleFaceValue other) method.

        PossibleFaceValue(BigDecimal faceValue) {
            this.faceValue = faceValue;
        }
    }
}
