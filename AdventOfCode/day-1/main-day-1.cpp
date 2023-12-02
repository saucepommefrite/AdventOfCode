#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <numeric>

int checkWord(const std::string& buffer) {
    static const std::map<std::string, int> compareString = {
            {"one", 1},
            {"two", 2},
            {"three", 3},
            {"four", 4},
            {"five", 5},
            {"six", 6},
            {"seven", 7},
            {"eight", 8},
            {"nine", 9}
    };
    for (const auto& [key, value] : compareString) {
        if (buffer.find(key) != std::string::npos) {
            return value;
        }
    }
    return -1;
}


int concatInteger(int a, int b){
    return std::stoi(std::to_string(a) + std::to_string(b));
}

int main(){

    std::ifstream file("/Users/luevard/CLionProjects/AdventOfCodeGithub/AdventOfCode/day-1/input.txt");
    if (!file.is_open()) {
        std::cout << "Erreur pendant l'ouverture du fichier" << std::endl;
        return -1;
    }

    std::vector<int> intArray;
    std::vector<int>result;
    std::vector<char>buffer;
    std::string bufferFile;
    
    while(!file.eof()){
        file >> bufferFile;
        for(char& c : bufferFile) {

            if(std::isdigit(c)) {
                buffer.clear();
                intArray.push_back(digittoint(c));
            }
            else buffer.push_back(c);

            std::string str(buffer.begin(),buffer.end());
            int response = checkWord(str);
            if (response > 0) {
                buffer.clear();
                buffer.push_back(str.back()); // Exemple: Threeight => 3 8
                intArray.push_back(response);
            }
        }
        if(!intArray.empty()){
            result.push_back(concatInteger(intArray.front(),intArray.back()));
            intArray.clear();
        }
    }
    std::cout << std::accumulate(result.begin(), result.end(), 0);
    return 0;
}
