/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DicoTST.h
 * Author: dname
 *
 * Created on January 12, 2018, 9:40 AM
 */

#ifndef DICOTST_H
#define DICOTST_H

#include "TernarySearchTree.h"


class DicoTST {
public:
    //
    // Constructor
    //
    DicoTST(){
        dictionary = TernarySearchtree();
    }
    
    /**
     * Regarde si une string est contenue dans le dico TST
     * @param word  mot à rechercher
     * @return      true si elle y est, sinon false
     */
    bool contains(std::string& word){
        return dictionary.contains(word);
    }
    
    /**
     * Sert à insérer un mot dans le TST
     * @param word  mot à insérer
     */
    void insert(std::string& word) {
        dictionary.insert(word);
    }
    
    /**
     * Indique si l'arbre est balancé
     * @return true is l'abre est balancé, sinon false
     */
    bool isBalanced(){
        return dictionary.isBalanced();
    }
    
    
    static std::string name(){
        return "TST";
    }
private:
    TernarySearchtree dictionary;
};

#endif /* DICOTST_H */

