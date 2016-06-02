#include <stdio.h>
void sort();
void copy_exact(int *a, int *b, int s);
void swap(int a[], int x, int y);
void print_sorted(int *a, int s);


void bubble_sort(int *a, int s);
void insertion_sort(int *a, int s);

/*Merge Sort*/
void mergeSort(int *a, int s);
void partition(int *a, int low, int high);
void merge(int *a, int low, int mid, int high);

/*Quick Sort*/
void quickSort(int *a, int s);
void qsort(int *a, int low, int high);
int qPartition(int *arr, int low, int high);
void qS(int *arr, int low, int high);

void swap(int a[], int x, int y){
	int temp = a[x];
	a[x] = a[y];
	a[y] = temp;
}
void copy_exact(int *a, int *b, int s)
{
	int i = 0;
	for (i = 0; i < s; i++){
		b[i] = a[i];
	}
}
void print_sorted(int *b, int s)
{
	int i = 0;
	printf("After sorting: ");
	for (i = 0; i<s; i++)
		printf(" %d", b[i]);
	printf("\n");
}

int main()
{
	printf("hi");
	sort();
	return 0;
}

void sort()
{
	int s, i, a[20];

	printf("Enter total numbers of elements: ");
	scanf_s("%d", &s);

	printf("Enter %d elements: ", s);
	for (i = 0; i<s; i++)
		scanf_s("%d", &a[i]);

	bubble_sort(a, s);
	insertion_sort(a, s);
	mergeSort(a, s);
	quickSort(a, s);
}
void bubble_sort(int *a, int s)
{
	int i, j, b[20];
	copy_exact(a, b, s);
	for (i = s - 2; i >= 0; i--){
		for (j = 0; j <= i; j++){
			if (b[j] > b[j+1]){
				swap(b, j, j + 1);
			}
		}
	}
	printf("Bubble Sort \t");
	print_sorted(b, s);
}
void insertion_sort(int *a, int s)
{
	int i, j, b[20], temp;

	copy_exact(a, b, s);

	for (i = 1; i<s; i++){
		temp = b[i];
		j = i - 1;
		while ((temp<b[j]) && (j >= 0)){
			b[j + 1] = b[j];
			j = j - 1;
		}
		b[j + 1] = temp;
	}

	printf("Insertion Sort \t");
	print_sorted(b, s);
}
void mergeSort(int *a, int s){
	int b[20];
	copy_exact(a, b, s);
	partition(b, 0, s - 1);
	printf("Merge Sort \t");
	print_sorted(b, s);
}
void partition(int *a, int low, int high){
	int mid;
	if (low<high){
		mid = (low + high) / 2;
		partition(a, low, mid);
		partition(a, mid + 1, high);
		merge(a, low, mid, high);
	}
}
void merge(int a[], int low, int mid, int high){

	int i, m, k, l, temp[20];

	l = low;
	i = low;
	m = mid + 1;

	while ((l <= mid) && (m <= high)){

		if (a[l] <= a[m]){
			temp[i] = a[l];
			l++;
		}
		else{
			temp[i] = a[m];
			m++;
		}
		i++;
	}

	if (l>mid){
		for (k = m; k <= high; k++){
			temp[i] = a[k];
			i++;
		}
	}
	else{
		for (k = l; k <= mid; k++){
			temp[i] = a[k];
			i++;
		}
	}

	for (k = low; k <= high; k++){
		a[k] = temp[k];
	}
}
void quickSort(int *a, int s){
	int b[20], c[20];
	copy_exact(a, b, s);
	copy_exact(a, c, s);
	qsort(b, 0, s - 1);
	qS(c, 0, s - 1);
	printf("Quick Sort \t");
	print_sorted(b, s);
	print_sorted(c, s);
}
void qsort(int *a, int low, int high)
{
	int i, j, pivot, tmp;
	if (low<high)
	{
		pivot = low;
		i = low;
		j = high;
		while (i<j)
		{
			while (i<high && a[i] <= a[pivot])
				i++;
			while (a[j]>a[pivot])
				j--;
			if (i<j)
				swap(a, i, j);
		}
		tmp = a[pivot];
		a[pivot] = a[j];
		a[j] = tmp;
		qsort(a, low, j - 1);
		qsort(a, j + 1, high);
	}
}
int qPartition(int arr[], int low, int high)
{
	int pivot = arr[low], i = low;
  	for (int j = i + 1; j <= high; j++) {
		if (arr[j] <= pivot){// If current element is smaller than or equal to pivot
			i++;
			swap(arr,i,j);
		}
	}
	swap(arr, i, low);
	return (i + 1);
}
void qS(int arr[], int low, int high)
{
	if (low < high)	{
		int pi = qPartition(arr, low, high);/* pi is partitioning index, arr[p] is now at right place */
		qS(arr, low, pi - 1);
		qS(arr, pi + 1, high);
	}
}