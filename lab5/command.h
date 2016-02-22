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
		root = new Op(val);
};

class AddCommand : public Command {
	//AddCommand Code Here
	public:
	AddCommand(Command* root, double val){
		Base* value = new Op(val);
		Base* newroot = new Add(root->get_root(), value);
		this->root = newroot;
	}
};

class SubCommand : public Command {
	//SubCommand Code Here
	public:
	SubCommand(Command* root, double val){
		Base* newroot = new Sub;
		newroot->right = new Op(val);
		newroot.left = root;
		this->root = newroot;
	}
};

class MultCommand : public Command {
	//MultCommand Code Here
	public:
	MultCommand(Command* root, double val){
		Base* newroot = new Mult;
		newroot->right = new Op(val);
		newroot.left = root;
	}
};

class SqrCommand : public Command {
	//SqrCommand Code Here
	public:
	SqrCommand(Command* root, double val){
		Base* newroot = new Sqr;
		newroot.child = root;
	}
};

#endif //__COMMAND_CLASS__
