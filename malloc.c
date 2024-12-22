#include <stdio.h>
#include<stdlib.h> 
int main() {
int n,i; 
printf("Enter the number ofelements: ");
scanf("%d", &n);
int *arr = (int*)malloc(n * sizeof(int));
printf("Enter initial elements:\n");
for ( i = 0; i < n; i++)
{
scanf("%d", &arr[i]);
}
printf("Enter new size for reallocation: ");
scanf("%d", &n);
arr = realloc(arr, n * sizeof(int));
printf("Enter new elements:\n");
for ( i = 0; i < n; i++)
{
scanf("%d", &arr[i]);
}
printf("Elements after reallocation:\n");
for ( i = 0; i < n; i++)
{
printf("%d ", arr[i]);
}
free(arr);
return 0;
}