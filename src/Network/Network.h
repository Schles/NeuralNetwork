#ifndef NETWORK_H
#define NETWORK_H

#include <armadillo>
#include <vector>

#include "Layer.h"
#include "ActivationFunc.h"

class Network {
public:
    void step(arma::mat input);

    arma::mat forward(arma::mat input);
    void backward(arma::mat _input);
    void update(arma::mat input);

    void addHiddenLayer(Layer layer);
    void setOutputLayer(Layer layer);

private:
    ActivationFunc func;

    std::vector<Layer> hiddenLayers;
    Layer outputLayer;

    std::vector<arma::mat> z;
    std::vector<arma::mat> d;
    std::vector<arma::mat> f;
};

#endif
