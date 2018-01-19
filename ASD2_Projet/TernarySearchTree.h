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
        
        int nodeSize; // Nombre d'élément
        
        int nodeSize; // taille du sous-arbre dont ce noeud est la racine.
        Node(char key) : key(key), isWord(false), right(nullptr), left(nullptr), front(nullptr), nodeSize(1) { }
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
        
        return x;
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
    int size() {
        return size(root);
    }
private:
    int size(Node* x) {
        return ( x == nullptr ) ? 0 : x->nodeSize;
    }
}



#endif /* TERNARYSEARCHTREE_H */

