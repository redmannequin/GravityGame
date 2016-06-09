#ifndef LIST_H
#define LIST_H

template <class T>
class DList  {

  template <class V>
  friend string& operator<<(string&, DList<V>&);

  class Node {
    friend class DList<T>;

    template <class V>  
    friend string& operator<<(string&, DList<V>&);
    private:
      T       data;
      Node*   next;
      Node*   prev;
  };

  public:
    DList();
    ~DList();
    
    // getters
    int getSize();
    T& get(int);
    T& operator[](int);

    // add
    void add(T&);
    DList<T>& operator+=(T&);
    
    // remove
    void remove(T&);
    DList<T>& operator-=(T&);
  
  private:
    Node* head;
    int size;
};

template <class T>
DList<T>::DList() { 
  this->size = 0;
  this->head = 0;
}

template <class T>
DList<T>::~DList() {
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
void DList<T>::add(T& toAdd) {
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
DList<T>& DList<T>::operator+=(T& c) {
  this->add(c);
  return *this;
}

// remove
template <class T>
void DList<T>::remove(T& toRemove) {
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
DList<T>& DList<T>::operator-=(T& c) {
  this->remove(c);
  delete c;
  return *this;
}

// getters 
template <class T>
int DList<T>::getSize() { return this->size; }

template <class T>
T& DList<T>::get(int i) {
  if (i >= getSize()) exit(1);
  Node* currNode = this->head;
  while(i-- > 0) currNode = currNode->next;
  return currNode->data;
}

template <class T>
T& List::operator[](int) { return this->get(i); }

#endif
