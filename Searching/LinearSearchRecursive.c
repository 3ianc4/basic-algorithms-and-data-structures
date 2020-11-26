#include <stdio.h>

int linearSearch(int list[], int i, int target) {
    size_t n = sizeof(list) / sizeof(list[0]);
    if (list[i] == target)
    {
        return i;
    } 
    else if (i == n)
    {
        return -1;
    }
    else
    {
        linearSearch(list, i+1, target);
    }
}

int main(){
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    printf("Value found at %d\n", 1, linearSearch(a, 0, 1));
    linearSearch(a, 0, 10);
}