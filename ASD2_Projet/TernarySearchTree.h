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
    /**
     * Insertion d'une string dans le TST
     * @param key string à insérer
     */
    void insert(std::string& key){
        root = put(root, key);
    }
    
    /**
     * Insertion d'une string char par char dans le TST
     * @param x     racine d'insértion
     * @param key   contient la string à insérer
     * @param d     position du caractère courant à insérer
     * @param val   valeur qui indique la fin du mot
     * @return      racine du TST après rebalançage
     */
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
    
    /**
     * 
     * @param x 
     * @return difference de hauteur entre droit et gauche
     */
    int balance(Node* x){
        return x == nullptr ? 0 : height(x->right) - height(x->left);
    }
    
    /**
     * Restauration par rotation simple ou double
     * @param x     Noeud de départ
     * @return      racine du TST après rebalançage
     */
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
    
    /**
     * Effecture une rotation à droite
     * @param x  Noeud de base
     * @return   Nouveau neaud de base
     */
    Node* rotateRight(Node* x){
        Node* x1 = x->left;
        x->left = x1->right;
        x1->right = x;
        
        updateNodeHeight(x);
        updateNodeHeight(x1);
        
        return x1;
    }
    
     /**
     * Effecture une rotation à gauche
     * @param x  Noeud de base
     * @return   Nouveau neaud de base
     */
    Node* rotateLeft(Node* x){
        Node* x1 = x->right;
        x->right = x1->left;
        x1->left = x;
        
        updateNodeHeight(x);
        updateNodeHeight(x1);
        
        return x1;
    }
    
    
public:
    /**
     * Indique si un string est contenu dans le TST
     * @param s     Chaine à rechercher
     * @return      true si la chaine est dans le TST, autrement false
     */
    bool contains(std::string& s){
        // std::cout << "Get key: " << s << std::endl;
        Node* x = contains(root, s, 0);
        return !(x == nullptr || x->isWord != true);
    }
private:
    /**
     * Indique si un string est contenu dans le TST
     * @param s     Chaine à rechercher
     * @return      true si la chaine est dans le TST, autrement false
     */
    Node* contains(Node* x, std::string& key, int d){
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
    /**
     * Indique la heuteur d'un noeud
     * @param x Noeud 
     * @return  Hauteur
     */
    int height(Node* x){
        if( x == nullptr ) return -1;
        
        return x->nodeHeight;
    }
private:
    /**
     * Met à jour la hauteur d'un noeud
     * @param x Noeud à mettre à jour
     */
    void updateNodeHeight(Node* x){
        x->nodeHeight = std::max(height(x->right), height(x->left)) + 1;
    }
  
    
    // Fonction de test si un arbre est balancé inspiré de :
    // https://www.geeksforgeeks.org/how-to-determine-if-a-binary-tree-is-balanced/
public:
    /**
     * Indique si l'arbre est balancé à partir de sa racine
     * @return true si balancé, autrement false
     */
    bool isBalanced(){
        return isBalanced(root);
    }
private: 
    /**
     * Indique si l'arbre est balancé à partir d'un noeud
     * @param x Noeud de départ
     * @return true si balancé, autrement false
     */
    bool isBalanced(Node* x)
    {
       int lh; /* for height of left subtree */
       int rh; /* for height of right subtree */ 

       /* If tree is empty then return true */
       if(x == nullptr)
        return 1; 

       /* Get the height of left and right sub trees */
       lh = height(x->left);
       rh = height(x->right);

       if( abs(lh-rh) <= 1 &&
           isBalanced(x->left) &&
           isBalanced(x->right))
         return 1;

       /* If we reach here then tree is not height-balanced */
       return 0;
    }
};
#endif /* TERNARYSEARCHTREE_H */

