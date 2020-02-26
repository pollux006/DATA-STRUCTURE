// Pet.cpp
#include "Pet.h"
#include "Animal.h"
using namespace std;


Pet::Pet():Animal("cat","fish"){
    name_ = "Fluffy";
    owner_name_ = "Cinda";
}

Pet::Pet(string type, string food,string name,string ownername):Animal(type,food){
    name_ = name;
    owner_name_ = ownername;

}
void Pet::setName(string name){
    name_ = name;

}

void Pet::setOwnerName(string ownername){
    owner_name_ = ownername;

}

string Pet::getName(){
    return name_ ;

}
string Pet::getOwnerName(){
    return owner_name_ ;

}



string Pet::print(){
    return "My name is " + name_;
}