//
//  07_linkedlist.c
//  GeekTimeAlgorithm
//
//  Created by study_sun on 2018/11/11.
//  Copyright © 2018 study_sun. All rights reserved.
//

#include "07_linkedlist.h"

void reverse(SMLinkedList *list)
{
    assert(list!=NULL);
    SMLinkedNode *node = list->head;
    // 0，1个元素都没必要做操作
    if (node==NULL||node->next==NULL) {
        return;
    }
    SMLinkedNode *lastNode = NULL;
    while (node->next!=NULL) {
        SMLinkedNode *nextNode = node->next;
        node->next = lastNode;
        lastNode = node;
        node = nextNode;
    }
    node->next = lastNode;
    list->head = node;
}

bool hasCircle(SMLinkedList *list)
{
    assert(list!=NULL);
    bool has = false;
    SMLinkedNode *head = list->head;
    if (head == NULL) {
        return has;
    }
    SMLinkedNode *slow = head;
    SMLinkedNode *fast = head;
    while (fast->next!=NULL&&fast->next->next!=NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            has = true;
            break;
        }
    }
    return has;
}

SMLinkedList* merge(SMLinkedList *list1, SMLinkedList* list2)
{
    assert(list1!=NULL&&list2!=NULL);
    SMLinkedList *l = createSMLinkedList();
    assert(l!=NULL);
    SMLinkedNode *node = NULL;
    SMLinkedNode *node1 = list1->head;
    SMLinkedNode *node2 = list2->head;
    while (node1!=NULL||node2!=NULL) {
        // 其实只要有一个为null，就可以直接接另一个了
        if (node1 == NULL) {
            if (node == NULL) {
                l->head = node2;
            }
            else {
                node->next = node2;
            }
        }
        else if (node2 == NULL) {
            if (node == NULL) {
                l->head = node1;
            }
            else {
                node->next = node1;
            }
        }
        else {
            SMLinkedNode *tempNode = NULL;
            if (node1->value < node2->value) {
                tempNode = node1;
                node1 = node1->next;
            }
            else {
                tempNode = node2;
                node2 = node2->next;
            }
            if (node == NULL) {
                l->head = tempNode;
            }
            else {
                node->next = tempNode;
            }
            node = tempNode;
        }
    }
    return l;
}


void removeLastN(SMLinkedList *list, size_t n)
{
    assert(list!=NULL&&list->head!=NULL);
    size_t length = 0;
    SMLinkedNode *slow = list->head;
    SMLinkedNode *fast = list->head;
    while (fast->next!=NULL&&fast->next->next!=NULL) {
        slow = slow->next;
        fast = fast->next->next;
        length++;
    }
    // 特别处理下只有1个2个元素的场景,此时一步未走
    if (slow == fast) {
        if (slow->next == NULL) {
            length = 1;
        }
        else {
            length = 2;
        }
    }
    else {
        if (fast->next == NULL) {
            length = length * 2 + 1;
        }
        else {
            length = length * 2 + 2;
        }
    }
    assert(n <= length);
    
    // 处理下是第一个的情况
    if (n == length) {
        SMLinkedNode *t = list->head;
        list->head = list->head->next;
        free(t);
    }
    else {
        SMLinkedNode *node = list->head;
        for (int i = 0; i < length - n - 1; i++) {
            node = node->next;
        }
        SMLinkedNode *remove = node->next;
        // 此时node一定有next，但是再next就不一定了
        if (remove->next == NULL) {
            node->next = NULL;
        }
        else {
            node->next = node->next->next;
        }
        free(remove);
    }
}
