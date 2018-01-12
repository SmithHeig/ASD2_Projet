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

/**
 * @class Corrector
 * @authors Allemand Adrien, Chatillon Jeremie and James Smith
 */
template <typename DicoType>
class Corrector {
private:
    DicoType dictionary;
    
public:
    /**
     * Constructor Corrector
     * @param dico_file_name nom du fichier représentant le dictionnaire
     */
    Corrector(std::string dico_file_name){
        // dictionaire ou stocker nos mots
        dictionary = DicoType();
        
        // extraction depuis le fichier et remplissage du dico
        std::ifstream file;
        
        file.open(dico_file_name);
        if(file){
            
            std::string word;
            word.clear();

            while(!file.eof()){
                word = getWord(file);
                dictionary.insert(word);
                word.clear();
            }
        }
    }
    
    
    
private:
    /**
     * Test l'ortho de fichier
     * @param test_file_name - nom du fichier à tester
     */
    void test(std::string test_file_name){
        std::ifstream file;
        
        file.open(test_file_name);
        
        if(file){
            std::string word;
            word.clear();
            
            while(!file.eof()){
                word = getWord(file);
                if(!dictionary.contains(word)){
                    testSupLetter(word);
                    testMissingLetter(word);
                    testWrongLetter(word);
                    testExchangeLetter(word);
                }
            }
        }
    }
    
    /**
     * Si mot non existant dans le dictionnaire, test si il y a pas une lettre
     *  supplementaire
     * @param word - mot à tester
     */
    void testSupLetter(std::string word){
        for(int i = 0; i < word.size(); ++i){
            std::string temp = word;
            if(dictionary.contains(temp.erase(i,1))){
#ifdef VERBOSE
                std::cout << " " << temp << std::endl;
#endif
            }
        }
    }
    
    /**
     * Si mot non existant dans le dictionnaire, test si il y a pas une lettre
     *  manquante
     * @param word
     */
    void testMissingLetter(std::string word){
        for(int i = 0; i < word.size(); ++i){
            std::string temp = word;
            for(char j = 'a'; 'a' <= 'z'; ++j){
                if(dictionary.contains(temp.insert(i,1,j))){
#ifdef VERBOSE
                    std::cout << " " << temp << std::endl;
#endif  
                }
            }
        }
    }
    
    /**
     * Si mot non existant dans le dictionnaire, test si il y a pas une lettre
     *  fausse
     * @param word
     */
    void testWrongLetter(std::string word){
        for(int i = 0; i < word.size(); ++i){
            std::string temp = word;
            for(char j = 'a'; 'a' <= 'z'; ++j){
                if(dictionary.contains(temp.replace(i,1,j))){
#ifdef VERBOSE
                    std::cout << " " << temp << std::endl;
#endif  
                }
            }
        }
    }
    
    /**
     * Si mot non existant dans le dictionnaire, test si il y a pas deux lettre
     *  inverser (une à coté de l'autre)
     * @param word
     */
    void testExchangeLetter(std::string word){
        for(int i = 0; i < word.size() - 1; ++i){
            std::string temp = word;
            std::swap(temp[i], temp[i+1]);
            if(dictionary.contains(temp)){
#ifdef VERBOSE
                std::cout << " " << temp << std::endl;
#endif  
            }
        }
    }
    
    /**
     * Recupère un mot dans un fichier et le format 
     * @param file
     * @return mot en minuscule avec que des l'etre et '
     */
    std::string getWord(std::ifstream file){
        std::string word;
        char x = file.get();
        x = tolower(x);
        while(x != ' '){
            if((x > 'a' && x < 'z') || (x == '\'' && word.size() > 1)){
                word += x;
            }
        }
        return word;
    }
};

#endif /* CORRECTOR_H */

