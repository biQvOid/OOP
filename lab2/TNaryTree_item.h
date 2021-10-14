#ifndef TNARYTREE_ITEM
#define TNARYTREE_ITEM

#include "octagon.h"

class TreeItem
{
public:

//private:
    octagon figure;
    TreeItem* son;
    TreeItem* brother;
};

#endif