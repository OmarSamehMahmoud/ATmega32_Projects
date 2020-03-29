
char temp;

#define set_bit(reg,bitno)	reg|=(1<<bitno)
#define clr_bit(reg,bitno)	reg&=( ~(1<<bitno) )
#define toggle_bit(reg,bitno)	reg^=(1<<(bitno))
//#define assign_bit(reg,bitnum,value) (value) ? set_bit(reg,bitnum): clr_bit(reg,bitnum)
#define assign_bit(reg,bitno,value)	do{ clr_bit(reg,bitno); reg|=((value)<<bitno); }while(0)

#define set_nibbleLow(reg)	reg=reg|0b00001111
#define clr_nibbleLow(reg)	reg=reg&0b11110000
#define toggle_nibbleLow(reg)	reg=reg^0b00001111
#define assign_nibbleLow(reg,value)	do{ clr_nibbleLow(reg); reg=reg|value; }while(0)
 

#define set_nibbleHigh(reg)	reg=reg|0b11110000
#define clr_nibbleHigh(reg)	reg=reg&0b00001111
#define toggle_nibbleHigh(reg)	reg=reg^0b11110000
#define assign_nibbleHigh(reg,value)	do{ clr_nibbleHigh(reg); reg=reg|value<<4; }while(0)
	
#define get_bit(reg,bitno)	( reg&(1<<bitno) )>>bitno
#define get_nibbleLow(reg)	reg&0b00001111
#define get_nibbleHigh(reg)	(reg&0b11110000)>>4

#define cir_shiftRight(reg,shiftno)	reg= (reg<<( sizeof(reg)*8 -shiftno)) | (reg>>shiftno)  	
#define cir_shiftLeft(reg,shiftno)	reg= (reg>>( sizeof(reg)*8 -shiftno)) | (reg<<shiftno)		
