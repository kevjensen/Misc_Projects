//
// Created by kev_j on 3/4/2020.
//

#include "Naboofruit.h"

std::string Naboofruit::name() const {
    return "Naboo Fruit";
}

double Naboofruit::price() const {
    return weight * .69;
}

Naboofruit::Naboofruit(double weight_) : weight(weight_) {

}