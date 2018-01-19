/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: james
 *
 * Created on 12 janvier 2018, 08:40
 */

#include <cstdlib>
#include "Corrector.h"
#include "DicoHashMap.h"

using namespace std;

int main(int argc, char** argv) {

    /*std::cout << "Starto !" << std::endl;
    // chargement du dico
    Corrector<DicoHashMap<std::string>> c("MON_DICO.txt");
    
    std::cout << "Starto correcto!" << std::endl;
    c.test("MON_TEXTE.txt");*/
    //Corrector<DicoHashMap<std::string>> c("dictionary.txt"); 
    const std::string DICO = "dictionary.txt"; 
    const std::string LATES = "input_lates.txt"; 
    const std::string SH = "input_sh.txt"; 
    const std::string SIMPLE = "input_simple.txt"; 
    const std::string WIKIPEDIA = "input_wikipedia.txt"; 
    
    
    Corrector<DicoHashMap<std::string>> c(DICO);
    
    c.test(SH);
    
    //c.test(WIKIPEDIA);
    
    
     /*
    //initialisation du correcteur 
    Corrector<DicoHashMap<std::string>> corrector_HashMap(DICO); 
    //Corrector<DicoTST<std::string>> corrector_TST(DICO); 
     
    // Correction 
    // DicoHashMap 
    std::cout << "Hash map:" << std::endl; 
    corrector_HashMap.test(LATES); 
    // corrector_HashMap.test(SH);  // TO not work (On doit traité les '
    corrector_HashMap.test(SIMPLE); 
    corrector_HashMap.test(WIKIPEDIA); 
    std::cout << std::endl; 
     
    // DicoTST 
    /*std::cout << "Hash map:" << std::endl; 
    corrector_TST.test(LATES); 
    corrector_TST.test(SH); 
    corrector_TST.test(SIMPLE); 
    corrector_TST.test(WIKIPEDIA);*/ 
    
    
    return 0;
}

