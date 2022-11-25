package complexcode;

import java.util.*;
import java.util.regex.Pattern;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class ComplexCode {
    public static void main(String... args) {
        var scan = new Scanner(System.in);
        var testCaseCount = scan.nextInt();
        for (int i = 0; i < testCaseCount; i++) {
            int lineNumber = scan.nextInt(), expC = scan.nextInt(), expN = scan.nextInt();
            scan.nextLine();
            var code = new StringBuilder(lineNumber << 4);
            for (int j = 0; j < lineNumber; j++) {
                code.append(scan.nextLine()).append(System.lineSeparator());
            }
            solve(code.toString(), expC, expN);
        }
    }

    private static void solve(String code, int C, int N) {
        var tokens = tokenize(code);
        var actC = findCyclomaticComplexity(tokens);
        var actN = findNestedStatements(tokens);
        System.out.printf("%d %d %s%n", actC, actN, (actC <= C && actN <= N) ? "PASS" : "FAIL");
    }

    public static final Set<String> OPERATORS = new HashSet<>(Set.of(">", "<", "<=", ">=", "==", "!="));
    public static final Set<String> KEYWORDS = new HashSet<>(Set.of("Else", "If", "Print"));

    private static List<Token> tokenize(String code) {
        var allRegex = Pattern.compile(Arrays.stream(TokenType.values()).map(tokenType -> "(?<" + tokenType.name() + ">" + tokenType.regex + ")").collect(Collectors.joining("|")), Pattern.MULTILINE);

        var matcher = allRegex.matcher(code);
        var tokens = new ArrayList<Token>();
        while (matcher.find()) {
            Arrays.stream(TokenType.values()).map(it -> new Token(it, matcher.group(it.name()))).filter(it -> it.value != null && !it.value.isEmpty()).map(it -> new Token(it.type, it.value.strip())).forEach(tokens::add);
        }
        return tokens;
    }

    enum TokenType {
        NUMBER("\\d+"),
        OPERATOR(OPERATORS.stream().map(Pattern::quote).collect(Collectors.joining("|"))),
        KEYWORD(KEYWORDS.stream().map(Pattern::quote).collect(Collectors.joining("|"))),
        STRING("\".*?\""),
        BRACKET("\\{|\\}"),
        IDENTIFIER("\\w+");


        public final String regex;

        TokenType(String regex) {
            this.regex = regex;
        }
    }

    record Token(TokenType type, String value) {

    }

    // Cyclomatic complexity
    // Number of possible paths.
    // As they are limited to if. and any if,
    // If it exists, regardless whether it has a else
    // cause C++
    // hence, count if + 1 is enough.
    public static long findCyclomaticComplexity(List<Token> tokens) {
        return tokens.stream().filter(it -> it.type == TokenType.KEYWORD && it.value.equals("If")).count() + 1;
    }


    // Max depth of nesting brackets.
    public static int findNestedStatements(List<Token> tokens) {
        Stack<Token> brackets = new Stack<>();
        var it = tokens.iterator();
        var max = 0;
        while (it.hasNext()) {
            var token = it.next();
            if (token.type == TokenType.BRACKET) {
                if (token.value.equals("{")) {
                    brackets.push(token);
                    max = Math.max(brackets.size(), max);
                } else {
                    brackets.pop();
                }
            }
        }
        return max;
    }

    private static IntStream revRange(int from, int to) {
        return IntStream.range(from, to)
                .map(i -> to - i + from - 1);
    }

    private static boolean isBefore(List<Token> tokens, int i, String val) {
        return revRange(i, 0).mapToObj(tokens::get).takeWhile(it -> it.type != TokenType.KEYWORD && !it.value.equals(val))
                .allMatch(it -> it.type == TokenType.NUMBER || it.type == TokenType.OPERATOR || it.type == TokenType.IDENTIFIER);
    }
}
