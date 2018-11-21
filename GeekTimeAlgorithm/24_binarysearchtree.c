//
//  24_binarysearchtree.c
//  GeekTimeAlgorithm
//
//  Created by study_sun on 2018/11/18.
//  Copyright © 2018 study_sun. All rights reserved.
//

#include "24_binarysearchtree.h"

SMBinaryTreeNode *binary_search_tree_find(SMBinaryTree *tree, int value)
{
    assert(tree!=NULL&&tree->root!=NULL);
    
    SMBinaryTreeNode *node = tree->root;
    while (node!=NULL) {
        if (node->value == value) {
            return node;
        }
        else if (node->value < value) {
            node = node->right;
        }
        else {
            node = node->left;
        }
    }
    return NULL;
}

SMBinaryTreeNode *binary_search_tree_insert(SMBinaryTree *tree, int value)
{
    assert(tree!=NULL&&tree->root!=NULL);

    SMBinaryTreeNode *node = tree->root;
    // 就不考虑相同了哦
    while (1) {
        if (value > node->value) {
            if (node->right == NULL) {
                SMBinaryTreeNode *right = create_node(value);
                node->right = right;
                return right;
            }
            else {
                node = node->right;
            }
        }
        else {
            if (node->left == NULL) {
                SMBinaryTreeNode *left = create_node(value);
                node->left = left;
                return left;
            }
            else {
                node = node->left;
            }
        }
    }
    // 其实不可能走到这里的啦
}

SMBinaryTreeNode *binary_search_tree_remove(SMBinaryTree *tree, int value)
{
    assert(tree!=NULL&&tree->root!=NULL);
    
    SMBinaryTreeNode *parent = NULL;
    SMBinaryTreeNode *node = tree->root;
    while (node!=NULL) {
        if (node->value == value) {
            // 如果压根没有子节点
            if (node->left==NULL&&node->right==NULL) {
                //有可能是根节点哦嘻嘻
                if (node == tree->root) {
                    tree->root = NULL;
                }
                else {
                    if (parent->left == node) {
                        parent->left = NULL;
                    }
                    else {
                        parent->right = NULL;
                    }
                }
                return node;
            }
            // 如果只有一个子节点，就把其提上来
            else if (node->left==NULL||node->right==NULL) {
                SMBinaryTreeNode *onlyNode = (node->left == NULL ? node->right : node ->left);
                //当然还是要看是不是root
                if (node == tree->root) {
                    tree->root = onlyNode;
                }
                else {
                    if (parent->left == node) {
                        parent->left = onlyNode;
                    }
                    else {
                        parent->right = onlyNode;
                    }
                }
                return onlyNode;
            }
            else {
                // 比较麻烦了，先找到右子树最小的，移动上来之后又要当作删除那个最小的处理
                SMBinaryTreeNode *rightMin = node->right;
                SMBinaryTreeNode *rightMinParent = node;
                while (1) {
                    if (rightMin->left == NULL) {
                        break;
                    }
                    else {
                        rightMinParent = rightMin;
                        rightMin = rightMin->left;
                    }
                }
                
                // 被提上的的元素要么没有子节点，要么只有右节点
                if (rightMin->right == NULL) {
                    if (parent->left == node) {
                        parent->left = rightMin;
                    }
                    else {
                        parent->right = rightMin;
                    }
                    // 有可能这个rightMin就是被删除的右节点哦,但多操作一下也无所谓就是了
                    if (rightMinParent == node) {
                        
                    }
                    else {
                        rightMinParent->left = NULL;
                    }
                }
                // 有右节点，此时只能提rightmin，但是rightmin的右节点要提到原rightmin的位置
                else {
                    if (parent->left == node) {
                        parent->left = rightMin;
                    }
                    else {
                        parent->right = rightMin;
                    }
                    rightMinParent->left = rightMin->right;
                    rightMin->left = node->left;
                    rightMin->right = node->right;
                }
                
                return node;
            }
        }
        else if (node->value < value) {
            parent = node;
            node = node->right;
        }
        else {
            parent = node;
            node = node->left;
        }
    }
    return NULL;
}


int binary_search_tree_max(SMBinaryTree *tree)
{
    assert(tree!=NULL&&tree->root!=NULL);
    
    SMBinaryTreeNode *node = tree->root;
    while (node!=NULL) {
        if (node->right==NULL) {
            return node->value;
        }
        else {
            node = node->right;
        }
    }
    return -1;
}

int binary_search_tree_min(SMBinaryTree *tree)
{
    assert(tree!=NULL&&tree->root!=NULL);
    
    SMBinaryTreeNode *node = tree->root;
    while (node!=NULL) {
        if (node->left==NULL) {
            return node->value;
        }
        else {
            node = node->left;
        }
    }
    return -1;
}


static int binary_tree_node_height(SMBinaryTreeNode *node)
{
    if (node == NULL) {
        return 0;
    }
    else {
        return fmax(binary_tree_node_height(node->left), binary_tree_node_height(node->right)) + 1;
    }
}

int binary_tree_height(SMBinaryTree *tree)
{
    assert(tree!=NULL&&tree->root!=NULL);
    
    return binary_tree_node_height(tree->root);
}

static void invert_binart_tree_node(SMBinaryTreeNode *node)
{
    if (node == NULL) {
        SMBinaryTreeNode* temp = node->left;
        node->left = node->right;
        node->right = temp;
        invert_binart_tree_node(node->left);
        invert_binart_tree_node(node->right);
    }
}

void invert_binary_tree(SMBinaryTree *tree)
{
    assert(tree!=NULL&&tree->root!=NULL);
    invert_binart_tree_node(tree->root);
}
