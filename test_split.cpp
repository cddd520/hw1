/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include "iostream"
using namespace std;

int main(int argc, char* argv[])
{
  // create test case

  Node* node1 = new Node(1, nullptr);
  Node* node2 = new Node(2, nullptr);
  node1 -> next = node2;
  Node* node3 = new Node(3, nullptr);
  node2 -> next = node3;
  Node* node4 = new Node(4, nullptr);
  node3 -> next = node4;
  Node* node5 = new Node(5, nullptr);
  node4 -> next = node5;
  // print the original list
  Node* temp = node1;
  while (temp != nullptr)
  {
    cout << temp -> value << endl;
    temp = temp -> next;
  }
  // create node for odds and evens
  Node* odds = nullptr;
  Node* evens = nullptr;

  cout << "----------------" << endl;
  // use the function split
  split(node1, odds, evens);

  // print odds and evens
  Node* tempOdd = odds;
  while (tempOdd != nullptr)
  {
    cout << tempOdd -> value << endl;
    tempOdd = tempOdd -> next;
  }
  cout << "----------------" << endl;
  Node* tempEven = evens;
  while (tempEven != nullptr)
  {
    cout << tempEven -> value << endl;
    tempEven = tempEven -> next;
  }

  // delete and release memory
  while (odds != nullptr)
  {
    Node* temp = odds;
    odds = odds -> next;
    delete temp;
  }
  while (evens != nullptr)
  {
    Node* temp = evens;
    evens = evens -> next;
    delete temp;
  }


}
