//
// Created by AnGa on 2022-12-07.
//

#ifndef LABB5_ANGA2001_TANK_H
#define LABB5_ANGA2001_TANK_H


#include <string>
#include <ostream>
#include <array>
#include <vector>

class Tank{
public:
    Tank() = default;
    Tank(const std::string &name, double cannon);
    bool operator==(const Tank &rhs) const;

    friend std::ostream &operator<<(std::ostream &os, const Tank &objects);

private:
    std::string name;
    double cannon; //how many mm
};


#endif //LABB5_ANGA2001_TANK_H
