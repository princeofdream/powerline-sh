/*
 * =====================================================================================
 *
 *       Filename:  cwd_segment.cpp
 *
 *    Description:  cwd_segment
 *
 *        Version:  1.0
 *        Created:  05/09/2018 11:25:53 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  James Lee (JamesL), princeofdream@outlook.com
 *   Organization:  BookCL
 *
 * =====================================================================================
 */

#include <cwd_segment.h>

cwd_segment::cwd_segment ()
{
	JCG("%s",__FUNCTION__);
}


cwd_segment::~cwd_segment ()
{
	JCG("%s",__FUNCTION__);
}

int
cwd_segment::segment_get_foreground(char* name, segment_color** value)
{
	// segment_color m_color[sizeof(segmentaction)];
	// *value = (segment_color*)malloc(sizeof(segment_color));

	// (*value)->fg_color[SEGMENT_ACTION_NORMAL].red   = 244;
	// (*value)->fg_color[SEGMENT_ACTION_ACTIVE].red   = 245;
	// (*value)->fg_color[SEGMENT_ACTION_DEACTIVE].red = 246;
	// (*value)->fg_color[SEGMENT_ACTION_WARNING].red  = 247;
	// (*value)->fg_color[SEGMENT_ACTION_ERROR].red    = 248;

	JCG("sizeof segment true color: %d, action: %d",sizeof(segment_color), sizeof(segmentaction));
	return 0;
}

int
cwd_segment::segment_get_background(char* name, segment_color** value)
{
	return 0;
}

int
cwd_segment::segment_get_value(char* name,char** value)
{
	char cwd_path[MAXLEN];
	char* get_value;
	char abs_path_buff[MAXLEN];
	char *pwd_path;

	JCG("%s",__FUNCTION__);

	getcwd(cwd_path,sizeof(cwd_path));
	get_value = getenv("HOME");
	pwd_path = getenv("PWD");
	realpath(get_value, abs_path_buff);

	if (cwd_path!= NULL && strlen(cwd_path) > 0)
	{
#if 1
		*value = (char*)malloc(MAXLEN);
		if (strncmp(cwd_path, abs_path_buff, strlen(abs_path_buff)) == 0) {
			// sprintf(*value," ~%s ",cwd_path + strlen(abs_path_buff));
			sprintf(*value," ~%s ",pwd_path + strlen(abs_path_buff));
		} else {
			// sprintf(*value," %s ",cwd_path);
			sprintf(*value," %s ",pwd_path);
		}
#else
		segment_set_value(cwd_path);
#endif
	}

	return 0;
}

int
cwd_segment::segment_get_color(char* fg_color_name, char* bg_color_name, segment_color* value)
{
	value = (segment_color*)malloc(sizeof(segment_color));

	(value)->fg_color[SEGMENT_ACTION_NORMAL].red   = 244;
	(value)->fg_color[SEGMENT_ACTION_ACTIVE].red   = 245;
	(value)->fg_color[SEGMENT_ACTION_DEACTIVE].red = 246;
	(value)->fg_color[SEGMENT_ACTION_WARNING].red  = 247;
	(value)->fg_color[SEGMENT_ACTION_ERROR].red    = 248;

	(value)->bg_color[SEGMENT_ACTION_NORMAL].red   = 244;
	(value)->bg_color[SEGMENT_ACTION_ACTIVE].red   = 245;
	(value)->bg_color[SEGMENT_ACTION_DEACTIVE].red = 246;
	(value)->bg_color[SEGMENT_ACTION_WARNING].red  = 247;
	(value)->bg_color[SEGMENT_ACTION_ERROR].red    = 248;

	JCG("sizeof segment true color: %d, action: %d",sizeof(segment_color), sizeof(segmentaction));
	return 0;
}


