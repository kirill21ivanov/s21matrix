#include "s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int res = 0;
  if (MatrixWrong(A) == 0) {
    res = s21_create_matrix(A->rows, A->columns, result);
    if (res == 0) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = MatrixValue(A, i, j) * number;
        }
      }
    }
  } else {
    res = 1;
  }
  return res;
}