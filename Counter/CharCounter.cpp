//=============================================
// CS 173
// Fall 2024
// CharCounter.cpp
//=============================================

#include "CharCounter.h"


//=============================================
CharCounter::CharCounter()
{
	count = 'A';
}
//=============================================
CharCounter::CharCounter( char v )
{
	count = v;
}
//=============================================
void CharCounter::increment()
{
	count++;
}
//=============================================
void CharCounter::reset()
{
	count = 'A';
}
//=============================================
char CharCounter::getCount()
{
	return count;
}
//=============================================



