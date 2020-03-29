#ifndef _MATH_H
#define _MATH_H

#define SETBIT(REG, BITNO)   ((REG) |= (1 << (BITNO))) 
#define CLRBIT(REG, BITNO)   ((REG) &= ( ~(1 << (BITNO))))
#define TOGBIT(REG, BITNO)   ((REG) ^= (1 << BITNO))
#define GETBIT(REG, BITNO)   ((REG) & (1 << BITNO))


#endif
