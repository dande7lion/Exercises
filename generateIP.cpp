#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

std::vector<std::string> generateIP(const std::string& s){
    std::vector<std::string> result;
    std::string prepareIP[4];
    int length = s.length();
    if(length < 4 || length > 12){
        std::cout << "Incorrect data. Please try again" << std::endl;
        return result;
    }
    for(int i = 0; i < 3; i++){
        prepareIP[0] = s.substr(0,i+1);
        if(atoi(prepareIP[0].c_str()) > 255)
            break;
        for(int j = i + 1; j < i + 4; j++){
            if(j >= length-2)
                break;
            prepareIP[1] = s.substr(i+1,(j+1)-(i+1));
                if(atoi(prepareIP[1].c_str()) > 255)
                    break;
            for(int k = j + 1; k < j + 4; k++){
                if(k >= length-1)
                    break;
                prepareIP[2] = s.substr(j+1, (k+1)-(j+1));
                prepareIP[3] = s.substr(k+1, length-(k+1));

                if(atoi(prepareIP[2].c_str()) > 255)
                    break;

                if(atoi(prepareIP[3].c_str()) > 255)
                    continue;

                std::string oneCorrectAddress;
                    oneCorrectAddress = prepareIP[0] + "." + prepareIP[1] + "." + prepareIP[2] + "." + prepareIP[3];
                    result.push_back(oneCorrectAddress);
            }
        }
    }

    return result;

}

//In the main function I present an example of using the function "generateIP"

int main(){

    std::string numbers = "31212";
    std::cout << "Number: " << numbers << std::endl;
    std::vector <std::string> IPaddresses = generateIP(numbers);
    for(int i = 0; i < (int)IPaddresses.size(); i++){
        std::cout << IPaddresses[i] << std::endl;
    }
}
