#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int concatInteger(int a, int b){
    std::string inta=std::to_string(a);
    std::string intb=std::to_string(b);

    std::string concatInt = inta + intb;
    return std::stoi(concatInt);
}

int main(){
    std::ifstream file;
    std::vector<int>temparray;
    std::vector<int>result;
    file.open("/Users/luevard/CLionProjects/AdventOfCodeGithub/AdventOfCode/day-1/input.txt");
    std::string buffer;

    if(!file.is_open()) {
        std::cout<< "Erreur pendant l'ouverture du fichier"<<std::endl;
        return -1;
    }

    while(!file.eof()){
        file >> buffer;
        for(char& c : buffer) {
            if((int)c>47 && (int)c<58) {
                temparray.push_back(digittoint(c));
            }
        }
        if(!temparray.empty()){
            result.push_back(concatInteger(temparray.front(),temparray.back());
            temparray.clear();
        }
    }

    int final=0;
    for(int i : result){
        final=final+i;
    }

    std::cout<<final;

    return 0;
}