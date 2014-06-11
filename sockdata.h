#ifndef __SOCKDATA_H__
#define __SOCKDATA_H__


#define msg_down	1
#define msg_draw	2
#define msg_ok_draw 3
#define msg_no_draw 4
#define msg_other	5

struct msg_data
{
	BYTE msg_type;
	int x;
	int y;
	int color;
};
#endif