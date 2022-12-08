//
// Created by AnGa on 2022-12-07.
//

#include "Tank.h"

Tank::Tank(const std::string &name, double cannon) : name(name), id(cannon) {}

bool Tank::operator==(const Tank &rhs) const {
    return name == rhs.name;
}


std::ostream &operator<<(std::ostream &os, const Tank &objects) {
    os << "name: " << objects.name << " id: " << objects.id << "mm";
    return os;
}

double Tank::getCannon() const {
    return id;
}





