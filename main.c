#include <stc12c5a60s2.h>

#define uchar unsigned char
#define uint unsigned int

#define LongToBin(n) (((n>>21)&0x80)|((n>>18)&0x40)|((n>>15)&0x20)|((n>>12)&0x10)|((n>>9)&0x08)|((n>>6)&0x04)|((n>>3)&0x02)|((n)&0x01))
#define BIN(n) LongToBin(0x##n##)

sbit anjian=P4^5;

sbit P0_0=P0^0;//层
sbit P0_1=P0^1;
sbit P0_2=P0^2;
sbit P0_3=P0^3;
sbit P0_4=P0^4;
sbit P0_5=P0^5;
sbit P0_6=P0^6;
sbit P0_7=P0^7;
sbit P4_6=P4^6;
sbit P1_1=P1^1;
sbit P1_2=P1^2;
sbit P1_3=P1^3;
sbit P1_4=P1^4;
sbit P1_5=P1^5;
sbit P1_6=P1^6;
sbit P1_7=P1^7;

sbit P3_0=P3^0;//竖
sbit P3_1=P3^1;
sbit P3_2=P3^2;
sbit P3_3=P3^3;
sbit P3_4=P3^4;
sbit P3_5=P3^5;
sbit P3_6=P3^6;
sbit P3_7=P3^7;
sbit P2_0=P2^0;
sbit P2_1=P2^1;
sbit P2_2=P2^2;
sbit P2_3=P2^3;
sbit P2_4=P2^4;
sbit P2_5=P2^5;
sbit P2_6=P2^6;
sbit P2_7=P2^7;
sbit P4_4=P4^4;

char moshi=1;
char h=0,v=0;
int t=0;
char zy=0,sj=0,jz=0;

bit ly_flag=0;								//成功接收标志

void delay_1ms(uint q)
{
	uint i,j;
	for(i=0;i<q;i++)
		for(j=0;j<110;j++);
} 
void key()
{
	if(anjian==0)
	{
		delay_1ms(5);
		if(anjian==0)
		{
			while(anjian==0);
			jz++;
			if(jz==2)jz=0;
			if(jz==0){moshi=1;TR0=0;ET0=0;};
			if(jz==1){moshi=0;ly_flag=1;TR0=1;ET0=1;}
		}	
	}
}
void dh1()
{
	char i,j;
	P3_0=0;//J1
	P3_1=0;//J2
	P3_3=0;//J3
	P3_4=0;//J4
	P3_5=0;//J5
	P3_6=0;//J6
	P3_7=0;//J7
	P2_0=0;//J8
	P2_1=0;//J9
	P2_2=0;//J10
	P2_3=0;//J11
	P2_4=0;//J12
	P2_5=0;//J13
	P2_6=0;//J14
	P2_7=0;//J15
	P4_4=0;//J16
	
	P1_7=0;
	P1_6=0;
	P1_5=0;
	P1_4=0;
	P1_3=0;
	P1_2=0;
	P1_1=0;

	P4_6=0;

	P0=0X01;
	delay_1ms(10);
	for(j=0;j<7;j++)
	{
		P0=(P0<<1)|0x01;
		delay_1ms(10);
	}
	P4_6=1;
	delay_1ms(10);	
	P1_1=1;
	delay_1ms(10);
	P1_2=1;
	delay_1ms(10);
	P1_3=1;
	delay_1ms(10);
	P1_4=1;
	delay_1ms(10);
	P1_5=1;
	delay_1ms(10);
	P1_6=1;
	delay_1ms(10);
	P1_7=1;	

	for(i=0;i<2;i++)
	{
		P1_7=0;
		P1_6=0;
		P1_5=0;
		P1_4=0;
		P1_3=0;
		P1_2=0;
		P1_1=0;
	
		P4_6=0;
	
		P0=0X01;
		delay_1ms(1000);
		for(j=0;j<7;j++)
		{
			P0=(P0<<1)|0x01;
			delay_1ms(700);
			key();
			if(ly_flag==1){ly_flag=0;break;}
		}
	
		P4_6=1;
		delay_1ms(700);
		key();
		if(ly_flag==1){moshi=0;ly_flag=0;break;}	
		P1_1=1;
		delay_1ms(700);
		key();
		if(ly_flag==1){moshi=0;ly_flag=0;break;}
		P1_2=1;
		delay_1ms(700);
		key();
		if(ly_flag==1){moshi=0;ly_flag=0;break;}
		P1_3=1;
		delay_1ms(700);
		key();
		if(ly_flag==1){moshi=0;ly_flag=0;break;}
		P1_4=1;
		delay_1ms(700);
		key();
		if(ly_flag==1){moshi=0;ly_flag=0;break;}
		P1_5=1;
		delay_1ms(700);
		key();
		if(ly_flag==1){moshi=0;ly_flag=0;break;}
		P1_6=1;
		delay_1ms(700);
		key();
		if(ly_flag==1){moshi=0;ly_flag=0;break;}
		P1_7=1;
		delay_1ms(8000);
		key();
		if(ly_flag==1){moshi=0;ly_flag=0;break;}
		delay_1ms(8000);
		key();
		if(ly_flag==1){moshi=0;ly_flag=0;break;}
		delay_1ms(8000);
		key();
		if(ly_flag==1){moshi=0;ly_flag=0;break;}
		delay_1ms(8000);
		key();
		if(ly_flag==1){moshi=0;ly_flag=0;break;}
		delay_1ms(8000);
		key();
		if(ly_flag==1){moshi=0;ly_flag=0;break;}
		delay_1ms(8000);
		key();			
		if(ly_flag==1){moshi=0;ly_flag=0;break;}
	}				
}
void dh2()
{
	char j;
	P1_7=1;
	P1_6=1;
	P1_5=1;
	P1_4=1;
	P1_3=1;
	P1_2=1;
	P1_1=1;

	P4_6=1;

	P0_7=1;
	P0_6=1;
	P0_5=1;
	P0_4=1;
	P0_3=1;
	P0_2=1;
	P0_1=1;
	P0_0=1;

	for(j=0;j<12;j++)
	{
		P4_4=1;
		P2_0=1;
		P3_0=0;
		P2_1=0;
		delay_1ms(400);
	
		P3_0=1;
		P2_1=1;
		P3_1=0;
		P2_2=0;
		delay_1ms(400);
	
		P3_1=1;
		P2_2=1;
		P3_3=0;
		P2_3=0;
		delay_1ms(400);
		key();
		if(ly_flag==1){moshi=0;ly_flag=0;break;}	
		P3_3=1;
		P2_3=1;
		P3_4=0;
		P2_4=0;
		delay_1ms(400);
	
		P3_4=1;
		P2_4=1;
		P3_5=0;
		P2_5=0;
		delay_1ms(400);
	
		P3_5=1;
		P2_5=1;
		P3_6=0;
		P2_6=0;
		delay_1ms(400);
		if(ly_flag==1){moshi=0;ly_flag=0;break;}	
		P3_6=1;
		P2_6=1;
		P3_7=0;
		P2_7=0;
		delay_1ms(400);
	
		P3_7=1;
		P2_7=1;
		P4_4=0;
		P2_0=0;
		delay_1ms(400);	
		key();
		if(ly_flag==1){moshi=0;ly_flag=0;break;}
	}
}
void dh3()
{
	char i,j;
	int yanshi=400;
	P3_0=0;//J1
	P3_1=0;//J2
	P3_3=0;//J3
	P3_4=0;//J4
	P3_5=0;//J5
	P3_6=0;//J6
	P3_7=0;//J7
	P2_0=0;//J8
	P2_1=0;//J9
	P2_2=0;//J10
	P2_3=0;//J11
	P2_4=0;//J12
	P2_5=0;//J13
	P2_6=0;//J14
	P2_7=0;//J15
	P4_4=0;//J16

   	for(i=0;i<3;i++)
	{
		P1_7=0;
		P1_6=0;
		P1_5=0;
		P1_4=0;
		P1_3=0;
		P1_2=0;
		P1_1=0;
	
		P4_6=0;
	
		P0=0X01;
		delay_1ms(yanshi);
		for(j=0;j<7;j++)
		{
			P0=(P0<<1);
			delay_1ms(yanshi);
			key();
			if(ly_flag==1){moshi=0;ly_flag=0;break;}
		}
	
		P0_7=0;	
		P4_6=1;
		delay_1ms(yanshi);
	
		P4_6=0;	
		P1_1=1;
		delay_1ms(yanshi);
	
		P1_1=0;	
		P1_2=1;
		delay_1ms(yanshi);
		key();
		if(ly_flag==1){moshi=0;ly_flag=0;break;}
		P1_2=0;		
		P1_3=1;
		delay_1ms(yanshi);
	
		P1_3=0;		
		P1_4=1;
		delay_1ms(yanshi);
	
		P1_4=0;		
		P1_5=1;
		delay_1ms(yanshi);
		key();
		if(ly_flag==1){moshi=0;ly_flag=0;break;}
		P1_5=0;		
		P1_6=1;
		delay_1ms(yanshi);
	
		P1_6=0;		
		P1_7=1;
		delay_1ms(yanshi);
	
		P1_6=1;		
		P1_7=0;
		delay_1ms(yanshi);
		key();
		if(ly_flag==1){moshi=0;ly_flag=0;break;}
		P1_5=1;		
		P1_6=0;
		delay_1ms(yanshi);
	
		P1_4=1;		
		P1_5=0;
		delay_1ms(yanshi);
	
		P1_3=1;		
		P1_4=0;
		delay_1ms(yanshi);
		key();
		if(ly_flag==1){moshi=0;ly_flag=0;break;}
		P1_2=1;		
		P1_3=0;
		delay_1ms(yanshi);
	
		P1_1=1;		
		P1_2=0;
		delay_1ms(yanshi);
	
		P1_1=0;		
		P0_7=1;
		delay_1ms(yanshi);
		key();
		if(ly_flag==1){moshi=0;ly_flag=0;break;}
		P0_6=1;		
		P0_7=0;
		delay_1ms(yanshi);
	
		P0_5=1;		
		P0_6=0;
		delay_1ms(yanshi);
	
		P0_4=1;		
		P0_5=0;
		delay_1ms(yanshi);
		key();
		if(ly_flag==1){moshi=0;ly_flag=0;break;}
		P0_3=1;		
		P0_4=0;
		delay_1ms(yanshi);
	
		P0_2=1;		
		P0_3=0;
		delay_1ms(yanshi);
	
		P0_1=1;		
		P0_2=0;
		delay_1ms(yanshi);
		key();
		if(ly_flag==1){moshi=0;ly_flag=0;break;}
	}
}
void dh4()
{
	char j;
	P3_0=0;//J1
	P3_1=0;//J2
	P3_3=0;//J3
	P3_4=0;//J4
	P3_5=0;//J5
	P3_6=0;//J6
	P3_7=0;//J7
	P2_0=0;//J8
	P2_1=0;//J9
	P2_2=0;//J10
	P2_3=0;//J11
	P2_4=0;//J12
	P2_5=0;//J13
	P2_6=0;//J14
	P2_7=0;//J15
	P4_4=0;//J16
	
	P1_7=0;
	P1_6=0;
	P1_5=0;
	P1_4=0;
	P1_3=0;
	P1_2=0;
	P1_1=0;
	P4_6=0;
	P0_7=0;
	P0_6=0;
	P0_5=0;
	P0_4=0;
	P0_3=0;
	P0_2=0;
	P0_1=0;
	P0_1=0;	
	P0_0=0;	
	for(j=0;j<3;j++)
	{
		P1_7=0;
		P0_0=0;		
		P4_6=1;
		P0_7=1;	
		delay_1ms(500);
		
		P4_6=0;
		P0_7=0;	
		P1_1=1;
		P0_6=1;
		delay_1ms(500);
		key();
		if(ly_flag==1){moshi=0;ly_flag=0;break;}
		P1_2=1;
		P0_5=1;	
		P1_1=0;
		P0_6=0;
		delay_1ms(500);
		
		P1_3=1;
		P0_4=1;	
		P1_2=0;
		P0_5=0;
		delay_1ms(500);
		key();
		if(ly_flag==1){moshi=0;ly_flag=0;break;}
		P1_4=1;
		P0_3=1;	
		P1_3=0;
		P0_4=0;
		delay_1ms(500);
		
		P1_5=1;
		P0_2=1;	
		P1_4=0;
		P0_3=0;
		delay_1ms(500);
		key();
		if(ly_flag==1){moshi=0;ly_flag=0;break;}
		P1_6=1;
		P0_1=1;	
		P1_5=0;
		P0_2=0;
		delay_1ms(500);
		
		P1_7=1;
		P0_0=1;	
		P1_6=0;
		P0_1=0;
		delay_1ms(500);	
		key();
		if(ly_flag==1){moshi=0;ly_flag=0;break;}
	}				
}
void dh5()
{
	char i;
	P1_7=1;
	P1_6=1;
	P1_5=1;
	P1_4=1;
	P1_3=1;
	P1_2=1;
	P1_1=1;
	P4_6=1;
	P0_7=1;
	P0_6=1;
	P0_5=1;
	P0_4=1;
	P0_3=1;
	P0_2=1;
	P0_1=1;
	P0_1=1;	
	P0_0=1;
	
	for(i=0;i<3;i++)
	{
		P3_0=0;	
		delay_1ms(400);	
		P3_1=0;	
		delay_1ms(400);	
		P3_3=0;	
		delay_1ms(400);	
		P3_4=0;	
		delay_1ms(400);	
		key();
		if(ly_flag==1){moshi=0;ly_flag=0;break;}
		P3_5=0;	
		delay_1ms(400);	
		P3_6=0;	
		delay_1ms(400);	
		P3_7=0;	
		delay_1ms(400);		
		P2_0=0;	
		delay_1ms(400);	
		key();
		if(ly_flag==1){moshi=0;ly_flag=0;break;}
		P2_1=0;	
		delay_1ms(400);	
		P2_2=0;	
		delay_1ms(400);	
		P2_3=0;	
		delay_1ms(400);	
		P2_4=0;	
		delay_1ms(400);
		key();
		if(ly_flag==1){moshi=0;break;}	
		P2_5=0;	
		delay_1ms(400);	
		P2_6=0;	
		delay_1ms(400);	
		P2_7=0;	
		delay_1ms(400);	
		P4_4=0;	
		delay_1ms(9000);
		key();
		if(ly_flag==1){moshi=0;break;}
		delay_1ms(9000);
		key();
		if(ly_flag==1){moshi=0;break;}
		delay_1ms(9000);
		key();
		if(ly_flag==1){moshi=0;break;}		
		P2=0XFF;
		P3=0XFF;
		P4_4=1;		
	}			
}
void dh6()
{
	char j;
	int yanshi=3000;
	P1_7=1;
	P1_6=1;
	P1_5=1;
	P1_4=1;
	P1_3=1;
	P1_2=1;
	P1_1=1;

	P4_6=1;

	P0_7=1;
	P0_6=1;
	P0_5=1;
	P0_4=1;
	P0_3=1;
	P0_2=1;
	P0_1=1;
	P0_0=1;

	for(j=0;j<20;j++)
	{
 		P3_4=1;
		P2_0=1;
		P2_4=1;
		P4_4=1;

 		P3_0=0;
		P3_5=0;
		P2_1=0;
		P2_5=0;
		delay_1ms(yanshi);
		key();
		if(ly_flag==1){moshi=0;ly_flag=0;break;}
 		P3_0=1;
		P3_5=1;
		P2_1=1;
		P2_5=1;

 		P3_1=0;
		P3_6=0;
		P2_2=0;
		P2_6=0;
		delay_1ms(yanshi);
		key();
	    if(ly_flag==1){moshi=0;ly_flag=0;break;}
 		P3_1=1;
		P3_6=1;
		P2_2=1;
		P2_6=1;

 		P3_3=0;
		P3_7=0;
		P2_3=0;
		P2_7=0;
		delay_1ms(yanshi);
		key();
		if(ly_flag==1){moshi=0;ly_flag=0;break;}
 		P3_3=1;
		P3_7=1;
		P2_3=1;
		P2_7=1;

 		P3_4=0;
		P2_0=0;
		P2_4=0;
		P4_4=0;
		delay_1ms(yanshi);
		if(j<6)yanshi=yanshi-400;
		key();
		if(ly_flag==1){moshi=0;ly_flag=0;break;}
	}	
}
void dh7()
{
	P3_0=0;//J1
	P3_1=0;//J2
	P3_3=0;//J3
	P3_4=0;//J4
	P3_5=0;//J5
	P3_6=0;//J6
	P3_7=0;//J7
	P2_0=0;//J8
	P2_1=0;//J9
	P2_2=0;//J10
	P2_3=0;//J11
	P2_4=0;//J12
	P2_5=0;//J13
	P2_6=0;//J14
	P2_7=0;//J15
	P4_4=0;//J16
	
	P1=0X00;
	P0=0X00;
	P4_6=0;

	P1_7=1;
	delay_1ms(400);
	P1_6=1;
	delay_1ms(400);
	P1_6=0;
	P1_5=1;
	delay_1ms(400);	
	P1_5=0;
	P1_4=1;
	delay_1ms(400);	
	P1_4=0;
	P1_3=1;
	delay_1ms(400);	
	P1_3=0;
	P1_2=1;
	delay_1ms(400);	
	P1_2=0;
	P1_1=1;
	delay_1ms(400);	
	P1_1=0;
	P4_6=1;
	delay_1ms(400);	
	key();
	if(ly_flag==1){moshi=0;ly_flag=0;goto hm;}
	P4_6=0;
	P0_7=1;
	delay_1ms(400);	
	P0_7=0;
	P0_6=1;
	delay_1ms(400);
	P0_6=0;
	P0_5=1;
	delay_1ms(400);	
	P0_5=0;
	P0_4=1;
	delay_1ms(400);	
	P0_4=0;
	P0_3=1;
	delay_1ms(400);	
	P0_3=0;
	P0_2=1;
	delay_1ms(400);	
	P0_2=0;
	P0_1=1;
	delay_1ms(400);
	P0_1=0;
	P0_0=1;
	delay_1ms(400);	/////////////P00
	key();
	if(ly_flag==1){moshi=0;ly_flag=0;goto hm;}
	P1_6=1;
	delay_1ms(400);
	P1_6=0;
	P1_5=1;
	delay_1ms(400);	
	P1_5=0;
	P1_4=1;
	delay_1ms(400);	
	P1_4=0;
	P1_3=1;
	delay_1ms(400);	
	P1_3=0;
	P1_2=1;
	delay_1ms(400);	
	P1_2=0;
	P1_1=1;
	delay_1ms(400);	
	P1_1=0;
	P4_6=1;
	delay_1ms(400);	
	P4_6=0;
	P0_7=1;
	delay_1ms(400);	
	key();
	if(ly_flag==1){moshi=0;ly_flag=0;goto hm;}
	P0_7=0;
	P0_6=1;
	delay_1ms(400);
	P0_6=0;
	P0_5=1;
	delay_1ms(400);	
	P0_5=0;
	P0_4=1;
	delay_1ms(400);	
	P0_4=0;
	P0_3=1;
	delay_1ms(400);	
	P0_3=0;
	P0_2=1;
	delay_1ms(400);	
	P0_2=0;
	P0_1=1;
	delay_1ms(400);/////////////////////////////P01
	key();
	if(ly_flag==1){moshi=0;ly_flag=0;goto hm;}
	P1_6=1;
	delay_1ms(400);
	P1_6=0;
	P1_5=1;
	delay_1ms(400);	
	P1_5=0;
	P1_4=1;
	delay_1ms(400);	
	P1_4=0;
	P1_3=1;
	delay_1ms(400);	
	P1_3=0;
	P1_2=1;
	delay_1ms(400);	
	P1_2=0;
	P1_1=1;
	delay_1ms(400);	
	key();
	if(ly_flag==1){moshi=0;ly_flag=0;goto hm;}
	P1_1=0;
	P4_6=1;
	delay_1ms(400);	
	P4_6=0;
	P0_7=1;
	delay_1ms(400);	
	P0_7=0;
	P0_6=1;
	delay_1ms(400);
	P0_6=0;
	P0_5=1;
	delay_1ms(400);	
	P0_5=0;
	P0_4=1;
	delay_1ms(400);	
	P0_4=0;
	P0_3=1;
	delay_1ms(400);	
	key();
	if(ly_flag==1){moshi=0;ly_flag=0;goto hm;}
	P0_3=0;
	P0_2=1;
	delay_1ms(400);/////////////////////////////////P02
	P1_6=1;
	delay_1ms(400);
	P1_6=0;
	P1_5=1;
	delay_1ms(400);	
	P1_5=0;
	P1_4=1;
	delay_1ms(400);	
	P1_4=0;
	P1_3=1;
	delay_1ms(400);	
	P1_3=0;
	P1_2=1;
	delay_1ms(400);	
	P1_2=0;
	P1_1=1;
	delay_1ms(400);	
	key();
	if(ly_flag==1){moshi=0;ly_flag=0;goto hm;}
	P1_1=0;
	P4_6=1;
	delay_1ms(400);	
	P4_6=0;
	P0_7=1;
	delay_1ms(400);	
	P0_7=0;
	P0_6=1;
	delay_1ms(400);
	P0_6=0;
	P0_5=1;
	delay_1ms(400);	
	P0_5=0;
	P0_4=1;
	delay_1ms(400);	
	P0_4=0;
	P0_3=1;
	delay_1ms(400);//////////////////////////P03
	key();
	if(ly_flag==1){moshi=0;ly_flag=0;goto hm;}
	P1_6=1;
	delay_1ms(400);
	P1_6=0;
	P1_5=1;
	delay_1ms(400);	
	
	P1_5=0;
	P1_4=1;
	delay_1ms(400);	
	P1_4=0;
	P1_3=1;
	delay_1ms(400);	
	
	P1_3=0;
	P1_2=1;
	delay_1ms(400);	
	
	P1_2=0;
	P1_1=1;
	delay_1ms(400);	
	key();
	if(ly_flag==1){moshi=0;ly_flag=0;goto hm;}
	P1_1=0;
	P4_6=1;
	delay_1ms(400);	
	P4_6=0;
	P0_7=1;
	delay_1ms(400);		
	P0_7=0;
	P0_6=1;
	delay_1ms(400);
	P0_6=0;
	P0_5=1;
	delay_1ms(400);	
	P0_5=0;
	P0_4=1;
	delay_1ms(400);///////////////////////////P04
	P1_6=1;
	delay_1ms(400);
	key();
	if(ly_flag==1){moshi=0;ly_flag=0;goto hm;}
	P1_6=0;
	P1_5=1;
	delay_1ms(400);	
	
	P1_5=0;
	P1_4=1;
	delay_1ms(400);	
	
	P1_4=0;
	P1_3=1;
	delay_1ms(400);	

	P1_3=0;
	P1_2=1;
	delay_1ms(400);	
	key();
	if(ly_flag==1){moshi=0;ly_flag=0;goto hm;}	
	P1_2=0;
	P1_1=1;
	delay_1ms(400);	
	
	P1_1=0;
	P4_6=1;
	delay_1ms(400);	
	P4_6=0;
	P0_7=1;
	delay_1ms(400);	
	
	P0_7=0;
	P0_6=1;
	delay_1ms(400);
	
	P0_6=0;
	P0_5=1;
	delay_1ms(400);//////////////////////////////////P05
	key();
	if(ly_flag==1){moshi=0;ly_flag=0;goto hm;}
	P1_6=1;
	delay_1ms(400);

	P1_6=0;
	P1_5=1;
	delay_1ms(400);	
	
	P1_5=0;
	P1_4=1;
	delay_1ms(400);	

	P1_4=0;
	P1_3=1;
	delay_1ms(400);	
	
	P1_3=0;
	P1_2=1;
	delay_1ms(400);	
	
	P1_2=0;
	P1_1=1;
	delay_1ms(400);	
	key();
	if(ly_flag==1){moshi=0;ly_flag=0;goto hm;}
	P1_1=0;
	P4_6=1;
	delay_1ms(400);	

	P4_6=0;
	P0_7=1;
	delay_1ms(400);	
	
	P0_7=0;
	P0_6=1;
	delay_1ms(400);	///////////////////P06
	P1_6=1;
	delay_1ms(400);

	P1_6=0;
	P1_5=1;
	delay_1ms(400);	
	
	P1_5=0;
	P1_4=1;
	delay_1ms(400);	
	key();
	if(ly_flag==1){moshi=0;ly_flag=0;goto hm;}
	P1_4=0;
	P1_3=1;
	delay_1ms(400);	
	
	P1_3=0;
	P1_2=1;
	delay_1ms(400);	
	
	P1_2=0;
	P1_1=1;
	delay_1ms(400);	

	P1_1=0;
	P4_6=1;
	delay_1ms(400);	

	P4_6=0;
	P0_7=1;
	delay_1ms(400);//////////////////////////////////////P07

	P1_6=1;
	delay_1ms(400);
	key();
	if(ly_flag==1){moshi=0;ly_flag=0;goto hm;}
	P1_6=0;
	P1_5=1;
	delay_1ms(400);	
	
	P1_5=0;
	P1_4=1;
	delay_1ms(400);	
	
	P1_4=0;
	P1_3=1;
	delay_1ms(400);	

	P1_3=0;
	P1_2=1;
	delay_1ms(400);	
	
	P1_2=0;
	P1_1=1;
	delay_1ms(400);	
	
	P1_1=0;
	P4_6=1;
	delay_1ms(400);	///////////////////////////P46
	key();
	if(ly_flag==1){moshi=0;ly_flag=0;goto hm;}
	P1_6=1;
	delay_1ms(400);

	P1_6=0;
	P1_5=1;
	delay_1ms(400);	
	
	P1_5=0;
	P1_4=1;
	delay_1ms(400);	

	P1_4=0;
	P1_3=1;
	delay_1ms(400);	
	
	P1_3=0;
	P1_2=1;
	delay_1ms(400);	
	
	P1_2=0;
	P1_1=1;
	delay_1ms(400);	///////////////////////////////////
	key();
	if(ly_flag==1){moshi=0;ly_flag=0;goto hm;}
	P1_6=1;
	delay_1ms(400);

	P1_6=0;
	P1_5=1;
	delay_1ms(400);	
	
	P1_5=0;
	P1_4=1;
	delay_1ms(400);	

	P1_4=0;
	P1_3=1;
	delay_1ms(400);	
	
	P1_3=0;
	P1_2=1;
	delay_1ms(400);	///////////////////////////////////////////

	P1_6=1;
	delay_1ms(400);
	key();
	if(ly_flag==1){moshi=0;ly_flag=0;goto hm;}
	P1_6=0;
	P1_5=1;
	delay_1ms(400);	
	
	P1_5=0;
	P1_4=1;
	delay_1ms(400);	
	
	P1_4=0;
	P1_3=1;
	delay_1ms(400);/////////////////////////////////////

	P1_6=1;
	delay_1ms(400);

	P1_6=0;
	P1_5=1;
	delay_1ms(400);	
	
	P1_5=0;
	P1_4=1;
	delay_1ms(400);///////////////////////////////////
	key();
	if(ly_flag==1){moshi=0;ly_flag=0;goto hm;}
	P1_6=1;
	delay_1ms(400);

	P1_6=0;
	P1_5=1;
	delay_1ms(400);	//////////////////////

	P1_6=1;
	delay_1ms(400);	/////////////////////
hm: ;																			
}
void dh8()
{
	P3_0=0;//J1
	P3_1=0;//J2
	P3_3=0;//J3
	P3_4=0;//J4
	P3_5=0;//J5
	P3_6=0;//J6
	P3_7=0;//J7
	P2_0=0;//J8
	P2_1=0;//J9
	P2_2=0;//J10
	P2_3=0;//J11
	P2_4=0;//J12
	P2_5=0;//J13
	P2_6=0;//J14
	P2_7=0;//J15
	P4_4=0;//J16

	P1_7=1;
	P1_6=1;
	P1_5=1;
	P1_4=1;
	P1_3=1;
	P1_2=1;
	P1_1=1;
	P4_6=1;
	P0_7=1;
	P0_6=1;
	P0_5=1;
	P0_4=1;
	P0_3=1;
	P0_2=1;
	P0_1=1;
	P0_1=1;	
	P0_0=1;
	delay_1ms(9000);
	key();
	if(ly_flag==1){moshi=0;ly_flag=0;goto hm;}
	delay_1ms(9000);
	key();
	if(ly_flag==1){moshi=0;ly_flag=0;goto hm;}
	delay_1ms(9000);
	key();
	if(ly_flag==1){moshi=0;ly_flag=0;goto hm;}
	delay_1ms(9000);
hm: ;
}
void dh9()
{
	char i;
	P3_0=0;//J1
	P3_1=0;//J2
	P3_3=0;//J3
	P3_4=0;//J4
	P3_5=0;//J5
	P3_6=0;//J6
	P3_7=0;//J7
	P2_0=0;//J8
	P2_1=0;//J9
	P2_2=0;//J10
	P2_3=0;//J11
	P2_4=0;//J12
	P2_5=0;//J13
	P2_6=0;//J14
	P2_7=0;//J15
	P4_4=0;//J16
	
	P1_7=0;
	P1_6=0;
	P1_5=0;
	P1_4=0;
	P1_3=0;
	P1_2=0;
	P1_1=0;
	P4_6=0;
	P0_7=0;
	P0_6=0;
	P0_5=0;
	P0_4=0;
	P0_3=0;
	P0_2=0;
	P0_1=0;
	P0_1=0;	
	P0_0=0;	

	for(i=0;i<5;i++)
	{
		P1_4=0;
		P1_3=0;
		P0_4=0;
		P0_3=0;
	
		P1_7=1;
		P4_6=1;
		P0_7=1;
		P0_0=1;
		delay_1ms(1000);

		P1_7=0;
		P4_6=0;
		P0_7=0;
		P0_0=0;
	
		P1_6=1;
		P1_1=1;
		P0_6=1;
		P0_1=1;
		delay_1ms(1000);
		key();	
		if(ly_flag==1){moshi=0;ly_flag=0;break;}	
		P1_6=0;
		P1_1=0;
		P0_6=0;
		P0_1=0;
	
		P1_5=1;
		P1_2=1;
		P0_5=1;
		P0_2=1;
		delay_1ms(1000);	
	
		P1_5=0;
		P1_2=0;
		P0_5=0;
		P0_2=0;
	
		P1_4=1;
		P1_3=1;
		P0_4=1;
		P0_3=1;
		delay_1ms(1000);
		key();
		if(ly_flag==1){moshi=0;ly_flag=0;break;}	
	}			
}
void dh10()
{
	P3_0=0;//J1
	P3_1=0;//J2
	P3_3=0;//J3
	P3_4=0;//J4
	P3_5=0;//J5
	P3_6=0;//J6
	P3_7=0;//J7
	P2_0=0;//J8
	P2_1=0;//J9
	P2_2=0;//J10
	P2_3=0;//J11
	P2_4=0;//J12
	P2_5=0;//J13
	P2_6=0;//J14
	P2_7=0;//J15
	P4_4=0;//J16

	P1_7=1;
	P1_6=0;
	P1_5=1;
	P1_4=0;
	P1_3=1;
	P1_2=0;
	P1_1=1;
	P4_6=0;
	P0_7=1;
	P0_6=0;
	P0_5=1;
	P0_4=0;
	P0_3=1;
	P0_2=0;
	P0_1=1;	
	P0_0=0;	
	delay_1ms(9000);
	key();
		if(ly_flag==1){moshi=0;ly_flag=0;goto hm;}
	delay_1ms(9000);
	key();
		if(ly_flag==1){moshi=0;ly_flag=0;goto hm;}
	delay_1ms(9000);
	key();
		if(ly_flag==1){moshi=0;ly_flag=0;goto hm;}
	delay_1ms(9000);
hm: ;
}
uchar STC_ADC()		   //！！根据数据手册写一个ad读取函数
{												 
     uchar i;
     ADC_RES   = 0;
     ADC_RESL  = 0;
	 ADC_CONTR = BIN(10001000);
	 i=3;
     while(i--);
     while (1)                      
     {
         if (ADC_CONTR & BIN(10000))       
     	 { 
  	  		 break;
  	 	 }
     }
     ADC_CONTR = BIN(10000000);
  	 return( ADC_RESL<<2) ;
}
uchar date;
void init()
{
    TMOD= 0x01;				   
    TL0 = (65536-50000)/256;        //设置定时初值
    TH0 = (65536-50000)%256;        //设置定时初值
    ET0 = 0;
    TR0 = 0;	
    EA = 1;
}
void pp()
{
	if(date<=15 && date>0)
	{	
		h=1;
		if(v<h)
		{
			v=h;	
			P0=0X01;P1_7=0;P1_6=0;P1_5=0;P1_4=0;P1_3=0;P1_2=0;P1_1=0;P4_6=0;
		}
	}

	if(date<=30 && date>15)
	{	
		h=2;
		if(v<h)
		{
			v=h;	
			P0=0X03;P1_7=0;P1_6=0;P1_5=0;P1_4=0;P1_3=0;P1_2=0;P1_1=0;P4_6=0;		
		}
	}
	
	if(date<=45 && date>30)
	{
		h=3;
		if(v<h)
		{
			v=h;
			P0=0X07;P1_7=0;P1_6=0;P1_5=0;P1_4=0;P1_3=0;P1_2=0;P1_1=0;P4_6=0;
		}
	}
	if(date<=60 && date>45)
	{
		h=4;
		if(v<h)
		{
			v=h;
			P0=0X0F;P1_7=0;P1_6=0;P1_5=0;P1_4=0;P1_3=0;P1_2=0;P1_1=0;P4_6=0;
		}	
	}
	if(date<=75 && date>60)
	{
		h=5;
		if(v<h)
		{
			v=h;	
			P0=0X1F;P1_7=0;P1_6=0;P1_5=0;P1_4=0;P1_3=0;P1_2=0;P1_1=0;P4_6=0;
		}			
	}
	if(date<=90 && date>75)
	{
		h=6;
		if(v<h)
		{
			v=h;	
			P0=0X3F;P1_7=0;P1_6=0;P1_5=0;P1_4=0;P1_3=0;P1_2=0;P1_1=0;P4_6=0;	
		}	
	}
	if(date<=105 && date>90)
	{
		h=7;
		if(v<h)
		{
			v=h;	
			P0=0X7F;P1_7=0;P1_6=0;P1_5=0;P1_4=0;P1_3=0;P1_2=0;P1_1=0;P4_6=0;
		}
	}
	if(date<=130 && date>105)
	{
		h=8;
		if(v<h)
		{
			v=h;	
			P0=0XFF;P1_7=0;P1_6=0;P1_5=0;P1_4=0;P1_3=0;P1_2=0;P1_1=0;P4_6=0;
		}
	}
	if(date<=145 && date>130)
	{
		h=9;
		if(v<h)
		{
			v=h;	
			P0=0XFF;P4_6=1;P1_7=0;P1_6=0;P1_5=0;P1_4=0;P1_3=0;P1_2=0;P1_1=0;		
		}	
	}
	if(date<=160 && date>145)
	{
		h=10;		 
		if(v<h)
		{
			v=h;
			P0=0XFF;P4_6=1;P1_1=1;P1_7=0;P1_6=0;P1_5=0;P1_4=0;P1_3=0;P1_2=0;						
		}		
	}
	if(date<=175 && date>160)
	{
		h=11;
		if(v<h)
		{
			v=h;	
			P0=0XFF;P4_6=1;P1_1=1;P1_2=1;P1_7=0;P1_6=0;P1_5=0;P1_4=0;P1_3=0;		
		}
	}
	if(date<=190 && date>175)
	{
		h=12;
		if(v<h)
		{
			v=h;	
			P0=0XFF;P4_6=1;P1_1=1;P1_2=1;P1_3=1;P1_7=0;P1_6=0;P1_5=0;P1_4=0;			
		}		
	}
	if(date<=205 && date>190)
	{
		h=13;
		if(v<h)
		{
			v=h;	
			P0=0XFF;P4_6=1;P1_1=1;P1_2=1;P1_3=1;P1_4=1;P1_7=0;P1_6=0;P1_5=0;
		}			
	}
	if(date<=220 && date>205)
	{
		h=14;
		if(v<h)
		{
			v=h;	
			P0=0XFF;P4_6=1;P1_1=1;P1_2=1;P1_3=1;P1_4=1;P1_5=1;P1_7=0;P1_6=0;		
		}	
	}
	if(date<=235 && date>220)
	{
		h=15;
		if(v<h)
		{
			v=h;	
			P0=0XFF;P4_6=1;P1_1=1;P1_2=1;P1_3=1;P1_4=1;P1_5=1;P1_6=1;P1_7=0;
		}			
	}
	if(date>235)
	{
		h=16;
		if(v<h)
		{
			v=h;	
			P0=0XFF;P4_6=1;P1_1=1;P1_2=1;P1_3=1;P1_4=1;P1_5=1;P1_6=1;P1_7=1;			
		}				
	}
}

void sl()
{
	P3_0=0;//J1
	P3_1=0;//J2
	P3_3=0;//J3
	P3_4=0;//J4
	P3_5=0;//J5
	P3_6=0;//J6
	P3_7=0;//J7
	P2_0=0;//J8
	P2_1=0;//J9
	P2_2=0;//J10
	P2_3=0;//J11
	P2_4=0;//J12
	P2_5=0;//J13
	P2_6=0;//J14
	P2_7=0;//J15
	P4_4=0;//J16
}

void main()
{
	P4SW =0Xff;

	P4M0=0xef;//  BIN(11111111);//P2组设置为推挽输出
	P4M1=0x00;	

	P1M0=0xff;
	P1M1=0x00;
 	P1ASF =1;	   //设置P1.0为AD口
    AUXR1 =BIN(100);
	init();

	P0M0=0xff;
	P0M1=0x00;
	
	while(1)
	{
		if(moshi==1)dh1();
		if(moshi==1)dh2();
		if(moshi==1)dh3();
		if(moshi==1)dh4();
		if(moshi==1)dh5();
		if(moshi==1)dh6();
		if(moshi==1)dh7();
		if(moshi==1)dh8();
		if(moshi==1)dh9();
		if(moshi==1)dh10();
	
		if(moshi==0)
		{
			sl();
			key();
			date=STC_ADC();
			pp();
			delay_1ms(2);			
		}
	}
}

void InitTimer0() interrupt 1  // 1毫秒@11.0592MHz
{
    TL0 = (65536-10000)/256;        //设置定时初值
    TH0 = (65536-10000)%256;        //设置定时初值
	t++;
	if(t==3)
	{
		t=0;
		if(v==0);
		else v--;

		if(v==16){P1_7=1;}	
		if(v==15){P1_7=0;}	
		if(v==14){P1_7=0;P1_6=0;}	
		if(v==13){P1_7=0;P1_6=0;P1_5=0;}
		if(v==12){P1_7=0;P1_6=0;P1_5=0;P1_4=0;}	
		if(v==11){P1_7=0;P1_6=0;P1_5=0;P1_4=0;P1_3=0;}	
		if(v==10){P1_7=0;P1_6=0;P1_5=0;P1_4=0;P1_3=0;P1_2=0;}	
		if(v==9) {P1_7=0;P1_6=0;P1_5=0;P1_4=0;P1_3=0;P1_2=0;P1_1=0;}	
		if(v==8) {P1_7=0;P1_6=0;P1_5=0;P1_4=0;P1_3=0;P1_2=0;P1_1=0;P4_6=0;}	
		if(v==7) {P1_7=0;P1_6=0;P1_5=0;P1_4=0;P1_3=0;P1_2=0;P1_1=0;P4_6=0;P0=0X7F;}//	
		if(v==6) {P1_7=0;P1_6=0;P1_5=0;P1_4=0;P1_3=0;P1_2=0;P1_1=0;P4_6=0;P0=0X3F;}//		
		if(v==5) {P1_7=0;P1_6=0;P1_5=0;P1_4=0;P1_3=0;P1_2=0;P1_1=0;P4_6=0;P0=0X1F;}//	
		if(v==4) {P1_7=0;P1_6=0;P1_5=0;P1_4=0;P1_3=0;P1_2=0;P1_1=0;P4_6=0;P0=0X0F;}//	
		if(v==3) {P1_7=0;P1_6=0;P1_5=0;P1_4=0;P1_3=0;P1_2=0;P1_1=0;P4_6=0;P0=0X07;}//
		if(v==2) {P1_7=0;P1_6=0;P1_5=0;P1_4=0;P1_3=0;P1_2=0;P1_1=0;P4_6=0;P0=0X03;}//		
		if(v==1) {P1_7=0;P1_6=0;P1_5=0;P1_4=0;P1_3=0;P1_2=0;P1_1=0;P4_6=0;P0=0X01;}//		
		if(v==0) {P1_7=0;P1_6=0;P1_5=0;P1_4=0;P1_3=0;P1_2=0;P1_1=0;P4_6=0;P0=0X00;}//		
	}				
}