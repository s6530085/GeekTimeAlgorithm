//
//  12_sort.h
//  GeekTimeAlgorithm
//
//  Created by study_sun on 2018/11/14.
//  Copyright © 2018 study_sun. All rights reserved.
//

#ifndef _2_sort_h
#define _2_sort_h

void merge_sort(int *array, size_t length);

void quick_sort(int *array, size_t length);

// 第k大还是自然语言，不会说找出第0大的元素的
int find_kth_largest(int *array, size_t length, size_t k);
#endif /* _2_sort_h */
