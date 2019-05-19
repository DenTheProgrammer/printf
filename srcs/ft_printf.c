#include "printf.h"
#include <limits.h>
#define STR "%eLf\n", 12.847
//    %[parameter][flags][width][.precision][length]type

int		ft_printf(const char *str, ...)
{
	va_list valist;

	va_start(valist, str);
	t_flist *format_list = parse_input(str);
	parse_formats(format_list);
	apply_formats(format_list, &valist);
	va_end(valist);
	return (printf_output(format_list));
}
//todo float, rounding//in progress
// Makefile for testing//done
//todo better format parcing//done
//todo parcing for all flags in structure fields//done
//todo multiple flags handling!//in progress//done
//todo 0x and negative fix!//done

//todo Parse_res strdup 6 bytes lost //fix needed
//todo "%1lf|%-1lf|%+1lf|% 1lf|%#1lf|%01lf", 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849, 38546.5849 //why exp = 0?


//
//#include <math.h>
//
//int		main()
//{
//	ft_printf(STR);//todo
//	printf(STR);
//	return 0;
//}