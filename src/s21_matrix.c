#include "s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int res = 0;
  if (MatrixWrong(A) == 0) {
    res = s21_create_matrix(A->columns, A->rows, result);
    if (res == 0) {
      for (int i = 0; i < result->rows; i++) {
        for (int j = 0; j < result->columns; j++) {
          result->matrix[i][j] = A->matrix[j][i];
        }
      }
    }
  } else {
    res = 1;
  }
  return res;
}

int MatrixWrong(matrix_t *result) {
  int res = 1;
  if (result->columns > 0 && result->rows > 0 && result->matrix != NULL &&
      result != NULL)
    res = 0;
  return res;
}
double MatrixValue(matrix_t *A, int row, int colummn) {
  return A->matrix[row][colummn];
}

int size_check(matrix_t *A, matrix_t *B) {
  int res = 0;
  if (A->rows == B->rows && A->columns == B->columns) {
    res = 1;
  }
  return res;
}

void sWithhout(matrix_t *mas, matrix_t *result, int i, int j) {
  s21_create_matrix(mas->rows - 1, mas->columns - 1, result);
  int for_rows = 0, for_columns = 0;
  for (int row = 0; row < mas->rows; row++) {
    if (row != i) {
      for (int col = 0; col < mas->columns; col++) {
        if (col != j) {
          result->matrix[for_rows][for_columns] = mas->matrix[row][col];
          for_columns++;
        }
      }
      for_columns = 0;
      for_rows++;
    }
  }
}
