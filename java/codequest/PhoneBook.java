package codequest;
import java.util.NoSuchElementException;
import java.util.Scanner;
import java.util.stream.Stream;

public class PhoneBook {
    public static void main(String[] args) {
        try (var in = new Scanner(System.in)) {
            var limit = Long.valueOf(in.nextLine());
            Stream.<String>generate(in::nextLine).limit(limit).forEach(it -> {
                var temp = it.split("\\s+");
                System.out.println(PhoneNumberFormatter.valueOf(temp[1]).formatPhoneNumber(temp[0]));
            });
        } catch (NoSuchElementException e) {

        } catch (NumberFormatException e) {

        } catch (ArrayIndexOutOfBoundsException e) {

        }
    }

    private enum PhoneNumberFormatter {
        PARENTHESES("(%3$03d) %2$03d-%1$04d"),
        DASHES("%3$03d-%2$03d-%1$04d"),
        PERIODS("%3$03d.%2$03d.%1$04d");

        private PhoneNumberFormatter(String fString) {
            this.fString = fString;
        }

        private final String fString;

        public String formatPhoneNumber(String number) {
            try {
                return formatPhoneNumber(Long.valueOf(number));
            } catch (NumberFormatException e) {

            }
            return null;
        }

        public String formatPhoneNumber(long number) {
            return String.format(fString, number % 10000, (number /= 10000) % 1000, (number /= 1000) % 1000);
        }
    }
}
