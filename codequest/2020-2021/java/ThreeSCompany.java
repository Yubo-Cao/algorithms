package codequest;
import java.util.*;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.function.BiFunction;
import java.util.function.Function;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class ThreeSCompany {
    // NP problems
    // 3 satisfiability problems - 3SAT
    private static Scanner scan = new Scanner(System.in);

    public static void main(String[] args) {
        int testCaseCount = scan.nextInt();
        IntStream.range(0, testCaseCount).forEach(i -> {
            int tripletCount = scan.nextInt();
            int evalCount = scan.nextInt();
            var expression = parse(tripletCount);
            solve(expression, evalCount);
        });
    }

    private static Expression parse(int lineCount) {
        scan.nextLine();
        return IntStream.range(0, lineCount).mapToObj(i -> {
            var line = scan.nextLine();
            return Arrays.stream(line.split("\\s+"))
                    .map(it -> {
                        if (it.startsWith("!")) {
                            return new UnaryExpression(new Variable(it.substring(1)), UnaryOperator.NOT);
                        } else {
                            return new Variable(it);
                        }
                    }).reduce((a, b) -> new BiExpression(a, b, Operator.OR)).orElseThrow(); // Since it always provide a triplet
        }).reduce((a, b) -> new BiExpression(a, b, Operator.AND)).orElseThrow(); // Since it always provide at least two triplets. It must be at least one
    }

    private static void solve(Expression expression, int testCaseCount) {
        IntStream.range(0, testCaseCount).forEach(i -> {
            var line = scan.nextLine();
            var key = new AtomicInteger(65);
            Map<Expression, Boolean> values = Arrays.stream(line.split("\\s+"))
                    .map(it -> it.equals("1"))
                    .collect(Collectors.toMap(it -> new Variable(new String(new int[]{key.getAndIncrement()}, 0, 1)), Function.identity()));
            System.out.println(expression.eval(values)? "TRUE" : "FALSE");
        });
    }

    private static abstract class Expression {
        public abstract boolean eval(Map<Expression, Boolean> unknowns);
    }

    // In Python, eval("A or B or C ...") and global.update() or pass an dict to eval would be enough.
    private static class Variable extends Expression {
        private final String name;

        public Variable(String name) {
            this.name = name;
        }

        public boolean eval(Map<Expression, Boolean> unknowns) {
            return unknowns.get(this);
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Variable variable = (Variable) o;
            return Objects.equals(name, variable.name);
        }

        @Override
        public int hashCode() {
            return Objects.hash(name);
        }

        public String toString() {
            return name;
        }
    }

    enum Operator {
        AND((a, b) -> a && b),
        OR((a, b) -> a || b);

        public final BiFunction<Boolean, Boolean, Boolean> op;

        Operator(BiFunction<Boolean, Boolean, Boolean> op) {
            this.op = op;
        }
    }

    enum UnaryOperator {
        NOT((a) -> !a);
        public final Function<Boolean, Boolean> op;

        UnaryOperator(Function<Boolean, Boolean> op) {
            this.op = op;
        }
    }

    private static class BiExpression extends Expression {
        private Expression left;
        private Expression right;
        private Operator operator;

        public BiExpression(Expression left, Expression right, Operator operator) {
            this.left = left;
            this.right = right;
            this.operator = operator;
        }

        @Override
        public boolean eval(Map<Expression, Boolean> unknowns) {
            return operator.op.apply(left.eval(unknowns), right.eval(unknowns));
        }

        @Override
        public String toString() {
            return "(" + left + ") " + operator + " (" + right + ")";
        }
    }

    private static class UnaryExpression extends Expression {
        private Expression expression;
        private UnaryOperator operator;

        public UnaryExpression(Expression expression, UnaryOperator operator) {
            this.expression = expression;
            this.operator = operator;
        }

        @Override
        public boolean eval(Map<Expression, Boolean> unknowns) {
            return operator.op.apply(expression.eval(unknowns));
        }

        @Override
        public String toString() {
            if (expression instanceof Variable) {
                return operator + " " + expression;
            } else {
                return operator + "(" + expression + ")";
            }
        }
    }

}
