//
//  09_queue.c
//  GeekTimeAlgorithm
//
//  Created by study_sun on 2018/11/12.
//  Copyright © 2018 study_sun. All rights reserved.
//

#include "09_queue.h"

SMCircularQueue* createQueue(size_t capacity)
{
    assert(capacity > 0);
    SMCircularQueue *q = (SMCircularQueue *)malloc(sizeof(SMCircularQueue));
    int *d = (int *)malloc(capacity * sizeof(int));
    assert(q!=NULL&&d!=NULL);
    q->capacity = capacity;
    q->data = d;
    q->head = 0;
    q->tail = 0;
    q->count = 0;
    return q;
}

void freeQueue(SMCircularQueue *queue)
{
    assert(queue!=NULL);
    free(queue->data);
    free(queue);
}

bool enqueue(SMCircularQueue *queue, int value)
{
    assert(queue!=NULL);
    if (queueIsFull(queue)) {
        return false;
    }
    else {
        // 入队要小心tail已经到最后了
        queue->data[queue->tail] = value;
        queue->tail = (queue->tail + 1) % queue->capacity;
        queue->count++;
        return true;
    }
}

int dequeue(SMCircularQueue *queue, int *error)
{
    assert(queue!=NULL);
    if (queueIsEmpty(queue)) {
        if (error != NULL) {
            *error = true;
        }
        return 0;
    }
    else {
        int value = queue->data[queue->head];
        queue->head = (queue->head + 1) % queue->capacity;
        queue->count--;
        return value;
    }
}

bool queueIsEmpty(SMCircularQueue *queue)
{
    assert(queue!=NULL);
    return queue->count == 0;
}


bool queueIsFull(SMCircularQueue *queue)
{
    assert(queue!=NULL);
    return queue->count == queue->capacity;
}

void traverseQueue(SMCircularQueue *queue)
{
    assert(queue!=NULL);
    size_t c = queue->count;
    size_t index = queue->head;
    while (c > 0) {
        printf("at index %zu is %d ,", index, queue->data[index]);
        if (index == queue->capacity-1) {
            index = 0;
        }
        else {
            index++;
        }
        c--;
    }
    printf("\n");
}

