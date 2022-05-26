//
// Created by kev_j on 3/4/2020.
//

#include "Porg.h"

std::string Porg::name() const {
    return "Porg";
}

double Porg::price() const {
    return weight * 25.65;
}

Porg::Porg(double weight_) : weight(weight_) {
}

