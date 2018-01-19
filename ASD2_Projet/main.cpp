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

    std::cout << "Starto !" << std::endl;
    // chargement du dico
    Corrector<DicoHashMap<std::string>> c("dictionary.txt");
    
    std::cout << "Starto correcto!" << std::endl;
    c.test("input_late.txt");
       
    return 0;
}

