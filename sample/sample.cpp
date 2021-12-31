/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: main.c
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 12-Dec-2021 16:44:00
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/

/* Include Files */
#include "main.h"
#include "rt_nonfinite.h"
#include "shuffleF.h"
#include "shuffleF_emxAPI.h"
#include "shuffleF_terminate.h"
#include "shuffleF_types.h"
#include <iostream>

/* non-generated functions */
std::ostream& operator<<(std::ostream& s_, emxArray_real_T& array_)
{
  s_ << "[" << array_.numDimensions << "], allocated size=" << array_.allocatedSize << "={";
  for (auto i = 0; i < array_.numDimensions; ++i)
  {
    if (i != 0)
        s_ << ",";
    if (array_.data)
        s_ << array_.data[i];
    else
        s_ << "NULL";
  }
  s_ << "}";
  return s_;
}

std::ostream& operator<<(std::ostream& s_, emxArray_real_T *array_)
{
  if (array_ == nullptr)
    s_ << "NULL";
  else 
    s_ << *array_;
  return s_;
}

/* Function Declarations */
static emxArray_real_T *argInit_Unboundedx1_real_T(void);
static double argInit_real_T(void);
static emxArray_real_T *c_argInit_UnboundedxUnbounded_r(void);
static void main_shuffleF(void);

/* Function Definitions */
/*
 * Arguments    : void
 * Return Type  : emxArray_real_T *
 */
static emxArray_real_T *argInit_Unboundedx1_real_T(void)
{
  static const int iv[1] = { 2 };

  emxArray_real_T *result;
  int idx0;

  /* Set the size of the array.
     Change this size to the value that the application requires. */
  result = emxCreateND_real_T(1, iv);

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < result->size[0U]; idx0++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result->data[idx0] = argInit_real_T();
  }

  return result;
}

/*
 * Arguments    : void
 * Return Type  : double
 */
static double argInit_real_T(void)
{
  return 0.0;
}

/*
 * Arguments    : void
 * Return Type  : emxArray_real_T *
 */
static emxArray_real_T *c_argInit_UnboundedxUnbounded_r(void)
{
  emxArray_real_T *result;
  int idx0;
  int idx1;

  /* Set the size of the array.
     Change this size to the value that the application requires. */
  result = emxCreate_real_T(2, 2);

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < result->size[0U]; idx0++) {
    for (idx1 = 0; idx1 < result->size[1U]; idx1++) {
      /* Set the value of the array element.
         Change this value to the value that the application requires. */
      result->data[idx0 + result->size[0] * idx1] = argInit_real_T();
    }
  }

  return result;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_shuffleF(void)
{
  emxArray_real_T *F;
  emxArray_real_T *X;
  emxArray_real_T *ind;
  emxArray_real_T *y;
  emxInitArray_real_T(&F, 2);

  /* Initialize function 'shuffleF' input arguments. */
  /* Initialize function input argument 'X'. */
  X = c_argInit_UnboundedxUnbounded_r();

  /* Initialize function input argument 'y'. */
  y = c_argInit_UnboundedxUnbounded_r();

  /* Initialize function input argument 'ind'. */
  ind = argInit_Unboundedx1_real_T();

  std::cout << "arguments before call to shuffleF"
            << "X"     << X << std::endl
            << "y"     << y << std::endl 
            << "ind"  << ind << std::endl
            << "F"    << F
            << std::endl;

  /* Call the entry-point 'shuffleF'. */
  shuffleF(X, y, ind, argInit_real_T(), F);
  std::cout << "F after call to shuffleF" << F << std::endl;
  emxDestroyArray_real_T(F);
  emxDestroyArray_real_T(ind);
  emxDestroyArray_real_T(y);
  emxDestroyArray_real_T(X);
}

/*
 * Arguments    : int argc
 *                const char * const argv[]
 * Return Type  : int
 */
int main(int argc, const char * const argv[])
{
  (void)argc;
  (void)argv;

  /* The initialize function is being called automatically from your entry-point function. So, a call to initialize is not included here. */
  /* Invoke the entry-point functions.
     You can call entry-point functions multiple times. */
  main_shuffleF();

  /* Terminate the application.
     You do not need to do this more than one time. */
  shuffleF_terminate();
  return 0;
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
