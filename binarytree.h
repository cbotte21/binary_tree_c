#include <stdio.h>
#include <stdlib.h>

/*
 * BINARYTREE and NODE are the same.
 * Just different names for UI.
 */

typedef void* BINARYTREE;
typedef void* NODE;

BINARYTREE binary_tree_init_default(void);
BINARYTREE binary_tree_init_int(int num);

void binary_tree_insert(BINARYTREE hBinary_tree, int num);
NODE binary_tree_traverse(BINARYTREE hBinary_tree, int num);
//void binary_tree_delete_node(BINARYTREE hBinary_tree, NODE hNode);

//void binary_tree_output(BINARYTREE hBinary_tree);
void binary_tree_output_node(NODE node);

//void binary_tree_delete(BINARYTREE* phBinary_tree); //free when both children == NULL

/*
 * DELETE_NODE function
 *
 * - Call unlink function (BINARYTREE, NODE) -> loop like inserting value, stop when (left or right)'s adress == NODE, set NULL.
 * - Call append_children function (BINARYTREE, NODE) -> insert() all non NULL children of NODE
 * - FREE all children of NODE.
 */

/*
 * DELETE function
 * - Call DELETE_NODE(BINARYTREE, BINARYTREE)
 */
