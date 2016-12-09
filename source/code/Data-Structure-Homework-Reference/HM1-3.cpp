#include <algorithm>
#include <cassert>
#include <cstdio>
#include <ctime>
#include <fstream>

#define R(x, y) (x < y)

void InsertionSort(int *data, int n) {
  for (int i = 1; i < n; i++) {
    int x = data[i], j;
    for (j = i - 1; j >= 0 && R(x, data[j]); j--) {
      data[j + 1] = data[j];
    }
    data[j + 1] = x;
  }
}

void SelectionSort(int *data, int n) {
  for (int i = 0; i < n; i++) {
    int minIndex = i;
    for (int j = i + 1; j < n; j++) {
      if (R(data[j], data[minIndex])) {
        minIndex = j;
      }
    }
    std::swap(data[i], data[minIndex]);
  }
}

void ShellSort(int *data, int n) {
  for (int step = n / 2; step >= 1; step /= 2) {
    for (int i = step; i < n; i++) {
      int x = data[i], j;
      for (j = i - step; j >= 0 && R(x, data[j]); j -= step) {
        data[j + step] = data[j];
      }
      data[j + step] = x;
    }
  }
}

void QuickSort(int *data, int n) {
  int i = 0, j = n - 1, x = data[(n - 1) / 2];
  while (i <= j) {
    while (R(data[i], x)) {
      i++;
    }
    while (R(x, data[j])) {
      j--;
    }
    if (i <= j) {
      std::swap(data[i++], data[j--]);
    }
  }
  if (0 < j) {
    QuickSort(data, j + 1);
  }
  if (i < n - 1) {
    QuickSort(data + i, n - i);
  }
}

void MergeSort(int *data, int n) {
  int *tape = new int[n];
  int *from = data, *to = tape;
  int blocks = n, size = 1;
  while (blocks > 1) {
    for (int i = 0; i < blocks; i += 2) {
      int begin1 = i * size;
      int begin2 = (i + 1) * size;
      int end1 = std::min(begin2, n);
      int end2 = std::min((i + 2) * size, n);
      int curTo = i * size;
      while (begin1 < end1 && begin2 < end2) {
        if (R(from[begin1], from[begin2])) {
          to[curTo++] = from[begin1++];
        } else {
          to[curTo++] = from[begin2++];
        }
      }
      while (begin1 < end1) {
        to[curTo++] = from[begin1++];
      }
      while (begin2 < end2) {
        to[curTo++] = from[begin2++];
      }
    }
    blocks = (blocks + 1) >> 1;
    size <<= 1;
    std::swap(from, to);
  }
  if (to == data) {
    for (int i = 0; i < n; i++) {
      data[i] = tape[i];
    }
  }
  delete tape;
}

double test(void (*sort)(int *, int), int n, int (*gen)(int), int times = 1) {
  double Timer = 0;
  int *data = new int[n];
  for (int t = 0; t < times; t++) {
    for (int i = 0; i < n; i++) {
      data[i] = gen(i);
    }
    Timer -= double(clock());
    sort(data, n);
    Timer += double(clock());
    for (int i = 1; i < n; i++) {
      assert(!R(data[i], data[i - 1]));
    }
  }
  delete data;
  return Timer / times / CLOCKS_PER_SEC;
}

int SortedArrayGen(int i) { return i; }
int ReversedSortedArrayGen(int i) { return -i; }
int UniformRandomArrayGen(int i) { return rand(); }

void testAlgo(std::ofstream &out, void (*algo)(int *, int), int times = 1) {
  out << "Number of elements,sorted array,reverse sorted array,random array"
      << std::endl;
  for (int n = 100; n <= 10000; n += 100) {
    out << n << "," << test(algo, n, SortedArrayGen, times) << ","
        << test(algo, n, ReversedSortedArrayGen, times) << ","
        << test(algo, n, UniformRandomArrayGen, times) << std::endl;
  }
}
void compareAlgo(std::ofstream &out, int (*gen)(int), int times = 1) {
  out << "Numbers of elements,Insertion Sort,Selection Sort,Shell Sort,Quick "
         "Sort,Merge Sort"
      << std::endl;
  for (int n = 100; n <= 10000; n += 100) {
    out << n << "," << test(InsertionSort, n, gen, times) << ","
        << test(SelectionSort, n, gen, times) << ","
        << test(ShellSort, n, gen, times) << ","
        << test(QuickSort, n, gen, times) << ","
        << test(MergeSort, n, gen, times) << std::endl;
  }
}

int main() {
  srand(time(0));
  int times = 10;

  std::ofstream FInsertionSort("InsertionSort.csv");
  testAlgo(FInsertionSort, InsertionSort, times);
  
  std::ofstream FSelectionSort("SelectSort.csv");
  testAlgo(FSelectionSort, SelectionSort, times);

  std::ofstream FShellSort("ShellSort.csv");
  testAlgo(FShellSort, ShellSort, times);

  std::ofstream FMergeSort("MergeSort.csv");
  testAlgo(FMergeSort, MergeSort, times);

  std::ofstream FQuickSort("QuickSort.csv");
  testAlgo(FQuickSort, QuickSort, times);

  std::ofstream FSortedArray("SortedArray.csv");
  compareAlgo(FSortedArray, SortedArrayGen, times);

  std::ofstream FReversedSortedArray("ReversedSortedArray.csv");
  compareAlgo(FReversedSortedArray, ReversedSortedArrayGen, times);

  std::ofstream FRandomArray("RandomArray.csv");
  compareAlgo(FRandomArray, UniformRandomArrayGen, times);

  return 0;
}
