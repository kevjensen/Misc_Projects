//
// Created by kev_j on 3/4/2020.
//

#ifndef UNTITLED5_JABAJUICE_H
#define UNTITLED5_JABAJUICE_H

#include "Items.h"


class Jabajuice : public Items {
public:

    // Rule of 0 compliant

    Jabajuice() = default;
    virtual std::string name() const override;
    virtual double price () const override;
};


#endif //UNTITLED5_JABAJUICE_H
