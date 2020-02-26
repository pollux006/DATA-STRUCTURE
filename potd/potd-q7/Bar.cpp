// your code here
#include "Bar.h"
using namespace potd;
Bar::Bar(std::string name) {
	Foo* f = new Foo(name);
	f_ = f;
}

Bar::Bar(const Bar& other) {
	Foo* f = new Foo(other.f_->get_name());
	f_ = f;
}
Bar::~Bar() {
	delete f_;
}
Bar& Bar::operator=(const Bar& other) {
	Foo* f = new Foo(other.f_->get_name());
	this->f_->~Foo();
	f_ = f;
	return *this;
}
std::string Bar::get_name() {
	return f_->get_name();
}
