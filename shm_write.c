#include <stdio.h>
#include <sys/shm.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int id;		//‹¤—Lƒƒ‚ƒŠID
	int *send_data;

	if(argc>=3)
	{
		//	‘æˆêˆø”‚ğ‹¤—Lƒƒ‚ƒŠID
		id = atoi(argv[1]);

		//‹¤—Lƒƒ‚ƒŠì¬
		send_data = (int *)shmat(id,NULL,0);
		*send_data = atoi(argv[2]); 
	}

	return 0;
}



