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
#include <vector>
#include <stdexcept>

using namespace std;

typedef std::vector<double> Row;
typedef std::vector<Row> DataV;

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
        s_ << array_.data[j];
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
static emxArray_real_T *argInit_Unboundedx1_real_T(const DataV& dataV_);
static double argInit_real_T(void);
static emxArray_real_T *c_argInit_UnboundedxUnbounded_r
    (const DataV& dataV_);
static void main_shuffleF(void);

DataV parse_csv(const std::string& fileName_)
{
    ifstream fs;
    fs.open(fileName_, std::ifstream::in);
    if (!fs)
    {
        throw std::runtime_error("unable to open filename=" + fileName_ + 
            + ":" +  strerror(errno));
    }

    DataV v;
    std::string line;
    size_t currPos = 0, idx=0;
    while (std::getline(fs, line))
    {
        currPos = 0;
        idx=0;
        Row row;
        while((idx = line.find(',', currPos)) != std::string::npos)
        {
           string elmt = line.substr(currPos, idx - currPos);
           double ve = atof(elmt.c_str());
           row.push_back(ve);
           currPos = idx+1;
        }
        
        if (currPos < line.length())
        {
           string elmt = line.substr(currPos, line.length() - currPos);
           double ve = atof(line.c_str());
           row.push_back(ve);
        }
        
        v.push_back(row);
    }
    return v;
}

void load_from_csv(const std::string& fileName_, emxArray_real_T *array_)
{
   DataV v = parse_csv(fileName_);
   if (v.size() > 0)
   {
      size_t cols = v.begin()->size();
      std::cout << "Parsed file=" << fileName_
                << ", rows=" << v.size()
                << ", cols=" << cols << std::endl;
      if (cols > 1)
        array_ = c_argInit_UnboundedxUnbounded_r(v);
      else if (cols == 1)
        array_ = argInit_Unboundedx1_real_T(v);
      else  
        throw std::runtime_error("0 columsn when loadingg csv filename=" + fileName_);
   }
   else 
    throw std::runtime_error("empty vector when loading csv filename=" + fileName_);
    
   std::cout << "Loaded file=" << fileName_ << std::endl;
}

void load_from_csv(const std::string& fileName_, double& value_)
{
   DataV v = parse_csv(fileName_);
   if (v.size() != 1)
       throw std::runtime_error("invalid number of parsed elements: " + std::to_string(v.size()));
   Row r = v[0];
   if (r.size() != 1)
       throw std::runtime_error("Expected 1 element, received: " + std::to_string(r.size()));
   value_ = r[0];
}

struct Args
{
  emxArray_real_T *X = nullptr;
  emxArray_real_T *Y = nullptr;
  emxArray_real_T *Ind = nullptr;
  emxArray_real_T *NaN = nullptr;
  emxArray_real_T *F = nullptr;
  double nansCols = 1.0;

  Args(const std::string& x_file,
       const std::string& y_file,
       const std::string& ind_file,
       const std::string& nan_file,
       unsigned runTime_)
  {
    load_from_csv(x_file, X);
    load_from_csv(y_file, Y);
    load_from_csv(ind_file, Ind);
    load_from_csv(nan_file, nansCols);
  }
  ~Args()
  {
    if (F)
      emxDestroyArray_real_T(F);
    if (Ind)
      emxDestroyArray_real_T(Ind);
    if (Y)
      emxDestroyArray_real_T(Y);
    if (X)
      emxDestroyArray_real_T(X);
    if (NaN)
      emxDestroyArray_real_T(NaN);
  }
};

/* Function Definitions */
/*
 * Arguments    : void
 * Return Type  : emxArray_real_T *
 */
static emxArray_real_T *argInit_Unboundedx1_real_T(const DataV& dataV_)
{
  emxArray_real_T *result;
  int idx0;
  int rows = (int)dataV_.size();

  /* Set the size of the array.
     Change this size to the value that the application requires. */
  result = emxCreateND_real_T(1, &rows);

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < result->size[0U]; idx0++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result->data[idx0] = dataV_[idx0][0];
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
static emxArray_real_T *c_argInit_UnboundedxUnbounded_r
    (const DataV& dataV_)
{
  emxArray_real_T *result;
  int idx0;
  int idx1;

  /* Set the size of the array.
     Change this size to the value that the application requires. */
  size_t rows = dataV_.size();
  size_t cols = dataV_.begin()->size();
  result = emxCreate_real_T(rows, cols);

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < result->size[0U]; idx0++) {
      Row row = dataV_[idx0];
      if (row.size() != cols)
      {
          throw std::runtime_error(std::string("Invalid number of cols for row=") +
                std::to_string(idx0) +
                ": row size=" + std::to_string(row.size()) + 
                ", cols=" + std::to_string(cols));
      }
    for (idx1 = 0; idx1 < result->size[1U]; idx1++) {
      /* Set the value of the array element.
         Change this value to the value that the application requires. */
      double elmt = row[idx1];
      result->data[idx0 + result->size[0] * idx1] = elmt;
      //double elmt = argInit_real_T();
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

  //dummy 2-dimensional Vector {2, 2}. Will remove this eventually
  //in favor or Args.
  DataV dummyV;
  Row   dummyRow;
  dummyRow.push_back(0.0);
  dummyRow.push_back(0.0);
  dummyV.push_back(dummyRow);

  /* Initialize function 'shuffleF' input arguments. */
  /* Initialize function input argument 'X'. */
  X = c_argInit_UnboundedxUnbounded_r(dummyV);

  /* Initialize function input argument 'y'. */
  y = c_argInit_UnboundedxUnbounded_r(dummyV);

  /* Initialize function input argument 'ind'. */
  dummyV.clear();
  dummyRow.push_back(0.0);
  dummyRow.push_back(0.0);
  ind = argInit_Unboundedx1_real_T(dummyV);
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
            << std::endl
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
  Args arg(X_csv, Y_csv, Ind_csv, NaN_csv, runCnt); 

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
