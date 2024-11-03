#include <iostream>
#include <queue>
using namespace std;

class TreeNode
{
public:
    int m_value;
    TreeNode* m_left;
    TreeNode* m_right;

public:
    TreeNode(int val)
    {
        m_value = val;
        m_left = nullptr;
        m_right = nullptr;
    }

    //(root -> left -> right)
    void printPreOrderTreeTraversal(TreeNode* root)
    {
        if (root == nullptr)
        {
            return;
        }

        cout << root->m_value << " ";

        printPreOrderTreeTraversal(root->m_left);

        printPreOrderTreeTraversal(root->m_right);
    }

    //(left -> root -> right)
    void printInOrderTreeTraversal(TreeNode* root)
    {
        if (root == nullptr)
        {
            return;
        }

        printInOrderTreeTraversal(root->m_left);

        cout << root->m_value << " ";

        printInOrderTreeTraversal(root->m_right);
    }

    //(left -> right -> root)
    void printPostOrderTreeTraversal(TreeNode* root)
    {
        if (root == nullptr)
        {
            return;
        }

        printPostOrderTreeTraversal(root->m_left);

        printPostOrderTreeTraversal(root->m_right);

        cout << root->m_value << " ";
    }

    // Level wise (L1, L2, L3 ...)
    void printLevelOrderTraversalOrBFS(TreeNode* root)
    {
        if (root == nullptr)
        {
            return;
        }

        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();

            cout << node->m_value << " ";

            if (node->m_left != nullptr)
            {
                q.push(node->m_left);
            }

            if (node->m_right != nullptr)
            {
                q.push(node->m_right);
            }
        }
    }
};

int main()
{
    TreeNode* root = new TreeNode(1);

    root->m_left = new TreeNode(2);

    root->m_right = new TreeNode(3);

    root->m_left->m_left = new TreeNode(4);
      
    root->m_left->m_right = new TreeNode(5);

    root->m_right->m_left = new TreeNode(6);

    root->m_right->m_right = new TreeNode(7);

    root->printPreOrderTreeTraversal(root);

    cout << endl;

    root->printInOrderTreeTraversal(root);

    cout << endl;

    root->printPostOrderTreeTraversal(root);

    cout << endl;

    root->printLevelOrderTraversalOrBFS(root);


    //Input 
    /*
        1
      2   3
    4  5  6 7
    
    */

    // PreOrderTraversalOutput
    // 1 2 4 5 3 6 7

    // InOrderTraversalOutput
    // 4 2 5 1 6 3 7

    // PostOrderTraversalOutput
    // 4 5 2 6 7 3 1

    // LevelOrderTraversalOutput
    // 1 2 3 4 5 6 7

    return 0;
}
