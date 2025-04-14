#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
static int idx = -1;
Node *buildTree(vector<int> preorder)
{
    idx++;
    if (preorder[idx] == -1)
    {
        return NULL;
    }

    Node *root = new Node(preorder[idx]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);
    return root;
}

// Preorder Traversal
void preOrder(Node *root)
{

    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
};

// inorder traversal
void inOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " " << endl;
    inOrder(root->right);
};

// poatorder traversal
void postOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

// level order tarversal

void levelOrder(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(root);
    q.push(NULL); // Marker for end of level

    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();

        if (curr == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL); // Add marker for the next level
            }
        }
        else
        {
            cout << curr->data << " ";
            if (curr->left != NULL)
            {
                q.push(curr->left);
            }
            if (curr->right != NULL)
            {
                q.push(curr->right);
            }
        }
    }
};

// height of Tree
int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lftHt = height(root->left);
    int rgtHt = height(root->right);
    return max(lftHt, rgtHt) + 1;
}

// count the nodes of tree
int count(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int lftHt = count(root->left);
    int rgtHt = count(root->right);
    return lftHt + rgtHt + 1;
}

int sumodNodes(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int lftsum = sumodNodes(root->left);
    int rgtsum = sumodNodes(root->right);
    return lftsum + rgtsum + root->data;
}

int main()
{
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node *root = buildTree(preorder);
    // cout << root->data << endl;
    // cout << root->left->data << endl;
    // cout << root->right->data << endl;

    // preOrder(root);
    // inOrder(root);
    // postOrder(root);
    // levelOrder(root);
    cout << "Height : " << height(root) << endl;
    cout << "count : " << count(root) << endl;
    cout << "sum : " << sumodNodes(root) << endl;

    return 0;
}






// rough work