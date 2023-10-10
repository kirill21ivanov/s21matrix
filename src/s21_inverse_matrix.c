#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int res = 1;
  if (MatrixWrong(A) == 0) {
    res = 2;
    double resuult;
    res = s21_determinant(A, &resuult);
    if (res == 0) {
      if (fabs(resuult) > 1e-07) {
        matrix_t for_alg_ext;
        res = s21_calc_complements(A, &for_alg_ext);
        if (res == 0) {
          matrix_t for_transp;
          res = s21_transpose(&for_alg_ext, &for_transp);
          if (res == 0) {
            res = s21_mult_number(&for_transp, 1.0 / resuult, result);
          }
          s21_remove_matrix(&for_transp);
        }
        s21_remove_matrix(&for_alg_ext);
      }
    }
  }
  return res;
}
