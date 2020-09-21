#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
#include "processInfo.h"

int main(int argc, char* argv[])
{
	int i, max;
	struct processInfo info;

	printf(1,"PID     PPID    SIZE     Number of Context Switch\n");
	max = get_max_pid();
	for(i = 1; i <= max; i++){
		if(get_proc_info(i, &info) == 0){
			printf(1,"%d %d %d %d\n", i, info.ppid, info.psize, info.numberContextSwitches);
		}
	}
    exit();
}

