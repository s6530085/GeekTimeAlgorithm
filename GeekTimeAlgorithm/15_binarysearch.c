//
//  15_binarysearch.c
//  GeekTimeAlgorithm
//
//  Created by study_sun on 2018/11/15.
//  Copyright © 2018 study_sun. All rights reserved.
//

#include "15_binarysearch.h"

int binary_search(int *array, int target, int length)
{
    assert(array!=NULL&&length>0);
    int lo = 0;
    int hi = length - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo)/2;
        int value = array[mid];
        if (value == target) {
            return mid;
        }
        else if (value < target) {
            lo = mid+1;
        }
        else {
            hi = mid-1;
        }
    }
    return -1;
}

int binary_search_r_inner(int *array, int target, int lo, int hi)
{
    if (lo > hi) {
        return -1;
    }
    int mid = lo + (hi - lo) / 2;
    int value = array[mid];
    if (value == target) {
        return mid;
    }
    else if (value < target) {
        return binary_search_r_inner(array, target, mid+1, hi);
    }
    else {
        return binary_search_r_inner(array, target, lo, mid-1);
    }
}

int binary_search_r(int *array, int target, int length)
{
    assert(array!=NULL&&length>0);
    return binary_search_r_inner(array, target, 0, length-1);
}

//typedef int (*BCOMP)();
//int binary_search_comp(int *array, )

double sqrt_binary_search(double root, int precise)
{
    // 先找整数部分
    int integer = 1;
    if (root >= 1) {
        while (integer*integer<=root) {
            integer++;
        }
        integer--;
    }
    else {
        integer = 0;
    }
    int lo = 0;
    int hi = pow(10, precise) - 1;
    double space = 1.0 / pow(10, precise);
    while (lo <= hi) {
        int mid = lo + (hi - lo)/2;
        double value = integer + mid * space;
        double offset = pow(value, 2) - root;
        if (fabs(offset) < 0.00001) {
            return value;
        }
        else if (offset < 0) {
            lo = mid+1;
        }
        else {
            hi = mid-1;
        }
    }
    return 0;
}
