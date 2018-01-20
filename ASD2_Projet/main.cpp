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
#include "TernarySearchTree.h"
#include "DicoTST.h"
#include "DicoSet.h"

#define DICO "dictionary.txt"
#define LATES "input_lates.txt"
#define SH "input_sh.txt"
#define SIMPLE "input_simple.txt"
#define WIKIPEDIA "input_wikipedia.txt"

int main(int argc, char** argv) {

    /*std::cout << "Starto !" << std::endl;
    // chargement du dico
    Corrector<DicoHashMap<std::string>> c("MON_DICO.txt");
    
    std::cout << "Starto correcto!" << std::endl;
    c.test("MON_TEXTE.txt");*/
    //Corrector<DicoHashMap<std::string>> c("dictionary.txt"); 
    /*
    const std::string DICO = "dictionary.txt"; 
    const std::string LATES = "input_lates.txt"; 
    const std::string SH = "input_sh.txt"; 
    const std::string SIMPLE = "input_simple.txt"; 
    const std::string WIKIPEDIA = "input_wikipedia.txt"; 
    */
    
    // les différents dico a notre disposition
    Corrector<DicoHashMap<std::string>> corHM(DICO);
    Corrector<DicoTST> corTST(DICO);
    Corrector<DicoSet<std::string>> corSET(DICO);
    
    corHM.test(LATES);
    corTST.test(LATES);
    corSET.test(LATES);
    
    corHM.test(SIMPLE);
    corTST.test(SIMPLE);
    corSET.test(SIMPLE);
    
    corHM.test(SH);
    corTST.test(SH);
    corSET.test(SH);
    
    corHM.test(WIKIPEDIA);
    corTST.test(WIKIPEDIA);
    corSET.test(WIKIPEDIA);
    
    
    //c.test(WIKIPEDIA);
    
    
     /*
    //initialisation du correcteur 
    Corrector<DicoHashMap<std::string>> corrector_HashMap(DICO); 
    Corrector<DicoTST> corrector_TST(DICO);
    /*
    std::cout << "TST is balanced: ";
    std::cout<< std::boolalpha << corrector_TST.isBalanced();
    std::cout << std::endl << std::endl;
    */
    
    std::cout << "TST is balanced: " << corrector_TST.isBalanced() << std::endl << std::endl;
    
    // Correction 
    // DicoHashMap 
    std::cout << "Hash map:" << std::endl; 
    corrector_HashMap.test(LATES); 
    // corrector_HashMap.test(SH);  // TO not work (On doit traité les '
    //corrector_HashMap.test(SIMPLE); 
    //corrector_HashMap.test(WIKIPEDIA); 
    std::cout << std::endl; 
    
    // DicoTST 
    std::cout << std::endl << "TST test:" << std::endl;
    corrector_TST.test(LATES); 
    corrector_TST.test(SH); 
    corrector_TST.test(SIMPLE); 
    corrector_TST.test(WIKIPEDIA);*/ 
    
    
    Corrector<DicoTST> c2("myInput.txt");
    std::cout << "TST is balanced: " << c2.isBalanced() << std::endl << std::endl;
    std::cout << "Starto correcto!" << std::endl;
    bool val = c2.contain("jermie");
    std::cout << "1) " << (c2.contain("late")? true: false) << std::endl;
    std::cout << "2) " << (c2.contain("lates")? true: false) << std::endl;
    
    c2.test("myInputERR.txt");
    c2.test(LATES);
    
    
    return 0;
}

