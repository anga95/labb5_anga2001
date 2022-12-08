//
// Created by AnGa on 2022-12-07.
//

#include "Tank.h"

bool Tank::operator==(const Tank &rhs) const {
    return name == rhs.name;
}

std::ostream &operator<<(std::ostream &os, const Tank &objects) {
    os << "name: " << objects.name << " cannon: " << objects.cannon  << "mm";
    return os;
}


