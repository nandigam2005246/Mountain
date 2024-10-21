#include <iostream>
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

    //(left -> right -> node)
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

    return 0;
}
