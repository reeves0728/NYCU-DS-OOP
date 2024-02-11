#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *add(Node *root, int data)
{
    if (root == NULL)
    {
        Node *newNode = new Node();
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    else if (data <= root->data)
    {
        root->left = add(root->left, data);
    }
    else
    {
        root->right = add(root->right, data);
    }
    return root;
}

void search(Node *root, int data, vector<string> &output)
{
    Node *current = root;
    bool found = false;
    while (current != NULL)
    {
        if (current->data == data)
        {
            found = true;
            // cout << current->data;
            output.push_back(to_string(current->data));
            break;
        }
        else
        {
            // cout << current->data << " ";
            output.push_back(to_string(current->data));
            output.push_back(" ");
            if (data < current->data)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }
    }
    if (found)
    {
        // cout << endl;
        output.push_back("\n");
    }
    else
    {
        // cout << "not found" << endl;
        output.push_back("not found");
        output.push_back("\n");
    }
}

Node *findMin(Node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

Node *findMax(Node *root)
{
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

Node *deleteNode(Node *root, int data, vector<string> &output)
{
    if (root == NULL)
    {
        // cout << "not found" << endl;
        output.push_back("not found");
        output.push_back("\n");
        return root;
    }
    else if (data < root->data)
    {
        root->left = deleteNode(root->left, data, output);
    }
    else if (data > root->data)
    {
        root->right = deleteNode(root->right, data, output);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }
        else if (root->left == NULL)
        {
            Node *temp = root;
            root = root->right;
            delete temp;
        }
        // else if (root->right == NULL)
        // {
        //     Node *temp = root;
        //     root = root->left;
        //     delete temp;
        // }
        else if (root->right != NULL)
        {
            // cout << "find right min!" << endl;
            Node *temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data, output);
        }
        else if (root->right == NULL && root->left != NULL)
        {
            // cout << "find left max!" << endl;
            Node *temp = findMax(root->left);
            root->data = temp->data;
            root->left = deleteNode(root->left, temp->data, output);
        }
    }
    return root;
}

int main()
{
    Node *root = NULL;
    string op;
    vector<string> output;
    int data;
    while (cin >> op >> data)
    {
        if (op == "add")
        {
            root = add(root, data);
        }
        else if (op == "search")
        {
            search(root, data, output);
        }
        else if (op == "delete")
        {
            root = deleteNode(root, data, output);
        }

        // cout << "output size: " << output.size() << endl;
    }

    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i];
    }
    return 0;
}