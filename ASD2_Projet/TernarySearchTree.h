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
#include <math>



class TernarySearchtree {
private:
   
    struct Node {
    public:
        char key;    
        bool isWord; // indique si c'est la dernière lettre d'un mot
        Node* right; // sous arbre avec des cles plus grandes
        Node* left;  // sous arbre avec des cles plus petites
        Node* front; // sous arbre avec des clé coresspondantes
        
        int nodeHeight; // hauteur du noeud
        
        Node(char key) : key(key), isWord(false), right(nullptr), left(nullptr), front(nullptr), nodeHeight(0) { }
    };
    
    //
    // Racine de l'arbre.
    //
    Node* root;
    
    //
    // Constructeur. La racine est vide
    //
public:
    TernarySearchtree() : root(nullptr) { }
    
        
    //
    // Destructeur.
    //
public:
    ~TernarySearchtree() {
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
    void insert(std::string& key){
        //std::cout << "Insert key: " << key << std::endl;
        root = put(root, key);
    }
    
    Node* put(Node* x, std::string& key, int d = 0, bool val = true){
        char c = key.at(d);
        
        if(x == nullptr) 
            x = new Node(c);
        
        if( c < x->key)
            x->left = put(x->left, key, d);
        else if ( c > x->key)
            x->right = put(x->right, key, d);
        else if (d < key.size() -1)
            x->front = put(x->front, key, d+1);
        else
            x->isWord = val;
        
        return restoreBalance(x);
    }
    
    int balance(Node* x){
        if(x == nullptr)
            return 0;
        return height(x->right) - height(x->left);
    }
    
    Node* restoreBalance(Node* x){
        if(balance(x) < -1) { // right < left -1
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
        
        updateNodeHeight(x);
        updateNodeHeight(x1);
        
        return x1;
    }
    
    Node* rotateLeft(Node* x){
        Node* x1 = x->right;
        x->right = x1->left;
        x1->left = x;
        
        updateNodeHeight(x);
        updateNodeHeight(x1);
        
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
    bool contains(std::string& s){
        // std::cout << "Get key: " << s << std::endl;
        Node* x = get(root, s, 0);
        return !(x == nullptr || x->isWord != true);
    }
private:
    Node* get(Node* x, std::string& key, int d){
        if(x == nullptr) 
            return nullptr;
        
        char c = key.at(d);
        
        if( c < x->key)
            return get(x->left, key, d);
        else if ( c > x->key)
            return get(x->right, key, d);
        else if (d < key.length() - 1)
            return get(x->front, key, d+1);
        else
            return x;
            
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
        x->nodeHeight = std::max(height(x->right), height(x->left)) + 1;
    }
  
    /*
public:
    int checkHeight(){
        return che
    }
    
    int checkHeight(Node* x){
        if(abs(x.nodeHeight)
    }
     * */
};



#endif /* TERNARYSEARCHTREE_H */

