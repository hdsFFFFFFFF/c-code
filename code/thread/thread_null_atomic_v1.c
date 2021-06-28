#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>
#include <unistd.h>

/*开启16个线程*/
#define PTHREAD_NUM 16

unsigned long sum = 0;
 int i;

void *thread(void *arg)
{
        for ( i = 0; i < 10000; i++)
                sum += 1;               //不使用原子锁
}

int main(void)
{
        printf("before ...sum = %lu\n", sum);

        pthread_t pthread[PTHREAD_NUM]; //被创建线程的标识
        int ret;                        //接收返回值
        void *retval[PTHREAD_NUM];

        for ( i = 0; i < PTHREAD_NUM; i++) {
                ret = pthread_create(&pthread[i], NULL, thread, NULL);
                if (ret != 0) {
                        perror("cause:");
                        printf("creat pthread %d failed.\n", i + 1);
                }

        }

        for ( i = 0; i < PTHREAD_NUM; i++)
                pthread_join(pthread[i], &retval[i]);

        printf("after......sum = %lu\n", sum);

        return 0;
}
