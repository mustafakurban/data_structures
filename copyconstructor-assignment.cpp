//copy assigment praticles
//date		: 26/11/21 
//author	: mustafa kurban

#include <iostream>

namespace uiuc{
	class Cube{
		public:
			void setLength(int _length);
			int  getLength();
			//constructor
			Cube();
			//copy constructor
			Cube(const Cube & obj);
			//copy assignment
			Cube & operator=(const Cube & obj);

		private:
			int _length;
			
	};
	
	void Cube::setLength(int _length){this->_length = _length;}
	int  Cube::getLength(){return this->_length;}
	Cube::Cube()
	{
		//initialize the default value of the _length variable to 0
		std::cout << "constructor invoked!\n";
		_length = 0;
	} 

	Cube::Cube(const Cube & obj)
	{
		//this section is execute that while want to copy this object to another object
		std::cout << "copy constructor invoked\n";
	}
	Cube & Cube::operator=(const Cube & obj)
	{
		//this part will be executed, if you want to copy this object to another object, if you use '=' assignment
		std::cout << "copy assignment invoked\n";
		return *this;
	}



}

int main()
{
	uiuc::Cube c;
	
	c.setLength(5);
	std::cout << "get number : " << c.getLength() << std::endl;

	//trigger the copy constructor
	uiuc::Cube c_ = c; 

	std::cout << "get number c_ : " << c_.getLength() << std::endl;

	c_ = c;

 	std::cout << "get number c_(after use copy assignment) : " << c_.getLength() << std::endl;


}


