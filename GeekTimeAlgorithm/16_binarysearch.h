//
//  16_binarysearch.h
//  GeekTimeAlgorithm
//
//  Created by study_sun on 2018/11/16.
//  Copyright © 2018 study_sun. All rights reserved.
//

#ifndef _6_binarysearch_h
#define _6_binarysearch_h

// 数组默认升序，第一个也是从左数第一个哦
int binary_search_firt_equal(int *array, int target, int length);

int binary_search_last_equal(int *array, int target, int length);

int binary_search_first_large_or_equal(int *array, int target, int length);

int binary_search_last_less_or_equal(int *array, int target, int length);

// 查找循环数组第一个值,形如{4,5,6,1,2,3}这种的，暂时只处理不同值的情况
int binary_search_loop(int *array, int target, int length);
#endif /* _6_binarysearch_h */
