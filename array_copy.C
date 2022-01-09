#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <string.h>
#include <sys/time.h>
int main (int argc, char *argv[])
{
    if (argc < 4)
    {
       std::cerr << "usage: "  << argv[0] 
                 << "<rows>"   << std::endl
                 << "<cols>"   << std::endl
                 << "iterations=" << std::endl
                 << "-m"       << std::endl;
       exit(0);
    }
    unsigned rows = atoi(argv[1]);
    unsigned cols = atoi(argv[2]);
    unsigned iterations = atoi(argv[3]);
    unsigned limit = rows * cols;
    bool useMemcpy = (argc > 4 && !strcmp(argv[4], "-m"));

    std::cout << "rows=" << rows
              << ",cols=" << cols
              << ", limit=" << limit
              << ", iterations=" << iterations
              << ", memcpy=" << (useMemcpy ? "true" : "false")
              << std::endl;

    double *src = (double *)calloc(limit, sizeof(double));
    double *targ = (double *)calloc(limit, sizeof(double));
    struct timeval start, end;
    if (!useMemcpy)
    { 
        gettimeofday(&start, 0);
        double blkSize = cols * sizeof(double);
        for (unsigned k = 0; k < iterations; ++k)
        {
            for (unsigned i = 0; i < rows; ++i)
            {
                size_t offset = cols * i;
                size_t len = cols * sizeof(double);
                memcpy((void *)&src[offset],
                    (void *)&targ[offset], 
                    len);
            }
        }
        gettimeofday(&end, 0);
    }
    else
    {
        gettimeofday(&start, 0);
        for (unsigned k = 0; k < iterations; ++k)
        {
            for (unsigned i = 0; i < rows; ++i)
            {
                for (unsigned j = 0; j < cols; ++j)
                {
                    size_t offset = cols * i + j;
                    //std::cout << "array offset=" << offset << std::endl;
                    targ[offset] = src[offset];
                }
            }
        }
        gettimeofday(&end, 0);
    }
    unsigned long etime = ((end.tv_sec * 1000000) + end.tv_usec) - ((start.tv_sec * 1000000) + start.tv_usec);
    std::cout << std::endl << "Elapsed time=" << etime << std::endl;
}
