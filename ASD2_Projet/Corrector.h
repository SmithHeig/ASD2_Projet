/* 
 * File:   Corrector.h
 * Author: Allemand Adrien, Chatillon Jeremie and James Smith
 *
 * Created on 12 janvier 2018, 09:18
 */

#ifndef CORRECTOR_H
#define CORRECTOR_H

#include <fstream>
#include <iostream>
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
        
        std::cout << "Chargement du dico !" << std::endl;
        
        // dictionaire ou stocker nos mots
        dictionary = DicoType();
        
        // extraction depuis le fichier et remplissage du dico
        std::ifstream file;
        
        file.open(dico_file_name);
        if(file){
            
            std::string word;
            //word.clear();

            while(!file.eof()){
                
                //std::cout << "DA" << std::endl;
                word = getWord(file);
                //std::cout << "DADA" << std::endl;
                
                //std::cout << word << std::endl;
                dictionary.insert(word);
                word.clear();
            }
        }
        file.close();
        
        std::cout << "End chargement du dico !" << std::endl;
    }
    
    /**
     * Test l'ortho de fichier
     * @param test_file_name - nom du fichier à tester
     */
    void test(std::string test_file_name){
        
        
        std::cout << "Start testing " << test_file_name << std::endl;
        std::ifstream file;
        
        file.open(test_file_name);
        
        std::string prefixFile = "corr_";
        std::string prefixWord = "*";
        
        std::ofstream fileCorr;
        fileCorr.open(prefixFile.append(test_file_name), std::ios::out);
                
        if(!fileCorr) {
            std::cout << "Could not open " << prefixFile.append(test_file_name) << std::endl;
            return;
        }
        
        if(file){
            std::string word;
            word.clear();
            
            while(!file.eof()){
                word = getWord(file);
                if(!dictionary.contains(word)){
                    
                    fileCorr << "*" << word << std::endl;
                    
                    testSupLetter(word, fileCorr);
                    testMissingLetter(word, fileCorr);
                    testWrongLetter(word, fileCorr);
                    testExchangeLetter(word, fileCorr);
                }
            }
        }
        file.close();
    }
    
private:
    /**
     * Si mot non existant dans le dictionnaire, test si il y a pas une lettre
     *  supplementaire
     * @param word - mot à tester
     */
    void testSupLetter(std::string word, std::ofstream& file){
        for(int i = 0; i < word.size(); ++i){
            std::string temp = word;
            if(dictionary.contains(temp.erase(i,1))){
#ifdef VERBOSE
                std::cout << " " << temp << std::endl;
#endif
                file << "1)" << word << std::endl;
            }
        }
    }
    
    /**
     * Si mot non existant dans le dictionnaire, test si il y a pas une lettre
     *  manquante
     * @param word
     */
    void testMissingLetter(std::string word, std::ofstream& file){
        for(int i = 0; i < word.size(); ++i){
            std::string temp = word;
            for(char j = 'a'; 'a' <= 'z'; ++j){
                if(dictionary.contains(temp.insert(i,1,j))){
#ifdef VERBOSE
                    std::cout << " " << temp << std::endl;
#endif  
                file << "2)" << word << std::endl;
                }
            }
        }
    }
    
    /**
     * Si mot non existant dans le dictionnaire, test si il y a pas une lettre
     *  fausse
     * @param word
     */
    void testWrongLetter(std::string word, std::ofstream& file){
        for(int i = 0; i < word.size(); ++i){
            std::string temp = word;
            for(char j = 'a'; 'a' <= 'z'; ++j){
                std::string str(1,j);
                if(dictionary.contains(temp.replace(i,1,str))){
#ifdef VERBOSE
                    std::cout << " " << temp << std::endl;
#endif  
                file << "3)" << word << std::endl;
                }
            }
        }
    }
    
    /**
     * Si mot non existant dans le dictionnaire, test si il y a pas deux lettre
     *  inverser (une à coté de l'autre)
     * @param word
     */
    void testExchangeLetter(std::string word, std::ofstream& file){
        for(int i = 0; i < word.size() - 1; ++i){
            std::string temp = word;
            std::swap(temp[i], temp[i+1]);
            if(dictionary.contains(temp)){
#ifdef VERBOSE
                std::cout << " " << temp << std::endl;
#endif  
                file << "4)" << word << std::endl;
            }
        }
    }
    
    /**
     * Recupère un mot dans un fichier et le format 
     * @param file
     * @return mot en minuscule avec que des l'etre et '
     */
    std::string getWord(std::ifstream& file){
        
        std::string word;
        file >> word;
        std::string properWord = "";
        for(int i = 0 ; i < word.size(); i++) {
            char x = tolower(word.at(i));
            
            if((x > 'a' && x < 'z') || (x == '\'' && word.size() > 1)){
                properWord += x;
            }
        }       
        return properWord;
    }
};

#endif /* CORRECTOR_H */

