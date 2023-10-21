/*
 * Filename: Stems and Leaves.cpp
 * Challenge link: https://edabit.com/challenge/9GipYjC8YSD3oaq3c
 * Functions used: Bubble sort, vector print, plot stem and leaf diagram
 */
 
#include <string>
#include <iostream>
#include <vector>

std::vector<int> order(std::vector<int> arr) {
  bool swap = true;
  while (swap) {
    swap = false;
    for (int i = 0; i < arr.size() - 1; i++) {
      if (arr[i] > arr[i+1]) {
        int copy = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = copy;
        swap = true;
      }
    }
  }

  return arr;
}


template <typename T>
void print_vector(std::vector<T> arr, std::string end = ",", std::vector<std::string> braces = {"{","}"}) {
  std::cout << braces[0] << arr[0];
  for (int i = 1; i < arr.size() - 1; i++) {
    std::cout << end << arr[i];
  }
  std::cout << end << arr[arr.size() - 1] << braces[1];
  std::cout << '\n';
}


std::vector<std::string> stemPlot(std::vector<int> raw_arr) {
  std::vector<std::string> diagram = {};
  std::vector<std::string> stems = {};
  std::vector<int> arr = order(raw_arr);
  
  //iterate through arr
  for (int i = 0; i < arr.size(); i++) {
    int stem = arr[i] / 10;
	int leaf = arr[i] % 10;

    std::string stem_str = std::to_string(stem);
    std::string leaf_str = std::to_string(leaf);
    //std::cout << "stem and leaf: " << stem_str << ' ' << leaf_str << '\n';

    /* iterate through stems
     * if stem already exists, the leaf will be added to that string, 
     * if not, it's  added at the end
     */
    diagram.push_back(stem_str + " | " + leaf_str);
    bool pop = false;
    for (int s_i = 0; s_i < stems.size(); s_i++) {
      if (stem_str == stems[s_i]) {
        pop = true;
        diagram.pop_back();
        diagram[s_i] += " " + leaf_str;
        break;
      }
    }

    //add to stems list
    if (!pop) {stems.push_back(stem_str);}
  }
  return diagram;
}




int main() {
  std::cout << "Enter (enter blank when finished): " << '\n';
    std::vector<int> input = {};
    std::string var = " ";

    while (true) {
        std::cin >> var;
        if (var == "blank") {
            break;
        }
        input.push_back(stoi(var));
    }
  print_vector(stemPlot(input), "\n", {"",""});
}