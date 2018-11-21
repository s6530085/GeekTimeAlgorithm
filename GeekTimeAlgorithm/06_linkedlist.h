//
//  06_linklist.h
//  GeekTimeAlgorithm
//
//  Created by study_sun on 2018/11/11.
//  Copyright © 2018 study_sun. All rights reserved.
//

#ifndef _6_linklist_h
#define _6_linklist_h


typedef struct SMLinkedNode {
    int value;
    struct SMLinkedNode *next;
}SMLinkedNode, *pSMLinkedNode;

typedef struct SMLinkedList {
    struct SMLinkedNode *head;
}SMLinkedList, *pSMLinkedList;

SMLinkedList* createSMLinkedList(void);
void freeSMLinkedList(SMLinkedList* list);
SMLinkedNode* valueNode(SMLinkedList *list, int value);// 这也要求数据不能重哦
void removeValue(SMLinkedList *list, int value);
void removeNode(SMLinkedList *list, SMLinkedNode *node);
SMLinkedNode* appendValue(SMLinkedList *list, int value);// 加在最后哦
SMLinkedNode* insertValue(SMLinkedList *list, int value);// 加在最前哦
SMLinkedNode* insertValueAfter(SMLinkedNode *node, int value);// 加在某节点之后
SMLinkedNode* isnertValueBefore(SMLinkedList *list, SMLinkedNode* node, int value);// 加在某节点之前，不好意思得遍历了
void traverse(SMLinkedList *list);


typedef struct  SMDoubleLinkedNode {
    struct SMDoubleLinkedNode *prev;
    int value;
    struct SMDoubleLinkedNode *next;
} *pSMDoubleLinkedNode;

bool isPalindrome(const char *s);

bool isLinkedListPalindrome(SMLinkedList *list);

#endif /* _6_linklist_h */
