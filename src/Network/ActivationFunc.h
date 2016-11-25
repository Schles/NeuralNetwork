#ifndef ACTIVATION_FUNC_H
#define ACTIVATION_FUNC_H


#include <iostream>
#include <armadillo>

class ActivationFunc {
public:
    arma::mat f(arma::mat input, unsigned int i);
    arma::mat f_derivate(arma::mat input, unsigned int i);

private:
    arma::mat identity(arma::mat input);
    arma::mat identityDerivate(arma::mat input);

};

#endif
