#include <vector> 
#include <algorithm>
#include <iostream>
#include <cmath>

 std::string resistorCode(std::vector<std::string> bands) {
    std::string val = ""; 
    std::vector<std::string> colours = {"black","brown","red","orange","yellow","green","blue","violet","gray","white","gold","silver"};
    
    std::vector<std::string> tolerances = {"-","+-1%","+-2%","-","-","+-0.5%","+-0.25%","+-0.1%","+-0.05%","-","+-5%","+-10%"};
    
    std::vector<std::string> tcrs = {"-","100ppm/k","50ppm/k","15ppm/k","25ppm/k","-","10ppm/k","5ppm/k","-","-","-","-"};
    
    int n_bands = bands.size() - (bands.size() / 2);
    char multiples[3] = {'k', 'M', 'G'};
    std::string tolerance = "";
    std::string tcr = "";
    double expo;
    
    for (int i = 0; i < bands.size(); i++) {
        auto loc = find(colours.begin(), colours.end(), bands[i]) - colours.begin();
        if (i < n_bands) val += std::to_string(loc);
        else if (i == n_bands) expo = loc;
        else if (i == n_bands+1) tolerance = tolerances[loc];
        else if (bands.size() == 6) tcr = tcrs[loc];
    }
    
    if (expo > 9) expo = -(expo-9);
    double resistance = stoi(val) * pow(10.0, expo);
    std::string multiple = "";
    
    for (int m = 0; m < 3; m++) {
        if (resistance / 1000 > 1) {
            multiple = multiples[m];
            resistance /= 1000;
        }
    }
    
    val = std::to_string(resistance);
    val = val.substr(0, val.find_last_not_of('0')+1);
    if(val.find('.') == val.size()-1) val = val.substr(0, val.size()-1);
    val += multiple + "" + " " + tolerance;
    if (bands.size() == 6) val += " " + tcr;
    return val;
 }
 
 int main() {
    std::cout << "Enter your resistor colours (enter blank when finished): " << '\n';
    std::vector<std::string> input = {};
    std::string var = " ";

    while (input.size() != 7) {
        std::cin >> var;
        if (var == "blank") {
            break;
        }
        input.push_back(var);
    }

    std::cout << resistorCode(input);
 }