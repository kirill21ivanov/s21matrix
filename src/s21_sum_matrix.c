#include "s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res = 0;
  if (MatrixWrong(A) == 0 && MatrixWrong(B) == 0) {
    if (size_check(A, B)) {
      res = s21_create_matrix(A->rows, A->columns, result);
      if (res == 0) {
        for (int i = 0; i < result->rows; i++) {
          for (int j = 0; j < result->columns; j++) {
            result->matrix[i][j] = MatrixValue(A, i, j) + MatrixValue(B, i, j);
          }
        }
      }
    } else {
      res = 2;
    }
  } else {
    res = 1;
  }
  return res;
}