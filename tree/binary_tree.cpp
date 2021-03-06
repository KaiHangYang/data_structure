#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

class mBinaryTree {
public:
    struct TreeNode {
        TreeNode* left;
        TreeNode* right;
        int val; // val is unique
        TreeNode(int val): val(val), left(nullptr), right(nullptr) {}
    };
    mBinaryTree() {
        this->head = nullptr;
    }

    TreeNode* insert(int val) {
        TreeNode* cur_node = this->head;
        TreeNode* par_node = nullptr;

        while (cur_node != nullptr) {
            par_node = cur_node;
            if (val > cur_node->val) {
                cur_node = cur_node->right;
            }
            else if (val < cur_node->val) {
                cur_node = cur_node->left;
            }
            else {
                // when equal, I do nothing currently.
                return;
            }
        }
        if (val > par_node->val) {
            par_node->right = new TreeNode(val);
            return par_node->right;
        }
        else {
            par_node->left = new TreeNode(val);
            return par_node->left;
        }
    }

    void remove(int val) {
        TreeNode* cur_node = this->head;
        TreeNode* par_node = nullptr;
        TreeNode* tar_node = nullptr;

        while (cur_node != nullptr) {
            if (val > cur_node->val) {
                par_node = cur_node;
                cur_node = cur_node->right;
            }
            else if (val < cur_node->val) {
                par_node = cur_node;
                cur_node = cur_node->left;
            }
            else {
                tar_node = cur_node;
                break;
            }
        }

        if (tar_node != nullptr) {
            if (par_node == nullptr) {
                this->head = nullptr;
                delete cur_node;
            }
            else {
                if (cur_node->right != nullptr && cur_node->left != nullptr) {

                }
                else {
                    TreeNode* reserve_node;
                    if (cur_node->right == nullptr && cur_node->left == nullptr) {
                        // delete it directly
                        reserve_node = nullptr;
                    }
                    else if (cur_node->right == nullptr) {
                        reserve_node = cur_node->left;
                    }
                    else (cur_node->left == nullptr) {
                        reserve_node = cur_node->right;
                    }

                    if (par_node->left == cur_node) {
                        par_node->left = reserve_node;
                    }
                    else {
                        par_node->right = reserve_node;
                    }
                    delete cur_node;
                    
                }
            }
        }
    }

    ~mBinaryTree() {
        if (this->head == nullptr) {
            return;
        }
        stack<TreeNode*> waiting_nodes;
        queue<TreeNode*> vis_queue;
        vis_queue.push(this->head);

        while (!vis_queue.empty()) {
            TreeNode* cur_node = vis_queue.front();
            vis_queue.pop();

            waiting_nodes.push(cur_node);
            if (cur_node->left != nullptr) vis_queue.push(cur_node->left);
            if (cur_node->right != nullptr) vis_queue.push(cur_node->right);
        }

        while (waiting_nodes.empty()) {
            delete waiting_nodes.top();
            waiting_nodes.pop();
        }
    }

private:
    TreeNode* head;
}
