package codequest;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.stream.IntStream;

public class PlayfairCipher {
    private static final int encryptTableSize = 5;
    private static final int[][] encryptTable = new int[encryptTableSize][encryptTableSize];
    private static final Scanner scan = new Scanner(System.in);

    public static void main(String[] args) {
        var testCaseCount = scan.nextInt();
        IntStream.range(0, testCaseCount)
                .forEach(i -> {
                    var encryptedLine = scan.nextInt();
                    var key = scan.next();
                    generateEncryptTable(key);
                    var encrypted = new StringBuilder();
                    IntStream.range(0, encryptedLine)
                            .forEach(j -> {
                                var c = scan.next();
                                encrypted.append(decrypt(c));
                                encrypted.append(System.lineSeparator());
                            });
                    System.out.println(encrypted.toString().toLowerCase());
                });
    }

    private static void generateEncryptTable(String key) {
        Set<Integer> alreadyUsed = new HashSet<>(26);
        AtomicInteger index = new AtomicInteger(0);
        alreadyUsed.add((int) 'J');
        key.codePoints()
                .filter(Character::isLetter)
                .map(Character::toUpperCase)
                .filter(it -> !alreadyUsed.contains(it)) // J is omitted
                .distinct()
                .forEach(c -> {
                    alreadyUsed.add(c);
                    encryptTable[index.get() / encryptTableSize][index.getAndIncrement() % encryptTableSize] = c;
                });

        IntStream.range(65, 91)
                .boxed()
                .filter(it -> !alreadyUsed.contains(it)) // J is omitted and no reuse of characters
                .forEach(c -> encryptTable[index.get() / encryptTableSize][index.getAndIncrement() % encryptTableSize] = c);
    }

    private static String decrypt(String cipheredText) {
        // It is assumed that you already generated encrypt table.
        var prepared = cipheredText.codePoints()
                .boxed()
                .filter(Character::isLetter)
                .map(Character::toUpperCase)
                // .map(c -> c == 'J' ? 'X' : c) // replace any J with X. As instructed, don't care about X and leave it as is.
                .mapToInt(c -> c)
                .toArray();
        if (prepared.length % 2 != 0) {
            // This never happens. Encrypted text always has even numbered of characters.
            throw new IllegalArgumentException("Ciphered text is not even number of characters.");
        }
        var index = 0;
        var len = prepared.length;
        while (index < len) {
            int a = prepared[index++], b = prepared[index++];
            int[] indexA = indexOf(a), indexB = indexOf(b);
            // x is not handled!
            if (indexA[0] == indexB[0]) {// same row
                // move one to the left
                prepared[index - 1] = encryptTable[indexB[0]][(indexB[1] - 1 + encryptTableSize) % encryptTableSize];
                prepared[index - 2] = encryptTable[indexA[0]][(indexA[1] - 1 + encryptTableSize) % encryptTableSize];
            } else if (indexA[1] == indexB[1]) {// same column
                // move one up
                prepared[index - 1] = encryptTable[(indexB[0] - 1 + encryptTableSize) % encryptTableSize][indexB[1]];
                prepared[index - 2] = encryptTable[(indexA[0] - 1 + encryptTableSize) % encryptTableSize][indexA[1]];
            } else {
                // same row and same col as partner. Hence, swap
                prepared[index - 1] = encryptTable[indexB[0]][indexA[1]];
                prepared[index - 2] = encryptTable[indexA[0]][indexB[1]];
            }
        }
        return new String(prepared, 0, prepared.length);
    }

    private static int[] indexOf(int key) {
        for (int i = 0; i < encryptTableSize; i++) {
            for (int j = 0; j < encryptTableSize; j++) {
                if (encryptTable[i][j] == key) {
                    return new int[]{i, j};
                }
            }
        }
        throw new IllegalArgumentException("Key not found in encrypt table.");
    }
}
