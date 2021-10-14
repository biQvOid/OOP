#include "figure.h"
#include "triangle.h"
#include "square.h"
#include "TNaryTree.h"
#include "TNaryTree_item.h"
#include "octagon.h"
#include <string>

int main()
{
    TNaryTree a(9);
    if (a.Empty()) {
        std::cout << "The tree is empty !\n";
    } else {
        std::cout << "The tree is not empty !\n";
    }
    a.Update(octagon(Point(3, 4), Point(1, 2), Point(5, 6), Point(2, 8), Point(3, 1), Point(2, 6), Point(9, 5), Point(5, 4)), ""); // 1
    a.Update(octagon(Point(81, 5), Point(1, 5), Point(16, 6), Point(3, 6), Point(1, 8), Point(4, 2), Point(7, 3), Point(1, 15)), "c"); // 2
    a.Update(octagon(Point(8, 5), Point(9, 1), Point(7, 3), Point(1, 8), Point(5, 6), Point(4, 8), Point(9, 5), Point(6, 4)), "cb"); // 3
    a.Update(octagon(Point(3, 4), Point(1, 2), Point(5, 6), Point(2, 8), Point(3, 1), Point(2, 6), Point(9, 5), Point(5, 4)), "cbb"); // 4
    a.Update(octagon(Point(81, 5), Point(1, 5), Point(16, 6), Point(3, 6), Point(1, 8), Point(4, 2), Point(7, 3), Point(1, 15)), "cbbc"); // 5
    a.Update(octagon(Point(8, 5), Point(9, 1), Point(7, 3), Point(1, 8), Point(5, 6), Point(4, 8), Point(9, 5), Point(6, 4)), "cc"); // 6
    a.Update(octagon(Point(3, 4), Point(1, 2), Point(5, 6), Point(2, 8), Point(3, 1), Point(2, 6), Point(9, 5), Point(5, 4)), "ccb"); // 7
    a.Update(octagon(Point(81, 5), Point(1, 5), Point(16, 6), Point(3, 6), Point(1, 8), Point(4, 2), Point(7, 3), Point(1, 15)), "cbc"); // 8
    a.Update(octagon(Point(8, 5), Point(9, 1), Point(7, 3), Point(1, 8), Point(5, 6), Point(4, 8), Point(9, 5), Point(6, 4)), "cbcb"); // 9
    std::cout << a;
    std::cout << a.Area("cbc") << "\n";
    TNaryTree b(a);
    std::cout << b;
    a.Clear("cbc");
    a.Clear("ccb");
    std::cout << a;
    if (a.Empty()) {
        std::cout << "The tree is empty !\n";
    } else {
        std::cout << "The tree is not empty !\n";
    }
    return 0;
}
