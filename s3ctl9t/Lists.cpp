#include <iostream>
#include"SList.cpp"
class Lists {
public:
	//init node
	Slist* init(char* buf) {
		Slist* sl = new Slist();
		sl->next = nullptr;
		sl->len = strlen(buf);
		sl->val = buf;
		return sl;
	}
	//add node
	Slist* add(Slist* sl, char* buf) {
		Slist* nsl = new Slist();
		nsl->next = nullptr;
		nsl->len = strlen(buf);
		nsl->val = buf;
		sl->next = nsl;
		
		return nsl;
	
	}
	//print all list (val)
	void print(Slist* sl, int i = 65) {
		
		while (sl != nullptr)
		{
			std::cout << (char)i <<" = " << sl->val<<std::endl;
			i++;
			sl = sl->next;
	} 
	
	}
	
};