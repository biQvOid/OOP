#include "figure.h"
#include "TNaryTree.h"
#include "TNaryTree_item.h"
#include "octagon.h"
#include <string>

int main()
{
    TNaryTree a(4);
    if (a.Empty()) {
        std::cout << "The tree is empty !\n";
    } else {
        std::cout << "The tree is not empty !\n";
    }
    a.Update(octagon(Point(1, 4), Point(1, 2), Point(5, 6), Point(2, 8),
    Point(3, 1), Point(2, 6), Point(9, 5), Point(5, 4)), ""); // 1
    a.Update(octagon(Point(2, 5), Point(1, 5), Point(16, 6), Point(3, 6),
    Point(1, 8), Point(4, 2), Point(7, 3), Point(1, 15)), "c"); // 2
    a.Update(octagon(Point(3, 5), Point(9, 1), Point(7, 3), Point(1, 8),
    Point(5, 6), Point(4, 8), Point(9, 5), Point(6, 4)), "cb"); // 3
    a.Update(octagon(Point(4, 4), Point(1, 2), Point(5, 6), Point(2, 8),
    Point(3, 1), Point(2, 6), Point(9, 5), Point(5, 4)), "cbb"); // 4
    a.Update(octagon(Point(5, 5), Point(1, 5), Point(16, 6), Point(3, 6),
    Point(1, 8), Point(4, 2), Point(7, 3), Point(1, 15)), "cbbc"); // 5
    a.Update(octagon(Point(6, 5), Point(9, 1), Point(7, 3), Point(1, 8),
    Point(5, 6), Point(4, 8), Point(9, 5), Point(6, 4)), "cc"); // 6
    a.Update(octagon(Point(7, 4), Point(1, 2), Point(5, 6), Point(2, 8),
    Point(3, 1), Point(2, 6), Point(9, 5), Point(5, 4)), "ccb"); // 7
    a.Update(octagon(Point(8, 5), Point(1, 5), Point(16, 6), Point(3, 6),
    Point(1, 8), Point(4, 2), Point(7, 3), Point(1, 15)), "cbc"); // 8
    a.Update(octagon(Point(9, 5), Point(9, 1), Point(7, 3), Point(1, 8),
    Point(5, 6), Point(4, 8), Point(9, 5), Point(6, 4)), "cbcb"); // 9
    a.Update(octagon(Point(9, 5), Point(9, 1), Point(7, 3), Point(1, 8),
    Point(5, 6), Point(4, 8), Point(9, 5), Point(6, 4)), "ccc"); // 10
    a.Update(octagon(Point(9, 5), Point(9, 1), Point(7, 3), Point(1, 8),
    Point(5, 6), Point(4, 8), Point(9, 5), Point(6, 4)), "cccb"); // 11
    std::cout << a;
    std::cout << a.Area("cb") << "\n";
    TNaryTree b(a);
    std::cout << b;
    octagon c = a.GetItem("");
    std::cout << c;
    a.RemoveSubTree("cbc");
    if (a.Empty()) {
        std::cout << "The tree is empty !\n";
    } else {
        std::cout << "The tree is not empty !\n";
    }
    return 0;
}
