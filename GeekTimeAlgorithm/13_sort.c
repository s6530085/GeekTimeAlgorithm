//
//  13_sort.c
//  GeekTimeAlgorithm
//
//  Created by study_sun on 2018/11/15.
//  Copyright © 2018 study_sun. All rights reserved.
//

#include "13_sort.h"

void counting_sort(int *array, size_t length)
{
    assert(array!=NULL&&length>1);
    // 找出最大值
    int max = array[0];
    for (size_t i = 1; i < length; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    // 还要容纳0哦
    max++;
    int *c = (int *)malloc(sizeof(int) * max);
    assert(c!=NULL);
    // 先清空
    for (size_t i = 0; i < max; i++) {
        c[i] = 0;
    }
    // 算出每个点位有多少人
    for (size_t j = 0; j < length; j++) {
        c[array[j]]++;
    }
    
    // 把人数进行累加，当前点位存储的是小于等于的人数总和
    int sum = 0;
    for (size_t k = 0; k < length; k++) {
        sum += c[k];
        c[k] = sum;
    }
    
    // 暂时停放结果的数组
    int *r = (int *)malloc(sizeof(int)*length);
    assert(r!=NULL);
    for (size_t i = 0; i < length; i++) {
        r[i] = 0;
    }
    for (int m = (int)length - 1; m >= 0; m--) {
        int value = array[m];
        int order = c[value];
        r[order] = value;
        c[value]--;
    }
    
    // 最后把结果拷回
    for (size_t i = 0; i < length; i++) {
        array[i] = r[i];
    }
    
}
