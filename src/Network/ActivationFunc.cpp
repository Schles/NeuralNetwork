#include "ActivationFunc.h"
#include <iostream>

arma::mat ActivationFunc::f(arma::mat input, unsigned int i){
    switch(i){
        case 2:
            break;
    }

    return identity(input);

}

arma::mat ActivationFunc::f_derivate(arma::mat input, unsigned int i){

    return identityDerivate(input);
};

arma::mat ActivationFunc::identity(arma::mat input){
    return input;
}

arma::mat ActivationFunc::identityDerivate(arma::mat input){
    return input;
}
