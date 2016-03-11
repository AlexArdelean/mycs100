#include "visitor.h"


//=------------------------
//PrintVisitor
PrintVisitor::PrintVisitor(){
	output = "";
}
void PrintVisitor::rootNode(){
	return;
}
void PrintVisitor::sqrNode(){
	output += "^ ";
}
void PrintVisitor::multNode(){
	output += "* ";
}
void PrintVisitor::subNode(){
	output += "- ";	
}
void PrintVisitor::addNode(){
	output += "+ ";
}
void PrintVisitor::opNode(Op* op){
	ostringstream ss;
	ss << (int)op->evaluate();
	output += ss.str(); 
	output += " ";
}
void PrintVisitor::execute(){ 
	cout << output;
}


