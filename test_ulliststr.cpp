#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"
using namespace std;

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  // initialize a list
  ULListStr* newList = new ULListStr();
  // push back the list
  newList->push_back("man");
  newList->push_back("what");
  newList->push_back("can");
  newList->push_back("I");
  newList->push_back("say");
  newList->push_back("Mamba");
  newList->push_back("Out");
  // try push_front
  newList->push_front("Hello, ");
  // check what is back and front
  cout << newList->back() << endl;
  cout << newList->front() << endl;
  // pop_front() and print it out
  newList->pop_front();
  cout <<newList->front() << endl;
  // pop_back() and print it out
  newList->pop_back();
  cout <<newList->back() << endl;

}
