#ifndef UNIX_SORT_H
#define UNIX_SORT_H
#include <assert.h>
void bubble_sort(int* a, int n)
{
    assert(a);
    int i = n - 1, j = 0;
    while(i != 0){
        for(j = 0; j != i; j++){
            if(a[j] > a[j+1]){
                int tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
        --i;
    }
}

static int qsort_divide(int* a, int l, int r)
{
    int x = a[l];
    --r;
    while(l < r){
        while(l < r && a[r] >= x) --r;
        a[l] = a[r];
        while(l < r && a[l] <= x) ++l;
        a[r] = a[l];
    }
    a[l] = x;
    return l;
}

void quick_sort(int* a, int l, int r)
{
    int i;
    assert(a);
    if (l < r){
        i = qsort_divide(a, l, r);
        quick_sort(a, l, i);
        quick_sort(a, i + 1, r);
    }
}

void select_sort(int* a, int n)
{
    int i, j;
    assert(a);
    for(i = n - 1; i != 0; i--){
        int index = 0;
        for(j = 0; j <= i; j++){
            if(a[index] < a[j]){
                index = j;
            }
        }
        int tmp = a[i];
        a[i] = a[index];
        a[index] = tmp;
    }
}
static void heap_adjust(int* a, int r, int n)
{
    int c = 2 * r + 1, tmp;
    while(c < n){
        if(c + 1 < n && a[c] < a[c + 1])c++;
        if(a[r] < a[c]){
            tmp = a[r];
            a[r] = a[c];
            a[c] = tmp;
        }else{
            break;
        }
        r = c;
        c = 2 * r + 1;
    }
}

void heap_sort(int* a, int n)
{
    int i;
    for(i = n/2 - 1; i >=0; --i){
        heap_adjust(a, i, n);
    }
    for(i = n - 1; i > 0; --i){
        int tmp = a[i];
        a[i] = a[0];
        a[0] = tmp;
        heap_adjust(a, 0, i);
    }
}
void insert_sort(int* a, int n)
{
    int i, j;
    for(i = 1; i < n; ++i){
        int tmp = a[i];
        for(j = i - 1; j >= 0 && tmp < a[j]; j--)
            a[j + 1] = a[j];
        a[j+1] = tmp;
    }
};
#endif //UNIX_SORT_H
