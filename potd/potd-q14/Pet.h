// Pet.h
#pragma once
#include <string>
#include "Animal.h"

using namespace std;

class Pet:public Animal{
    public:
    Pet();
    Pet(string type, string food,string name,string onwername);
    string getName();
    string getOwnerName();
    string print();
    void setName(string name);
    void setOwnerName(string ownername);

    private:
    string name_;
    string owner_name_;



};