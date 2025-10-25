#include <iostream>
#include <limits.h>
bool isPyth(unsigned a,unsigned b,unsigned c);
bool isOverflowing(unsigned,unsigned, unsigned);
int main(){
	using u_t = unsigned;
	u_t a = 0, b=0, c=0;
	std::cin>>c>>b;
	size_t k = 0;
	while(std::cin>>a)
	{
		if (isOverflowing(a,b,c))
		{
			std::cerr<<"Overflow err\n";
			return 2;
		}
		c = b;
		b = a;
		k += isPyth(a,b,c)?1:0;
	}
	if (std::cin.eof())
	{
		std::cout<<k;
		std::cout<<"\n";
	}
	else if(std::cin.fail())
	{
		std::cerr<<"Input err\n";
		return 1;
	}
}

bool isPyth(unsigned a,unsigned b,unsigned c)
{
	bool p = (a*a == b*b+c*c);
	p = p || (b*b == a*a+c*c);
	p = p || (c*c == a*a+b*b);
	return p;
}

bool isOverflowing(unsigned a,unsigned b, unsigned c)
{
	unsigned max = UINT_MAX;
	bool p = (a>0 && max/a < a);
	p = p || (b>0 && max/b < b);
	p = p || (c>0 && max/c < c);
	p = p || (max-b*b < c*c);
	p = p || (max-a*a < c*c);
	p = p || (max-a*a < b*b);
	return p;
}