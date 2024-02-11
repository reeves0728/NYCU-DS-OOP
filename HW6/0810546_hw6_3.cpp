#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<int> output;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    int height;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree
{
public:
    TreeNode *root;

    AVLTree() : root(nullptr) {}

    int getHeight(TreeNode *node)
    {
        if (node == nullptr)
            return 0;
        return node->height;
    }

    int getBalance(TreeNode *node)
    {
        if (node == nullptr)
            return 0;
        return getHeight(node->left) - getHeight(node->right);
    }

    TreeNode *rotateRight(TreeNode *z)
    {
        TreeNode *y = z->left;
        TreeNode *T3 = y->right;

        y->right = z;
        z->left = T3;

        z->height = 1 + max(getHeight(z->left), getHeight(z->right));
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));

        return y;
    }

    TreeNode *rotateLeft(TreeNode *z)
    {
        TreeNode *y = z->right;
        TreeNode *T2 = y->left;

        y->left = z;
        z->right = T2;

        z->height = 1 + max(getHeight(z->left), getHeight(z->right));
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));

        return y;
    }

    TreeNode *insert(TreeNode *root, int val)
    {
        if (root == nullptr)
            return new TreeNode(val);
        else if (val < root->val)
            root->left = insert(root->left, val);
        else
            root->right = insert(root->right, val);

        root->height = 1 + max(getHeight(root->left), getHeight(root->right));

        int balance = getBalance(root);

        if (balance > 1 && val < root->left->val)
            return rotateRight(root);

        if (balance < -1 && val > root->right->val)
            return rotateLeft(root);

        if (balance > 1 && val > root->left->val)
        {
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }

        if (balance < -1 && val < root->right->val)
        {
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }

        return root;
    }

    void levelOrderTraversal()
    {
        if (root == nullptr)
            return;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            output.push_back(node->val);
            // cout << node->val << " ";

            if (node->left)
                q.push(node->left);

            if (node->right)
                q.push(node->right);
        }
    }
};

int main()
{
    AVLTree avlTree;
    int x;
    vector<int> arr;

    while (cin >> x)
    {
        arr.push_back(x);
    }

    if (cin.eof())
    {
        for (int i = 0; i < arr.size(); i++)
        {
            avlTree.root = avlTree.insert(avlTree.root, arr[i]);
        }
        avlTree.levelOrderTraversal();
        for (int i = 0; i < output.size(); i++)
        {
            if (i == output.size() - 1)
            {
                cout << output[i] << endl;
            }
            else
            {
                cout << output[i] << " ";
            }
        }
        arr.clear();
    }

    return 0;
}