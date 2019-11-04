#include<bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

/*
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/

    void topView(Node * root) {
        queue<pair<int,Node*>> q;
        q.push({0,root});
        map<int,Node*> topView;
        while(!q.empty())
        {
            topView.insert(q.front());
            if(q.front().second->left)q.push({q.front().first-1,q.front().second->left});
            if(q.front().second->right)q.push({q.front().first+1,q.front().second->right});
            q.pop();
        }
        for(auto pnode:topView)cout << pnode.second->data << " ";
    }

}; //End of Solution
