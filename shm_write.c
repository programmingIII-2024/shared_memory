#include <stdio.h>
#include <sys/shm.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int id;		//���L������ID
	int *send_data;

	if(argc>=3)
	{
		//	�����������L������ID
		id = atoi(argv[1]);

		//���L�������쐬
		send_data = (int *)shmat(id,NULL,0);
		*send_data = atoi(argv[2]); 
	}

	return 0;
}



