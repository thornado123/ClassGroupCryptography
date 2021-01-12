#include "IQF_CG.hpp"
/*
 
    Setting the generator of the CL
 
 */

void QF_CG::setGenerator(QUADRATIC_FORM *element){
    
    generator = element;
    
}

/*
 
    Setting the generator of easy DLP group CL
 
 */

void QF_CG::setDLPGenerator(QUADRATIC_FORM *element){
    
    dlp_generator = element;
    
}

/*
 
    Check if the QF is normal and if not normalize it
 
 */
void QF_CG::normalize(QUADRATIC_FORM * element){
    
    if(!(-1*element->a < element->b and element->b <= element->a)){
    
        int r = floor((double)(element->a - element->b)/(double)(2 * element->a));
        int b = element->b;
        element->b = element->b + 2 * r * element->a;
        element->c = element->a*r*r + b*r + element->c;
        
    }
    
}
/*
 
    Check if the QF is normal
 
 */
bool QF_CG::isReduced(QUADRATIC_FORM *element){
    
    
    if(-1*element->a < element->b and element->b <= element->a){
        
        if(element->a < element->c){
    
            return true;
            
        }else if (element->a == element->c){
            
            if(element->b >= 0){
                    
                return true;
            
            }
            
        }
        
    }
    
    return false;
    
}

/*
 
    Check if the QF is reduced if not reduce it
 
 */
void QF_CG::reduce(QUADRATIC_FORM * element){
    
    int s, a, b;
    
    if(!(element->a < (sqrt(abs(discriminant))/2))){

    
        // If the element isn't normal, normalize it
        normalize(element);
        
        while (!isReduced(element)) {
                
                s = floor((double)(element->c + element->b)/(double)(2 * element->c));
                
                a = element->a;
                b = element->b;
                
                element->a = element->c;
                element->b = -1*b + 2*s*element->c;
                element->c = element->c*s*s - (b*s) + a;

            }
    }
}


/*
 
    Solving congurenss equations
    Credit:
    https://www.techiedelight.com/find-general-solution-to-given-linear-congruence-equation/

 
 */

struct generalSolutionCongruence {
    
    int a, b;
    
};

int inverse(int a, int b)
{
    int inv = -1;
    int q, r, r1 = a, r2 = b, t, t1 = 0, t2 = 1;

    while (r2 > 0)
    {
        q = r1 / r2;
        r = r1 - q * r2;
        r1 = r2;
        r2 = r;

        t = t1 - q * t2;
        t1 = t2;
        t2 = t;
    }

    if (r1 == 1)
        inv = t1;

    if (inv < 0)
        inv = inv + a;

    return inv;
}

int gcd(int a, int b)
{
    int q, r;
    if (b < 0 ){
        b = b * -1;
    }
    if (a < 0){
        a = a*-1;
    }
    while (b > 0)
    {
        q = a / b;
        r = a - q * b;
        a = b;
        b = r;
    }
    return a;
}

generalSolutionCongruence solveCongruence(int a, int b, int n){

    int d, a1, b1, n1, x0;
    int inv;
    
//    fprintf(stdout, "%dx=%d(mod %d)\n", a, b, n);

    d = gcd(a, n);

    a1 = a / d;
    b1 = b / d;
    n1 = n / d;
    
    inv = inverse(n1, a1);

    x0 = (b1 * inv) % n1;
        
//    fprintf(stdout, "General Solution: x = %d + %dk where k is any integer\n\n", x0, n / d);
    
    generalSolutionCongruence result;
    result.a = x0;
    result.b = n/d;
    
    return result;
    
}

/*
 
    Take three element pointers a do BQF composition on the two first and return the result in the last
 
 */
void QF_CG::compose(QUADRATIC_FORM *leftElement, QUADRATIC_FORM *rightElement, QUADRATIC_FORM *result){
    
    // Part 1 and 2
    double g = (leftElement->b + rightElement->b)/2;
    double h = (-1*(leftElement->b - rightElement->b))/2;
    int w = gcd(gcd(leftElement->a, rightElement->a), g);
    int j = w;
    int s = leftElement->a/w;
    int t = rightElement->a/w;
    int u = g/w;
    
    printf(">%f, %f, %d, %d, %d, %d, %d\n", g,h,w,j,s,t,u);
    
    //    printf("g: %f, h: %f, w: %d, s: %d, t: %d, u: %d\n", g, h, w, s, t, u);
    // Part 3 solving congurences
    generalSolutionCongruence leftSol = solveCongruence(t*g, (h*u+s*leftElement->c), s*t);
    
    printf(">%d, %d\n", leftSol.a, leftSol.b);
    
    // Part 4 solving congurences
    generalSolutionCongruence rightSol = solveCongruence(t*leftSol.b, (h-t*leftSol.a), s);
    
    
    printf(">%d, %d\n", rightSol.a, rightSol.b);
    
    // Part 5
    int k = leftSol.a + leftSol.b*rightSol.a;
    int l = (k*t-h)/s;
    int m = (t*u*k-h*u-leftElement->c*s)/(s*t);
    
    //    printf("k: %d, l: %d, m: %d\n", k, l, m);
    
    // Part 6
    int A,B,C;
    
    A = s*t;
    B = j*u-(k*t+l*s);
    C = k*l-j*m;
    
    result->setForm(A, B, C);
    
}
