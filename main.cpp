#include <iostream>
int main(){
	using u_t = unsigned;
	u_t a = 0;
	size_t k = 0;
	while(std::cin>>a){
		k++;
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
