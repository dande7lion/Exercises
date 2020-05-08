#include <iostream>
#include <vector>
#include <array>
#include <cstdlib>
#include <ctime>

std::array<int, 4> pickMorphs(const std::vector<float>& weights){

    std::array<int, 4> maxIndexes = {-1, -1, -1, -1};

    float maxWeights [] = {-0.1, -0.1, -0.1, -0.1, 1.1};
    float currentWeight;
    int j;

    for(int i = 0; i < (int)weights.size(); i++){
        currentWeight = weights[i];
        if(currentWeight < 0.0 || currentWeight > 1.0) continue;        //if there were incorrect values in the vector
        for(j = 0; currentWeight > maxWeights[j]; j++){
            maxWeights[j] = maxWeights[j+1];
            maxIndexes[j] = maxIndexes[j+1];
        }
        if(j > 0){
            maxWeights[j-1] = currentWeight;
            maxIndexes[j-1] = i;
        }
    }

    return maxIndexes;
}


//In the main function I present an example of using the function "pickMorphs"

int main()
{
    srand(time(NULL));
    float number;
    std::vector<float> weights;
    std::cout << "Vector: ";
    for(int i = 0; i < 20; i++){
        number = (std::rand()%101)/100.0;
        weights.push_back(number);
        std::cout << number << " " ;
    }

    std::array<int, 4> result = pickMorphs(weights);
    std::cout << std::endl << "Result: ";
    for(int i = 0; i < (int)result.size(); i++){
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
