#include <stdio.h>
#include<dos.h>
int main()
{ char  c;
  _AH = 1;
  geninterrupt(0x21);
  c = _AL;          /*AL�д洢�����ַ���ASCII��*/
  printf("%c\n", c);
  return 0;
}
