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

template <typename T>
class DicoHashMap {
public:
    
    DicoHashMap(){
        //dictionary = std::unordered_set<T>();
    }
    
    bool contains(T word){
        return false; //(dictionary.find(word) != dictionary.end);
    }
    void insert(T word) {
        //dictionary.insert(word);
    }
private:
    //std::unordered_set<T> dictionary;
};

#endif /* DICOTST_H */
