#ifndef RS_COMMANDEVENT_H
#define RS_COMMANDEVENT_H

/** 
* Command Events
*/

class RS_CommandEvent {
public:
	/** 
	* Create a new command event that is not yet accepted.
	*
	* @param cmd the command that was triggered.
	*/
	RS_CommandEvent(const RS_String& cmd) {
		this->cmd = cmd;
		accepted = false;
	}

	/** 
	* @ return the command that was triggered, usually by the user.
	*/
	RS_String getCommand() {
		return cmd;
	}

	/** 
	* sets the event state to accepted.
	*/
    
	void accept() {
		accepted = true;
	}

	/** 
	* @return Whether the event was already accepted or not.
	*/
	bool isAccepted() {
		return accepted;
	}

protected:
	RS_String cmd;
	bool accepted;
};

#endif