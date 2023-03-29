package codequest;
import java.util.*;
import java.util.regex.Pattern;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class AssembleTheTeam {
    /*
     * Personality score
     * - maximum gap between any two member in team must not greater than 10.
     * - Select as many team member as possible.
     * - Choose agent with lower letter, when tied.
     * Agent identifier, represents by a single uppercase letter(A-Z)
     */


    public static void main(String[] args) {
        try (var scanner = new Scanner(System.in)) {
            int numberOfTestCases = scanner.nextInt();
            scanner.nextLine();
            for (int i = 0; i < numberOfTestCases; i++) {
                var members = Member.fromStr(scanner.nextLine());
                // a little brutal here
                // As sample size will never exceed 26, brutal does not matter?
                members.sort(Comparator.comparing(Member::score));
                // Sort according to score. Break tie by name, when applicable. Higher name goes further left
                int maxCount = 0, maxIndex = 0;
                for (int j = 0; j < members.size(); j++) {
                    int count = 1, score = members.get(j).score;
                    while ((j - count) >= 0 && (score - members.get(j - count).score) <= 10) {
                        count++;
                    }
                    if (count > maxCount) {
                        maxCount = count;
                        maxIndex = j;
                    } else if (count == maxCount && count != 0) {
                        var oldMembers = members.subList(maxIndex - maxCount + 1, maxIndex + 1);
                        oldMembers.sort(Comparator.comparing(Member::name));
                        var newMembers = members.subList(j - count + 1, j + 1);
                        newMembers.sort(Comparator.comparing(Member::name));
                        if (IntStream.range(0, oldMembers.size()).anyMatch(index -> oldMembers.get(index).name.compareTo(newMembers.get(index).name) > 0)) {
                            // A member with higher name(codePoint) failed.
                            maxCount = count;
                            maxIndex = j;
                        }
                        members.sort(Comparator.comparing(Member::score));
                    }
                }
                System.out.println(members.subList(maxIndex - maxCount + 1, maxIndex + 1).stream().map(Member::name).sorted(Comparator.naturalOrder()).collect(Collectors.joining(" ")));
            }
        }
    }


    record Member(String name, int score) {
        private static Pattern regex = Pattern.compile("(?<name>[A-Z])=(?<score>\\d+)");

        public static Member oneFromStr(String str) {
            var matcher = regex.matcher(str);
            if (!matcher.find()) {
                throw new IllegalArgumentException("Invalid input");
            }
            return new Member(matcher.group("name"), Integer.parseInt(matcher.group("score")));
        }

        public static List<Member> fromStr(String str) {
            var matcher = regex.matcher(str);
            return matcher.results().map(m -> Member.oneFromStr(m.group())).collect(Collectors.toCollection(ArrayList::new));
        }
    }
}
