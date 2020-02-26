// Your code here!
#include	"Thing.h"

using namespace potd;

Thing::Thing(int i){
	props_ct_ = 0;
	props_max_ = i;
	properties_ = new std::string[i];
	values_ = new std::string[i];
}


Thing::Thing(const Thing & other){
	this->props_ct_ = other.props_ct_;
	this->props_max_ = other.props_max_;
	this->properties_ = new std::string[other.props_max_];
	this->values_ = new std::string[other.props_max_];
	for (int i =0;i<other.props_ct_;i++){
		this->properties_[i] = other.properties_[i];
		this->values_[i] = other.values_[i];
	}
}


Thing & Thing::operator=(const Thing & other){
	this->props_ct_ = other.props_ct_;
	this->props_max_ = other.props_max_;
	delete[] this->properties_;
	delete[] this->values_;
	this->properties_ = new std::string[other.props_max_];
	this->values_ = new std::string[other.props_max_];
	for (int i =0;i<other.props_ct_;i++){
		this->properties_[i] = other.properties_[i];
		this->values_[i] = other.values_[i];
	}
	return *this;
}

Thing::~Thing(){
	delete[] this->properties_;
	delete[] this->values_;
}


int Thing::set_property(std::string name ,std::string value){
	for (int i=0;i<this->props_ct_;i++){
		if( this->properties_[i] == name){
			values_[i] = value;
			return i;
		}
	}
	if (props_max_>props_ct_){
			properties_[props_ct_]=name;
			values_[props_ct_]=value;
			props_ct_++;
			return (props_ct_-1);
	}

	return -1;
}

std::string Thing::get_property(std::string name){
	for (int i =0;i<props_ct_;i++){
		if(properties_[i]==name){
			return values_[i];
		}
	}
	return "";
}
