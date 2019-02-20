//
//  28_heap.c
//  GeekTimeAlgorithm
//
//  Created by study_sun on 2018/11/29.
//  Copyright © 2018 study_sun. All rights reserved.
//

#include "28_heap.h"
SMHeap *create_heap(size_t capacity) {
    SMHeap *h = (SMHeap *)malloc(sizeof(SMHeap));
    assert(h!=NULL);
    int *d = (int *)malloc(sizeof(int)*capacity);
    assert(d!=NULL);
    h->capacity = capacity;
    h->data = d;
    h->count = 0;
    return h;
}

void free_head(SMHeap *heap)
{
    assert(heap!=NULL);
    free(heap->data);
    free(heap);
}

void insert_heap(SMHeap *heap, int value)
{
    assert(heap!=NULL);
    if (heap->count == heap->capacity) return;
    size_t index = ++heap->count;
    heap->data[index] = value;
    while (index/2>0) {
        if (heap->data[index/2] < value) {
            swap_array(heap->data, index, index/2);
            index = index/2;
        }
        else {
            break;
        }
    }
}

void delete_heap_top(SMHeap *heap)
{
    assert(heap!=NULL);
    if (heap->count == 0) return;
    heap->count--;
    // 如果就是一个元素，那也不用做了
    if (heap->count == 0) return;
    // 这次要自顶向下栈化
    size_t index = 1;
    heap->data[index] = heap->data[heap->count+1];
    while (index < heap->count) {
        int value = heap->data[index];
        if (value < heap->data[index*2]) {
            swap_array(heap->data, index, index*2);
            index *= 2;
        }
        else if (value < heap->data[index*2+1]) {
            swap_array(heap->data, index, index*2+1);
            index = index*2 + 1;
        }
        else {
            break;
        }
    }
}

void heapify(SMHeap *heap, size_t n, size_t i)
{
    
}

void build_heap(SMHeap *heap)
{
    
}



void sort_heap(SMHeap *heap)
{
    assert(heap!=NULL);
    build_heap(heap);
    size_t i = heap->count;
    while (i > 1) {
        swap_array(heap->data, 1, i);
        i--;
        heapify(heap, i, 1);
    }
 }
