# Class Group Cryptography

As a part of my master thesis, we implemented the construction of the DDH-DLP group.
Our implementation is based on the description of the construction described in https://eprint.iacr.org/2015/047.pdf. 
At this point our implementation allows one to:


1) Construct class groups of binary quadratic forms

2) Do composition, reduction and normalization of binary quadratic forms

3) Construct a DDH-DLP Group for p = 3 and q = 13 i.e. the class group of discriminant -39

4) The main.c code runs a example of the above operations. For the example we use the class group of discriminant -23.
   We also run the DDH-DLP Group generator.

The reason why the DDH-DLP group is fixed for the above p and q, is because we need to solve a two variable equation when
moving the generator of the DDH group into the class group of the non-maximal order. Furthermore, we need to find the integer solutions.
We hvaent been able to create such a equation solver, as furture work we would adapt the methods of the PARI framework for algebraic implementations.
https://pari.math.u-bordeaux.fr
