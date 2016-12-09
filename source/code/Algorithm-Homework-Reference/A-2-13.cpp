#define R(x, y) (x > y)
template <class T>
void QuickSort(T *A, int p, int r) {
	int i = p, j = r, x = A[(p + r) / 2];
	while (i <= j) {
		while (R(A[i], x)) i++;
		while (R(x, A[j])) j--;
		if (i <= j) std::swap(A[i++], A[j--]);
	}
	if (p < j) QuickSort(A, p, j);
	if (i < r) QuickSort(A, i, r);
}

