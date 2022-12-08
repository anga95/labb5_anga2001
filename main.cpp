#include <iostream>
#include <vector>
#include <array>
#include "Tank.h"
struct MyPrint{
    void operator()(Tank t){
        std::cout << t << std::endl;
    }
};

int main() {
    Tank arrTank[3];
    arrTank[0] = Tank("Stridsfordon90", 40);
    arrTank[1] = Tank("strv122",120);
    arrTank[2] = Tank("centurion", 10.5);
    std::vector<Tank> vecTank(std::begin(arrTank), std::end(arrTank));

    //1. for_each
    std::for_each(vecTank.begin(), vecTank.end(), MyPrint());

    //2.

    return 0;
}
