#include <stdio.h>
#include <stdlib.h>
int main() {
    int *array;
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    array = (int *)calloc(n, sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    printf("The elements are:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    free(array);
    array = NULL; 
    return 0;
}
