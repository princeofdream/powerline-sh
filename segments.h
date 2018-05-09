/*
 * =====================================================================================
 *
 *       Filename:  segments.h
 *
 *    Description:  segments header
 *
 *        Version:  1.0
 *        Created:  05/07/2018 04:14:49 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  James Lee (JamesL), princeofdream@outlook.com
 *   Organization:  BookCL
 *
 * =====================================================================================
 */

#ifndef __SEGMENTS_HEADER__
#define __SEGMENTS_HEADER__

#include "basic.h"



class segments
{
public:
	segments ();
	virtual ~segments ();

public:
	int set_segment_color(char* src, int color, char** dest);

private:
	char* segment_string;
};







#endif


