/*
 * =====================================================================================
 *
 *       Filename:  cwd_segment.h
 *
 *    Description:  cwd_segment.h
 *
 *        Version:  1.0
 *        Created:  05/09/2018 11:26:30 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  James Lee (JamesL), princeofdream@outlook.com
 *   Organization:  BookCL
 *
 * =====================================================================================
 */


#ifndef __CWD_SEGMENTS_HEADER__
#define __CWD_SEGMENTS_HEADER__

#include "basic.h"
#include "abstract_segments.h"


// class cwd_segment
class cwd_segment :public abstract_segments
{
public:
	cwd_segment ();
	virtual ~cwd_segment ();

public:
	int powerline_set_segment_value(char* value, true_color fg, true_color bg);
	// int test_vt ();
private:
	/* data */
};


#endif /* ifndef __CWD_SEGMENTS_HEADER__ */



