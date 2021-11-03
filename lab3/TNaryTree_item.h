#ifndef TNARYTREE_ITEM
#define TNARYTREE_ITEM

#include "octagon.h"
#include <memory>

class TreeItem
{
public:
    std::shared_ptr<octagon> figure;
    int cur_size;
    std::shared_ptr<TreeItem> son;
    std::shared_ptr<TreeItem> brother;
    std::shared_ptr<TreeItem> parent;
};

#endif
