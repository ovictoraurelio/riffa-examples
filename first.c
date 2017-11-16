#include <stdio.h>
#include <stdlib.h>
#include <riffa.h>

/**
	*
	*	# To compile (if your enviromment isn't correctly configured this will not compile)
	*	$ gcc firstExample.c -lriffa
	*	@author UCSD (from official website)
	*
**/
 
#define BUF_SIZE (1*1024*1024)
unsigned int buf[BUF_SIZE];
 
int main(int argc, char* argv[]) {
  fpga_t * fpga;
  int fid = 0; // FPGA id
  int channel = 0; // FPGA channel
 
  fpga = fpga_open(fid);
  fpga_send(fpga, channel, (void *)buf, BUF_SIZE, 0, 1, 0);
  fpga_recv(fpga, channel, (void *)buf, BUF_SIZE, 0);
  fpga_close(fpga);
  return 0;
}
