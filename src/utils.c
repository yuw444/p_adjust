#include "utils.h"

void PrintArrayInt(int *array, size_t n)
{
  if (array == NULL)
  {
    printf("NULL\n");
    return;
  }
  for (int i = 0; i < n; i++)
  {
    printf("%d ", array[i]);
  }
  printf("\n");
}

void PrintArrayDouble(double *array, size_t n)
{
  if (array == NULL)
  {
    printf("NULL\n");
    return;
  }
  for (int i = 0; i < n; i++)
  {
    printf("%.3f ", array[i]);
  }
  printf("\n");
}

int *GetSeqInt(int start, int end, int step)
{
  if (step == 0)
  {
    printf("step cannot be 0\n");
    exit(1);
  }

  if ((end - start) * step < 0)
  {
    printf("Error: step must be positive when start < end, or negative when start > end\n");
    exit(1);
  }
  size_t n = (end - start) / step + 1;
  int *seq = (int *)calloc(n, sizeof(int));
  if (seq == NULL)
  {
    printf("Memory allocation failed\n");
    exit(1);
  }
  for (int i = 0; i < n; i++)
  {
    seq[i] = start + i * step;
  }
  return seq;
}

double *GetSeqDouble(double start, double end, double step)
{
  if (step == 0.0)
  {
    printf("Error: step cannot be 0");
    exit(1);
  }

  if ((end - start) * step < 0.0)
  {
    printf("Error: step must be positive when start < end, or negative when start > end");
    exit(1);
  }

  int n = (int)((end - start) / step + 1);
  double *seq = (double *)calloc(n, sizeof(double));
  if (seq == NULL)
  {
    printf("Memory allocation failed\n");
    exit(1);
  }
  for (int i = 0; i < n; i++)
  {
    seq[i] = start + i * step;
  }
  return seq;
}

// used for qsort
int vsD(const void *a, const void *b)
{
  if (*(double *)a > *(double *)b)
    return 1;
  else if (*(double *)a < *(double *)b)
    return -1;
  else
    return 0;
}

double Max(double *arrayIn, size_t n)
{
  double max = arrayIn[0];
  for (int i = 1; i < n; i++)
  {
    if (arrayIn[i] > max)
    {
      max = arrayIn[i];
    }
  }
  return max;
}

double Min(double *arrayIn, size_t n)
{
  double min = arrayIn[0];
  for (int i = 1; i < n; i++)
  {
    if (arrayIn[i] < min)
    {
      min = arrayIn[i];
    }
  }
  return min;
}

int vsP(const void *a, const void *b)
{
  double x = ((IndexedValue *)a)->value;
  double y = ((IndexedValue *)b)->value;
  if (x < y)
    return -1;
  if (x > y)
    return 1;
}

int vsPI(const void *a, const void *b)
{
  double x = ((IndexedValue *)a)->value;
  double y = ((IndexedValue *)b)->value;
  if (x < y)
    return 1;
  if (x > y)
    return -1;
}

int *Order(void *arrayIn, size_t n, bool decreasing, bool is_double)
{
  IndexedValue *indexedValues = calloc(n, sizeof(IndexedValue));
  if (indexedValues == NULL)
  {
    printf("Memory allocation failed\n");
    exit(1);
  }

  for (size_t i = 0; i < n; i++)
  {
    indexedValues[i].index = i;
    if (is_double)
    {
      indexedValues[i].value = ((double *)arrayIn)[i];
    }
    else
    {
      indexedValues[i].value = ((int *)arrayIn)[i];
    }
  }

  if (decreasing)
  {
    qsort(indexedValues, n, sizeof(IndexedValue), vsPI);
  }
  else
  {
    qsort(indexedValues, n, sizeof(IndexedValue), vsP);
  }

  int *order = calloc(n, sizeof(int));
  if (order == NULL)
  {
    printf("Memory allocation failed\n");
    exit(1);
  }
  for (size_t i = 0; i < n; i++)
  {
    order[i] = indexedValues[i].index;
  }

  free(indexedValues);
  return order;
}

double *Cummax(double *arrayIn, size_t n)
{
  double *cummax = calloc(n, sizeof(double));
  if (cummax == NULL)
  {
    printf("Memory allocation failed\n");
    exit(1);
  }
  cummax[0] = arrayIn[0];
  for (size_t i = 1; i < n; i++)
  {
    cummax[i] = arrayIn[i] > cummax[i - 1] ? arrayIn[i] : cummax[i - 1];
  }
  return cummax;
}

double *Cummin(double *arrayIn, size_t n)
{
  double *cummin = calloc(n, sizeof(double));
  if (cummin == NULL)
  {
    printf("Memory allocation failed\n");
    exit(1);
  }
  cummin[0] = arrayIn[0];
  for (size_t i = 1; i < n; i++)
  {
    cummin[i] = arrayIn[i] < cummin[i - 1] ? arrayIn[i] : cummin[i - 1];
  }
  return cummin;
}
