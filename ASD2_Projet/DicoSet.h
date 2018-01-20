/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DicoSet.h
 * Author: dname
 *
 * Created on January 19, 2018, 3:07 PM
 */

#ifndef DICOSET_H
#define DICOSET_H

#include <set>

template <typename T>
class DicoSet {
public:
    
    DicoSet(){
        dictionary = std::set<T>();
    }
    
    bool contains(T word){
        return (dictionary.find(word) != dictionary.end());
    }
    void insert(T word) {
        dictionary.insert(word);
    }
    
    static std::string name(){
        return "Dico using set";
    }
private:
    std::set<T> dictionary;
};

#endif /* DICOSET_H */

