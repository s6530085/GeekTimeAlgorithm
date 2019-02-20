//
//  27_recursiontree.c
//  GeekTimeAlgorithm
//
//  Created by study_sun on 2018/11/26.
//  Copyright © 2018 study_sun. All rights reserved.
//

#include "27_recursiontree.h"

static void print_array(int *array, int length)
{
    for (int i = 0; i< length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// left是这个数组还剩下来没排序的长度，length是总长
void print_all_full_permutation_inner(int *array, int left, int length)
{
    if (left == 1) {
        print_array(array, length);
    }
    else {
        for (int i = 0; i < left; i++) {
            swap_array(array, i, left-1);
            print_all_full_permutation_inner(array, left-1, length);
            swap_array(array, i, left-1);
        }
    }
}
//
void print_all_full_permutation(int *array, int length)
{
    assert(array!=NULL&&length>0);
    print_all_full_permutation_inner(array, length, length);
}

const static int life_limit = 3;
static int cell_splinter_inner(int life, int hour)
{
    if (life == 0) {
        return 0;
    }
    else if (hour == 0) {
        return 1;
    }
    else {
        return cell_splinter_inner(life_limit, hour-1) + cell_splinter_inner(life-1, hour-1);
    }
}

int cell_splinter(int hour)
{
    assert(hour>=0);
    return cell_splinter_inner(life_limit, hour);
}
