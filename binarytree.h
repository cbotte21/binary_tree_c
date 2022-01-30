//
// Created by cbotte21 on 1/30/22.
//


/*
 * BINARYTREE and NODE are the same.
 * Just different names for UI.
 */

#ifndef NEW_BINARYTREE_H
#define NEW_BINARYTREE_H

#include <stdio.h>
#include <stdlib.h>

typedef void* BINARYTREE;
typedef void* NODE;

BINARYTREE binary_tree_init_default(void);
BINARYTREE binary_tree_init_int(int num);

void binary_tree_insert(BINARYTREE hBinary_tree, int num);
NODE binary_tree_traverse(BINARYTREE hBinary_tree, int num);

void binary_tree_unlink(BINARYTREE hBinary_tree, NODE hNode);
void binary_tree_append_children(BINARYTREE hBinary_tree, NODE hNode);
void binary_tree_delete_node(BINARYTREE hBinary_tree, NODE hNode);

void binary_tree_free_below_inclusive(NODE* phNode);

//void binary_tree_output(BINARYTREE hBinary_tree);
void binary_tree_output_node(NODE node);

#endif //NEW_BINARYTREE_H
