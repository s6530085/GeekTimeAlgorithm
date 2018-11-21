//
//  12_sort.c
//  GeekTimeAlgorithm
//
//  Created by study_sun on 2018/11/14.
//  Copyright © 2018 study_sun. All rights reserved.
//

#include "12_sort.h"

static void merge_sort_inner(int *array, size_t p, size_t r);
static void merge(int *array, size_t p, size_t q, size_t r);

static void quick_sort_inner(int *array, size_t p, size_t r);
static size_t partition(int *array, size_t p, size_t r);

void merge_sort(int *array, size_t length)
{
    assert(array!=NULL);
    merge_sort_inner(array, 0, length-1);
}

void merge_sort_inner(int *array, size_t p, size_t r)
{
    // 既然是inner的，就没必要反复判断null了
    if (p >= r) return;
    size_t q = (p + r)/2;
    merge_sort_inner(array, p, q);
    merge_sort_inner(array, q+1, r);
    merge(array, p, q, r);
}

void merge(int *array, size_t p, size_t q, size_t r)
{
    const size_t length = r - p + 1;
    int *temp = (int *)malloc(length);
    assert(temp!=NULL);
    size_t i = p;
    size_t j = q+1;
    size_t m = 0;
    while (m < length) {
        if (array[i] < array[j]) {
            temp[m++] = array[i++];
        }
        else {
            temp[m++] = array[j++];
        }
        // 当其中任何一边到头了，就直接复制后面所有
        if (i >= q+1) {
            for (; j <= r; j++) {
                temp[m++] = array[j];
            }
            break;
        }
        else if (j >= r+1) {
            for (; i <= q; i++) {
                temp[m++] = array[i];
            }
            break;
        }
    }
    // 最后拷过去
    for (size_t t = p; t <= r; t++) {
        array[t] = temp[t-p];
    }
    free(temp);
}


void quick_sort(int *array, size_t length)
{
    assert(array!=NULL&&length>0);
    quick_sort_inner(array, 0, length-1);
}

void quick_sort_inner(int *array, size_t p, size_t r)
{
    if (p >= r) return;
    size_t q = partition(array, p, r);
    // 很烦，有点想把size_t改成int了
    if (q >= 1) {
        quick_sort_inner(array, p, q-1);
    }
    quick_sort_inner(array, q+1, r);
}

size_t partition(int *array, size_t p, size_t r)
{
    int pivot = array[r];
    size_t i = p;
    for (size_t j = p; j < r; j++) {
        if (array[j] < pivot) {
            swap_array(array, i, j);
            i++;
        }
    }
    swap_array(array, i, r);
    return i;
}


int find_kth_largest(int *array, size_t length, size_t k)
{
    assert(array!=NULL&&(k>=1&&k<=length));
    size_t p = 0;
    size_t r = length - 1;
    size_t q = partition(array, p, r);
    if (q == length - k) {
        return array[q];
    }
    else if (q < length - k) {
        return find_kth_largest(array+q, length-q, k);
    }
    else {
        return find_kth_largest(array, q-1, k-(length-q+1));
    }
}
