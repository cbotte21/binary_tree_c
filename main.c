#include "binarytree.h"

int main(int argc, const char* argv[]) {
    BINARYTREE startingNode = binary_tree_init_int(10);

    binary_tree_insert(startingNode, 5);
    binary_tree_insert(startingNode, 15);
    binary_tree_insert(startingNode, 7);
    binary_tree_insert(startingNode, 22);
    binary_tree_insert(startingNode, 11);

    NODE searchedNode = binary_tree_traverse(startingNode, 15);

    binary_tree_delete_node(startingNode, searchedNode);

    searchedNode = binary_tree_traverse(startingNode, 11);

    binary_tree_output_node(searchedNode);

    searchedNode = binary_tree_traverse(startingNode, 22);

    binary_tree_output_node(searchedNode);

    binary_tree_free_below_inclusive(&startingNode);
    return 0;
}