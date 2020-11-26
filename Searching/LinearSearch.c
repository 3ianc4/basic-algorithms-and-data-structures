#include <stdio.h>

int linearSearch(int list[], int target) {
    size_t n = sizeof(list[0]);
    for (int i = 0; i < n; i++)
    {
        if (list[i] == target)
        {
            return i;
        }
    }
    return -1;    
}

int main(){
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    linearSearch(a, 3);
    linearSearch(a, 9);
}