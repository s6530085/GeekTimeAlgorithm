//
//  16_binarysearch.c
//  GeekTimeAlgorithm
//
//  Created by study_sun on 2018/11/16.
//  Copyright © 2018 study_sun. All rights reserved.
//
#include "15_binarysearch.h"

#include "16_binarysearch.h"


int binary_search_firt_equal(int *array, int target, int length)
{
    int lo = 0;
    int hi = length - 1;
//    while (lo <= hi) {
//        int mid = lo + ((hi - lo) >> 1);
//        if (array[mid] >= target) {
//            hi = mid - 1;
//        }
//        else {
//            lo = mid + 1;
//        }
//    }
//    if (lo < length && array[lo] == target) return lo;
//    else return -1;
    while (lo < hi) {
        int mid = lo + ((hi - lo) >> 1);
        if (array[mid] > target) {
            hi = mid - 1;
        }
        else if (array[mid] < target) {
            lo = mid + 1;
        }
        else {
            if (mid == 0 || array[mid-1] != target) {
                return mid;
            }
            else {
                hi = mid - 1;
            }
        }
    }
    return -1;
}

int binary_search_last_equal(int *array, int target, int length)
{
    int lo = 0;
    int hi = length - 1;
    while (lo <= hi) {
        int mid = lo + ((hi - lo) >> 1);
//        if (array[mid] <= target) {
//            lo = mid + 1;
//        }
//        else {
//            hi = mid - 1;
//        }
//    }
//    if (hi >= 0 && array[hi] == target) return hi;
//    else return -1;
        if (array[mid] < target) {
            lo = mid + 1;
        }
        else if (array[mid] > target) {
            hi = mid - 1;
        }
        else {
            if ((mid == (length - 1)) || array[mid+1] != target) {
                return mid;
            }
            else {
                lo = mid + 1;
            }
        }
    }
    return -1;
}

int binary_search_first_large_or_equal(int *array, int target, int length)
{
    int lo = 0;
    int hi = length - 1;
    while (lo <= hi) {
        int mid = lo + ((hi - lo) >> 1);
        if (array[mid] < target) {
            lo = mid + 1;
        }
        else {
            if (mid == 0 || array[mid-1] < target) return mid;
            else hi = mid - 1;
        }
    }
    return -1;
}

int binary_search_last_less_or_equal(int *array, int target, int length)
{
    int lo = 0;
    int hi = length - 1;
    while (lo <= hi) {
        int mid = lo + ((hi - lo) >> 1);
        if (array[mid] > target) {
            hi = mid - 1;
        }
        else {
            if ((mid == (length -1)) || array[mid+1] > target) return mid;
            else lo = mid + 1;
        }
    }
    return -1;
}

int binary_search_loop(int *array, int target, int length)
{
    int lo = 0;
    int hi = length - 1;
    
    while (lo <= hi) {
        int mid = lo + ((hi - lo) >> 1);
        int value = array[mid];
        if (value == target) {
            return mid;
        }
        // 没意义划分了
        if (length == 1) {
            return -1;
        }
        
        // 如果中间值大于头部，说明左边还是顺序的
        if (value > array[0]) {
            // 如果target落在左边，就原始二分查找
            if (target < value && target >= array[0]) {
                return binary_search(array, target, mid);
            }
            // 否则递归调用自己,但要加上偏移量
            else {
                // 但要小心mid可能已经到最右了
//                if (mid == (length - 1)) {
//                    return -1;
//                }
//                else {
                int ret = binary_search_loop(&array[mid+1], target, length-mid-1);
                if (ret == -1) {
                    return -1;
                }
                else {
                    return mid + 1 + ret;
                }
//                    return mid+1+ binary_search_loop(&array[mid+1], target, length-mid-1);
//                }
            }
        }
        // 否则右边是有序数组,做法则是和上面正好相反
        else {
            // mid都是最右了，那肯定两个都在最右
//            if (mid == (length - 1)) {
//                return -1;
//            }
            // 只能通过判断是否在顺序列表中
            if (target >= array[mid+1] && target <= array[length-1]) {
                if (mid == (length - 1)) {
                    return -1;
                }
                else {
                    int ret = binary_search(&array[mid+1], target, length-mid-1);
                    if (ret == -1) {
                        return -1;
                    }
                    else {
                        return mid+1+ret;
                    }
                }
            }
            else {
                return binary_search_loop(array, target, length - mid - 1);
            }
        }
    }
    return -1;
}
