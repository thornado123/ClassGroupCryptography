# Class Group Cryptography



As a part of the master thesis titled Class Group Cryptography, we implemented the construction of class groups and the DDH-DLP group.

Our implementation of the DDH-DLP group is based on the description of the construction described in https://eprint.iacr.org/2015/047.pdf. 

At this point our implementation allows one to:





1) Construct class groups of binary quadratic forms



2) Do composition, reduction and normalization of binary quadratic forms



3) Construct a DDH-DLP Group for p = 3 and q = 13 i.e. the class group of discriminant -39



4) The main.c code runs a example of the above operations. For the example we use the class group of discriminant -23.

   We also run the DDH-DLP Group generator.



## Short explanation of code

The source code is under the directory: ClassGroupCryptography/DDH_DLP_LinHomomorphicEncryption/DDH_DLP_LinHomomorphicEncryption/



1. main.cpp -> Contains the examples, with some text explaining what to expect from the operations

2. QUADRATIC_FORM.cpp -> Contains the definition of a binary quadratic form. It lets you set the coefficients: a,b,c

3. IQF_CG.cpp -> Contains the code for the composition, reduction and normalization of binary quadratic forms. It allows you to define a group structure and to set a generator of the group, and the discriminant.

4. DDH_DLP_LHES.cpp -> Contains the code for generating the DDH-DLP group.



## Future work and bugs



The reason why the DDH-DLP group has fixed input for p and q, is because we need to find the integer solutions of a two variable equation when

moving the generator of the DDH group into the class group of the non-maximal order.

We have not been able to create such an equation solver, as future work we would adapt the methods of the PARI framework for algebraic implementations.

https://pari.math.u-bordeaux.fr
