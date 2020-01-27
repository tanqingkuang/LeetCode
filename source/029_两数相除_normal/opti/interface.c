#include "../interface.h"

int64 divide_fast(int64 dividend, int64 divisor)
{
	int64 rst = 0;
	switch (divisor) {
	case 1: rst = dividend; break;
	case 2: rst = dividend >> 1; break;
	default:
		while (dividend >= divisor) {
			rst++;
			dividend -= divisor;
		}
		break;
	}

	return rst;
}

int divide(int dividend, int divisor)
{
	int64 my_dividend = dividend;
	int64 my_divisor = divisor;
	int64 rst = 0;
	int flag = 1;
	
	if (my_dividend < 0) {
		flag = -flag;
		my_dividend = -my_dividend;
	}
	if (my_divisor < 0) {
		flag = -flag;
		my_divisor = -my_divisor;
	}
	rst = divide_fast(my_dividend, my_divisor);
	
	if (flag == -1) {
		rst = -rst;
	}
	if (rst > 0x7fffffffLL) {
		return 0x7fffffff;
	}
	return rst;
}
