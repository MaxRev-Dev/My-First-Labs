#pragma once
#include "classes.h"
template <class type>
class writer
{
public:
	writer();
	void w(const type&);
};

template <class type>
writer<type>::writer() {

};

template <class type>
void writer<type>::w(const type&str) {
	std::cout << str << endl;
};

