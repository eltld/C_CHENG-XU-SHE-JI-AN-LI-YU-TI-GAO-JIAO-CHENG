#include <dos.h>
#include <stdio.h>
int delete_file(char near *filename)
{
 union REGS regs; 
 int ret; 
 regs.h.ah = 0x41;                /*���ܺ�41H��ɾ���ļ�*/
 regs.x.dx = (unsigned) filename; /*dx��ƫ�Ƶ�ַ*/
 ret = intdos(&regs, &regs); 
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