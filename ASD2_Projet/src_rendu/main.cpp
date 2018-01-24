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
    
    // les différents dico a notre disposition
    // premièrement notre HashMAP de la STD  (unordered_set) avec insertion, recherche et suppression en O(1) en moyenne
    // c'est notre choix pour implémenter notre dictionnaire avec une structure de la STL car elle offre les meilleurs temps
    // à tout niveaux.
    Corrector<DicoHashMap<std::string>> corHM(DICO);
    
    // Celui-ci est notre implémentation du TST avec insertion, recherche et suppression en temps constant en moyenne
    Corrector<DicoTST> corTST(DICO);
    std::cout << "TST is balanced: " << corTST.isBalanced() << std::endl << std::endl;
    
    // pour finir une structure "BONUS" pour comparer avec les deux autres (celle-ci n'est pas en temps constant 
    // pourtant elle ne prends même pas 2 fois le temps des autres donc reste potable
    // Celui-ci a ses insertion, recherche et supression en O(log(n))
    // nous voulions comparer quelquechose en O(log(n)) avec nos 2 structures a temps constant
    Corrector<DicoSet<std::string>> corSET(DICO);
    
    
    
    // on test sur les différents fichiers :
    // on notera que les résultats sont donnés en microsecondes pour les tests contrairement
    // aux temps de chargement des dictionnaires qui sont donnés en milisecondes.
    // on remaque que le TST est très légèrement meilleur que le unordered_set mais que les deux sont largement meilleurs que le set.
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
    return 0;
}

