#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
std::string find_vowels(std::string word) {
  std::string vowels = "aeiou";
  //remove vowels that are not in word, then return that
  for (int v = 0; v < vowels.size();v++){
    bool remove = true;
    for (char i : word) {
      if (i == vowels[v]) {
        remove = false;
        break;
      }
    }
    if (remove) {
      vowels.erase(std::remove(vowels.begin(), vowels.end(), vowels[v]), vowels.end());
      v--;
    }
  }
  std::cout<< word << ": " << vowels << '\n';
  return vowels;
}


std::vector<std::string> sameVowelGroup(std::vector<std::string> words) {
  std::vector<std::string> vowel_group = {};
  vowel_group.push_back(words[0]);
  std::string master_v = find_vowels(words[0]);
  for (int i = 1; i < words.size(); i++) {
    if (master_v == find_vowels(words[i])) {
      vowel_group.push_back(words[i]);
    }
  }
  return vowel_group;
}