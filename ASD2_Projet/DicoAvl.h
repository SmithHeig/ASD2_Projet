/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DicoAvl.h
 * Author: dname
 *
 * Created on January 26, 2018, 7:55 AM
 */

#ifndef DICOAVL_H
#define DICOAVL_H


#include "AVLTree.h"

template <typename T>
class DicoAvl {
public:
    
    DicoAvl(){
        dictionary = AVLTree<T,T>();
    }
    
    bool contains(T word){
        return dictionary.contains(word);
    }
    void insert(T word) {
        dictionary.put(word, word);
    }
    
    static std::string name(){
        return "AVL";
    }
private:
    AVLTree<T,T> dictionary;
};

#endif /* DICOAVL_H */

