//
//  utils.c
//  GeekTimeAlgorithm
//
//  Created by study_sun on 2018/11/12.
//  Copyright © 2018 study_sun. All rights reserved.
//

#include "utils.h"

void swap_array(int *array, size_t i, size_t j)
{
    assert(array!=NULL);
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

void traverArray(int *array, size_t length)
{
    assert(array!=NULL);
    printf("array content is ");
    for (size_t i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int *rand_array(size_t length)
{
    int *a = (int *)malloc(length);
    assert(a!=NULL);
    srand((unsigned int)length);
    for (size_t i = 0; i < length; i++) {
        a[i] = rand();
    }
    return a;
}

bool is_ordered(int *array, size_t length, bool asc)
{
    assert(array!=NULL&&length>0);
    if (asc) {
        for (size_t i = 0; i < length - 1; i++) {
            if (array[i] > array[i+1]) {
                return false;
            }
        }
        return true;
    }
    else {
        for (size_t i = 0; i < length - 1; i++) {
            if (array[i] < array[i+1]) {
                return false;
            }
        }
        return true;
    }
}
