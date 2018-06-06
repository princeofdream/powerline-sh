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


#ifndef __CWD_SEGMENT_HEADER__
#define __CWD_SEGMENT_HEADER__

#include <basic.h>
#include <abstract_segments.h>


// class cwd_segment
class cwd_segment :public abstract_segments
{
public:
	cwd_segment ();
	virtual ~cwd_segment ();

public:
	int segment_get_value(char* name, char** value);
	int segment_get_foreground(char* name, segment_color** value);
	int segment_get_background(char* name, segment_color** value);
	int segment_get_color(char* fg_color_name, char* bg_color_name, segment_color* value);
private:
	/* data */
};


#endif /* ifndef __CWD_SEGMENTS_HEADER__ */



