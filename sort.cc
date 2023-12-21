#include <iostream>

void BubbleSort(int A[], int length) {
  int temp;
  for (int i = 0; i < length - 1; i++) {
    bool flag = false;
    for (int j = length - 1; j > i; j--)
      if (A[j - 1] > A[j]) {
        temp = A[j - 1];
        A[j - 1] = A[j];
        A[j] = temp;
        flag = true;
      }
    if (flag == false)
      return;
    // 当没有发生交换的时候，说明已经有序
    // 通过设置flag，加速算法
  }
}

int Partition(int A[], int low, int high) {
  int pivot = A[low];
  while (low < high) {
    while (low < high && A[high] >= pivot)
      --high;
    A[low] = A[high];
    while (low < high && A[high] <= pivot)
      ++low;
    A[high] = A[low];
  }
  A[low] = pivot;
  return low;
}

void QuickSort(int A[], int low, int high) {
  if (low < high) {
    int pivotpos = Partition(A, low, high);
    QuickSort(A, low, pivotpos - 1);
    QuickSort(A, pivotpos + 1, high);
  }
}

int main() {
  int argv[10] = {5, 1, 1, 8, 0, 3, 6, 9, 4, 7};
  QuickSort(argv, 0, 9);
  // BubbleSort(argv,10);
  for (int i = 0; i < 10; i++) {
    printf("%d ", argv[i]);
  }
  return 0;
}
