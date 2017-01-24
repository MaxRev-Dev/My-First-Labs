#pragma once
template <typename type>
class writer
{
private:
public:
	writer();
	void w(const type&);
};
template <typename type>
writer<type>::writer() {
	std::cout ;
}


template <typename type>
void writer<type>::w(const type& str) {
	std::cout<<  str << endl;
}