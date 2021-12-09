#include "FazzyNumber.h"
#include <fstream>

int main()
{
    std::ifstream file("test_01.txt");
    int size;
    file >> size;
    for(int i = 0; i < size; i++) {
        float a, b, c, e, f, g;
        file >> a >> b >> c >> e >> f >> g;
        FazzyNumber N1(a, b, c); FazzyNumber N2(e, f, g);
        std::cout << "Sum of fazzy numbers:" << N1 + N2 << "\n";
        std::cout << "Difference of fazzy numbers: " << N1 - N2 << "\n";
        std::cout << "Composition of fazzy numbers: " << N1 * N2 << "\n";
        std::cout << "Quotient of fazzy numbers: " << N1 / N2 << "\n";
        std::cout << "Opposite fazzy number: " << N1.get_opposite() << "\n";
        if (N1 < N2) {
            std::cout << "First number < than second one\n";
        }
        if (N1 == N2) {
            std::cout << "First number is equal to second one\n";
        }
        std::cout << "\n";
    }
    FazzyNumber N = "3.98|4.13|4.28"_fn;
    std::cout << N << "\n";
    return 0;
}
