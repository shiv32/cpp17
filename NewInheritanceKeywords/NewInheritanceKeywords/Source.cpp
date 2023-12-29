#include <iostream>


class Zip final {
public:
	Zip() {

	}
	void Compress(const std::string &filename) {

	}
	void Decompress(const std::string &filename) {

	}
	void PrintStatistics() {

	}
	/*
	Destructor is not virtual, therefore it is risky to 
	inherit from this class.

	Zip *p = new FastZip ;
	delete p ;

	This would call Zip destructor only. Therefore, the destructor 
	of FastZip will not execute & it will not be able to release
	any resources
	*/
	~Zip() {
		//release resources
	}
};

//class FastZip : public Zip { //Cannot inherit from a final class
//
//};

#pragma region Override
class Document {
public:
	virtual void Serialize(float version) = 0;
};
class Text : public Document {
public:
	void Serialize(float version)override final{
		std::cout << "Text::Serialize" << std::endl;
	}
};
class RichText : public Text {
public:
	//Cannot override because the function is final in base    
	/*void Serialize(float version)override {
		std::cout << "RichText::Serialize" << std::endl;
	}*/
};

class XML : public Document {
public:
	void Serialize(float version)override {
		std::cout << "XML::Serialize" << std::endl; 
	}
};

void Write(Document *p) {
	p->Serialize(1.1f);
}
#pragma endregion

int main() {
	XML xml;
	Write(&xml);
	return 0;
}