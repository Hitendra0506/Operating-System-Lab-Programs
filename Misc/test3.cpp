// STATE VARIABLES 
// Number of active readers; initially = 0 
int NReaders = 0; 

// Number of waiting readers; initially = 0 
int WaitingReaders = 0; 

// Number of active writers; initially = 0 
int NWriters = 0; 

// Number of waiting writers; initially = 0 
int WaitingWriters = 0; 

Condition canRead = NULL; 
Condition canWrite = NULL; 

Void BeginWrite() 
{ 

	// A writer can enter if there are no other 
	// active writers and no readers are waiting 
	if (NWriters == 1 || NReaders > 0) { 

		++WaitingWriters; 
		wait(CanWrite); 
		--WaitingWriters; 
	} 

	NWriters = 1; 
} 

Void EndWrite() 
{ 

	NWriters = 0; 

	// Checks to see if any readers are waiting 
	if (WaitingReaders) 

		Signal(CanRead); 

	else

		Signal(CanWrite); 
} 

Void BeginRead() 
{ 

	// A reader can enter if there are no writers 
	// active or waiting, so we can have 
	// many readers active all at once 
	if (NWriters == 1 || WaitingWriters > 0) { 

		++WaitingReaders; 

		// Otherwise, a reader waits (maybe many do) 
		Wait(CanRead); 

		--WaitingReaders; 
	} 

	++NReaders; 
	Signal(CanRead); 
} 

Void EndRead() 
{ 

	// When a reader finishes, if it was the last reader, 
	// it lets a writer in (if any is there). 
	if (--NReaders == 0) 

		Signal(CanWrite); 
} 

