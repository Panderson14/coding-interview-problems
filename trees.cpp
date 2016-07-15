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

/*************************
 * Given a binary tree, design an algorithm that creates a linked list of all the nodes at each depth (CtCI, 07-07-2016)
*************************/

ArrayListList<TreeNode> convToList(TreeNode root) {
  ArrayList<List> list = new ArrayList<ListNode>;
  convToListHelper(root, 0, list);
  return list;
}

void convToListHelper(TreeNode root, int depth, ArrayList<List> list) {
	if(root == NULL) return NULL;
  
  else {
    ListNode<TreeNode> cur = new ListNode;
    cur.value = root;
   	
    if( !list[depth] ) {
      list[depth] = new List<TreeNode>;
    }
   	
    list[depth].add(cur);
    if(root.left) convToListHelper(root.left, depth++, list);
    if(root.right) convToListHelper(root.right, depth++, list);
  }
}

/*************************
 * Print out a tree in prefix order WITHOUT using recursion (PIE, 07-12-2016)
*************************/


void prefixPrint(TreeNode* root) {
  Stack<int> s = new Stack<int>;
  
  do {
    cout << root->value;
    if(root->right) s.push(root->right);
    if(root->left) root = root->left;
  	if(!root->left) {
    	if (s.top()) {
      	root = s.top();
      	s.pop();
      }
    }
  } while(!s.top() && !root->left && !root->right)
  
  delete s;
}

/*************************
 * Write an algorithm to find the node that is the in-order successor in a BST (CtCI, 07-13-2016)
*************************/


TreeNode nextInOrder(TreeNode n) {
	if(n) return NULL;
	if (n->right)
  		return n->right;
  	else {
  		TreeNode child = n;
  		TreeNode parent = n->parent;
    		while(parent != NULL) {
			// ID the right node we want to return
			if (child = parent -> left) break;
			else {
      				child = parent;
        			parent = child -> parent;
      			}
    		}
    		return parent;
  	}
}


/*************************
 * Given a set of integers in an unordered Binary Tree, transform the tree into a heap. (PIE, 07-14-2016)
*************************/

int[] turnToHeap(TreeNode* root) {
  int[] treeHeap = new int[];
 	return turnToHeap(root, 0, treeHeap);
}

int[] turnToHeap(TreeNode* root, int index, &const int[] treeHeap) {
  treeHeap[index] = root->value;
  if(root->left) turnToHeap(root->left, index*2+1, treeHeap);
  if(root->right) turnToHeap(root->right, index*2+2, treeHeap);
  return treeHeap;
}
