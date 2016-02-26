#ifndef __MENU_CLASS__
#define __MENU_CLASS__

#include <iostream>
#include "command.h"

using namespace std;


class Menu {
	private:
		int history_index;
		vector<Command*> history;

	public:
		Menu() {
			//Base constructor to set up all necessary members
		};
		void execute() {
			//Prints the current commands value (based on history_index), if no commands exist
			//print 0 by default
			if (history.size() <= 0)
				cout << "0" << endl;
			else 
				cout << history.at(history_index)->execute() << endl;			
		};
		bool initialized() {
			//Return true if the history has been primed with a single op instruciton
			//This is necessary because that is the base of a calculation
			if (history.size() > 0)
				return true;
			else
				return false;
		};
		void add_command(Command* cmd) {
			if ((unsigned int)history_index == (history.size()-1))
				history.push_back(cmd);
			else {
				for (unsigned int i=history_index; i < history.size(); i++)
					history.pop_back();
				history.push_back(cmd);
			}
			if (history.size() > 1)
				history_index++;
		};
		Command* get_command() {
			//Returns the command in history we are currently referring to (based on history_index)
			return history.at(history_index);		
		};
		void undo() {
			//Moves to the last command in history (if possible)
			if (history_index > 0)
				history_index--;
		};
		void redo() {
			//Moves to the next command in history (if possible)
			if ((unsigned int)history_index < history.size() - 1)
				history_index++;
		};
};

#endif //__MENU_CLASS__
