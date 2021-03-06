/* Drew Bozarth | Thomas Gooding
2373658 | 2373468
dbozarth@chapman.edu | tgooding@chapman.edu
CPSC 350-02
Assignment 6 - bst.h */

//these are the header guards
#ifndef BST_H
#define BST_H
//these include some of the system defined libraries in C++
#include <iostream>
#include <exception>
#include <fstream>
//standard namespace libaray in C++
using namespace std;

/*
Template Class: TreeNode
*/
template <class T>
class TreeNode{
  public:
    TreeNode();
    TreeNode(T* key);
    virtual ~TreeNode();

    T* key; //key = data
    TreeNode<T> *left;
    TreeNode<T> *right;
};

template <class T>
TreeNode<T>::TreeNode(){
  left = NULL;
  right = NULL;
  key = NULL;
}

template <class T>
TreeNode<T>::TreeNode(T* k){
  left = NULL;
  right = NULL;
  key = k;
}

template <class T>
TreeNode<T>::~TreeNode(){
  left = NULL;
  right = NULL;
}

/*
Template Class: BST
*/
template <class T>
class BST{
  public:
    //BST functions
    //all T objects/values were changed to pointers in order to fit with Student and Faculty classes
    BST();
    virtual ~BST();
    void insert(T* value);
    bool contains(T* value); //search
    bool deleteNode(T* k);
    bool isEmpty();
    T* find(T* value);
    void printNode(T* value);
    T* getMin();
    T* getMax();
    TreeNode<T> *getSuccessor(TreeNode<T> *d); //d represents the node we are going to delete
    void printNodes();
    void recPrint(TreeNode<T> *node);
    void treeToString(string file);
    void recString(TreeNode<T> *node, string file);
  private:
    TreeNode<T> *root;

};

template <class T>
BST<T>::BST(){
  root = NULL;
}

template <class T>
BST<T>::~BST(){
  //build some character
  //and do a little research
}

template <class T>
void BST<T>::recPrint(TreeNode<T> *node){
  if (node == NULL){
    return;
  }
  cout << *(node->key) << endl;
  recPrint(node->left);
  recPrint(node->right);
}

template <class T>
void BST<T>::printNodes(){
  recPrint(root);
}
//writes the entire BST to a file in the proper format, takes in file name as a string
template <class T>
void BST<T>::recString(TreeNode<T> *node, string file){
  if (node == NULL) {
  return; }
  ofstream output;
  output.open(file, fstream::app);
  output << node->key->toFile() << endl;
  recString(node->left, file);
  recString(node->right, file);

}

template <class T>
void BST<T>::treeToString(string file){
  //allows easy access to print out entire tree
  recString(root, file);

}

template <class T>
bool BST<T>::isEmpty(){
  return (root == NULL);
}

template <class T>
T* BST<T>::find(T* value){
  if (isEmpty()){
    return NULL;
  }
  else{
    TreeNode<T> *current = root;
    while(*(current->key) != *(value)){
      if (*(current->key) > *(value)){
        current = current->left;
      }
      else{
        current = current->right;
      }

      if (current == NULL)
        return NULL;
    }
    return (current->key);
  }
}

template <class T>
void BST<T>::printNode(T* value){
  if (isEmpty()){
    return;
  }
  else{
    TreeNode<T> *current = root;
    while(*(current->key) != *(value)){
      if (*(current->key) > *(value)){
        current = current->left;
      }
      else{
        current = current->right;
      }

      if (current == NULL)
        return;
    }
    cout << *(current->key) << endl;
  }
}

template <class T>
T* BST<T>::getMin(){
  TreeNode<T> *current = root;
  if (isEmpty())
    return NULL;

  while (current->left != NULL){
    current = current->left;
  }
  return &(current->key);
}

template <class T>
T* BST<T>::getMax(){
  TreeNode<T> *current = root;
  if (isEmpty())
    return NULL;

  while (current->right != NULL){
    current = current->right;
  }
  return &(current->key);
}

template <class T>
void BST<T>::insert(T* value){
  TreeNode<T> *node = new TreeNode<T>(value);
  if (isEmpty()){
    root = node;
  }
  else{
    //tree is not empty, let's go find the insertion point for node
    TreeNode<T> *current = root;
    TreeNode<T> *parent = NULL;

    while (true){
      parent = current;

      if (*(current->key) > *(value)){
        current = current->left;
        if (current == NULL){
          //we found the insertion point
          parent->left = node;
          break;
        }
      }
      else{
        current = current->right;
        if (current == NULL){
          //found the insertion point
          parent->right = node;
          break;
        }
      }
    }
  }
}

template <class T>
bool BST<T>::contains(T* value){
  if (isEmpty()){
    return false;
  }
  else{
    //it's not empty, let's try and find it
    TreeNode<T> *current = root;
    if (*(current->key) == *(value)){
      return true;
    }
    while(*(current->key) != *(value)){
      if (*(current->key) > *(value)){
        current = current->left;
      }
      else{
        current = current->right;
      }

      if (current == NULL){
        return false;
      }
    }
    return true;
  }
}

template <class T>
bool BST<T>::deleteNode(T* k){

  if(!contains(k))
    return false;

  //if we get here, we need to find it and set our pointers
  TreeNode<T> *current = root;
  TreeNode<T> *parent = root;
  bool isLeft = true;

  while(*(current->key) != *(k)){
    parent = current;

    if(*(current->key) > *(k)){
      isLeft = true;
      current = current->left;
    }
    else{
      isLeft = false;
      current = current->right;
    }
    if(current == NULL)
      return false;
  }

  //if we make here, we found the note, now let's proceed to delete

  /* no children, node to be deleted is a leaf*/
  if(current->left == NULL && current->right == NULL){
    if(current == root)
      root = NULL;
    else if(isLeft)
      parent->left = NULL;
    else
      parent->right = NULL;
  }
  else if (current->right == NULL){
    //has one child and it's left child
    if(current == root)
      root = current->left;
    else if(isLeft)
      parent->left = current->left;
    else
      parent->right = current->left;
  }
  else if (current->left == NULL){
    //has one child and it's right child
    if(current == root)
      root = current->right;
    else if(isLeft)
      parent->left = current->right;
    else
      parent->right = current->right;

  }
  else{
    /*node to be deleted has two children*/
    TreeNode<T> *successor = getSuccessor(current);

    if (current == root)
      root = successor;
    else if (isLeft)
      parent->left = successor;
    else
      parent->right = successor;

    successor->left = current->left;
    current->left = NULL;
    current->right = NULL;
  }
  return true;
}

template <class T>
/* d represents the node to be deleted */
TreeNode<T>* BST<T>::getSuccessor(TreeNode<T> *d){
  TreeNode<T> *sp = d; //successors parent
  TreeNode<T> *successor = d;
  TreeNode<T> *current = d->right;

  while(current != NULL){
    sp = successor;
    successor = current;
    current = current->left;
  }

  //all pointers should be in the correct locations

  /* check if successor is a descendant of the right child (d->right) */
  if (successor != d->right){
    sp->left = successor->right;
    successor->right = d->right;
  }
}


#endif
