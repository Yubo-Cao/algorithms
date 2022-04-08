import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.stream.Collectors;

public class PlayingWithPolynomials {
    public static void main(String[] args) {
        try (var scan = new Scanner(System.in)) {
            int testCases = scan.nextInt();
            scan.nextLine();
            for (int i = 0; i < testCases; i++) {
                var coeffsA = Arrays.stream(scan.nextLine().split("\\s+")).mapToInt(Integer::parseInt).toArray();
                var coeffsB = Arrays.stream(scan.nextLine().split("\\s+")).mapToInt(Integer::parseInt).toArray();
                var expA = new Expression(coeffsA);
                var expB = new Expression(coeffsB);
                System.out.println(expA.multiply(expB));
            }
        }
    }
}

class Expression {
    private PriorityQueue<Term> terms = new PriorityQueue<>(Comparator.comparing(Term::exp));

    public Expression(int[] coefficients) {
        for (int i = 0; i < coefficients.length; i++) {
            if (coefficients[i] != 0) {
                terms.add(new Term(coefficients[i], i));
            }
        }
    }

    public Expression() {
    }

    public Expression multiply(Expression other) {
        Expression result = new Expression();
        for (Term term : terms) {
            for (Term otherTerm : other.terms) {
                result.terms.add(term.multiply(otherTerm));
            }
        }
        result.simplify();
        return result;
    }

    private void simplify() {
        PriorityQueue<Term> newTerms = new PriorityQueue<>(Comparator.comparing(Term::exp));
        if (terms.size() != 0) {
            while (!terms.isEmpty()) {
                int exp = terms.peek().exp();
                int coeff = 0;
                while (!terms.isEmpty() && terms.peek().exp() == exp) {
                    coeff += terms.poll().coeff();
                }
                newTerms.add(new Term(coeff, exp));
            }
        }
        terms = newTerms;
    }

    public String toString() {
        return terms.stream().map(Term::toString).collect(Collectors.joining("+"));
    }
}

record Term(int coeff, int exp) {
    public Term multiply(Term other) {
        return new Term(coeff * other.coeff, exp + other.exp);
    }

    public String toString() {
        if (coeff != 0) {
            if (coeff == 1 && exp != 0) {
                return "x^" + exp;
            } else if (exp != 1) {
                return coeff + "x^" + exp;
            } else {
                return coeff + "x";
            }
        } else {
            return "";
        }
    }
}