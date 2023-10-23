#include <stdint.h>
#include <stdio.h>

int kth(int arr1[], int arr2[], int m, int n, int k) {

  int i = 0;
  int j = 0;
  int count = 0;

  while (i < m && j < n) {
    if (arr1[i] <= arr2[j]) {
      count++;
      if (count == k)
        return arr1[i];
      i++;
    } else {
      count++;
      if (count == k)
        return arr2[j];
      j++;
    }
  }
}

int min(int x, int y) { return (x < y) ? x : y; }

int max(int x, int y) { return (x > y) ? x : y; }

int kthelement(int arr1[], int arr2[], int m, int n, int k) {
  if (m > n) {
    return kthelement(arr2, arr1, n, m, k);
  }

  int low = max(0, k - m), high = min(k, n);

  while (low <= high) {
    int cut1 = (low + high) >> 1;
    int cut2 = k - cut1;
    int l1 = cut1 == 0 ? INT32_MIN : arr1[cut1 - 1];
    int l2 = cut2 == 0 ? INT32_MIN : arr2[cut2 - 1];
    int r1 = cut1 == n ? INT32_MAX : arr1[cut1];
    int r2 = cut2 == m ? INT32_MAX : arr2[cut2];

    if (l1 <= r2 && l2 <= r1) {
      return max(l1, l2);
    } else if (l1 > r2) {
      high = cut1 - 1;
    } else {
      low = cut1 + 1;
    }
  }
  return 1;
}

int main() {
  // int A[] = {1, 3, 4, 7, 10, 12};
  // int B[] = {2, 3, 6, 15};
  // int A[] = {7, 12, 14, 15};
  // int B[] = {1, 2, 3, 4, 9, 11};

  int A[] = {5, 6};
  int B[] = {1};

  // 1 ,2 ,3,4,9

  int k = 2;

  int sizeA = sizeof(A) / sizeof(A[0]);
  int sizeB = sizeof(B) / sizeof(B[0]);
  printf("Size of A: %d\nSize of B: %d\n", sizeA, sizeB);

  int kElem = kth(A, B, sizeA, sizeB, k);

  printf("The %dth Elem: %d", k, kElem);
}
