#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

std::vector<std::string> generateIP(const std::string& s){
    std::vector<std::string> result;
    std::string tab[4];
    int length = s.length();
    if(length < 4 || length > 12){
        std::cout << "Incorrect data. Please try again" << std::endl;
        return result;
    }
    for(int i = 0; i < length-1; i++){
        for(int j = i + 1; j < length-1; j++){
            for(int k = j + 1; k < length-1; k++){
                std::string tmp;
                tab[0] = s.substr(0,i+1);
                tab[1] = s.substr(i+1,(j+1)-(i+1));
                tab[2] = s.substr(j+1, (k+1)-(j+1));
                tab[3] = s.substr(k+1, length-(k+1));
                bool suitable = true;
                for(int l = 0; l < 4; l++){
                    if(atoi(tab[l].c_str()) > 255){
                        suitable = false;
                        break;
                    }
                }
                if(suitable){
                    tmp = tab[0] + "." + tab[1] + "." + tab[2] + "." + tab[3];
                    result.push_back(tmp);
                }
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
