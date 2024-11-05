#include <stdio.h>
#include <sys/shm.h>

int main(void)
{
	int id;		//共有メモリID
	int *data;

	//共有メモリ作成
	id = shmget(IPC_PRIVATE, 512, IPC_CREAT|0666);

	//メモリ共有
	data = (int *)shmat(id,NULL,0);

	while(1)
	{
		printf("共有メモリ(id=%d)のデータは%d\n",id,*data);

		//負のデータが書き込まれたら終了
		if(*data <0)
			break;

		sleep(1);
	}

	//共有メモリ削除
	shmctl(id,IPC_RMID,0);

	return 0;
}
