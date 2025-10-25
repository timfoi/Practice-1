#include <iostream>
#include <limits.h>
bool ispith(unsigned a,unsigned b,unsigned c);
int main(){
	using u_t = unsigned;
	unsigned max = UINT_MAX;
	u_t a = 0, b=0, c=0;
	std::cin>>c>>b;
	size_t k = 0;
	while(std::cin>>a){
		c = b;
		b = a;
		if (a > max/a || b > max/b || c < max/c|| k>max){
			std::cerr<<"Overflow err \n";
			return 2;
		}
		k += ispith(a,b,c)?1:0;
	}
	if (std::cin.eof()){
		std::cout<<k;
		std::cout<<"\n";
	}
	else if(std::cin.fail()){
		std::cerr<<"Input err \n";
		return 1;
	}
}

bool ispith(unsigned a,unsigned b,unsigned c){
	bool p = a*a == b*b+c*c;
	p = p||b*b == a*a+c*c;
	p = p || c*c == a*a+b*b;
	return p;
}