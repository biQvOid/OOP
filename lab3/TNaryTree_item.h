#ifndef TNARYTREE_ITEM
#define TNARYTREE_ITEM

#include "octagon.h"
#include <memory>

class TreeItem
{
public:
    octagon figure;
    std::shared_ptr<TreeItem> son;
    std::shared_ptr<TreeItem> brother;
};

#endif