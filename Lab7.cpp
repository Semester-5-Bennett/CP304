#include <iostream>
#include <vector>

using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

TreeNode *insert(TreeNode *root, int val)
{
    if (root == nullptr)
    {
        return new TreeNode(val);
    }

    if (val < root->val)
    {
        root->left = insert(root->left, val);
    }
    else if (val > root->val)
    {
        root->right = insert(root->right, val);
    }

    return root;
}

void preorderTraversal(TreeNode *node, vector<string> &result)
{
    if (node == nullptr)
    {
        return;
    }

    result.push_back(to_string(node->val));
    preorderTraversal(node->left, result);
    preorderTraversal(node->right, result);
}

TreeNode *findMin(TreeNode *root)
{
    while (root && root->left)
    {
        root = root->left;
    }
    return root;
}

TreeNode *findInorderSuccessor(TreeNode *root, TreeNode *target)
{
    TreeNode *successor = nullptr;
    while (root)
    {
        if (target->val < root->val)
        {
            successor = root;
            root = root->left;
        }
        else if (target->val > root->val)
        {
            root = root->right;
        }
        else
        {
            if (root->right)
            {
                successor = findMin(root->right);
            }
            break;
        }
    }
    return successor;
}

void findSibling(TreeNode *root, int target, vector<string> &result)
{
    TreeNode *originalRoot = root;
    TreeNode *targetNode = nullptr;
    while (root)
    {
        if (target < root->val)
        {
            root = root->left;
        }
        else if (target > root->val)
        {
            root = root->right;
        }
        else
        {
            targetNode = root;
            break;
        }
    }

    if (!targetNode)
        return;

    TreeNode *sibling = findInorderSuccessor(originalRoot, targetNode);
    if (sibling)
    {
        preorderTraversal(sibling, result);
    }
}

void findSiblingOfWeight(vector<int> &weights, int weightToPluck)
{
    TreeNode *root = nullptr;
    for (int weight : weights)
    {
        root = insert(root, weight);
    }

    vector<string> result;
    findSibling(root, weightToPluck, result);

    if (result.empty())
    {
        cout << "NULL\n";
    }
    else
    {
        for (const string &val : result)
        {
            cout << val << "->";
        }
        cout << "NULL\n";
    }
}

int main()
{
    int N, W;
    cin >> N >> W;

    vector<int> fruitWeights(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> fruitWeights[i];
    }

    findSiblingOfWeight(fruitWeights, W);
    return 0;
}
