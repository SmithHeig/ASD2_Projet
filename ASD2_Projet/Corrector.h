/* 
 * File:   Corrector.h
 * Author: Allemand Adrien, Chatillon Jeremie and James Smith
 *
 * Created on 12 janvier 2018, 09:18
 */

#ifndef CORRECTOR_H
#define CORRECTOR_H

#include <fstream>
#include <cctype>
#include <string>
#include <algorithm>

#define VERBOSE 1

template <typename DicoType>
class Corrector {
private:
    DicoType dictionary;
    
public:
    
    Corrector(std::string dico_file_name){
        // dictionaire ou stocker nos mots
        dictionary = DicoType();
        
        // extraction depuis le fichier et remplissage du dico
        std::ifstream file;
        
        file.open(dico_file_name);
        if(file){
            
            std::string word;
            word.clear();
            char x;
            

            while(!file.eof()){
                x = file.get();
                x = tolower(x);
                while(x != ' '){
                    if(x > 'a' && x < 'z' || x == '\'' ){
                        word += x;
                    }
                }
                dictionary.insert(word);
                word.clear();
            }
        }
    }
    
    
    
private:
    void testSupLetter(std::string word){
        for(int i = 0; i < word.size(); ++i){
            std::string temp = word;
            if(dictionary.contain(temp.erase(i,1))){
#ifdef VERBOSE
                std::cout << " " << temp << std::endl;
#endif
            }
        }
    }
        
    void testMissingLetter(std::string word){
        for(int i = 0; i < word.size(); ++i){
            std::string temp = word;
            for(char j = 'a'; 'a' <= 'z'; ++j){
                if(dictionary.contain(temp.insert(i,1,j))){
#ifdef VERBOSE
                    std::cout << " " << temp << std::endl;
#endif  
                }
            }
        }
    }
    
    void testWrongLetter(std::string word){
        for(int i = 0; i < word.size(); ++i){
            std::string temp = word;
            for(char j = 'a'; 'a' <= 'z'; ++j){
                if(dictionary.contain(temp.replace(i,1,j))){
#ifdef VERBOSE
                    std::cout << " " << temp << std::endl;
#endif  
                }
            }
        }
    }
    
    void testExchangeLetter(std::string word){
        for(int i = 0; i < word.size() - 1; ++i){
            std::string temp = word;
            std::swap(temp[i], temp[i+1]);
            if(dictionary.contain(temp))){
#ifdef VERBOSE
                std::cout << " " << temp << std::endl;
#endif  
            }
        }
    }
    
    
};

#endif /* CORRECTOR_H */

