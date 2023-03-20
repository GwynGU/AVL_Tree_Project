#ifndef AVLNODE_H
#define AVLNODE_H

#include <iostream>
#include <limits>
#include <string>
#include <queue>
#include <array> 
#include <cmath>
using namespace std;
using std::cout;
using std::cin;
using std::endl;
using std::fstream;
using std::istream;
using std::ostream;
using std::string;

template <typename T>
class AVLNode{
    private:
        T data;
        int height;
        AVLNode<T>* left;
        AVLNode<T>* right;
    public:
        AVLNode(T newData, int newHeight = 0){
            this->data = newData;
			this->left = nullptr;
			this->right = nullptr;
            this->height = newHeight;
        }
        ~AVLNode(){
            this->left = nullptr;
            this->right = nullptr;
            this->height = 0;
        }
        void setHeight(int newHeight){
            height = newHeight;
        }
        void setLeft(AVLNode<T>* newNode){
            left = newNode;
        }
        void setRight(AVLNode<T>* newNode){
            right = newNode;
        }
        void setData(T newData){
            data = newData;
        }
        AVLNode<T>* getLeft() const{
            return left;
        }
         AVLNode<T>* getRight() const{
            return right;
        }
        T getData() const{
            return data;
        }
        int getHeight() const{
            return height;
        }

};





#endif