typedef struct {
	BINARYTREE* left;
	BINARYTREE* right;
	int data;
} Binary_tree;

BINARYTREE binary_tree_init_default(void) {
	pBinary_tree = (Binary_tree*)malloc(sizeof(Binary_tree));
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
	if (num > pBinary_tree) {
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

void binary_tree_output_node(NODE node) {
	printf("%d\n", node->data);
}
