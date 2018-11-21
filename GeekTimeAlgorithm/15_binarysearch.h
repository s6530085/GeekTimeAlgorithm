//
//  15_binarysearch.h
//  GeekTimeAlgorithm
//
//  Created by study_sun on 2018/11/15.
//  Copyright © 2018 study_sun. All rights reserved.
//

#ifndef _5_binarysearch_h
#define _5_binarysearch_h

// 找不到返回-1,最简单的找任何一个相等的值就行了
int binary_search(int *array, int target, int length);

// 递归的形式
int binary_search_r(int *array, int target, int length);

// 用二分查找的方式算平方根，精确到小数点后6位
double sqrt_binary_search(double root, int precise);

#endif /* _5_binarysearch_h */
