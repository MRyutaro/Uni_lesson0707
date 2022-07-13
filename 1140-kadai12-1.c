#include <stdio.h>
#include <stdlib.h>

int n;

void bubble_sort(int *A);
void show_array(int *A, int sign_num);

int main(int argc, char *argv[])
{
  int i;
  n = argc - 1;

  int A[n];

  for (i = 1; i < argc; i++)
    A[i - 1] = atoi(argv[i]);
  bubble_sort(A); // 配列A[0]からA[n-1]のバブルソート
  return 0;
}

void bubble_sort(int *A)
{
  int i, j, exchange_num = 0, comparison_num = 0;
  printf("A = ");
  for (i = 0; i < n - 1; i = i + 1)
  {
    printf("パス%d:\n", i + 1);
    for (j = n - 1; j > i; j = j - 1)
    {
      comparison_num += 1;
      show_array(A, j);
      if (A[j - 1] > A[j])
      {
        int t;
        t = A[j];
        A[j] = A[j - 1];
        A[j - 1] = t;
        exchange_num += 1;
      }
    }
    show_array(A, 0);
  }
  printf("比較は%d回でした。\n", comparison_num);
  printf("交換は%d回でした。\n", exchange_num);
}

void show_array(int *A, int sign_num)
{
  for (int i = 0; i < sign_num; i++)
  {
    printf(" %d", A[i]);
  }
  if (sign_num > 0)
  {
    if (A[sign_num - 1] > A[sign_num])
    {
      printf(" >");
    }
    else
    {
      printf(" <");
    }
  }
  for (int i = sign_num; i < n; i++)
  {
    printf(" %d", A[i]);
  }
  printf("\n");
}
