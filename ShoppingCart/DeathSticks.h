//
// Created by kev_j on 3/1/2020.
//

#ifndef UNTITLED5_DEATHSTICKS_H
#define UNTITLED5_DEATHSTICKS_H

#include "Items.h"

#include <string>

class DeathSticks : public Items {
public:

    // Rule of 0 compliant

    DeathSticks() = default;

    virtual std::string name() const override;
    virtual double price () const override;

private:

};


#endif //UNTITLED5_DEATHSTICKS_H
