#include "TNaryTree.h"
#include "octagon.h"
#include "titerator.h"
#include "TNaryTree_item.h"
#include "tallocation_block.h"
#include <string>

int main()
{
    TAllocationBlock block(sizeof(int), 10);
    int* n1;
    int* n2;
    int* n3;
    n1 = (int*)block.allocate();
    n2 = (int*)block.allocate();
    n3 = (int*)block.allocate();
    octagon* f1 = new octagon(Point(1, 1),Point(2, 2),Point(3, 3),Point(4, 4),
    Point(5, 5),Point(6, 6),Point(7, 7),Point(8, 8));
    octagon* f2 = new octagon(Point(9, 9),Point(10, 10),Point(11, 11),Point(12, 12),
    Point(13, 13),Point(14, 14),Point(15, 15),Point(16, 16));
    octagon* f3 = new octagon(Point(17, 17),Point(18, 18),Point(19, 19),Point(20, 20),
    Point(21, 21),Point(22, 22),Point(23, 23),Point(24, 24));
    (*f1).Print(std::cout);
    (*f2).Print(std::cout);
    (*f3).Print(std::cout);
    delete f1;
    delete f2;
    delete f3;
    *n1 = 10; *n2 = 100; *n3 = 1000;
    std::cout << *n1 << " " << *n2 << " " << *n3 << "\n";
    if (block.has_free_blocks()) {
        std::cout << "Free blocks are avaible !\n";
    } else {
        std::cout << "Free blocks are not avaible!\n";
    }
    return 0;
}
