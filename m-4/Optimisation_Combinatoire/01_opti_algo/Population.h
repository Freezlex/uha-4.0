//
// Created by julie on 09/01/2023.
//

#ifndef INC_01_OPTI_ALGO_POPULATION_H
#define INC_01_OPTI_ALGO_POPULATION_H


class Population {
public:
    Population(){

    }

    bool[] get_population(){
        return this->population;
    }

private:
    bool[] population;
};


#endif //INC_01_OPTI_ALGO_POPULATION_H
