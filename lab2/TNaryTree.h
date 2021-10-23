#ifndef TNARY_TREE
#define TNARY_TREE

#include "octagon.h"
#include "TNaryTree_item.h"

class TNaryTree
{
public:
    TNaryTree(int n);
    TNaryTree(const TNaryTree& other);
    TNaryTree();

    void Update(const octagon &&polygon, const std::string &&tree_path)
    {
        Update(&root, polygon, tree_path);
    }

    void Update(const octagon &polygon, const std::string &tree_path)
    {
        Update(&root, polygon, tree_path);
    }

    const octagon& GetItem(const std::string& tree_path)
    {
        return GetItem(&root, tree_path);
    }

    void RemoveSubTree(const std::string &&tree_path);
    void RemoveSubTree(const std::string &tree_path);
    bool Empty();
    double Area(std::string&& tree_path);
    double Area(std::string& tree_path);
    friend std::ostream& operator<<(std::ostream& os, const TNaryTree& tree);
    virtual ~TNaryTree();

private:
    int size;
    int cur_size;
    TreeItem* root;
    void Update(TreeItem** root, octagon polygon, std::string tree_path);
    const octagon& GetItem(TreeItem** root, const std::string tree_path);
};

#endif
