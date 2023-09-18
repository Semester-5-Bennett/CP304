#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <sstream>
#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void verticalTraversal(TreeNode *root)
{
    if (!root)
    {
        return;
    }
    map<int, vector<pair<int, int>>> column_map;

    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = q.front().first;
            int col = q.front().second;
            q.pop();

            column_map[col].push_back({node->val, i});

            if (node->left)
            {
                q.push({node->left, col - 1});
            }
            if (node->right)
            {
                q.push({node->right, col + 1});
            }
        }
    }
    for (auto &entry : column_map)
    {
        vector<pair<int, int>> &nodes = entry.second;
        sort(nodes.begin(), nodes.end(), [](const pair<int, int> &a, const pair<int, int> &b)
             { return a.second < b.second || (a.second == b.second && a.first < b.first); });

        for (auto &node : nodes)
        {
            cout << node.first << " ";
        }
        cout << endl;
    }
}

TreeNode *buildTree(vector<string> &nodes, int index)
{
    if (index >= nodes.size() || nodes[index] == "null")
    {
        return nullptr;
    }
    TreeNode *root = new TreeNode(stoi(nodes[index]));
    root->left = buildTree(nodes, 2 * index + 1);
    root->right = buildTree(nodes, 2 * index + 2);
    return root;
}

int main()
{
    string input;
    getline(cin, input);
    istringstream iss(input);
    vector<string> tree_nodes;
    string node;
    while (iss >> node)
    {
        tree_nodes.push_back(node);
    }

    TreeNode *root = buildTree(tree_nodes, 0);
    verticalTraversal(root);

    return 0;
}
