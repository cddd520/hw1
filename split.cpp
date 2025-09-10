/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  // base case
  if (in == nullptr)
  {
    return;
  }
  // parse the big problem into smaller problem, put the head into next position
  Node* temp = in;
  in = temp -> next;
  // recursive through smaller problem
  split(in, odds, evens);
  // add the head of odds or evens into front of these two lists
  if (temp->value % 2 == 1)
  {
    temp->next = odds;
    odds = temp;
  }
  else
  {
    temp->next = evens;
    evens = temp;
  }
  
}

/* If you needed a helper function, write it here */
