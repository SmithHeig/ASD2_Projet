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

template <typename DicoType>
class Corrector {
    
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
    
    DicoType dictionary;
};

#endif /* CORRECTOR_H */

