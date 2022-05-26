//
// Created by kev_j on 3/4/2020.
//

#ifndef UNTITLED5_PORTIONBREAD_H
#define UNTITLED5_PORTIONBREAD_H

#include "Items.h"

class Portionbread : public Items {
public:

    //Rule of 0 compliant

    Portionbread() = default;

    virtual std::string name() const override;
    virtual double price () const override;

};


#endif //UNTITLED5_PORTIONBREAD_H
