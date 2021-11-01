#ifndef TNARYTREE_ITEM
#define TNARYTREE_ITEM

#include "octagon.h"

class TreeItem
{
public:
    octagon figure;
    int cur_size;
    TreeItem* son;
    TreeItem* brother;
    TreeItem* parent;
};

#endif
