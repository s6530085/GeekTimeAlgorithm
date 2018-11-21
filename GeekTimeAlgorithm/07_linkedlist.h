//
//  07_linkedlist.h
//  GeekTimeAlgorithm
//
//  Created by study_sun on 2018/11/11.
//  Copyright © 2018 study_sun. All rights reserved.
//

#ifndef _7_linkedlist_h
#define _7_linkedlist_h

#include "06_linkedlist.h"

void reverse(SMLinkedList *list);
bool hasCircle(SMLinkedList *list);
SMLinkedList* merge(SMLinkedList *list1, SMLinkedList* list2);
void removeLastN(SMLinkedList *list, size_t n);

#endif /* _7_linkedlist_h */
