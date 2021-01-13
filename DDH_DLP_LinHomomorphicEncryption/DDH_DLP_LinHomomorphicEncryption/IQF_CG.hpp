#ifndef QF_CG_h
#define QF_CG_h

#include "QUADRATIC_FORM.hpp"
#include <math.h>
#include <iostream>
#include <algorithm>
#include <numeric>

class QF_CG {
    
    QUADRATIC_FORM * generator;
    int discriminant;
    
public:

    void setDiscriminant(int discriminant);
    void setGenerator(QUADRATIC_FORM *element);
    void setDLPGenerator(QUADRATIC_FORM *element);
    void normalize(QUADRATIC_FORM * element);
    bool isReduced(QUADRATIC_FORM *element);
    void reduce(QUADRATIC_FORM * element);
    void compose(QUADRATIC_FORM *leftElement, QUADRATIC_FORM *rightElement, QUADRATIC_FORM *result);
    void square(QUADRATIC_FORM *element, QUADRATIC_FORM *result);
    
};

#endif /* QF_CG_h */
