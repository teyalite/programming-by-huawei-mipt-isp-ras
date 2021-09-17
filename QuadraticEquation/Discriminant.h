//
// Created by Abdoulkader Haidara on 17.09.2021.
//

#ifndef QUADRATICEQUATION_DISCRIMINANT_H
#define QUADRATICEQUATION_DISCRIMINANT_H

#include "Discriminant.h"
#include "Coefficients.h"

// Discriminant Type help us to determine which type of root we may have.

enum DiscriminantType {
    PositiveDiscriminant,
    NegativeDiscriminant,
    ZeroDiscriminant,
};

// The value of the determinant and its type.

struct Discriminant {
    double value;
    enum DiscriminantType type;
};

typedef struct Discriminant Discriminant;

#endif //QUADRATICEQUATION_DISCRIMINANT_H
