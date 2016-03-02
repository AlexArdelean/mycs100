#include "iterator.h"
//#include "composite.h"
//#include <iostream>

//using namespace std;

class Iterator{
	protected:
	Base* self_ptr;
	Base* current_ptr;
	public:
	Iterator(Base* ptr){this->self_ptr=ptr;}
	/*Setsuptheiteratortostartatthebeginningoftraversal*/
	virtual void first()=0;
	/*Moveontothenextelement*/
	virtual void next()=0;
	/*Returnsifyouhavefinishediteratingthroughallelements*/
	virtual bool is_done()=0;
	/*Returntheelementtheiteratoriscurrentlyat*/
	virtual Base* current()=0;
};



//The OperatorIterator will be used to iterate over composite nodes with two children. 
//This means it’s first will initialize to the left child, 
//and its next will cycle from left child (which is where it is set
//to start), to right child, then to NULL.
class OperatorIterator:public Iterator{
	public:
	OperatorIterator(Base* ptr);
	void first(){
		this->current_ptr = self_ptr->get_left();	
	};
	void next(){
		if (current_ptr == self_ptr->get_left())
			this->current_ptr = this->self_ptr->get_right();
		else if (current_ptr == self_ptr->get_right())
			this->current_ptr = NULL;
		else
			cout << "Trying to get next from a null pointer(Class OperatorIterator).\n";
	};
	bool is_done(){
		if (this->current_ptr = NULL)
			return true;
		else
			return false;
	};
	Base* current(){
		return this->current_ptr;
	};
};


//The UnaryIterator will be used to iterate over composite nodes 
//with one child (only Sqr in our case). 
//This means it’s first will initialize to the only child 
//(which has been redeclared in the composite class as the left child, 
//with Unary having no right child to make for an easier
//interface), and next will cycle from child (which is where it is set to start) to NU
class UnaryIterator:public Iterator{
	public:
	UnaryIterator(Base* ptr);
	void first(){
		this->current_ptr = this->self_ptr->get_left();
	};
	void next(){
		this->current_ptr = NULL;
	};
	bool is_done(){
		if (this->current_ptr == NULL)
			return true
		else
			return false;
	};
	Base* current(){
		return this->current_ptr;
	};
};


//The NullIterator is used to iterate over leaf nodes. 
//Since leaf nodes have no children, the
//NullIterator’s is_done() will always return true and it’s current() 
//will always return NULL. It’s first()
//and next() functions don’t need to do anything.

class NullIterator:public Iterator{
	public:
	NullIterator(Base* ptr);
	void first(){return;};
	void next(){return;};
	bool is_done(){return true;};
	Base* current(){
		Base* ptr = NULL;
		return ptr;
	};
};

//The PreOrderIterator has an additional stack data member, 
//which we will use to keep tack of the collection iterators that
//we need to traverse. The rest of the functions will be written as
//follows

class PreOrderIterator:public Iterator{
	protected:
	stack<Iterator*> iterators;
	public:
	PreOrderIterator(Base* ptr);
	void first();
	void next();
	bool is_done();
	Base* current();
};
/*



void PreOrderIterator::first(){
//Emptythestack(justincasewehadsomethingleftoverfrom
//anotherrun)
//CreateaniteratorfortheBase*thatwebuilttheiteratorfor
//Initializethatiteratorandpushitontothestack
}
void PreOrderIterator::next(){
//Createaniteratorfortheitemonthetopofthestack
//Initializetheiteratorandpushitontothestack
//Aslongasthetopiteratoronthestackisdone,popitoffthe
//stackandthenadvancewhateveriteratorisnowontopofthestack
}
bool PreOrderIterator::is_done(){
//Returntrueiftherearenomoreelementsonthestacktoiterate
}
Base* PreOrderIterator::current(){
//Returnthecurrentforthetopiteratorinthestack
}
*/
