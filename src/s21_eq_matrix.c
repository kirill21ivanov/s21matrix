#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int res = SUCCESS;
  if (A->rows == B->rows && A->columns == B->columns) {
    for (int i = 0; i < A->rows && res != FAILURE; i++) {
      for (int j = 0; j < A->columns && res != FAILURE; j++) {
        double eps = fabs(MatrixValue(A, i, j) - MatrixValue(B, i, j));
        if (eps < 1e-7) {
          res = SUCCESS;
        } else {
          res = FAILURE;
        }
      }
    }
  } else {
    res = FAILURE;
  }
  return res;
}