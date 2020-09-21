#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
#include "processInfo.h"

void print_info(int num);

int main(int argc, char* argv[])
{
	int i, max;
	struct processInfo info;

	printf(1,"PID     PPID    SIZE    Number of Context Switch\n");
	max = get_max_pid();
	for(i = 1; i <= max; i++){
		if(get_proc_info(i, &info) == 0){
			print_info(i);
			print_info(info.ppid);
			print_info(info.psize);
			print_info(info.numberContextSwitches);
			printf(1,"\n");
		}
	}
    exit();
}

void print_info(int num)
{
	int cnt = 1;

	printf(1,"%d ",num);
	while((num/=10) > 0)
		cnt++;
	cnt = 7 - cnt;
	while(cnt-- > 0)
		printf(1," ");
}
