#include "iterator.h"

//-----------------------------
//OperatorIterator class

OperatorIterator::OperatorIterator(Base* ptr):Iterator(ptr){this->self_ptr=ptr;}
void OperatorIterator::first(){
	this->current_ptr = self_ptr->get_left();	
}
void OperatorIterator::next(){
	if (current_ptr == self_ptr->get_left())
		this->current_ptr = this->self_ptr->get_right();
	else if (current_ptr == self_ptr->get_right())
		this->current_ptr = NULL;
	else
		cout << "Trying to get next from a null pointer(Class OperatorIterator).\n";
}
bool OperatorIterator::is_done(){
	if (this->current_ptr == NULL)
		return true;
	else
		return false;
}
Base* OperatorIterator::current(){
	return this->current_ptr;
}

//----------------------------
//UnaryIterator::
UnaryIterator::UnaryIterator(Base* ptr):Iterator(ptr) {this->self_ptr=ptr;}
void UnaryIterator::first(){
	this->current_ptr = this->self_ptr->get_left();
}
void UnaryIterator::next(){
	this->current_ptr = NULL;
}
bool UnaryIterator::is_done(){
	if (this->current_ptr == NULL)
		return true;
	else
		return false;
}
Base* UnaryIterator::current(){
	return this->current_ptr;
}

//-----------------------------------
//NullIterator class


NullIterator::NullIterator(Base* ptr):Iterator(ptr) {this->self_ptr=ptr;}
void NullIterator::first(){return;}
void NullIterator::next(){return;}
bool NullIterator::is_done(){return true;};
Base* NullIterator::current(){
	Base* ptr = NULL;
	return ptr;
}

//---------------------------------
//PreorderIterator:Iterator

PreOrderIterator::PreOrderIterator(Base* ptr):Iterator(ptr){this->self_ptr=ptr;}
void PreOrderIterator::first(){
	this->iterators.empty();
	Iterator* iter = this->self_ptr->create_iterator(); 
	if (iter){
		iter->first();
		this->iterators.push(iter);
	}	
}

void PreOrderIterator::next(){
	Iterator* iter = this->iterators.top()->current()->create_iterator();
	iter->first();
	this->iterators.push(iter);
	while(this->iterators.size() > 1 && this->iterators.top()->is_done()){
		this->iterators.pop();
		this->iterators.top()->next();
	}
}

bool PreOrderIterator::is_done(){
	if (this->iterators.size() == 1 && iterators.top()->is_done())
		return true;
	else
		return false;
}

Base* PreOrderIterator::current(){
	if(this->iterators.size() > 0)
		return this->iterators.top()->current();
	else
		return NULL;
}


