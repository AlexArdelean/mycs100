#ifndef __COMMAND_CLASS__
#define __COMMAND_CLASS__

#include "composite.h"


class Command {
	protected:
		Base* root;
	
	public:
		Command() { };
		double execute() {
			return root->evaluate();
		};
		Base* get_root() {
			return root;
		};
};

class OpCommand : public Command {
	//OpCommand Code Here
	public:
	OpCommand(double val){
		delete root;
		root = new Op(val);
};

class AddCommand : public Command {
	//AddCommand Code Here
	public:
	AddCommand(Command* root, double val){
		this->root = new Add(root->get_root(), new Op(val));
	};
};

class SubCommand : public Command {
	//SubCommand Code Here
	public:
	SubCommand(Command* root, double val){
		this->root= new Sub(root->get_root(), new Op(val));
	};
};

class MultCommand : public Command {
	//MultCommand Code Here
	public:
	MultCommand(Command* root, double val){
		this->root = new Mult(root->get_root(), new Op(val));
	};
};

class SqrCommand : public Command {
	//SqrCommand Code Here
	public:
	SqrCommand(Command* root){
		this->root = new Sqr(root->get_root());
	};
};

#endif //__COMMAND_CLASS__
