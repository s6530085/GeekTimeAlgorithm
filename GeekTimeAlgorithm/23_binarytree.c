//
//  23_binarytree.c
//  GeekTimeAlgorithm
//
//  Created by study_sun on 2018/11/18.
//  Copyright © 2018 study_sun. All rights reserved.
//

#include "23_binarytree.h"


SMBinaryTree *create_tree(void)
{
    SMBinaryTree *tree = (SMBinaryTree *)malloc(sizeof(SMBinaryTree));
    assert(tree!=NULL);
    return tree;
}


SMBinaryTreeNode *create_node(int value)
{
    
    SMBinaryTreeNode *node = (SMBinaryTreeNode *)malloc(sizeof(SMBinaryTreeNode));
    assert(node!=NULL);
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void free_tree(SMBinaryTree *tree)
{
    
}

void traver_tree(SMBinaryTree *tree)
{
    assert(tree!=NULL&&tree->root!=NULL);
    // 没有容器实在是头疼
    printf("traver tree ");
    int currentLevelNodeCount = 1;
    SMBinaryTreeNode *currentNodes = (SMBinaryTreeNode *)malloc(sizeof(SMBinaryTreeNode));
    currentNodes[0] = *tree->root;
    printf("%d", tree->root->value);
    while (1) {
        int temCount = 0;
        for (int i = 0; i < currentLevelNodeCount; i++) {
            SMBinaryTreeNode node = currentNodes[i];
            if (node.left != NULL) {
                printf(" %d, ", node.left->value);
                temCount++;
            }
            if (node.right != NULL) {
                printf(" %d, ", node.right->value);
                temCount++;
            }
        }
        // 说明是最后一层了
        if (temCount == 0) {
            free(currentNodes);
            break;
        }
        else {
            // 没容器，只能再循环一次加咯
            SMBinaryTreeNode *temNodes = (SMBinaryTreeNode *)malloc(sizeof(SMBinaryTreeNode) * temCount);
            assert(temNodes !=NULL);
            int index = 0;
            for (int i = 0; i < currentLevelNodeCount; i++) {
                SMBinaryTreeNode node = currentNodes[i];
                if (node.left != NULL) {
                    temNodes[index++] = *node.left;
                }
                if (node.right != NULL) {
                    temNodes[index++] = *node.right;
                }
            }
            currentLevelNodeCount = temCount;
            SMBinaryTreeNode *toD = currentNodes;
            currentNodes = temNodes;
            free(toD);
        }
    }
    printf("\n");
}
