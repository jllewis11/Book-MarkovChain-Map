#pragma once
#include <fstream>
#include <vector>
#include <string>
#include <map>


#include <iostream>

#include "sanitize.h"

class BookBot {
private:
    std::map<std::string, std::vector<std::string>> markov_chain;

public:
    BookBot(const unsigned int seed);

    void readIn(const std::string & filename);
    bool isEndPunctuation(const char character);
    std::vector<std::string> getValues(const std::string & key);
    std::string generateSentence();
};


BookBot::BookBot(const unsigned int seed) {
  srand(seed);
}

bool BookBot::isEndPunctuation(char character) {
  if ((character == '.') || (character == '?') || (character == '!')) {
    return true;
  } else {
    return false;
  }
}

void BookBot::readIn(const std::string & filename) {
  std::string test;
  std::string old = "^";
  std::string punckey = "$";
  std::ifstream file;
  std::vector<std::string> word;

  file.open(filename);


  while (!file.eof()) {
    file >> test;
    sanitize(test);
    if (isEndPunctuation(test[test.size() - 1])) {

      std::string punctuation(1, test[test.size() - 1]);
      test = test.substr(0, test.size() -1);

      word.push_back(test);
      markov_chain[old] = word;

      word.push_back(punckey);
      markov_chain[punctuation] = word;


    } else {
      word.push_back(test);
      markov_chain[old] = word;
      old = test;
    }
  }
  file.close();
}

std::vector<std::string> BookBot::getValues(const std::string & key){
  return markov_chain[key];
}

std::string BookBot::generateSentence() {
  std::string sentence = "Hello";
  std::string word = "test";
  std::vector<std::string> list;
  std::string test = "$";
  std::string key;

  // while () {
  //
  // }

  sentence += word;



   return sentence;
 }
