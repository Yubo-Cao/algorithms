package asciisquares;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

class AsciiSquares {
    private List<List<Integer>> grid;

    public static void main(String[] args) {
        AsciiSquares asciiSquares = new AsciiSquares(5);
        System.out.println(asciiSquares);
    }

    public AsciiSquares(int rows) {
        this.grid = new ArrayList<List<Integer>>();
        new BufferedReader(new InputStreamReader(System.in)).lines().limit(rows)
                .map(row -> row.codePoints().boxed().collect(Collectors.toCollection(ArrayList::new)))
                .forEach(this.grid::add);
        for (List<Integer> row : this.grid) {
            if (row.get(row.size() - 1) == '_') {
                row.add((int) ' ');
            }
        }
    }

    public String toString() {
        return this.grid.stream().map(row -> row.stream().map(i -> (char) i.intValue()).map(String::valueOf).toList())
                .toList().toString();
    }
}