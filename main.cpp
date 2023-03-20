#include "AVLTree.h"
#include <algorithm>
#include <random>

int main(void){
    array<int, 50> sequence1; // ascending order (smallest --> largest)
    int k = 0;
    for(int i = 1; i < 100; i=i+2){
        sequence1.at(k) = i; 
        k++;
    }

    array<int, 50> sequence2; // descending order
    array<int, 50> sequence3; // random shuffle 
    k = 0;
    for(int i = 99; i > 0; i=i-2){
        sequence2.at(k) = i; 
        sequence3.at(k) = i; 
        k++;
    }
    auto rng = std::default_random_engine {};
    std::shuffle(std::begin(sequence3), std::end(sequence3), rng);

    AVLTree<int> tree1;
    AVLTree<int> tree2;
    AVLTree<int> tree3;
    for(int i = 0; i < 50; i++){ // insert each sequence into its own tree
        tree1.insert(sequence1.at(i));
        tree2.insert(sequence2.at(i));
        tree3.insert(sequence3.at(i));
    }
    cout << "Expected height: 5 " << endl;
    cout << "Height of tree 1: " << tree1.height() << endl; 
    cout << "Height of tree 2: " << tree2.height() << endl;
    cout << "Height of tree 3: " << tree3.height() << endl;


    cout << "result of validate on tree 1: " << tree1.validate() << endl;
    cout << "result of validate on tree 2: " << tree2.validate() << endl;
    cout << "result of validate on tree 3: " << tree3.validate() << endl;

    for (int i = 1; i <= 100; i++){
        if(tree1.contains(i) == 1 && i%2 == 0){
            cout << "My AVL tree implementation is wrong" << endl;
        }
        if(tree2.contains(i) == 1 && i%2 == 0){
            cout << "My AVL tree implementation is wrong" << endl;
        }
        if(tree3.contains(i) == 1 && i%2 == 0){
            cout << "My AVL tree implementation is wrong" << endl;
        }
    }
    return 0;
}