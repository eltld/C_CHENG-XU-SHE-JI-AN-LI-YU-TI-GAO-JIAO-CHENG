#include <dos.h>
#include <stdio.h>
int delete_file(char far *filename)
{
 union  REGS  regs;
 struct  SREGS  sregs;
 int  ret;
 regs.h.ah = 0x41;
 regs.x.dx = FP_OFF(filename);
 sregs.ds = FP_SEG(filename);
 ret = intdosx(&regs, &regs, &sregs);
 return(regs.x.cflag ? ret : 0);
}

int main()
{char filename[50];
 gets(filename);
 if(delete_file(filename)==0)
   printf("ɾ���ɹ���\n");
 else
   printf("ɾ��ʧ�ܣ�\n");
 return 0;
}