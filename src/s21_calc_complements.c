#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int res = 0;
  if (MatrixWrong(A) == 0) {
    if (A->rows == A->columns) {
      res = s21_create_matrix(A->rows, A->columns, result);
      if (res == 0) {
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < A->columns; j++) {
            matrix_t flags;
            double resuult = 0;
            sWithhout(A, &flags, i, j);
            res = s21_determinant(&flags, &resuult);
            if (res == 0) {
              result->matrix[i][j] = resuult * pow(-1, j + i);
            }
            s21_remove_matrix(&flags);
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