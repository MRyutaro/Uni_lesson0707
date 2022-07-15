#include <stdio.h>
#include <stdlib.h>

#define M 1000000     // バケットQの個数：1000000（任意に変更可）
#define QUEUESIZE 100 // 1つのバケットに格納可能なデータ数：100（任意に変更可）
#define TRUE 1
#define FALSE 0

// バケットをリングバッファ（キュー）として実現する際のポインタ増加用（2.5.3節参照）
#define next(x) (x + 1) % QUEUESIZE

// キューのデータ構造（frontとrearの各ポインタとデータを格納する配列から構成）
typedef struct queue
{
  int front;
  int rear;
  int data[QUEUESIZE];
} QUEUE;

QUEUE Q[M]; // 各要素がキューのデータ構造を持つ配列QとしてM個のバケットを定義

int n;

void init();
void enqueue(int i, int d);
int dequeue(int i);
int emptyqueue(int i);
void bucket_sort(int *A);

int main(int argc, char *argv[])
{
  int i;
  n = argc - 1;

  int A[n];

  for (i = 1; i < argc; i++)
    A[i - 1] = atoi(argv[i]);

  bucket_sort(A); // 配列A[0]からA[n-1]のバケットソート
  return 0;
}

// 全てのキューを初期化（空状態）
void init()
{
  int i;
  for (i = 0; i < M; i = i + 1)
  {
    Q[i].front = 0;
    Q[i].rear = 0;
  }
}

// キューQ[i]にデータdをエンキュー
void enqueue(int i, int d)
{
  if (next(Q[i].rear) == Q[i].front)
  {
    printf("Queue Overflow\n");
    exit(1);
  }
  Q[i].data[Q[i].rear] = d;
  Q[i].rear = next(Q[i].rear);
}

// キューQ[i]からデータをデキュー
int dequeue(int i)
{
  int x;
  if (Q[i].front == Q[i].rear)
  {
    printf("Queue Underflow\n");
    exit(1);
  }
  x = Q[i].data[Q[i].front];
  Q[i].front = next(Q[i].front);
  return x;
}

// キューQ[i]が空状態であればTRUEを，そうでなければFALSEを返却
int emptyqueue(int i)
{
  if (Q[i].front == Q[i].rear)
    return TRUE;
  else
    return FALSE;
}

// 要素数nの配列Aをバケットソートにより整列
// Q[0],...,Q[M-1]: M個のバケット（キューとして実現）
void bucket_sort(int *A)
{
  int i, j;
  init();
  for (i = 0; i < n; i = i + 1)
  {
    enqueue(A[i], A[i]);
  }
  for (int bucket_num = 0; bucket_num < 10; bucket_num = bucket_num + 1)
  {
    printf("Q[%d]", bucket_num);
    if(emptyqueue(bucket_num) == 0){
      for (int k = 0; k < n; k = k + 1){
        if(A[k] == bucket_num){
          printf(" -> A[%d]", k);
        }
      }
    }
    printf("\n");
  }
  for (i = 0, j = 0; j < M; j = j + 1)
  {
    // Q[j]の中にある配列が空じゃない間回す
    while (emptyqueue(j) == 0)
    {
      A[i] = dequeue(j);
      i = i + 1;
    }
  }
}
