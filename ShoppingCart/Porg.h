//
// Created by kev_j on 3/4/2020.
//

#ifndef UNTITLED5_PORG_H
#define UNTITLED5_PORG_H

#include "Weighted.h"


class Porg : public Weighted {
public:

    // Rule of 0 compliant

    Porg () = default;
    Porg(double weight);

    virtual std::string name() const override;
    virtual double price() const override;

private:

    double weight;
};


#endif //UNTITLED5_PORG_H
