#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

int maxDepth(TreeNode* root, int& max, int& currMax) {
    if (root != nullptr) {
        currMax++;
        maxDepth(root->left, max, currMax);

        if (currMax > max) {
            max = currMax;
        }

        maxDepth(root->right, max, currMax);
        currMax--;
    }

    return max;
}

bool isBalanced(TreeNode* root) {
    int max = 0, currMax = 0;

    if (root != nullptr) {

        int maxDepthLeft = maxDepth(root->left, max, currMax);
        max = 0, currMax = 0;
        int maxDepthRight = maxDepth(root->right, max, currMax);
        max = 0, currMax = 0;

        if (maxDepthLeft - maxDepthRight < -1) {
            return false;
        }

        if (maxDepthLeft - maxDepthRight > 1) {
            return false;
        }


        if (maxDepthLeft - maxDepthRight >= -1 &&
            maxDepthLeft - maxDepthRight <= 1) {
            max = 0, currMax = 0;

            if (isBalanced(root->left) == false || isBalanced(root->right) == false) {
                return false;
            }

        }
    }

    return true;
}

int main()
{
    TreeNode n5(5, nullptr, nullptr);
    TreeNode n15(15, &n5, nullptr);
    TreeNode n7(7, nullptr, nullptr);
    TreeNode n20(20, &n15, &n7);
    TreeNode n9(9, nullptr, nullptr);
    TreeNode n3(3, &n9, &n20);

    cout << isBalanced(&n3);

    return 0;
}