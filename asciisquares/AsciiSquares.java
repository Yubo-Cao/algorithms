package asciisquares;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

class AsciiSquares {
    private List<List<Token>> grid;
    private int x, y;

    public static void main(String[] args) {
        AsciiSquares asciiSquares = new AsciiSquares(5);
        System.out.println(asciiSquares);
        // try to parse squares
    }

    public AsciiSquares(int rows) {
        this.grid = new ArrayList<List<Token>>();
        new BufferedReader(new InputStreamReader(System.in)).lines().limit(rows)
                .map(row -> row.codePoints().mapToObj(c -> Token.fromChar((char) c))
                        .collect(Collectors.toCollection(ArrayList::new)))
                .forEach(this.grid::add);
        for (List<Token> row : this.grid) {
            if (row.get(row.size() - 1) == Token.UNDERSCORE) {
                row.add(Token.SPACE);
            }
        }
    }

    public String toString() {
        return this.grid.toString();
    }

    /**
     * Parse the squares in the grid.
     * _
     * |_| -> 1
     * |_| -> 2
     * 
     * A square has a size larger than 1.
     * __
     * | |
     * |__| -> 1
     */
    public void parseSquares() {

    }

    public static class Square {
        private int x, y, size;

        public Square(int x, int y, int size) {
            this.x = x;
            this.y = y;
            this.size = size;
        }

        public String toString() {
            return String.format("(%d, %d, %d)", this.x, this.y, this.size);
        }
    }

    public static enum Token {
        SPACE, UNDERSCORE, PIPE;

        public static Token fromChar(char c) {
            switch (c) {
                case ' ':
                    return SPACE;
                case '_':
                    return UNDERSCORE;
                case '|':
                    return PIPE;
                default:
                    throw new IllegalArgumentException("Invalid character: " + c);
            }
        }

        public String toString() {
            switch (this) {
                case SPACE:
                    return " ";
                case UNDERSCORE:
                    return "_";
                case PIPE:
                    return "|";
                default:
                    // unreachable
                    throw new IllegalArgumentException("Invalid token: " + this);
            }
        }
    }
}