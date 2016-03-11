#ifndef __Visitor_CLASS__
#define __Visitor_CLASS__
#include <iostream>
#include "composite.h"
#include "iterator.h"
#include <string>
#include <sstream>
using namespace std;

class Base;
class Op;
class Iterator;
class PreOrderIterator;

class Visitor {
	public:
	virtual void rootNode()=0;
	virtual void sqrNode()=0;
	virtual void multNode()=0;
	virtual void subNode()=0;
	virtual void addNode()=0;
	virtual void opNode(Op* op)=0;
	virtual void execute()=0;
};

class PrintVisitor : public Visitor {
	private:
	string output;
	public:
	PrintVisitor();
	void rootNode();
	void sqrNode();
	void multNode();
	void subNode();
	void addNode();
	void opNode(Op* op);
	void execute();
};

#endif 
