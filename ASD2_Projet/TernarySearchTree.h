/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TernarySearchTree.h
 * Author: Jeremie
 *
 * Created on 17. janvier 2018, 13:43
 */

#ifndef TERNARYSEARCHTREE_H
#define TERNARYSEARCHTREE_H
#include <algorithm>
#include <string>
#include <random>



class TernarySearchtree {
private:
   
    struct Node {
    public:
        char key;
        bool isWord;
        Node* right; // sous arbre avec des cles plus grandes
        Node* left;  // sous arbre avec des cles plus petites
        Node* front; // sous arbre avec des clé coresspondantes
        
        int nodeHeight; // Nombre d'élément
        
        Node(char key) : key(key), isWord(false), right(nullptr), left(nullptr), front(nullptr), nodeHeight(1) { }
    };
    
    //
    // Racine de l'arbre.
    //
    Node* root;
    
    //
    // Constructeur. La racine est vide
    //
public:
    BinarySearchTree() : root(nullptr) { }
    
        
    //
    // Destructeur.
    //
public:
    ~BinarySearchTree() {
        deleteSubTree( root );
    }
private:
    void deleteSubTree(Node* x) {
        if( x == nullptr) return;
        deleteSubTree( x->right );
        deleteSubTree( x->front );
        deleteSubTree( x->left );
        delete x;
    }
    
public:
    void Node put(std::string* key){
        root = put(*root, key);
    }
    
    Node put(Node* x, std::string* key, int d = 0, bool val = true){
        char c = *(key + d);
        
        if(x == nullptr) 
            x = *(new Node(c));
        
        if( c < x.key)
            x.left = put(x.left, key, d);
        else if ( c < x.key)
            x.right = put(x.right, key, d);
        else if (d < (*key).size() -1)
            x->front = put(x->front, key, d+1);
        else
            x.isWord = val;
        
        return restoreBalance(x);
    }
    
    int balance(Node* x){
        if(x == nullptr) return 0;
        return height(x->right) - height(x->left);
    }
    
    Node* restoreBalance(Node* x){
        if(balance(x) < -1) { // right < left -1{
            if(balance(x->left) > 0)
                x->left = rotateLeft( x-> left);
            x = rotateRight(x);
        }
        else if( balance(x) > 1){
            if(balance(x->right) < 0 )
                x->right = rotateRight( x->right);
            x = rotateLeft(x);
        } else
            updateNodeHeight(x);
        return x;
    }
    
    Node* rotateRight(Node* x){
        Node* x1 = x->left;
        x->left = x1->right;
        x1->right = x;
        
        return x1;
    }
    
    Node* rotateLeft(Node* x){
        Node* x1 = x->right;
        x->right = x1->left;
        x1->left = x;
        
        return x1;
    }
    
//public:
//     void insert(std::string s){
//         Node* x = root;
//         
//        for(char& c : s){
//             x = insertChar(x, *c);
//        }
//         
//        x->isWord = true;
//        
//     }
//private:
//    Node* insertChar(Node* x, char key){
//        if(x == nullptr)
//            return new Node(key);
//        
//        if(key < x.key)
//            x = x.left;
//        else if(key > x->key)
//            x = x.right;
//        else // key == y->key
//            x = x.front;
//        
//        x->nodeSize = 1 + size(x->left) + size(x->right) + size(x->front);
//        
//        return x;
//    }
    
public:
    
    bool contains(std::string s){
        Node* x = root;
        auto i = s.begin();
        
        while ( x != nullptr ) {
            if ( *i < x->key )
                x = x->left;
            else if ( *i > x->key)
                x = x->right;
            else {// x->key == key.
                if(i == s.end())
                    return x->isWord;
                x = x->front;
                i++;
            }
            
        }
        return false;
    }
    
    
    
    //
    // Nombre d'elements
    //
public:
    int height(Node* x){
        if( x == nullptr ) return -1;
        
        return x->nodeHeight;
    }
private:
    void updateNodeHeight(Node* x){
        x->nodeHeight = max(height(x->right), height(x->left)) + 1;
    }
}



#endif /* TERNARYSEARCHTREE_H */

