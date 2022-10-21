// https://www.lintcode.com/problem/854/

/*
Given a binary tree where every node has a unique value, and a target key k.

Find the value of the nearest leaf node to target k in the tree. If there are multiple cases, you should follow these priorities:

The leaf node is in the left subtree of the node with k;
The leaf node is in the right subtree of the node with k;
The leaf node is not in the subtree of the node with k.
*/

pair<int, int> findClosest(TreeNode *root, int target, int &mindist, int &ans){
    if(!root)
        return {1e8, -1};
    
    if(!root->left && !root->right){
        if(root->val == target){
            mindist = 0;
            ans = root->val;
        }
        return {1, root->val};
    }
    
    pair<int, int> left = findClosest(root->left, target, mindist, ans);
    pair<int, int> right = findClosest(root->right, target, mindist, ans);

    if(left.first < 0 || right.first < 0){
        if(left.first < 0){
            if(mindist > -left.first + right.first){
                mindist = -left.first + right.first;
                ans = right.second;
            }
            return {left.first-1, left.second};
        } else {
            if(mindist > left.first - right.first){
                mindist = left.first - right.first;
                ans = left.second;
            }
            return {right.first-1, right.second};
        }
    }

    if(left.first <= right.first){
        if(root->val == target){
            if(mindist > left.first){
                mindist = left.first;
                ans = left.second;
            }
            return {-1, left.second};
        } else {
            return {left.first+1, left.second}; 
        }
    } else {
        if(root->val == target){
            if(mindist > right.first){
                mindist = right.first;
                ans = right.second;
            }
            return {-1, right.second};
        } else {
            return {right.first+1, right.second}; 
        }
    }
}

int findClosestLeaf(TreeNode *root, int target) {
    int mindist = 1e8;
    int ans = -1;
    findClosest(root, target, mindist, ans);
    return ans;
}