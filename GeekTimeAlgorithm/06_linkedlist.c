//
//  06_linklist.c
//  GeekTimeAlgorithm
//
//  Created by study_sun on 2018/11/11.
//  Copyright © 2018 study_sun. All rights reserved.
//

#include "06_linkedlist.h"

SMLinkedList* createSMLinkedList(void)
{
    SMLinkedList* l = (SMLinkedList *)malloc(sizeof(struct SMLinkedList));
    assert(l!=NULL);
    l->head = NULL;
    return l;
}

void freeSMLinkedList(SMLinkedList* list)
{
    assert(list!=NULL);
    SMLinkedNode* node = list->head;
    while (node != NULL) {
        pSMLinkedNode temNode = node->next;
        free(node);
        node = temNode;
    }
    free(list);
}

SMLinkedNode* valueNode(SMLinkedList *list, int value)// 取到的第一个哦
{
    assert(list!=NULL);
    SMLinkedNode* node = list->head;
    while (node != NULL) {
        if (node->value == value) {
            return node;
        }
        node = node->next;
    }
    return NULL;
}

void removeValue(SMLinkedList *list, int value)
{
    assert(list!=NULL);
    SMLinkedNode* node = list->head;
    SMLinkedNode* lastNode = NULL;
    while (node != NULL) {
        if (node->value == value) {
            // 是头要做特殊处理
            if (list->head == node) {
                list->head = node->next;
            }
            else {
                lastNode->next = node->next;
            }
            
            free(node);
            break;
        }
        lastNode = node;
        node = node->next;
    }
}

void removeNode(SMLinkedList *list, SMLinkedNode *targetNode)
{
    assert(list!=NULL && targetNode!=NULL);
    SMLinkedNode* node = list->head;
    SMLinkedNode* lastNode = NULL;
    while (node != NULL) {
        if (node == targetNode) {
            if (list->head == targetNode) {
                list->head = targetNode->next;
            }
            else {
                lastNode->next = node->next;
            }
            free(node);
            break;
        }
        lastNode = node;
        node = node->next;
    }
}

SMLinkedNode* appendValue(SMLinkedList *list, int value)// 加在最后哦
{
    if (list != NULL) {
        SMLinkedNode* valueNode = (SMLinkedNode *)malloc(sizeof(SMLinkedNode));
        assert(valueNode!=NULL);
        valueNode->value = value;
        valueNode->next = NULL;
        SMLinkedNode* node = list->head;
        if (node == NULL) {
            list->head = valueNode;
            return valueNode;
        }
        else {
            while (node != NULL) {
                if (node->next == NULL) {
                    node->next = valueNode;
                    return valueNode;
                }
                node = node->next;
            }
        }
    }
    return NULL;
}


SMLinkedNode* insertValue(SMLinkedList *list, int value)// 加在最前哦
{
    assert(list!=NULL);
    SMLinkedNode* valueNode = (SMLinkedNode *)malloc(sizeof(SMLinkedNode));
    assert(valueNode!=NULL);
    valueNode->value = value;
    valueNode->next = list->head;
    
    list->head = valueNode;
    return valueNode;
}


SMLinkedNode* insertValueAfter(SMLinkedNode *node, int value)// 加在某节点之后
{
    assert(node!=NULL);
    SMLinkedNode* valueNode = (SMLinkedNode *)malloc(sizeof(SMLinkedNode));
    assert(valueNode!=NULL);
    valueNode->next = node->next;
    node->next = valueNode;
    return valueNode;
}


SMLinkedNode* isnertValueBefore(SMLinkedList* list, SMLinkedNode* node, int value)// 加在某节点之前，不好意思得遍历了
{
    assert(list!=NULL && node!=NULL);
    SMLinkedNode* valueNode = (SMLinkedNode *)malloc(sizeof(SMLinkedNode));
    assert(valueNode!=NULL);
    if (list->head == node) {
        list->head = valueNode;
    }
    else {
        SMLinkedNode *lastNode = list->head;
        while (lastNode->next != node) {
            lastNode = lastNode->next;
        }
        // 可能node根本不在list中哦
        assert(lastNode!=NULL);
        lastNode->next = valueNode;
    }
    valueNode->next = node;
    return valueNode;
}

bool isPalindrome(const char *s)
{
    size_t length;
    bool is = true;
    if (s == NULL) {
        return false;
    }
    length = strlen(s);
    for (int i = 0; i < length/2; i++) {
        if (s[i] != s[length-1-i]) {
            is = false;
            break;
        }
    }
    return is;
}


bool isLinkedListPalindrome(SMLinkedList *list)
{
    assert(list!=NULL&&list->head!=NULL);
    // 空的当然不算，如果只有一个就算把嘻嘻
    if (list->head->next == NULL) {
        return true;
    }
    bool is = true;
    SMLinkedNode *slow = list->head;
    SMLinkedNode *lastSlow = NULL;
    SMLinkedNode *fast = list->head;
    while (fast->next != NULL && fast->next->next != NULL) {
        fast = fast->next->next;
        lastSlow = slow;
        slow = slow->next;
    }
    // 如果fast是到尾部了，则这个链表是单数的，slow正好在中间，而如果fast前面还有一个，则slow在中间偏前一个
    SMLinkedNode *middleLeft;
    SMLinkedNode *middleRight;
    // 能走到这里一定最少两个
    if (fast->next == NULL) {
        middleLeft = lastSlow;
        middleRight = slow->next;
    }
    else {
        middleLeft = slow;
        middleRight = slow->next;
    }
    
    // 然后从头到middleLeft，将next反指
    SMLinkedNode *temp = list->head;
    SMLinkedNode *lastTemp = NULL;
    SMLinkedNode *rightMost = middleLeft->next;
    while (temp != rightMost) {
        SMLinkedNode *tempNext = temp->next;
        temp->next = lastTemp;
        lastTemp = temp;
        temp = tempNext;
    }
    
    // middleLeft向左，middleRight向右，一次比较，有一个不相等就不行
    SMLinkedNode *tempLeft = middleLeft;
    SMLinkedNode *tempRight = middleRight;
    while (tempLeft->next != NULL) {
        if (tempLeft->value != tempRight->value) {
            is = false;
            break;
        }
        tempRight = tempRight->next;
        tempLeft = tempLeft->next;
    }
    
    // 最后恢复左边的next,上面的temp是middleLeft的next
    SMLinkedNode* reserve = middleLeft;
    SMLinkedNode* lastReserve = temp;
    while (reserve->next != NULL) {
        SMLinkedNode *tempReserve = reserve->next;
        reserve->next = lastReserve;
        lastReserve = reserve;
        reserve = tempReserve;
    }
    reserve->next = lastReserve;
    
    return is;
}


void traverse(SMLinkedList *list)
{
    assert(list!= NULL&&list->head!=NULL);
    SMLinkedNode *node = list->head;
    do {
        printf("%d ", node->value);
        node = node->next;
    } while (node !=NULL);
    printf("\n");
}

