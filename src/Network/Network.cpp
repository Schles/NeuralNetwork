#include "Network.h"
#include <iostream>

void Network::step(arma::mat input){

    std::cout << "Starting" << std::endl;

    arma::mat y = forward(input);



    std::cout << "backwards" << std::endl;

    backward(y);

    std::cout << "updates" << std::endl;

    update(input);


}

arma::mat Network::forward(arma::mat _input){

    arma::mat input = _input;
    arma::mat s_i, z_i, f_i;

    z.clear();
    f.clear();

    for(int i = 0; i < hiddenLayers.size(); i++){
        std::cout << "Layer " << i + 1 << std::endl;

        s_i = input * hiddenLayers[i].w;

        z_i = func.f(s_i, hiddenLayers[i].f_a);
        z.push_back(z_i);

        f_i = func.f_derivate(s_i, hiddenLayers[i].f_a);
        f.push_back(f_i.t());

        z_i.print("z_0");
        f_i.t().print("f_0");

        input = z_i;
    }


    std::cout << "Outputlayer" << std::endl;
    //arma::mat result = outputLayer.forward(output);

    return input;

}


void Network::backward(arma::mat _input){
    arma::mat z_out = z[z.size() - 1];
    arma::mat tmp = z_out - _input;

    arma::mat d_j = tmp.t();
    arma::mat d_i;

    for(int i = hiddenLayers.size() - 1; i >= 0; i--){
        std::cout << "Layer " << i + 1 << std::endl;

        d_i = f[i] % (hiddenLayers[i].w * d_j);

        d.push_back(d_i);
        d_j = d_i;
    }




}

void Network::update(arma::mat _input){

    arma::mat z_i = _input;

    unsigned int d_index = 0;

    double n = 1.0;



    for(int i = 0; i < hiddenLayers.size(); i++){
        std::cout << "Layer " << i + 1 << std::endl;

        d_index = hiddenLayers.size() - 1 - i;

        arma::mat deltaW = n * (d[d_index] * z_i); //wrong for multi laye

        hiddenLayers[i].w += deltaW;
        //input = hiddenLayers[i].z;
    }

}

void Network::setOutputLayer(Layer layer){
    outputLayer = layer;
}

void Network::addHiddenLayer(Layer layer){
    hiddenLayers.push_back(layer);
}
