#include <vector>
using namespace std;
template <typename T>
class TreeNode
{
public:
    T data;
    // a vector of pointers which take TreeNode type elements and TreeNode which take <T> type of elements
    vector<TreeNode<T> *> children;
    TreeNode(T data)
    {
        this->data = data;
    }
};