#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int concatInteger(int a, int b){
    return std::stoi(std::to_string(a) + std::to_string(b));
}

int main(){
    std::ifstream file;
    std::vector<int>temparray;
    std::vector<int>result;
    int final=0;
    std::string buffer;

    file.open("/Users/luevard/CLionProjects/AdventOfCodeGithub/AdventOfCode/day-1/input.txt");
    if(!file.is_open()) {
        std::cout<< "Erreur pendant l'ouverture du fichier"<<std::endl;
        return -1;
    }
    
    while(!file.eof()){
        file >> buffer;
        for(char& c : buffer) {
            if(std::isdigit(c)) 
                temparray.push_back(digittoint(c));
        }
        if(!temparray.empty()){
            result.push_back(concatInteger(temparray.front(),temparray.back());
            temparray.clear();
        }
    }
    for(int i : result){
        final=final+i;
    }
    std::cout<<final;
    return 0;
}
