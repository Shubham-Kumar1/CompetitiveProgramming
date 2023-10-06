/************************************************************

   Following is the TreeNode class structure

   class TreeNode {
    public:
        int data;
        vector<TreeNode*> children;

        TreeNode(int data) {
            this->data = data;
        }
   }

************************************************************/
void dfs(TreeNode *node, int pathSum, int &maxSum)
{
    if(node->children.size()==0) 
    {
        maxSum = max(maxSum,pathSum);
        return;
    }
    for(TreeNode *child : node -> children) dfs(child,pathSum+child->data,maxSum);
}
int findMaxSum(int n, TreeNode* root)
{
    // Write your code here.
    if(root==nullptr) return 0;
    int maxSum=0;
    dfs(root,root->data,maxSum);
    return maxSum;
}
