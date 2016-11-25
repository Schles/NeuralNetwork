#include <iostream>

#include <armadillo>

#include "Network/Layer.h"
#include "Network/Network.h"


int main(){
     arma::mat input;
     input << 1 << 2 << arma::endr;
           //<< 3 << 4 << arma::endr;

     Network network;

     arma::mat layer1;
     layer1 << 1 << 0 << arma::endr
            << 0 << 1 << arma::endr;

    arma::mat oLayer;
    oLayer << 1 << arma::endr << 1 << arma::endr;

    struct Layer hiddenLayer = {layer1, 1};
    struct Layer outputLayer = {oLayer, 1};

    network.addHiddenLayer(hiddenLayer);

    network.setOutputLayer(outputLayer);

    network.step(input);

    return 0;
}
