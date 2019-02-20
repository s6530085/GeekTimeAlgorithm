//
//  28_heap.h
//  GeekTimeAlgorithm
//
//  Created by study_sun on 2018/11/29.
//  Copyright © 2018 study_sun. All rights reserved.
//

#ifndef _8_heap_h
#define _8_heap_h

typedef struct SMHeap {
    size_t capacity;
    int *data;
    size_t count;
}SMHeap;

SMHeap *create_heap(size_t capacity);
void free_heap(SMHeap *heap);
// 默认是大顶栈
void insert_heap(SMHeap *heap, int value);
void delete_heap_top(SMHeap *heap);

void sort_heap(SMHeap *heap);

#endif /* _8_heap_h */
