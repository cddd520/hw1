#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::push_back(const std::string& val)
{
  // if the linked list is null then we have to initialize it
  if (tail_ == nullptr)
  {
    Item* newItem = new Item();
    tail_ = head_ = newItem;
    tail_->val[tail_->last] = val;
    tail_->last++;
  }
  // if we come to the last element of a single item then we have to create a new one
  else if (tail_->last == ARRSIZE)
  {
    Item* newItem = new Item();
    newItem->prev = tail_;
    tail_->next = newItem;
    tail_ = newItem;
    tail_->val[tail_->first] = val;
    tail_->last ++;
  }
  // simple implementation of just putting the string into spot
  else
  {
    tail_->val[tail_->last] = val;
    tail_->last ++;
  }
  // we have to increase the size because we got one more element
  size_++;
}

void ULListStr::push_front(const std::string& val)
{
  if (head_ == nullptr)
  {
    // we can use push_back for simplicity but remeber we have add one size here, the scope of size should be changed
    push_back(val);
  }
  // if we come to the start of the head item then create a new one
  else if (head_->first == 0)
  {
    Item* newItem = new Item();
    newItem->next = head_;
    head_->prev = newItem;
    head_ = newItem;
    head_->val[ARRSIZE - 1] = val;
    head_->last = ARRSIZE;
    head_->first = ARRSIZE - 1;
    size_++;
  }
  // put the string into right spot
  else
  {
    head_->val[head_->first -1] = val;
    head_->first --;
    size_++;
  }
}

void ULListStr::pop_front()
{
  // if list is null then return immediately
  if (head_ == nullptr)
  {
    return;
  }
  // move to the next node, soft deletion
  head_->first++;
  // see whether we need to release an Item is the array is clean
  if (head_->first == head_->last)
  {
    Item* deleteItem = head_;
    // we have to move to next first and delete original item
    head_ = head_->next;
    delete deleteItem;
    // see if the linked list is empty after deletion of element
    if (head_ == nullptr)
    {
      tail_ = nullptr;
    }
    else
    {
      head_->prev = nullptr;
    }
  }
  size_--;
}

void ULListStr::pop_back()
{
  if (tail_==nullptr)
  {
    return;
  }
  tail_->last--;
  if (tail_->last == tail_->first)
  {
    Item* deleteItem = tail_;
    tail_ = tail_->prev;
    delete deleteItem;
    // same logic as pop front
    if (tail_ == nullptr)
    {
      head_ = nullptr;
    }
    else
    {
      tail_ -> next = nullptr;
    }
  }
  size_--;
}

std::string const & ULListStr::back() const
{
  return tail_->val[tail_->last - 1];
}

std::string const & ULListStr::front() const
{
  return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const
{
  // when loc >= size_, we know we are out of bounds
  if (loc >= size_)
  {
    return nullptr;
  }
  // we want to set a point of current item
  Item* currentItem = head_;
  int passElement = 0; // how many element we pass

  // into the loop, to the last Item
  while (currentItem != nullptr)
  {
    int elementItem = currentItem->last - currentItem->first; // record the number of elements in current Item
    // see whether we are in the currentItem, because we are moving elementItem each time
    if (loc < elementItem + passElement)
    {
      int temp = loc - passElement; // get to the distance from start of current Item
      int index = temp + currentItem->first; // start + distance
      return &currentItem->val[index];
    }
    // add elementItem mentioned before, and move to next Item
    passElement += elementItem;
    currentItem = currentItem->next;
  }
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
