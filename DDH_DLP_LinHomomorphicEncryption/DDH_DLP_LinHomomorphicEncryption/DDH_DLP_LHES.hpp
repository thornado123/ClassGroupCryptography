#ifndef DDH_DLP_LES_hpp
#define DDH_DLP_LES_hpp

#include <stdio.h>
#include "IQF_CG.hpp"
/*
 
    This is an implementation of the linearly encryption scheme defined in the paper:
    https://eprint.iacr.org/2015/047.pdf
 
 */

struct DDH_DLP_GROUP {
    
    QF_CG * g_of_maximal_order;
    QF_CG * f_of_kernel;
    QF_CG * gf_of_f_and_g;
    
    int bound, p;
    
};

struct pk {
    
    int B, p;
    QUADRATIC_FORM g, h, f;
    
};

class DDH_DLP_LES {
    
    //The group we are working in
    struct DDH_DLP_GROUP * group;
    struct pk;
    int sk;
    
    
public:
    
    void gen(int lambda, int phi, DDH_DLP_GROUP * group);
    
};

#endif /* DDH_DLP_LES_hpp */
