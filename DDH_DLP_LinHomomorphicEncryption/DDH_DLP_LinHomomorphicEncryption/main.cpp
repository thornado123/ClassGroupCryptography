#include <iostream>
#include "IQF_CG.hpp"
#include "DDH_DLP_LHES.hpp"

void printElements2(QUADRATIC_FORM * f){
    
    std::cout << "(" << f->a << "," << f->b << "," << f->c << ")\n";
}


int main(int argc, const char * argv[]) {
   
    DDH_DLP_GROUP h;
    DDH_DLP_LES test;
    test.gen(1, 1, &h);

    QUADRATIC_FORM f;
    f.setForm(11, 49, 55);
    QF_CG cg;

    printElements2(&f);

    cg.normalize(&f);

    printElements2(&f);

    assert(f.a == 11);
    assert(f.b == 5);
    assert(f.c == 1);

    cg.reduce(&f);

    assert(f.a == 1);
    assert(f.b == 1);

    std::cout << "finished reduction\n";

    QUADRATIC_FORM q, result;
    result.setForm(0, 0, 0);
    q.setForm(2, 1, 3);
    f.setForm(2, 1, 3);

//    printf("Input q=(2, -1, 3) f=(2, 1, 3)\n");
    cg.compose(&q, &f, &result);

    printElements2(&result);

    cg.reduce(&result);

    printElements2(&result);

    return 0;
}
