#include <stdio.h>
#include <stdlib.h>
int mutex = 1;
int full = 0;

int empty = 5, item = 0;

void producer()
{
	--mutex;
        ++full;
        --empty;
        item++;
	
        printf("\nProducer produces item %d",item);
        ++mutex;
}

void consumer()
{
	--mutex;
        --full;
        ++empty;

	printf("\nConsumer consumes item %d",item);
	item--;
	++mutex;
}

int main()
{
	int n, i;
	printf("\n1. Press 1 for Producer"
	       "\n2. Press 2 for Consumer"
	       "\n3. Press 3 for Exit");

/* Using '#pragma omp parallel for 'can give wrong value due to synchronization issues. */

/*'critical' specifies that code is executed by only one thread at a time i.e only one thread enters the critical section at a given time.*/
#pragma omp critical

	for (i=1; i>0; i++) {

		printf("\nEnter your choice: ");
		scanf("%d", &n);

		switch (n) {
		case 1:
			if ((mutex == 1) && (empty != 0)) {
                                producer();
			}
			else {
				printf("Buffer is full!");
			}
			break;

		case 2:
			if ((mutex == 1) && (full != 0)) {
				consumer();
			}
			else {
				printf("Buffer is empty!");
			}
			break;
		case 3:
			exit(0);
			break;
		}
	}
}
