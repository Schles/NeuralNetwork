#ifndef LAYER_H
#define LAYER_H

#include <armadillo>

struct Layer {
    arma::mat w;
    unsigned int f_a;
};

#endif
