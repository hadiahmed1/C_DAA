#include <stdio.h>
void merge(int arr[], int l, int m, int r)
{
int i, j, k;
int n1 = m - l + 1;
int n2 = r - m;
/* create temp arrays */
int L[n1], R[n2];
/* Copy data to temp arrays L[] and R[] */
for (i = 0; i < n1; i++)
L[i] = arr[l + i];
for (j = 0; j < n2; j++)
R[j] = arr[m + 1 + j];
/* Merge the temp arrays back into arr[l..r]*/
i = 0; // Initial index of first subarray
j = 0; // Initial index of second subarray
k = l; // Initial index of merged subarray
while (i < n1 && j < n2) {
if (L[i] <= R[j]) {
arr[k] = L[i];
i++;
}
else {
arr[k] = R[j];
j++;
}
k++;
}
/* Copy the remaining elements of L[], if there are any */
while (i < n1) {
arr[k] = L[i];
i++;
k++;
}
/* Copy the remaining elements of R[], if there are any */
while (j < n2) {
arr[k] = R[j];
j++;
k++;
}
}
/* l is for left index and r is right index of the sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
int m;
if (l < r) {
m = l + (r - l) / 2;
mergeSort(arr, l, m);
mergeSort(arr, m + 1, r);
merge(arr, l, m, r);
}
}
void printArray(int A[], int n)
{
int i;
for (i = 0; i < n; i++)
printf("%d ", A[i]);
printf("\n");
}
/* Driver code */
int main()
{
int arr[100], n, i;
printf("\nEnter the number of elements:");
scanf("%d", &n);
printf("\nEnter the %d elements\n", n);
for(i=0; i<n; i++)
scanf("%d", &arr[i]);
printf("*******Given array is ******** \n");
printArray(arr, n);
mergeSort(arr, 0, n - 1);
printf("\n******Sorted array is ******\n");
printArray(arr, n);
return 0;
}