#include <iostream>
#include "IQF_CG.hpp"
#include "DDH_DLP_LHES.hpp"

void printElements2(QUADRATIC_FORM * f){
    
    std::cout << "(" << f->a << "," << f->b << "," << f->c << ")\n";
}


int main(int argc, const char * argv[]) {
    
    /*
     
        We start by recreating the examples of Chapter 2 in the thesis.
        The class group Cl(-23)
     
     */
    printf("In the following example, we create a class group from the examples of chapter 2\n");
    printf("We show how we can do composition and reudce elements\n");
    printf("We also show how the idenity actually behave as it should\n");
    
    QF_CG cg;
    QUADRATIC_FORM a, b, c, result;
    
    a.setForm(1, 1, 6);
    b.setForm(2, 1, 3);
    c.setForm(2, -1, 3);
    
    // We start with an example that a is the identity
    printf("Now composing the identity (1,1,6) and (2,1,3)\n");
    cg.compose(&a, &b, &result);
    printf("The result of the composition of a and b should be b i.e. (2,1,3). Acutal Result: ");
    printElements2(&result);
    
    // We now use the composition on b and b. The non-reduced result should be (4,-3,2)
    printf("\n\nNow composing (2,1,3) and (2,1,3)\n");
    cg.compose(&b, &b, &result);
    printf("The result of the composition of a and b should be b i.e. (4,-3,2). Acutal Result: ");
    printElements2(&result);
    
    // We now want to reduce the element (4,-3,2)
    printf("\n\nNow we want to reduce the form (4,-3,2)\n");
    cg.reduce(&result);
    printf("The result of the reduction of (4,-3,2) should be (2,-1,3). Acutal Result: ");
    printElements2(&result);
    
    /*
     
        We now use the theory of Chapter 4 in the thesis to construct a DDH-DLP group
     
     */
    
    printf("\n\nIn the following we will create a DDH-DLP group of Chapter 4.\nWe will use the class group Cl(-39) into the class group of the non-maximal order with discriminat -351\n");
    printf("As conductor we will use the prime p=3\n");
    printf("We have that 53, is square free and p...\n");
    
    DDH_DLP_GROUP DDH_DLP_GROUP;
    DDH_DLP_LES DDH_DLP_GROUP_GEN;
    DDH_DLP_GROUP_GEN.gen(3, 13, &DDH_DLP_GROUP);

    return 0;
}
