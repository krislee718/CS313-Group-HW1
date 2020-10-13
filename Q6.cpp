#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <cmath> 
#include "VigCipher.h"
using namespace std;

int main() {

    vector<VCencrypt> myTrials;// we use vector to create multiple objects of our VigCipher class

    for (int i = 0; i < 10; i++){
        myTrials.push_back(VCencrypt());// we create 10 objects and use push_back to add it to the last position
    }

    return 0;
}