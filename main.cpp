#include <iostream>
#include <vector>
#include <array>
#include <random>
#include "Tank.h"
void shuffleVec(std::vector<double> &vec){
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(vec.begin(), vec.end(),g);
}
struct MyPrint{
    void operator()(Tank t){
        std::cout << t << std::endl;
    }
};
struct isGreater{
    double targetValue;
    explicit isGreater(double targetValue) : targetValue(targetValue) {}

    bool operator()(Tank t){
        return t.getCannon() > targetValue;
    }
};
struct sortAscending{
    template<typename T>
    bool operator()(T& lhs, T& rhs)const{
        return lhs< rhs;
    }
};

int main() {
    Tank arrTank[6];
    arrTank[0] = Tank("Stridsfordon90", 10);
    arrTank[1] = Tank("strv122",20);
    arrTank[2] = Tank("strv1337", 30);
    arrTank[3] = Tank("Stridsfordon22", 40);
    arrTank[4] = Tank("strv122",50);
    arrTank[5] = Tank("strv122", 60);
    std::vector<Tank> vecTank(std::begin(arrTank), std::end(arrTank));

    //1. for_each() -
    std::cout << "1. for_each" << std::endl;
    std::for_each(vecTank.begin(), vecTank.end(), MyPrint());

    std::cout <<"2. find_if()" << std::endl;
    isGreater ig(100);
    auto result2 = std::find_if(vecTank.begin(), vecTank.end(),ig );
    std::cout << *result2 << "\n";

    //3. Adjacent_find() - takes element (it+1) if true
    std::cout << "3. adjacent_find()" << std::endl;
    auto result3 = std::adjacent_find(vecTank.begin(), vecTank.end());
    std::cout << *result3 << "\n";

    //4. equal() - returns true if cont is equal size and elemens is same(in order)
    std::cout << "4. algorithm equal" << std::endl;

    auto result4 = std::equal(vecTank.begin(),vecTank.end(),
               std::begin(arrTank), std::end(arrTank));
    std::cout << result4 << "\n";

    //5. search() - is subsequence part of another sequence?
    std::cout << "5. std::search" << std::endl;
    auto result5 = std::search(vecTank.begin(),vecTank.end(),
                arrTank+2, arrTank+4);

    std::cout << *result5 << "\n";

    //6. accumulate()
    auto MyBinOp =[](double total, const Tank& tank) {
        return total + tank.getCannon();
    };
    std::cout << "6. accumulate" << std::endl;
    auto result6 = std::accumulate(vecTank.begin(),vecTank.end(),double(), MyBinOp);
    double mean =  result6/vecTank.size();
    std::cout << mean << std::endl;

    //7. transform
    auto MyUnOp = [](Tank t){
        return t.getCannon();
    };
    std::cout << "7. transform" << std::endl;
    std::vector<double> v2(vecTank.size());
    std::transform(vecTank.begin(),vecTank.end(),
                   v2.begin(), MyUnOp );
    for (auto & e: v2) {
        std::cout << e << ", ";
    }
    std::cout << std::endl;

    //8. transform again
    std::cout << "8. transform" << std::endl;
    auto MyFunc = [mean](double d){
        return d - mean ;
    };
    std::transform(v2.begin(),v2.end(),
                   v2.begin(), MyFunc);
    for (auto & e: v2) {
        std::cout << e << ", ";
    }
    std::cout << std::endl;
    std::cout << "9. std::sort" << std::endl;
    shuffleVec(v2);
    for (auto & e: v2) {
        std::cout << e << ", ";
    }
    std::cout << std::endl;
    std::sort(v2.begin(),v2.end(), sortAscending());
    for (auto & e: v2) {
        std::cout << e << ", ";
    }

    return 0;
}
//hur många funktionsobjekjt kan vara funktioner