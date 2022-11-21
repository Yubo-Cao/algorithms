package codequest;
import java.util.NoSuchElementException;
import java.util.Scanner;
import java.util.stream.Stream;

class EvenOdd {
    public static void main(String[] args) {
        try (var in = new Scanner(System.in)) {
            var limit = Long.valueOf(in.nextLine());
            Stream.generate(in::next).limit(limit).forEach(
                    input -> {
                        switch (input.charAt(input.length() - 1)) {
                            case 48:
                            case 56:
                            case 54:
                            case 52:
                            case 50:
                                System.out.println("EVEN");
                                break;
                            default:
                                System.out.println("ODD");
                                break;
                        }
                    });
        } catch (NoSuchElementException e) {
        } catch (NumberFormatException e) {
        }
    }
}