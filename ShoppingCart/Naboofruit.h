//
// Created by kev_j on 3/4/2020.
//

#ifndef UNTITLED5_NABOOFRUIT_H
#define UNTITLED5_NABOOFRUIT_H

#include "Weighted.h"

class Naboofruit : public Weighted {

public:

    // Rule of 0 compliant
    Naboofruit() = default;
    Naboofruit(double weight);

    std::string name() const override;
    double price() const override;

private:

    double weight;
};


#endif //UNTITLED5_NABOOFRUIT_H
