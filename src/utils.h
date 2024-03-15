/*
@author : Yu Wang
*/

#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Macro to check for NA
#define IS_NA(x) ((x) == NA)

// struct for double elements and its length
typedef struct
{
  size_t nElements;
  double *Elements;
} ElementStruct;

// print an array
void PrintArrayInt(int *array, size_t n);
void PrintArrayDouble(double *array, size_t n);

int *GetSeqInt(int start, int end, int step);

// get a double sequence
double *GetSeqDouble(double start, double end, double step);

// sample k elements with or without replacement from a integer array of length n using seed
int *SampleInt(int *arrayIn, size_t n, size_t nSample, unsigned int replace, unsigned int seed);

// used for qsort
int vsD(const void *a, const void *b);

// used for qsort
int vsI(const void *a, const void *b);

// get sum of double array
double Sum(double *arrayIn, size_t n);

// get max of double array
double Max(double *arrayIn, size_t n);
double Min(double *arrayIn, size_t n);

typedef struct {
  double value;
  int index;
} IndexedValue;

// compare IndexedValue by value for qsort
// increasing
int vsP(const void *a, const void *b);
// decreasing
int vsPI(const void *a, const void *b);

int *Order(void *arrayIn, size_t n, bool decreasing, bool is_double);
double *Cummax(double *arrayIn, size_t n);
double *Cummin(double *arrayIn, size_t n);
#endif