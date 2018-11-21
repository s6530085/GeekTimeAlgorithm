//
//  23_binarytree.h
//  GeekTimeAlgorithm
//
//  Created by study_sun on 2018/11/18.
//  Copyright © 2018 study_sun. All rights reserved.
//

#ifndef _3_binarytree_h
#define _3_binarytree_h

typedef struct SMBinaryTreeNode {
    int value;
    struct SMBinaryTreeNode *left;
    struct SMBinaryTreeNode *right;
}SMBinaryTreeNode;

typedef struct SMBinaryTree {
    SMBinaryTreeNode *root;
//    SMBinaryTreeNode *cur;
}SMBinaryTree;

// 操作树比较麻烦一些
SMBinaryTree *create_tree(void);
SMBinaryTreeNode *create_node(int value);
void free_tree(SMBinaryTree *tree);


// 层次遍历，也就是广度优先
void traver_tree(SMBinaryTree *tree);

#endif /* _3_binarytree_h */
