#include "AVLNode.h"


template <typename T>
class AVLTree{
    private:
        AVLNode<T>* root;

    protected:
        void destroyTreeHelper(AVLNode<T>* tree) {
			if (tree != nullptr){
				destroyTreeHelper(tree->getLeft());
				destroyTreeHelper(tree->getRight());
				delete tree;
			}
		}

        int containsHelper(AVLNode<T>* root, T value){
			int result = 0;
			if(value == root->getData()){
				result = 1;
			}
			else if(value > root->getData() && root->getRight() != nullptr){ 
				result = containsHelper(root->getRight(), value);
			}
			else if(value < root->getData() && root->getLeft() != nullptr){
				result = containsHelper(root->getLeft(), value);
			}
			return result; 
		}

        int heightHelper(AVLNode<T>* root) {
            if (root == nullptr) {
                return -1;
            }
            else {
                int leftHeight = heightHelper(root->getLeft());
                int rightHeight = heightHelper(root->getRight());
                if(leftHeight > rightHeight){
                    return 1 + leftHeight;
                }
                else{
                    return 1 + rightHeight;
                }
            }
        }

        void insertHelper(T newData, AVLNode<T>* root){ // DO NOT insert duplicates
            if(root == nullptr){
                root = new AVLNode<T>(newData);
            }
            else if(newData < root->getData()){
                insertHelper(newData, root->getLeft());
                if(abs(heightHelper(root->getLeft()) - heightHelper(root->getRight())) == 2){
                    if(newData < root->getLeft()->getData()){
                        rightRotate(root);
                    }
                    else{
                        leftRightRotate(root);
                    }
                }
            }
            else if(newData > root->getData()){
                insertHelper(newData, root->getRight());
                if(abs(heightHelper(root->getLeft()) - heightHelper(root->getRight())) == 2){
                    if(newData > root->getRight()->getData()){
                        leftRotate(root);
                    }
                    else{
                        rightLeftRotate(root);
                    }
                }
            }
        }

        void rightRotate(AVLNode<T>* x){
            AVLNode<T>* y = x->getLeft(), * z = x->getLeft()->getRight();
            y->setRight(x);
            x->setLeft(z);
        }

        void leftRotate(AVLNode<T>* x){
            AVLNode<T>* y = x->getRight(), * z = x->getRight()->getLeft();
            y->setLeft(x);
            x->setRight(z);
        }

        void leftRightRotate(AVLNode<T> * x){
            leftRotate(x->getLeft());
            rightRotate(x); 
        }

        void rightLeftRotate(AVLNode<T> * x){
            rightRotate(x->getRight());
            leftRotate(x); 
        }


    public:
        AVLTree(){
            this->root = nullptr;
        }

        ~AVLTree(){
            cout << "Destroying tree" << endl;
		    destroyTreeHelper(this->root);
		    delete this->root;
        }

        int height() {
		    return heightHelper(this->root);
	    }
    
        void insert(T newData){
            insertHelper(newData, this->root);
        }

        bool contains(T value) {
            int result = 0;
            if(this->root == nullptr){ // tree is empty
                result = 0;
            }
            else{
                result = containsHelper(this->root, value);
            }
            return result;
        }

        int validate(void){
            int result = 0, leftHeight = -1, rightHeight = -1;
            if(root == nullptr){
                result = 1;
            }
            else {
                if(root->getLeft() != nullptr){
                    leftHeight = heightHelper(root->getLeft());
                }
                if(root->getRight() != nullptr){
                    rightHeight = heightHelper(root->getRight());
                }
                if(abs(leftHeight - rightHeight) <= 1 ){
                    result = 1; // tree is balanced
                }
                else{
                    result = 0; // unbalanced
                }
            }
            return result;
        }



};