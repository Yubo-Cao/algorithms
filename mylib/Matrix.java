package mylib;

import java.util.Arrays;
import java.util.stream.Collectors;

public class Matrix {
    private int rows;
    private int columns;
    private double[][] matrix;

    public Matrix(int rows, int columns) {
        this.rows = rows;
        this.columns = columns;
        matrix = new double[rows][columns];
    }

    public Matrix(double[][] matrix) {
        check(matrix);
        this.rows = matrix.length;
        this.columns = matrix[0].length;
        this.matrix = matrix;
    }

    public void check(double[][] matrix) {
        if (matrix.length == 0) {
            throw new IllegalArgumentException("Matrix is empty");
        }
        if (matrix[0].length == 0) {
            throw new IllegalArgumentException("Matrix must be two-dimensional");
        }
    }

    public Matrix inv() {
        if (rows != columns) {
            throw new IllegalArgumentException("Matrix must be square");
        }
        double det = determinant();
        if (det == 0) {
            throw new IllegalArgumentException("Matrix is singular");
        }
        double[][] inv = new double[rows][columns];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                inv[i][j] = Math.pow(-1, i + j) * subMatrix(i, j).determinant();
            }
        }
        return new Matrix(inv).transpose().divide(det);
    }

    public double determinant() {
        if (rows != columns) {
            throw new IllegalArgumentException("Matrix must be square");
        }
        if (rows == 1) {
            return matrix[0][0];
        }
        if (rows == 2) {
            return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
        }
        double det = 0;
        for (int i = 0; i < columns; i++) {
            det += Math.pow(-1, i) * matrix[0][i] * subMatrix(0, i).determinant();
        }
        return det;
    }

    public Matrix subMatrix(int row, int column) {
        double[][] subMatrix = new double[rows - 1][columns - 1];
        for (int i = 0; i < rows - 1; i++) {
            for (int j = 0; j < columns - 1; j++) {
                if (i < row) {
                    if (j < column) {
                        subMatrix[i][j] = matrix[i][j];
                    } else {
                        subMatrix[i][j] = matrix[i][j + 1];
                    }
                } else {
                    if (j < column) {
                        subMatrix[i][j] = matrix[i + 1][j];
                    } else {
                        subMatrix[i][j] = matrix[i + 1][j + 1];
                    }
                }
            }
        }
        return new Matrix(subMatrix);
    }

    public Matrix transpose() {
        double[][] transpose = new double[columns][rows];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                transpose[j][i] = matrix[i][j];
            }
        }
        return new Matrix(transpose);
    }

    public Matrix multiply(Matrix matrix) {
        if (columns != matrix.rows) {
            throw new IllegalArgumentException("Matrices must have same number of rows");
        }
        double[][] product = new double[rows][matrix.columns];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < matrix.columns; j++) {
                for (int k = 0; k < columns; k++) {
                    product[i][j] += matrix.matrix[k][j] * matrix.matrix[i][k];
                }
            }
        }
        return new Matrix(product);
    }

    public Matrix divide(Matrix matrix) {
        if (columns != matrix.rows) {
            throw new IllegalArgumentException("Matrices must have same number of rows");
        }
        double[][] quotient = new double[rows][matrix.columns];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < matrix.columns; j++) {
                for (int k = 0; k < columns; k++) {
                    quotient[i][j] += matrix.matrix[k][j] / matrix.matrix[i][k];
                }
            }
        }
        return new Matrix(quotient);
    }

    public Matrix divide(double scalar) {
        double[][] quotient = new double[rows][columns];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                quotient[i][j] = matrix[i][j] / scalar;
            }
        }
        return new Matrix(quotient);
    }

    public Matrix multiply(double scalar) {
        double[][] product = new double[rows][columns];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                product[i][j] = matrix[i][j] * scalar;
            }
        }
        return new Matrix(product);
    }

    public Matrix add(Matrix matrix) {
        if (rows != matrix.rows || columns != matrix.columns) {
            throw new IllegalArgumentException("Matrices must have same dimensions");
        }
        double[][] sum = new double[rows][columns];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                sum[i][j] = matrix.matrix[i][j] + matrix.matrix[i][j];
            }
        }
        return new Matrix(sum);
    }

    public double frobeniusNorm() {
        double sum = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                sum += Math.pow(matrix[i][j], 2);
            }
        }
        return Math.sqrt(sum);
    }

    @Override
    public String toString() {
        return "[" + Arrays.stream(matrix).map(row -> Arrays.toString(row)).collect(Collectors.joining("\n")) + "]";
    }
}
