/*
 * =====================================================================================
 *
 *       Filename:  common_segment_manager.h
 *
 *    Description:  common_segment_manager.h
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


#ifndef __COMMON_SEGMENT_MANAGER_HEADER__
#define __COMMON_SEGMENT_MANAGER_HEADER__

#include <basic.h>
#include <abstract_segments.h>
#include <common_share.h>


// class common_segment_manager
class common_segment_manager :public abstract_segments
{
public:
	common_segment_manager ();
	virtual ~common_segment_manager ();

public:
	// int segment_set_value(char* value, segment_color fg, segment_color bg);
	int segment_get_foreground(char* name, segment_color** value);
	int segment_get_background(char* name, segment_color** value);
	int segment_get_value(char* name, char** value, void* param);
	int segment_get_color(char* fg_color_name, char* bg_color_name, segment_color* value);
private:
	/* data */
};


#endif /* ifndef __COMMON_SEGMENT_MANAGER_HEADER__ */



