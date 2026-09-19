/* Clear the screen via the BIOS */
#include <dos.h>

int main()
{
	union REGS in,out;

/* Read the current video mode,
   BIOS function 0x0f, set in register ah */
	in.h.ah = 0x0f;
	int86(0x10,&in,&out);	/* call the BIOS */

/* the CPU register values are now saved in the
   'out' union */

/* Call BIOS function 0x00 to clear the screen */
	/* BIOS function 0x00, set in register ah */
	in.h.ah = 0x00;

	/* copy the video mode number currently in
	   the al register */
	in.h.al = out.h.al;

	/* make the call */
	int86(0x10,&in,&out);

/* the screen is cleared */

	return 0;
}
