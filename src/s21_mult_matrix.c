#include "s21_matrix.h"
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res = 0;
  if (MatrixWrong(A) == 0 && MatrixWrong(B) == 0) {
    if (A->columns == B->rows) {
      res = s21_create_matrix(A->rows, B->columns, result);
      if (res == 0) {
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < B->columns; j++) {
            double mult = 0;
            for (int kol = 0; kol < B->rows; kol++) {
              mult = (MatrixValue(A, i, kol) * MatrixValue(B, kol, j)) + mult;
            }
            result->matrix[i][j] = mult;
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
