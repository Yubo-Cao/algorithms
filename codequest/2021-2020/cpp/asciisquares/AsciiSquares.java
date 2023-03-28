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
                .map(row -> row.codePoints().mapToObj(c -> Token.from(c))
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
     * 
     */
    public void parseSquares() {
        this.x = 0;
        this.y = 0;
        while (this.y < this.grid.size()) {
            if (this.grid.get(this.y).get(this.x) == Token.UNDERSCORE) {
                this.parseSquare();
            }
            this.x++;
            if (this.x >= this.grid.get(this.y).size()) {
                this.x = 0;
                this.y++;
            }
        }
    }

    public void parseSquare() {
        int x = this.x, y = this.y, size = 1;

        expect(Token.UNDERSCORE, Token.PIPE);
        while (current() == Token.SPACE) {
            size++;
            x++;
            y++;
        }
    }

    public boolean match(Token x, Token y) {
        if (nextH() == x && nextV() == y) {
            this.x++;
            this.y++;
            return true;
        }
        return false;
    }

    public boolean matchH(Token t) {
        if (nextH() == t) {
            this.x++;
            return true;
        }
        return false;
    }

    public boolean matchV(Token t) {
        if (nextV() == t) {
            this.y++;
            return true;
        }
        return false;
    }

    public boolean expect(Token x, Token y) {
        if (match(x, y)) {
            return true;
        }
        throw new RuntimeException("Expected " + x + " " + y + " at " + this.x + " " + this.y);
    }

    public void expectH(Token t) {
        if (!matchH(t)) {
            throw new RuntimeException("Expected " + t + " but got " + nextH());
        }
    }

    public void expectV(Token t) {
        if (!matchV(t)) {
            throw new RuntimeException("Expected " + t + " but got " + nextV());
        }
    }

    public Token nextH() {
        if (this.x + 1 < this.grid.get(this.y).size()) {
            return this.grid.get(this.y).get(this.x + 1);
        }
        return Token.EOF;
    }

    public Token nextV() {
        if (this.y + 1 < this.grid.size()) {
            return this.grid.get(this.y + 1).get(this.x);
        }
        return Token.EOF;
    }

    public Token current() {
        if (this.y >= this.grid.size() || this.x >= this.grid.get(this.y).size()) {
            return Token.EOF;
        }
        return this.grid.get(this.y).get(this.x);
    }

    public static class Square {
        private int x, y, size;
        private List<Square> inners;

        public Square(int x, int y, int size, List<Square> inners) {
            this.x = x;
            this.y = y;
            this.size = size;
            this.inners = inners;
        }

        public Square(int x, int y, int size) {
            this(x, y, size, new ArrayList<Square>());
        }

        public String toString() {
            return String.format("(%d, %d, %d) %s", this.x, this.y, this.size, this.inners.toString());
        }

        public int hashCode() {
            return this.x + this.y + this.size + this.inners.hashCode();
        }

        public boolean equals(Object o) {
            if (o instanceof Square) {
                Square s = (Square) o;
                return this.x == s.x && this.y == s.y && this.size == s.size && this.inners.equals(s.inners);
            }
            return false;
        }
    }

    public static enum Token {
        SPACE, UNDERSCORE, PIPE, EOF;

        public static Token from(String c) {
            return Token.from(c.codePoints().findFirst().orElseThrow());
        }

        public static Token from(int c) {
            return Token.from((char) c);
        }

        public static Token from(char c) {
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
                case EOF:
                    return "EOF";
                default:
                    // unreachable
                    throw new IllegalArgumentException("Invalid token: " + this);
            }
        }
    }
}