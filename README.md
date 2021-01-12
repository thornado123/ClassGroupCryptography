# Class Group Cryptography

As a part of my master thesis, we implemented the construction of the DDH-DLP group.
Our implementation is based on the description of the construction described in https://eprint.iacr.org/2015/047.pdf. 
At this point our implementation allows one to:


1) Construct class groups of binary quadratic forms

2) Do composition, reduction and normalization of binary quadratic forms

3) The main.c code runs a small example of the above



The part of the implementation that is not quite finished is being able to move between the class groups of the maximal and non-maximal order.
The reason this is a obsticale, is handling and get a definitive positive quadratic form of discriminant Delta prime to the conductor. 
As future work we wish to use the PARI computer algebra system to handle these cases. We found out that it is the standard when implementing algebraic constructs. https://pari.math.u-bordeaux.fr

