/*
这个题乍一看用二叉搜索树做不难。但自己折在了“Count += root -> count + 1;“
我写成了"cout = root-》count+1；insert_node = count" 这其实是难点所在。
每个节点的count都记录了左子树所有的节点的个数。这也是二叉搜索树的精华所在。可以
直接跳到下一个大于当前节点的位置。那这样看来count的值一定是+=计算下来的.
二叉搜索树示意：
 （8 9 10 （5 6 7））可以看到，每个节点左子树都记到了碰到比自己大的地方就停止了。
 所以不会出现我想的重复加的情况。count(7) = 2; count(10) = 2;所以如果下一个是11
 的话，计算过程是2+1+2+1 = 5;
*/

class Solution {
 public:
    typedef struct node{
        int count = 0; //这个点记录的是当前节点左子树的节点的全部个数
        int number;
        node *left = NULL;
        node *right = NULL;
    }node;
    void Insert(node* root,node* insert_node,int& Count){
        if(insert_node->number > root -> number){
            Count += root -> count + 1;
            if(root->right != NULL){
                Insert(root->right,insert_node,Count);
            }
            else{
                root->right = insert_node;
                return;
            }
        }
        else{
            root->count++;
            if(root->left != NULL){
                Insert(root->left,insert_node,Count);
            }
            else{
                root->left = insert_node;
                return;
            }
        }
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ans;
        if(nums.size() == 0) return ans;
        node* root = new node;
        root->number = nums.back();
        ans.push_back(0);
        for(int i = nums.size()-2;i >= 0 ; i--){
            int count = 0;
            node* insert_node = new node;
            insert_node->number = nums[i];
            Insert(root,insert_node,count);
            ans.push_back(count);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
 };

