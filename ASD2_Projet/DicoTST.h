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
    
    DicoTST(){
        dictionary = TernarySearchtree();
    }
    
    bool contains(std::string& word){
        return dictionary.contains(word);
    }
    void insert(std::string& word) {
        dictionary.insert(word);
    }
private:
    TernarySearchtree dictionary;
};

#endif /* DICOTST_H */

