//
// Created by cbotte21 on 1/30/22.
//

#include "binarytree.h"

typedef struct {
    BINARYTREE* left;
    BINARYTREE* right;
    int data;
} Binary_tree;

BINARYTREE binary_tree_init_default(void) {
    Binary_tree* pBinary_tree = (Binary_tree*)malloc(sizeof(Binary_tree));
    pBinary_tree->left = NULL;
    pBinary_tree->right = NULL;
    pBinary_tree->data = 0;
    return (pBinary_tree == NULL) ? NULL : (BINARYTREE)pBinary_tree;
}

BINARYTREE binary_tree_init_int(int num) {
    BINARYTREE hBinary_tree = binary_tree_init_default();
    Binary_tree* pBinary_tree = (Binary_tree*)hBinary_tree;
    pBinary_tree->data = num;
    return (pBinary_tree == NULL) ? NULL : hBinary_tree;
}

void binary_tree_insert(BINARYTREE hBinary_tree, int num) {
    Binary_tree* pBinary_tree = (Binary_tree*)hBinary_tree;
    if (num > pBinary_tree->data) {
        if (pBinary_tree->right == NULL)
            pBinary_tree->right = binary_tree_init_int(num);
        else
            binary_tree_insert(pBinary_tree->right, num);
    } else {
        if (pBinary_tree->left == NULL)
            pBinary_tree->left = binary_tree_init_int(num);
        else
            binary_tree_insert(pBinary_tree->left, num);
    }
}

NODE binary_tree_traverse(BINARYTREE hBinary_tree, int num) {
    Binary_tree* pBinary_tree = (Binary_tree*)hBinary_tree;
    if (pBinary_tree == NULL)
        return NULL;
    if (pBinary_tree->data == num)
        return (NODE)pBinary_tree;
    if (num > pBinary_tree->data)
        return binary_tree_traverse((BINARYTREE)pBinary_tree->right, num);
    else
        return binary_tree_traverse((BINARYTREE)pBinary_tree->left, num);
}

void binary_tree_output_node(NODE hNode) {
    Binary_tree* pNode = (Binary_tree*)hNode;
    printf("%d\n", pNode->data);
}

void binary_tree_unlink(BINARYTREE hBinary_tree, NODE hNode) {
    Binary_tree* pBinary_tree = (Binary_tree*)hBinary_tree;
    Binary_tree* pNode = (Binary_tree*)hNode;
    //if (pBinary_tree == pNode) binary_tree_delete()         Is the head of the binary tree. Delete whole tree
    if (pNode->data < pBinary_tree->data) {
        if (pNode == (Binary_tree*)pBinary_tree->left)
            pBinary_tree->left = NULL;
        else
            binary_tree_unlink((BINARYTREE)pBinary_tree->left, hNode);
    } else {
        if (pNode == (Binary_tree*)pBinary_tree->right)
            pBinary_tree->right = NULL;
        else
            binary_tree_unlink((BINARYTREE)pBinary_tree->right, hNode);
    }
}

void binary_tree_append_children(BINARYTREE hBinary_tree, NODE hNode) {
    Binary_tree* pBinary_tree = (Binary_tree*)hBinary_tree;
    Binary_tree* pNode = (Binary_tree*)hNode;
    //fix deconstructing
    if (pNode->left != NULL) {
        binary_tree_insert(pBinary_tree, ((Binary_tree*)(pNode->left))->data);
        binary_tree_append_children(hBinary_tree, pNode->left);
    }
    if (pNode->right != NULL) {
        binary_tree_insert(pBinary_tree, ((Binary_tree*)(pNode->right))->data);
        binary_tree_append_children(hBinary_tree, pNode->right);
    }
}

void binary_tree_free_below_inclusive(NODE* phNode) {
    Binary_tree* pNode = (Binary_tree*)(*phNode);

    if(pNode != NULL) {
        if (pNode->left != NULL) {
            binary_tree_free_below_inclusive(pNode->left);
        }

        if (pNode->right != NULL) {
            binary_tree_free_below_inclusive(pNode->right);
        }

        free(pNode);
    }
}

void binary_tree_delete_node(BINARYTREE hBinary_tree, NODE hNode) {
    binary_tree_unlink(hBinary_tree, hNode);
    binary_tree_append_children(hBinary_tree, hNode);
    binary_tree_free_below_inclusive(&hNode);
}

