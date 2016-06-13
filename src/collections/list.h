#ifndef LIST_H
#define LIST_H

template <class T>
class List  {

  class Node {
    friend class List<T>;
    private:
      T       data;
      Node*   next;
      Node*   prev;
  };

  public:
    List();
    ~List();
    
    // getters
    int getSize();
    T& get(int);
    T& operator[](int);

    // add
    void add(T&);
    List<T>& operator+=(T&);
    
    // remove
    void remove(T&);
    List<T>& operator-=(T&);
  
  private:
    Node* head;
    int size;
};

template <class T>
List<T>::List() { 
  this->size = 0;
  this->head = 0;
}

template <class T>
List<T>::~List() {
  Node* currNode = this->head;
  Node* nextNode;
  while (currNode != 0) {
    nextNode = currNode->next;
    delete currNode;
    currNode = nextNode;
  }
}

// add
template <class T>
void List<T>::add(T& toAdd) {
  Node* currNode;
  Node* prevNode;

  Node* newNode = new Node;
  newNode->data = toAdd;

  prevNode = 0;
  currNode = this->head;

  while (currNode != 0) {
    prevNode = currNode;
    currNode = currNode->next;
  }

  if (prevNode == 0) head = newNode;
  else prevNode->next = newNode;

  newNode->next  = 0;
  newNode->prev  = prevNode;

  ++(this->size);
}

template <class T>
List<T>& List<T>::operator+=(T& c) {
  this->add(c);
  return *this;
}

// remove
template <class T>
void List<T>::remove(T& toRemove) {
  Node* currNode = this->head;
  Node* prevNode = 0;

  while (currNode != 0) {
    if (currNode->data == toRemove) break;
    prevNode = currNode;
    currNode = currNode->next;
  }

  if (currNode == 0) return;
  
  if (prevNode == 0) {
    head = currNode->next;
    if(head != 0) head->prev = 0;
  } else {
    prevNode->next = currNode->next;
    if(currNode->next != 0) currNode->next->prev = prevNode;
  }  
  delete currNode;

  --(this->size);
}

template <class T>
List<T>& List<T>::operator-=(T& c) {
  this->remove(c);
  delete c;
  return *this;
}

// getters 
template <class T>
int List<T>::getSize() { return this->size; }

template <class T>
T& List<T>::get(int i) {
  if (i >= getSize()) exit(1);
  Node* currNode = this->head;
  while(i-- > 0) currNode = currNode->next;
  return currNode->data;
}

template <class T>
T& List::operator[](int i) { return this->get(i); }

#endif
