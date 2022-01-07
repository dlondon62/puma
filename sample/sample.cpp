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
#include "sample.h"
#include "rt_nonfinite.h"
#include "shuffleF.h"
#include "shuffleF_emxAPI.h"
#include "shuffleF_terminate.h"
#include "shuffleF_types.h"
#include <iostream>
#include <fstream>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>

using namespace std;

static void usage(const char *pgm_)
{
  std::cout << "usage: "              << pgm_
            << "-X <X_FILENAME> "     << std::endl          
            << "-Y<Y_FILENAME> "      << std::endl        
            << "-I<INDEX_FILENAME> "  << std::endl        
            << "-N<NAN_FILENAME> "    << std::endl      
            << " [-R<runtime_count>]" << std::endl         
            << "(All Files are CSV format, default runtime_count = 1)"
            << std::endl;
}

/* non-generated functions */
std::ostream& operator<<(std::ostream& s_, emxArray_real_T& array_)
{
  s_ << ": dimensions=" << array_.numDimensions 
     << ", allocated size=" << array_.allocatedSize 
     << ", size pointer=" << array_.size
     << "={";
  for (auto i = 0; i < array_.numDimensions; ++i)
  {
    std::cout << "{";
    for (auto j = 0; j < array_.size[j]; ++j)
    {
        if (j != 0)
            s_ << ",";
        if (array_.data[j])
            s_ << array_.data[j];
        else
            s_ << "NULL";
    }
    s_ << "}";
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

struct Args
{
  emxArray_real_T *F;
  emxArray_real_T *X;
  emxArray_real_T *ind;
  emxArray_real_T *y;
  double leastNansCols = 1.0;
};

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

  std::cout << std::endl << "arguments before call to shuffleF"
            << std::endl
            << "X"     << X << std::endl
            << "y"     << y << std::endl 
            << "ind"  << ind << std::endl
            << "F"    << F
            << std::endl;

  /* Call the entry-point 'shuffleF'. */
  shuffleF(X, y, ind, argInit_real_T(), F);
  std::cout << std::endl << "arguments after call to shuffleF"
            << "X"    << X << std::endl
            << "y"    << y << std::endl 
            << "ind"  << ind << std::endl
            << "F"    << F
            << std::endl;
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
int main(int argc, char *argv[])
{
  int c;
  std::string X_csv, Y_csv, Ind_csv, NaN_csv;
  unsigned runCnt = 1;

  while ((c = getopt (argc, argv, "X:Y:I:N:r:")) != -1)
    switch (c)
    {    
      case 'X':
        X_csv = optarg;
        break;
      case 'Y':
        Y_csv = optarg;
        break;
      case 'I':
        Ind_csv = optarg;
        break;
      case 'N':
        NaN_csv = optarg;
        break;
      case 'r':
        runCnt = atoi(optarg);
        break;
      case '?':
        usage(argv[0]);
        exit(0);
      default:
        std::cerr << "Unexpected option:" << c << std::endl;
        usage(argv[0]);
        abort();
    }

  if (!X_csv.length() || 
      !Y_csv.length() || 
      !Ind_csv.length() || 
      !NaN_csv.length())
  {
     std::cerr << "One or more arguments missing" << std::endl;
     usage(argv[0]);
     abort();
  }

  std::cout << "Using X=" << X_csv << std::endl
            << ", Y=" << Y_csv << std::endl
            << ", Index=" << Ind_csv << std::endl
            << ", NaN=="  << NaN_csv << std::endl
            << ", Iterations=" << runCnt 
            << std::endl;

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
