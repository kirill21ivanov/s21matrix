#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int res = 0;
  *result = 0;
  if (MatrixWrong(A) == 0) {
    if (A->columns == A->rows) {
      if (A->rows == 1) {
        *result = MatrixValue(A, 0, 0);
      } else if (A->rows == 2) {
        *result = MatrixValue(A, 0, 0) * MatrixValue(A, 1, 1) -
                  (MatrixValue(A, 0, 1) * MatrixValue(A, 1, 0));
      } else if (A->rows > 2) {
        for (int i = 0; i < A->rows && res == 0; i++) {
          matrix_t resuult;
          sWithhout(A, &resuult, i, 0);
          double M = 0;
          res = s21_determinant(&resuult, &M);
          if (res == 0) {
            *result = *result + pow(-1, i + 2) * MatrixValue(A, i, 0) * M;
          }
          s21_remove_matrix(&resuult);
        }
      }
    } else
      res = 2;
  } else
    res = 1;
  return res;
}