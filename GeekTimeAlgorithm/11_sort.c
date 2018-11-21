//
//  11_sort.c
//  GeekTimeAlgorithm
//
//  Created by study_sun on 2018/11/12.
//  Copyright © 2018 study_sun. All rights reserved.
//

#include "11_sort.h"

void bubbleSort(int *array, size_t length)
{
    assert(array!=NULL);
    for (size_t i = 0; i < length; i++) {
        bool hasChange = false;
        for (size_t j = 0; j < length - i - 1; j++) {
            if (array[j] > array[j+1]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
                hasChange = true;
            }
        }
        if (!hasChange) {
            break;
        }
    }
}

void insertionSort(int *array, size_t length)
{
    assert(array!=NULL);
    for (size_t i = 1; i < length; i++) {
        int insertion = array[i];
        size_t position = -1;
        for (size_t j = 0; j < i; j++) {
            if (insertion < array[j]) {
                position = j;
                break;
            }
        }
        if (position != -1) {
            // 开始移动,用int是因为--到了0
            for (int k = (int)i-1; k >= (int)position;k--) {
                array[k+1] = array[k];
            }
            array[position] = insertion;
        }
    }
}

void selectionSort(int *array, size_t length)
{
    assert(array!=NULL);
    for (size_t i = 0; i < length; i++) {
        size_t minIndex = i;
        for (size_t j = i+1; j <length; j++) {
            if (array[minIndex] > array[j]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int temp = array[minIndex];
            array[minIndex] = array[i];
            array[i] = temp;
        }
    }
}
