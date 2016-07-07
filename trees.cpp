// Problems from this file have been pulled from the CtCI, PIE and EPI

/*************************
 * “Given a sorted increasing array with unique increasing elements, create a BST with minimal height” (CtCI, 07-05-2016)
*************************/

TreeNode* createTree(int[] arr) {
	return createTree(arr, 0, arr.length-1);
}

TreeNode* createTree(int[] arr, int lowInd, int highInd) {
	int midInd = (lowInd+highInd)/2;
	TreeNode* mid = new TreeNode*;
	mid -> value = arr[midInd];

	if(lowInd == highInd) return mid;

	else {
		mid -> left = createTree(arr, lowInd, midInd-1);
		mid -> right = createTree(arr, midInd+1, highInd);
	}
	
	return mid;
}

/*************************
 * “Given the value of 2 integers in a BST, find nearest common ancestor. Can assume both exist. Return the ancestor.” (PIE, 07-06-2016)
*************************/

TreeNode* ancestor(int x, int y, TreeNode* root) {
	if (x == root->value) return root;
	if (y == root->value) return root;
	if (x < root->value && y < root->value) return ancestor(x, y, root->left);
	if (x > root->value && y > root->value) return ancestor(x, y, root->right);
	return root;
}
