#ifndef __Visitor_CLASS__
#define __Visitor_CLASS__



class Visitor {
	public:
	virtual void rootNode()=0;
	virtual void sqrNode()=0;
	virtual void multNode()=0;
	virtual void subNode()=0;
	virtual void addNode()=0;
	virtual void opNode(Op* op)=0;
	virtual void execute()=0;
}

class PrintVisitor : public Visitor {
	private:
	std::string output;
	public:
	void rootNode(){
		return;
	}
	void sqrNode(){
		output << "^ ";
	};
	void multNode(){
		output << "* ";
	};
	void subNode(){
		output << "- ";	
	};
	void addNode(){
		output << "+ ";
	};
	void opNode(Op* op){
		output << op->evaluate() << " ";
	};
	void execute(){ 
		cout << output;
	};
}










#endif 
