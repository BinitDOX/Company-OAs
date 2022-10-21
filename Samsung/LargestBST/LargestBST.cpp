// https://practice.geeksforgeeks.org/problems/largest-bst/1

struct BSTNode {
    int size = 0;
    int min = INT_MAX;
    int max = INT_MIN;
};

BSTNode largestBST(Node *root, int &maxsize){
    if(!root)
        return BSTNode();
        
    BSTNode l = largestBST(root->left, maxsize);
    BSTNode r = largestBST(root->right, maxsize);
    BSTNode c;
    
    if(l.size==-1 || r.size==-1)
        c.size = -1;
    else
        c.size = (root->data > l.max && root->data < r.min) ? l.size + r.size + 1 : -1;
        
    maxsize = max(maxsize, c.size);
    c.min = min(l.min, root->data);
    c.max = max(r.max, root->data);
    
    return c;
}

int largestBst(Node *root){
	int maxsize = 0;
	largestBST(root, maxsize);
	return maxsize;
}