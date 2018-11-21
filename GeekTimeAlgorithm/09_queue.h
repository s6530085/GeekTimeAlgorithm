//
//  09_queue.h
//  GeekTimeAlgorithm
//
//  Created by study_sun on 2018/11/12.
//  Copyright © 2018 study_sun. All rights reserved.
//

#ifndef _9_queue_h
#define _9_queue_h

// 增加一个元素个数的参数，方便判断是否满了
typedef struct SMCircularQueue {
    size_t capacity;
    int *data;
    size_t head;
    size_t tail;
    size_t count;
}SMCircularQueue;

SMCircularQueue* createQueue(size_t capacity);
void freeQueue(SMCircularQueue* queue);
bool enqueue(SMCircularQueue *queue, int value);
int dequeue(SMCircularQueue *queue, int *error);
bool queueIsEmpty(SMCircularQueue *queue);
bool queueIsFull(SMCircularQueue *queue);
void traverseQueue(SMCircularQueue *queue);
#endif /* _9_queue_h */
