#include <stdio.h>
#include <sys/shm.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int id;		//共有メモリID
	int *send_data;

	if(argc>=3)
	{
		//	第一引数を共有メモリID
		id = atoi(argv[1]);

		//共有メモリ作成
		send_data = (int *)shmat(id,NULL,0);
		*send_data = atoi(argv[2]); 
	}

	return 0;
}



