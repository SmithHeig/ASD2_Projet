/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DicoHashMap.h
 * Author: dname
 *
 * Created on January 12, 2018, 9:41 AM
 */

#ifndef DICOHASHMAP_H
#define DICOHASHMAP_H

#include <unordered_set>
#include <unordered_map>

template <typename T>
class DicoHashMap {
public:
    
    DicoHashMap(){
        dictionary = std::unordered_set<T>();
    }
    
    bool contains(T word){
        return (dictionary.find(word) != dictionary.end());
    }
    void insert(T word) {
        dictionary.insert(word);
    }
private:
    std::unordered_set<T> dictionary;
};

#endif /* DICOHASHMAP_H */

