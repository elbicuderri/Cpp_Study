#include <iostream>

typedef struct treenode
{
    int val;
    treenode* left;
    treenode* right;

} treenode;

class binaryTree
{
public:
    treenode* root;

public:
    binaryTree()
    : root{nullptr}
    {
    }

    binaryTree(int value)
    {
        treenode* new_root = new treenode;
        new_root->val = value;
        root = new_root;
    }

    ~binaryTree()
    {
    }

    void add_left(); // add left if there is a room

    void add_right();

    void print_root() const
    {
        if (root == nullptr)
        {
            std::cout << "There is no root!!!\n"; 
            return;
        }

        std::cout << root->val << std::endl;
        
    }

    void print_all(treenode* root) const
    {
        if (root == nullptr)
        {
            std::cout << "Tree is empty!!!\n";
            return;
        }

        std::cout << "root's value: " << root->val << std::endl;

        std::cout << "left -->\n";

        print_all(root->left); 

        std::cout << "right -->\n";

        print_all(root->right);
        
    }

};

int main()
{

    binaryTree t1;
    binaryTree t2(3);

    treenode* n3 = new treenode;
    treenode* n4 = new treenode;
    treenode* n5 = new treenode;
    treenode* n6 = new treenode;

    n3->val = 33;
    n4->val = 44;
    n5->val = 55;
    n6->val = 66;

    t2.root->left = n3;
    t2.root->right = n4;
    n3->left = n5;
    n3->right = n6;

    t2.print_all(t2.root);

    // t2.print_root();

    return 0;
}