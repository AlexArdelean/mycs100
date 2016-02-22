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
	OpCommand(double val){
	root = new Op(val);
};

class AddCommand : public Command {
	//AddCommand Code Here
	AddCommand(Command* root, double val){
		Base* newroot = new Add;
		newroot->right = new Op(val);
		newroot.left = root;
	}
};

class SubCommand : public Command {
	//SubCommand Code Here
	AddCommand(Command* root, double val){
		Base* newroot = new Sub;
		newroot->right = new Op(val);
		newroot.left = root;
	}
};

class MultCommand : public Command {
	//MultCommand Code Here
	AddCommand(Command* root, double val){
		Base* newroot = new Mult;
		newroot->right = new Op(val);
		newroot.left = root;
	}
};

class SqrCommand : public Command {
	//SqrCommand Code Here
	AddCommand(Command* root, double val){
		Base* newroot = new Sqr;
		newroot.child = root;;
	}
};

#endif //__COMMAND_CLASS__
