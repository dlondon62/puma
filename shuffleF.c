/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: shuffleF.c
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 12-Dec-2021 16:44:00
 */

/* Include Files */
#include "shuffleF.h"
#include "bsxfun.h"
#include "chol.h"
#include "combineVectorElements.h"
#include "ind2sub.h"
#include "mldivide.h"
#include "mtimes.h"
#include "mtimes1.h"
#include "permute.h"
#include "power.h"
#include "repmat.h"
#include "rt_nonfinite.h"
#include "shuffleF_emxutil.h"
#include "shuffleF_types.h"
#include "sparse.h"
#include "sparse1.h"
#include "squeeze.h"
#include "sum.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Find the F-statistic of the linear system X*beta=y. We use the Cholesky
 *  method that is used in the mixed effects solution.
 * Arguments    : const emxArray_real_T *X
 *                emxArray_real_T *y
 *                const emxArray_real_T *ind
 *                double leastNansCol
 *                emxArray_real_T *F
 * Return Type  : void
 */
void shuffleF(const emxArray_real_T *X, emxArray_real_T *y, const
              emxArray_real_T *ind, double leastNansCol, emxArray_real_T *F)
{
  b_sparse b_expl_temp;
  b_sparse c_expl_temp;
  b_sparse expl_temp;
  emxArray_boolean_T *b_yNan;
  emxArray_boolean_T *r3;
  emxArray_boolean_T *subsetiter;
  emxArray_boolean_T *timeswNan;
  emxArray_boolean_T *yNan;
  emxArray_int32_T *d_y;
  emxArray_int32_T *r;
  emxArray_int32_T *r1;
  emxArray_int32_T *r10;
  emxArray_int32_T *r11;
  emxArray_int32_T *r12;
  emxArray_int32_T *r13;
  emxArray_int32_T *r14;
  emxArray_int32_T *r16;
  emxArray_int32_T *r17;
  emxArray_int32_T *r2;
  emxArray_int32_T *r5;
  emxArray_int32_T *r6;
  emxArray_int32_T *r9;
  emxArray_int32_T *varargout_3;
  emxArray_int32_T *varargout_4;
  emxArray_real_T r15;
  emxArray_real_T *Rnonan;
  emxArray_real_T *Rvals;
  emxArray_real_T *Xiter;
  emxArray_real_T *Xrep;
  emxArray_real_T *Xty;
  emxArray_real_T *b_beta;
  emxArray_real_T *b_y;
  emxArray_real_T *beta;
  emxArray_real_T *blkdiagInds;
  emxArray_real_T *c_beta;
  emxArray_real_T *mse;
  emxArray_real_T *r4;
  emxArray_real_T *r7;
  emxArray_real_T *r8;
  emxArray_real_T *yiter;
  emxArray_uint32_T *e_y;
  double c_X[2];
  double a;
  double b_X;
  int iv[1];
  int b_i;
  int b_loop_ub;
  int b_n;
  int c_loop_ub;
  int c_y;
  int i;
  int i1;
  int i2;
  int i3;
  int i4;
  int loop_ub;
  int n;
  int nTimes;
  int p;
  emxInit_real_T(&b_y, 2);
  p = X->size[1];

  /* number of beta terms */
  nTimes = y->size[1];

  /* number of time points */
  /* number of shuffles */
  c_y = y->size[1] - 1;
  i = b_y->size[0] * b_y->size[1];
  b_y->size[0] = ind->size[0];
  b_y->size[1] = y->size[1];
  emxEnsureCapacity_real_T(b_y, i);
  for (i = 0; i <= c_y; i++) {
    loop_ub = ind->size[0];
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_y->data[i1 + b_y->size[0] * i] = y->data[((int)ind->data[i1] + y->size[0]
        * i) - 1];
    }
  }

  i = y->size[0] * y->size[1];
  y->size[0] = b_y->size[0];
  y->size[1] = b_y->size[1];
  emxEnsureCapacity_real_T(y, i);
  loop_ub = b_y->size[0] * b_y->size[1];
  for (i = 0; i < loop_ub; i++) {
    y->data[i] = b_y->data[i];
  }

  i = F->size[0] * F->size[1];
  F->size[0] = 1;
  F->size[1] = nTimes;
  emxEnsureCapacity_real_T(F, i);
  for (i = 0; i < nTimes; i++) {
    F->data[i] = rtNaN;
  }

  emxInit_boolean_T(&subsetiter, 1);

  /* pre-allocate */
  /* Find which rows to use. leastNansCol does not change between */
  /* iterations so specifying this an input reduces computation time. */
  loop_ub = y->size[0];
  i = subsetiter->size[0];
  subsetiter->size[0] = y->size[0];
  emxEnsureCapacity_boolean_T(subsetiter, i);
  for (i = 0; i < loop_ub; i++) {
    subsetiter->data[i] = rtIsNaN(y->data[i + y->size[0] * ((int)leastNansCol -
      1)]);
  }

  loop_ub = subsetiter->size[0];
  for (i = 0; i < loop_ub; i++) {
    subsetiter->data[i] = !subsetiter->data[i];
  }

  loop_ub = subsetiter->size[0] - 1;
  c_y = 0;
  for (b_i = 0; b_i <= loop_ub; b_i++) {
    if (subsetiter->data[b_i]) {
      c_y++;
    }
  }

  emxInit_int32_T(&r, 1);
  i = r->size[0];
  r->size[0] = c_y;
  emxEnsureCapacity_int32_T(r, i);
  c_y = 0;
  for (b_i = 0; b_i <= loop_ub; b_i++) {
    if (subsetiter->data[b_i]) {
      r->data[c_y] = b_i + 1;
      c_y++;
    }
  }

  emxInit_real_T(&Xiter, 2);
  loop_ub = X->size[1];
  i = Xiter->size[0] * Xiter->size[1];
  Xiter->size[0] = r->size[0];
  Xiter->size[1] = X->size[1];
  emxEnsureCapacity_real_T(Xiter, i);
  for (i = 0; i < loop_ub; i++) {
    c_y = r->size[0];
    for (i1 = 0; i1 < c_y; i1++) {
      Xiter->data[i1 + Xiter->size[0] * i] = X->data[(r->data[i1] + X->size[0] *
        i) - 1];
    }
  }

  emxFree_int32_T(&r);
  loop_ub = subsetiter->size[0] - 1;
  c_y = 0;
  for (b_i = 0; b_i <= loop_ub; b_i++) {
    if (subsetiter->data[b_i]) {
      c_y++;
    }
  }

  emxInit_int32_T(&r1, 1);
  i = r1->size[0];
  r1->size[0] = c_y;
  emxEnsureCapacity_int32_T(r1, i);
  c_y = 0;
  for (b_i = 0; b_i <= loop_ub; b_i++) {
    if (subsetiter->data[b_i]) {
      r1->data[c_y] = b_i + 1;
      c_y++;
    }
  }

  emxInit_real_T(&yiter, 2);
  loop_ub = y->size[1];
  i = yiter->size[0] * yiter->size[1];
  yiter->size[0] = r1->size[0];
  yiter->size[1] = y->size[1];
  emxEnsureCapacity_real_T(yiter, i);
  for (i = 0; i < loop_ub; i++) {
    c_y = r1->size[0];
    for (i1 = 0; i1 < c_y; i1++) {
      yiter->data[i1 + yiter->size[0] * i] = y->data[(r1->data[i1] + y->size[0] *
        i) - 1];
    }
  }

  n = 0;
  i = subsetiter->size[0];
  for (c_y = 0; c_y < i; c_y++) {
    if (subsetiter->data[c_y]) {
      n++;
    }
  }

  emxFree_boolean_T(&subsetiter);
  emxInit_boolean_T(&yNan, 2);
  i = yNan->size[0] * yNan->size[1];
  yNan->size[0] = yiter->size[0];
  yNan->size[1] = yiter->size[1];
  emxEnsureCapacity_boolean_T(yNan, i);
  loop_ub = yiter->size[0] * yiter->size[1];
  for (i = 0; i < loop_ub; i++) {
    yNan->data[i] = rtIsNaN(yiter->data[i]);
  }

  emxInit_boolean_T(&timeswNan, 2);
  emxInit_int32_T(&d_y, 2);
  combineVectorElements(yNan, d_y);
  i = timeswNan->size[0] * timeswNan->size[1];
  timeswNan->size[0] = 1;
  timeswNan->size[1] = d_y->size[1];
  emxEnsureCapacity_boolean_T(timeswNan, i);
  loop_ub = d_y->size[0] * d_y->size[1];
  for (i = 0; i < loop_ub; i++) {
    timeswNan->data[i] = (d_y->data[i] != 0);
  }

  b_n = 0;
  i = timeswNan->size[1];
  for (c_y = 0; c_y < i; c_y++) {
    if (timeswNan->data[c_y]) {
      b_n++;
    }
  }

  /* Calculate XtX. If there are timepoints with NaNs, these will have different XtX. */
  loop_ub = timeswNan->size[1] - 1;
  c_y = 0;
  for (b_i = 0; b_i <= loop_ub; b_i++) {
    if (timeswNan->data[b_i]) {
      c_y++;
    }
  }

  emxInit_int32_T(&r2, 2);
  i = r2->size[0] * r2->size[1];
  r2->size[0] = 1;
  r2->size[1] = c_y;
  emxEnsureCapacity_int32_T(r2, i);
  c_y = 0;
  for (b_i = 0; b_i <= loop_ub; b_i++) {
    if (timeswNan->data[b_i]) {
      r2->data[c_y] = b_i + 1;
      c_y++;
    }
  }

  emxInit_boolean_T(&b_yNan, 2);
  loop_ub = yNan->size[0];
  i = b_yNan->size[0] * b_yNan->size[1];
  b_yNan->size[0] = yNan->size[0];
  b_yNan->size[1] = r2->size[1];
  emxEnsureCapacity_boolean_T(b_yNan, i);
  c_y = r2->size[1];
  for (i = 0; i < c_y; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_yNan->data[i1 + b_yNan->size[0] * i] = !yNan->data[i1 + yNan->size[0] *
        (r2->data[i] - 1)];
    }
  }

  emxFree_int32_T(&r2);
  emxFree_boolean_T(&yNan);
  emxInit_real_T(&Xrep, 3);
  emxInit_real_T(&mse, 2);
  emxInit_boolean_T(&r3, 3);
  permute(b_yNan, r3);
  bsxfun(Xiter, r3, Xrep);
  emxFree_boolean_T(&r3);
  emxFree_boolean_T(&b_yNan);
  emxInit_uint32_T(&e_y, 2);
  if (X->size[1] < 1) {
    mse->size[0] = 1;
    mse->size[1] = 0;
    e_y->size[0] = 1;
    e_y->size[1] = 0;
  } else {
    i = mse->size[0] * mse->size[1];
    mse->size[0] = 1;
    mse->size[1] = (int)((double)X->size[1] - 1.0) + 1;
    emxEnsureCapacity_real_T(mse, i);
    loop_ub = (int)((double)X->size[1] - 1.0);
    for (i = 0; i <= loop_ub; i++) {
      mse->data[i] = (double)i + 1.0;
    }

    i = e_y->size[0] * e_y->size[1];
    e_y->size[0] = 1;
    e_y->size[1] = X->size[1];
    emxEnsureCapacity_uint32_T(e_y, i);
    loop_ub = X->size[1] - 1;
    for (i = 0; i <= loop_ub; i++) {
      e_y->data[i] = i + 1U;
    }
  }

  if ((double)b_n - 1.0 < 1.0) {
    d_y->size[0] = 1;
    d_y->size[1] = 0;
  } else {
    i = d_y->size[0] * d_y->size[1];
    d_y->size[0] = 1;
    loop_ub = (int)(((double)b_n - 1.0) - 1.0);
    d_y->size[1] = (int)(((double)b_n - 1.0) - 1.0) + 1;
    emxEnsureCapacity_int32_T(d_y, i);
    for (i = 0; i <= loop_ub; i++) {
      d_y->data[i] = i + 1;
    }
  }

  emxInit_real_T(&Rvals, 1);
  a = ((double)X->size[1] * (double)b_n + 1.0) * (double)X->size[1];
  b_X = (double)X->size[1] * (double)b_n;
  i = Rvals->size[0];
  Rvals->size[0] = mse->size[1] + e_y->size[1];
  emxEnsureCapacity_real_T(Rvals, i);
  loop_ub = mse->size[1];
  for (i = 0; i < loop_ub; i++) {
    Rvals->data[i] = mse->data[i];
  }

  loop_ub = e_y->size[1];
  for (i = 0; i < loop_ub; i++) {
    Rvals->data[i + mse->size[1]] = (double)e_y->data[i] + b_X;
  }

  emxFree_uint32_T(&e_y);
  i = mse->size[0] * mse->size[1];
  mse->size[0] = 1;
  mse->size[1] = d_y->size[1] + 1;
  emxEnsureCapacity_real_T(mse, i);
  mse->data[0] = 0.0;
  loop_ub = d_y->size[1];
  for (i = 0; i < loop_ub; i++) {
    mse->data[i + 1] = a * (double)d_y->data[i];
  }

  emxFree_int32_T(&d_y);
  emxInit_int32_T(&varargout_4, 2);
  emxInit_int32_T(&varargout_3, 2);
  emxInit_real_T(&r4, 2);
  c_X[0] = (double)X->size[1] * (double)b_n;
  c_X[1] = (double)X->size[1] * (double)b_n;
  repmat(Rvals, b_n, r4);
  b_bsxfun(r4, mse, b_y);
  ind2sub_indexClass(c_X, b_y, varargout_3, varargout_4);
  loop_ub = (int)((double)X->size[1] * (double)X->size[1] * (double)b_n);
  i = Rvals->size[0];
  Rvals->size[0] = loop_ub;
  emxEnsureCapacity_real_T(Rvals, i);
  for (i = 0; i < loop_ub; i++) {
    Rvals->data[i] = 0.0;
  }

  if (0 <= b_n - 1) {
    b_loop_ub = Xrep->size[0];
    i2 = Xrep->size[1];
    c_loop_ub = Xrep->size[1];
    i3 = Xrep->size[0];
    i4 = Xrep->size[1];
  }

  emxInit_real_T(&blkdiagInds, 2);
  for (b_i = 0; b_i < b_n; b_i++) {
    a = (double)p * (double)p;
    b_X = a * (((double)b_i + 1.0) - 1.0) + 1.0;
    a *= (double)b_i + 1.0;
    if (b_X > a) {
      i = -1;
      i1 = 0;
    } else {
      i = (int)b_X - 2;
      i1 = (int)a;
    }

    c_y = b_y->size[0] * b_y->size[1];
    b_y->size[0] = b_loop_ub;
    b_y->size[1] = i2;
    emxEnsureCapacity_real_T(b_y, c_y);
    c_y = blkdiagInds->size[0] * blkdiagInds->size[1];
    blkdiagInds->size[0] = i3;
    blkdiagInds->size[1] = i4;
    emxEnsureCapacity_real_T(blkdiagInds, c_y);
    for (c_y = 0; c_y < c_loop_ub; c_y++) {
      for (loop_ub = 0; loop_ub < b_loop_ub; loop_ub++) {
        a = Xrep->data[(loop_ub + Xrep->size[0] * c_y) + Xrep->size[0] *
          Xrep->size[1] * b_i];
        b_y->data[loop_ub + b_y->size[0] * c_y] = a;
        blkdiagInds->data[loop_ub + blkdiagInds->size[0] * c_y] = a;
      }
    }

    mtimes(b_y, blkdiagInds, r4);
    cholesky(r4);
    loop_ub = (i1 - i) - 1;
    for (i1 = 0; i1 < loop_ub; i1++) {
      Rvals->data[(i + i1) + 1] = r4->data[i1];
    }
  }

  i = b_y->size[0] * b_y->size[1];
  b_y->size[0] = varargout_3->size[0];
  b_y->size[1] = varargout_3->size[1];
  emxEnsureCapacity_real_T(b_y, i);
  loop_ub = varargout_3->size[0] * varargout_3->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_y->data[i] = varargout_3->data[i];
  }

  emxFree_int32_T(&varargout_3);
  i = blkdiagInds->size[0] * blkdiagInds->size[1];
  blkdiagInds->size[0] = varargout_4->size[0];
  blkdiagInds->size[1] = varargout_4->size[1];
  emxEnsureCapacity_real_T(blkdiagInds, i);
  loop_ub = varargout_4->size[0] * varargout_4->size[1];
  for (i = 0; i < loop_ub; i++) {
    blkdiagInds->data[i] = varargout_4->data[i];
  }

  emxFree_int32_T(&varargout_4);
  emxInit_real_T(&Rnonan, 2);
  emxInitStruct_sparse(&expl_temp);
  sparse(b_y, blkdiagInds, Rvals, (double)X->size[1] * (double)b_n, (double)
         X->size[1] * (double)b_n, &expl_temp);
  mtimes(Xiter, Xiter, Rnonan);
  cholesky(Rnonan);

  /* Form Xty. If there are timepoints with NaNs, these will have different XtX. */
  emxInit_real_T(&Xty, 2);
  if (b_n != 0) {
    i = Xty->size[0] * Xty->size[1];
    Xty->size[0] = X->size[1];
    Xty->size[1] = nTimes;
    emxEnsureCapacity_real_T(Xty, i);
    loop_ub = X->size[1] * nTimes;
    for (i = 0; i < loop_ub; i++) {
      Xty->data[i] = 0.0;
    }

    loop_ub = timeswNan->size[1] - 1;
    c_y = 0;
    for (b_i = 0; b_i <= loop_ub; b_i++) {
      if (timeswNan->data[b_i]) {
        c_y++;
      }
    }

    emxInit_int32_T(&r5, 2);
    i = r5->size[0] * r5->size[1];
    r5->size[0] = 1;
    r5->size[1] = c_y;
    emxEnsureCapacity_int32_T(r5, i);
    c_y = 0;
    for (b_i = 0; b_i <= loop_ub; b_i++) {
      if (timeswNan->data[b_i]) {
        r5->data[c_y] = b_i + 1;
        c_y++;
      }
    }

    loop_ub = r1->size[0];
    i = b_y->size[0] * b_y->size[1];
    b_y->size[0] = r1->size[0];
    b_y->size[1] = r5->size[1];
    emxEnsureCapacity_real_T(b_y, i);
    c_y = r5->size[1];
    for (i = 0; i < c_y; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_y->data[i1 + b_y->size[0] * i] = yiter->data[i1 + yiter->size[0] *
          (r5->data[i] - 1)];
      }
    }

    emxFree_int32_T(&r5);
    emxInit_real_T(&r7, 3);
    emxInit_real_T(&r8, 3);
    b_permute(Xiter, r7);
    c_bsxfun(r7, b_y, Xrep);
    sum(Xrep, r8);
    squeeze(r8, r4);
    i = blkdiagInds->size[0] * blkdiagInds->size[1];
    blkdiagInds->size[0] = r4->size[1];
    blkdiagInds->size[1] = r4->size[0];
    emxEnsureCapacity_real_T(blkdiagInds, i);
    loop_ub = r4->size[0];
    emxFree_real_T(&r8);
    emxFree_real_T(&r7);
    for (i = 0; i < loop_ub; i++) {
      c_y = r4->size[1];
      for (i1 = 0; i1 < c_y; i1++) {
        blkdiagInds->data[i1 + blkdiagInds->size[0] * i] = r4->data[i + r4->
          size[0] * i1];
      }
    }

    loop_ub = timeswNan->size[1] - 1;
    c_y = 0;
    for (b_i = 0; b_i <= loop_ub; b_i++) {
      if (timeswNan->data[b_i]) {
        c_y++;
      }
    }

    emxInit_int32_T(&r9, 2);
    i = r9->size[0] * r9->size[1];
    r9->size[0] = 1;
    r9->size[1] = c_y;
    emxEnsureCapacity_int32_T(r9, i);
    c_y = 0;
    for (b_i = 0; b_i <= loop_ub; b_i++) {
      if (timeswNan->data[b_i]) {
        r9->data[c_y] = b_i + 1;
        c_y++;
      }
    }

    loop_ub = blkdiagInds->size[1];
    for (i = 0; i < loop_ub; i++) {
      c_y = blkdiagInds->size[0];
      for (i1 = 0; i1 < c_y; i1++) {
        Xty->data[i1 + Xty->size[0] * (r9->data[i] - 1)] = blkdiagInds->data[i1
          + blkdiagInds->size[0] * i];
      }
    }

    emxFree_int32_T(&r9);
    loop_ub = timeswNan->size[1] - 1;
    c_y = 0;
    for (b_i = 0; b_i <= loop_ub; b_i++) {
      if (!timeswNan->data[b_i]) {
        c_y++;
      }
    }

    emxInit_int32_T(&r11, 2);
    i = r11->size[0] * r11->size[1];
    r11->size[0] = 1;
    r11->size[1] = c_y;
    emxEnsureCapacity_int32_T(r11, i);
    c_y = 0;
    for (b_i = 0; b_i <= loop_ub; b_i++) {
      if (!timeswNan->data[b_i]) {
        r11->data[c_y] = b_i + 1;
        c_y++;
      }
    }

    loop_ub = r1->size[0];
    i = blkdiagInds->size[0] * blkdiagInds->size[1];
    blkdiagInds->size[0] = r1->size[0];
    blkdiagInds->size[1] = r11->size[1];
    emxEnsureCapacity_real_T(blkdiagInds, i);
    c_y = r11->size[1];
    for (i = 0; i < c_y; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        blkdiagInds->data[i1 + blkdiagInds->size[0] * i] = yiter->data[i1 +
          yiter->size[0] * (r11->data[i] - 1)];
      }
    }

    emxFree_int32_T(&r11);
    loop_ub = timeswNan->size[1] - 1;
    c_y = 0;
    for (b_i = 0; b_i <= loop_ub; b_i++) {
      if (!timeswNan->data[b_i]) {
        c_y++;
      }
    }

    emxInit_int32_T(&r12, 2);
    i = r12->size[0] * r12->size[1];
    r12->size[0] = 1;
    r12->size[1] = c_y;
    emxEnsureCapacity_int32_T(r12, i);
    c_y = 0;
    for (b_i = 0; b_i <= loop_ub; b_i++) {
      if (!timeswNan->data[b_i]) {
        r12->data[c_y] = b_i + 1;
        c_y++;
      }
    }

    mtimes(Xiter, blkdiagInds, r4);
    loop_ub = r4->size[1];
    for (i = 0; i < loop_ub; i++) {
      c_y = r4->size[0];
      for (i1 = 0; i1 < c_y; i1++) {
        Xty->data[i1 + Xty->size[0] * (r12->data[i] - 1)] = r4->data[i1 +
          r4->size[0] * i];
      }
    }

    emxFree_int32_T(&r12);
  } else {
    mtimes(Xiter, yiter, Xty);
  }

  emxFree_int32_T(&r1);
  emxFree_real_T(&Xrep);

  /*  Solve the normal equations: */
  /*  Rt*cbeta=Xty */
  /*  R*beta=cbeta; */
  /*  */
  /*  Then calculate F: (betat*RtR*beta)/(dF*mse) */
  /*  */
  /*  Implemented separately in the cases of NaN timepoints and no-NaN */
  /*  timepoints */
  loop_ub = timeswNan->size[1] - 1;
  c_y = 0;
  for (b_i = 0; b_i <= loop_ub; b_i++) {
    if (!timeswNan->data[b_i]) {
      c_y++;
    }
  }

  emxInit_int32_T(&r6, 2);
  i = r6->size[0] * r6->size[1];
  r6->size[0] = 1;
  r6->size[1] = c_y;
  emxEnsureCapacity_int32_T(r6, i);
  c_y = 0;
  for (b_i = 0; b_i <= loop_ub; b_i++) {
    if (!timeswNan->data[b_i]) {
      r6->data[c_y] = b_i + 1;
      c_y++;
    }
  }

  i = b_y->size[0] * b_y->size[1];
  b_y->size[0] = Rnonan->size[1];
  b_y->size[1] = Rnonan->size[0];
  emxEnsureCapacity_real_T(b_y, i);
  loop_ub = Rnonan->size[0];
  for (i = 0; i < loop_ub; i++) {
    c_y = Rnonan->size[1];
    for (i1 = 0; i1 < c_y; i1++) {
      b_y->data[i1 + b_y->size[0] * i] = Rnonan->data[i + Rnonan->size[0] * i1];
    }
  }

  loop_ub = Xty->size[0];
  i = blkdiagInds->size[0] * blkdiagInds->size[1];
  blkdiagInds->size[0] = Xty->size[0];
  blkdiagInds->size[1] = r6->size[1];
  emxEnsureCapacity_real_T(blkdiagInds, i);
  c_y = r6->size[1];
  for (i = 0; i < c_y; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      blkdiagInds->data[i1 + blkdiagInds->size[0] * i] = Xty->data[i1 +
        Xty->size[0] * (r6->data[i] - 1)];
    }
  }

  emxFree_int32_T(&r6);
  emxInit_real_T(&beta, 2);
  mldivide(b_y, blkdiagInds, r4);
  mldivide(Rnonan, r4, beta);
  mtimes(Rnonan, Rnonan, blkdiagInds);
  emxFree_real_T(&Rnonan);
  if (b_n != 0) {
    loop_ub = timeswNan->size[1] - 1;
    c_y = 0;
    for (b_i = 0; b_i <= loop_ub; b_i++) {
      if (!timeswNan->data[b_i]) {
        c_y++;
      }
    }

    emxInit_int32_T(&r10, 2);
    i = r10->size[0] * r10->size[1];
    r10->size[0] = 1;
    r10->size[1] = c_y;
    emxEnsureCapacity_int32_T(r10, i);
    c_y = 0;
    for (b_i = 0; b_i <= loop_ub; b_i++) {
      if (!timeswNan->data[b_i]) {
        r10->data[c_y] = b_i + 1;
        c_y++;
      }
    }

    mtimes(beta, blkdiagInds, r4);
    i = b_y->size[0] * b_y->size[1];
    b_y->size[0] = r4->size[1];
    b_y->size[1] = r4->size[0];
    emxEnsureCapacity_real_T(b_y, i);
    loop_ub = r4->size[0];
    for (i = 0; i < loop_ub; i++) {
      c_y = r4->size[1];
      for (i1 = 0; i1 < c_y; i1++) {
        b_y->data[i1 + b_y->size[0] * i] = r4->data[i + r4->size[0] * i1] *
          beta->data[i1 + beta->size[0] * i];
      }
    }

    b_combineVectorElements(b_y, mse);
    loop_ub = mse->size[1];
    for (i = 0; i < loop_ub; i++) {
      F->data[r10->data[i] - 1] = mse->data[i];
    }

    emxFree_int32_T(&r10);

    /* This is not actually F. We */
    /* still have to divide by */
    /* MSE. */
    i = blkdiagInds->size[0] * blkdiagInds->size[1];
    blkdiagInds->size[0] = X->size[1];
    blkdiagInds->size[1] = nTimes;
    emxEnsureCapacity_real_T(blkdiagInds, i);
    loop_ub = X->size[1] * nTimes;
    for (i = 0; i < loop_ub; i++) {
      blkdiagInds->data[i] = 0.0;
    }

    loop_ub = timeswNan->size[1] - 1;
    c_y = 0;
    for (b_i = 0; b_i <= loop_ub; b_i++) {
      if (!timeswNan->data[b_i]) {
        c_y++;
      }
    }

    emxInit_int32_T(&r13, 2);
    i = r13->size[0] * r13->size[1];
    r13->size[0] = 1;
    r13->size[1] = c_y;
    emxEnsureCapacity_int32_T(r13, i);
    c_y = 0;
    for (b_i = 0; b_i <= loop_ub; b_i++) {
      if (!timeswNan->data[b_i]) {
        r13->data[c_y] = b_i + 1;
        c_y++;
      }
    }

    loop_ub = beta->size[1];
    for (i = 0; i < loop_ub; i++) {
      c_y = beta->size[0];
      for (i1 = 0; i1 < c_y; i1++) {
        blkdiagInds->data[i1 + blkdiagInds->size[0] * (r13->data[i] - 1)] =
          beta->data[i1 + beta->size[0] * i];
      }
    }

    emxFree_int32_T(&r13);
    loop_ub = timeswNan->size[1] - 1;
    c_y = 0;
    for (b_i = 0; b_i <= loop_ub; b_i++) {
      if (timeswNan->data[b_i]) {
        c_y++;
      }
    }

    emxInit_int32_T(&r14, 2);
    i = r14->size[0] * r14->size[1];
    r14->size[0] = 1;
    r14->size[1] = c_y;
    emxEnsureCapacity_int32_T(r14, i);
    c_y = 0;
    for (b_i = 0; b_i <= loop_ub; b_i++) {
      if (timeswNan->data[b_i]) {
        r14->data[c_y] = b_i + 1;
        c_y++;
      }
    }

    loop_ub = Xty->size[0];
    i = r4->size[0] * r4->size[1];
    r4->size[0] = Xty->size[0];
    r4->size[1] = r14->size[1];
    emxEnsureCapacity_real_T(r4, i);
    c_y = r14->size[1];
    for (i = 0; i < c_y; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        r4->data[i1 + r4->size[0] * i] = Xty->data[i1 + Xty->size[0] *
          (r14->data[i] - 1)];
      }
    }

    emxInit_real_T(&b_beta, 1);
    emxInitStruct_sparse(&b_expl_temp);
    emxInitStruct_sparse(&c_expl_temp);
    sparse_ctranspose(expl_temp.d, expl_temp.colidx, expl_temp.rowidx,
                      expl_temp.m, expl_temp.n, &b_expl_temp);
    c_y = Xty->size[0] * r14->size[1];
    r15 = *r4;
    iv[0] = c_y;
    r15.size = &iv[0];
    r15.numDimensions = 1;
    sparse_mldivide(b_expl_temp.d, b_expl_temp.colidx, b_expl_temp.rowidx,
                    b_expl_temp.m, b_expl_temp.n, &r15, Rvals);
    sparse_mldivide(expl_temp.d, expl_temp.colidx, expl_temp.rowidx, expl_temp.m,
                    expl_temp.n, Rvals, b_beta);
    sparse_ctranspose(expl_temp.d, expl_temp.colidx, expl_temp.rowidx,
                      expl_temp.m, expl_temp.n, &c_expl_temp);
    i = b_expl_temp.d->size[0];
    b_expl_temp.d->size[0] = c_expl_temp.d->size[0];
    emxEnsureCapacity_real_T(b_expl_temp.d, i);
    loop_ub = c_expl_temp.d->size[0];
    emxFree_int32_T(&r14);
    for (i = 0; i < loop_ub; i++) {
      b_expl_temp.d->data[i] = c_expl_temp.d->data[i];
    }

    i = b_expl_temp.colidx->size[0];
    b_expl_temp.colidx->size[0] = c_expl_temp.colidx->size[0];
    emxEnsureCapacity_int32_T(b_expl_temp.colidx, i);
    loop_ub = c_expl_temp.colidx->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_expl_temp.colidx->data[i] = c_expl_temp.colidx->data[i];
    }

    i = b_expl_temp.rowidx->size[0];
    b_expl_temp.rowidx->size[0] = c_expl_temp.rowidx->size[0];
    emxEnsureCapacity_int32_T(b_expl_temp.rowidx, i);
    loop_ub = c_expl_temp.rowidx->size[0];
    for (i = 0; i < loop_ub; i++) {
      b_expl_temp.rowidx->data[i] = c_expl_temp.rowidx->data[i];
    }

    emxInit_real_T(&c_beta, 2);
    sparse_mtimes(b_expl_temp.d, b_expl_temp.colidx, b_expl_temp.rowidx,
                  c_expl_temp.m, expl_temp.d, expl_temp.colidx, expl_temp.rowidx,
                  expl_temp.n, &c_expl_temp);
    i = c_beta->size[0] * c_beta->size[1];
    c_beta->size[0] = 1;
    c_beta->size[1] = b_beta->size[0];
    emxEnsureCapacity_real_T(c_beta, i);
    loop_ub = b_beta->size[0];
    emxFreeStruct_sparse(&b_expl_temp);
    for (i = 0; i < loop_ub; i++) {
      c_beta->data[i] = b_beta->data[i];
    }

    b_sparse_mtimes(c_beta, c_expl_temp.d, c_expl_temp.colidx,
                    c_expl_temp.rowidx, c_expl_temp.n, mse);
    loop_ub = timeswNan->size[1] - 1;
    c_y = 0;
    emxFree_real_T(&c_beta);
    emxFreeStruct_sparse(&c_expl_temp);
    for (b_i = 0; b_i <= loop_ub; b_i++) {
      if (timeswNan->data[b_i]) {
        c_y++;
      }
    }

    emxInit_int32_T(&r16, 2);
    i = r16->size[0] * r16->size[1];
    r16->size[0] = 1;
    r16->size[1] = c_y;
    emxEnsureCapacity_int32_T(r16, i);
    c_y = 0;
    for (b_i = 0; b_i <= loop_ub; b_i++) {
      if (timeswNan->data[b_i]) {
        r16->data[c_y] = b_i + 1;
        c_y++;
      }
    }

    i = b_y->size[0] * b_y->size[1];
    b_y->size[0] = X->size[1];
    b_y->size[1] = b_n;
    emxEnsureCapacity_real_T(b_y, i);
    loop_ub = X->size[1] * b_n;
    for (i = 0; i < loop_ub; i++) {
      b_y->data[i] = mse->data[i] * b_beta->data[i];
    }

    b_combineVectorElements(b_y, mse);
    loop_ub = mse->size[1];
    for (i = 0; i < loop_ub; i++) {
      F->data[r16->data[i] - 1] = mse->data[i];
    }

    emxFree_int32_T(&r16);
    loop_ub = timeswNan->size[1] - 1;
    c_y = 0;
    for (b_i = 0; b_i <= loop_ub; b_i++) {
      if (timeswNan->data[b_i]) {
        c_y++;
      }
    }

    emxInit_int32_T(&r17, 2);
    i = r17->size[0] * r17->size[1];
    r17->size[0] = 1;
    r17->size[1] = c_y;
    emxEnsureCapacity_int32_T(r17, i);
    c_y = 0;
    for (b_i = 0; b_i <= loop_ub; b_i++) {
      if (timeswNan->data[b_i]) {
        r17->data[c_y] = b_i + 1;
        c_y++;
      }
    }

    c_y = X->size[1];
    for (i = 0; i < b_n; i++) {
      for (i1 = 0; i1 < c_y; i1++) {
        blkdiagInds->data[i1 + blkdiagInds->size[0] * (r17->data[i] - 1)] =
          b_beta->data[i1 + c_y * i];
      }
    }

    emxFree_int32_T(&r17);
    emxFree_real_T(&b_beta);
    b_mtimes(Xiter, blkdiagInds, r4);
    i = b_y->size[0] * b_y->size[1];
    b_y->size[0] = yiter->size[0];
    b_y->size[1] = yiter->size[1];
    emxEnsureCapacity_real_T(b_y, i);
    loop_ub = yiter->size[0] * yiter->size[1];
    for (i = 0; i < loop_ub; i++) {
      b_y->data[i] = yiter->data[i] - r4->data[i];
    }

    power(b_y, r4);
    b_sum(r4, mse);
    i = mse->size[0] * mse->size[1];
    i1 = mse->size[0] * mse->size[1];
    mse->size[0] = 1;
    emxEnsureCapacity_real_T(mse, i1);
    a = (double)n - (double)X->size[1];
    loop_ub = i - 1;
    for (i = 0; i <= loop_ub; i++) {
      mse->data[i] = mse->data[i] / a * (double)X->size[1];
    }
  } else {
    mtimes(beta, blkdiagInds, r4);
    i = b_y->size[0] * b_y->size[1];
    b_y->size[0] = r4->size[1];
    b_y->size[1] = r4->size[0];
    emxEnsureCapacity_real_T(b_y, i);
    loop_ub = r4->size[0];
    for (i = 0; i < loop_ub; i++) {
      c_y = r4->size[1];
      for (i1 = 0; i1 < c_y; i1++) {
        b_y->data[i1 + b_y->size[0] * i] = r4->data[i + r4->size[0] * i1] *
          beta->data[i1 + beta->size[0] * i];
      }
    }

    b_combineVectorElements(b_y, mse);
    loop_ub = mse->size[1];
    for (i = 0; i < loop_ub; i++) {
      F->data[i] = mse->data[i];
    }

    b_mtimes(Xiter, beta, r4);
    i = b_y->size[0] * b_y->size[1];
    b_y->size[0] = yiter->size[0];
    b_y->size[1] = yiter->size[1];
    emxEnsureCapacity_real_T(b_y, i);
    loop_ub = yiter->size[0] * yiter->size[1];
    for (i = 0; i < loop_ub; i++) {
      b_y->data[i] = yiter->data[i] - r4->data[i];
    }

    power(b_y, r4);
    b_combineVectorElements(r4, mse);
    i = mse->size[0] * mse->size[1];
    i1 = mse->size[0] * mse->size[1];
    mse->size[0] = 1;
    emxEnsureCapacity_real_T(mse, i1);
    a = (double)n - (double)X->size[1];
    loop_ub = i - 1;
    for (i = 0; i <= loop_ub; i++) {
      mse->data[i] = mse->data[i] / a * (double)X->size[1];
    }
  }

  emxFree_real_T(&r4);
  emxFree_real_T(&b_y);
  emxFreeStruct_sparse(&expl_temp);
  emxFree_real_T(&beta);
  emxFree_real_T(&Xty);
  emxFree_real_T(&Rvals);
  emxFree_real_T(&blkdiagInds);
  emxFree_boolean_T(&timeswNan);
  emxFree_real_T(&yiter);
  emxFree_real_T(&Xiter);
  c_y = F->size[1] - 1;
  i = mse->size[0] * mse->size[1];
  mse->size[0] = 1;
  mse->size[1] = F->size[1];
  emxEnsureCapacity_real_T(mse, i);
  for (i = 0; i <= c_y; i++) {
    mse->data[i] = F->data[i] / mse->data[i];
  }

  loop_ub = mse->size[1];
  for (i = 0; i < loop_ub; i++) {
    F->data[i] = mse->data[i];
  }

  emxFree_real_T(&mse);

  /*  QR factorization method */
  /*  Does not work well with NaNs and slower than Cholesky so no longer used. */
  /*  */
  /*      [Q,R]=qr(Xiter,0); */
  /*      Qty=Q'*yiter; */
  /*      nsubset=nnz(subsetiter); */
  /*      mse=(sum(yiter.^2)-sum(Qty.^2,1))./((nsubset-p)).*p; */
  /*  */
  /*      betaHat=R\Qty; */
  /*      RtR=R'*R; */
  /*      F(j,:)=sum((betaHat'*RtR).*betaHat',2)./mse'; */
  /* F=F./p; */
}

/*
 * File trailer for shuffleF.c
 *
 * [EOF]
 */
