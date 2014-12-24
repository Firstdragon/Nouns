#pragma once

#include <locale.h>

inline void rus(void)
{
	setlocale(LC_CTYPE, ".1251");
	setlocale(LC_MONETARY, ".1251");

	return;
}
