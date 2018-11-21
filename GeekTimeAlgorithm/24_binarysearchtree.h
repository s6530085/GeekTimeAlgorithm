//
//  24_binarysearchtree.h
//  GeekTimeAlgorithm
//
//  Created by study_sun on 2018/11/18.
//  Copyright © 2018 study_sun. All rights reserved.
//

#ifndef _4_binarysearchtree_h
#define _4_binarysearchtree_h

#include "23_binarytree.h"

// 默认都是无重复数据的哦
SMBinaryTreeNode *binary_search_tree_find(SMBinaryTree *tree, int value);

SMBinaryTreeNode *binary_search_tree_insert(SMBinaryTree *tree, int value);

SMBinaryTreeNode *binary_search_tree_remove(SMBinaryTree *tree, int value);

int binary_search_tree_max(SMBinaryTree *tree);

int binary_search_tree_min(SMBinaryTree *tree);

int binary_tree_height(SMBinaryTree *tree);

// 交换所有节点的左右子树
void invert_binary_tree(SMBinaryTree *tree);
#endif /* _4_binarysearchtree_h */
