#include "types.h"
#include "user.h"
#include "stat.h"
#include "fcntl.h"

int
main(int argc, char* argv[])
{
	int n;
	if(argc != 2){
		printf(2,"Usage: prio_test [Priority Number]\n");
		exit();
	}
	else
		n = atoi(argv[1]);
		
	printf(1,"Before priority of process : %d\n",get_prio());

	set_prio(n);

	printf(1,"After priority of process : %d\n",get_prio());
    exit();
}

