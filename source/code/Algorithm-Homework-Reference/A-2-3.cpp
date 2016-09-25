template <class T>
void BinarySearch(const T *a, int n, const T &x, int &i, int &j) {
  // init
  i = -1, j = n;
  while (j - i > 1) { 
    // internal length > 1
    int mid = (i + j) / 2; 
    // j - i > 1 
    // => i < mid < j
    // => 0 <= mid < n
    // so a[mid] is available
    // and #[i', j'] < #[i, j]
    if(a[mid] < x) i = mid;
    else if(x < a[mid]) j = mid;
    else i = j = mid;
  }
}

