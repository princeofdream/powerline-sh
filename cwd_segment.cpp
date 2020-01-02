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
#include <stdlib.h>

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
cwd_segment::segment_get_value(char* name,char** value, void* param)
{
	char cwd_path[MAXLEN];
	char* get_value;
	char abs_path_buff[MAXLEN];
	char *pwd_path;

#if (! (defined _WIN32)) && (!(defined _WIN64))
	memset(abs_path_buff, 0x0, sizeof(abs_path_buff));
	getcwd(cwd_path,sizeof(cwd_path));
	get_value = getenv("HOME");
	pwd_path = getenv("PWD");
	realpath(get_value, abs_path_buff);

	*value = (char*)malloc(MAXLEN);
	if (strncmp(pwd_path, abs_path_buff, strlen(abs_path_buff)) == 0) {
		sprintf(*value," ~%s ",pwd_path + strlen(abs_path_buff));
	} else if (strncmp(pwd_path, get_value, strlen(get_value)) == 0) {
		sprintf(*value," ~%s ",pwd_path + strlen(get_value));
	} else {
		sprintf(*value," %s ",pwd_path);
	}
#else
	// TODO
	// Support HOME dir /home/$USERNAME only
	char *system_type;
	char *username;
	char set_env_buf[MAXLEN];
	char *path_buf;
	int len;

	*value = (char*)malloc(MAXLEN);

	system_type = getenv("MSYSTEM");
	pwd_path = getenv("PWD");
	username = getenv("USERNAME");

	// if (strncasecmp(system_type, "MINGW", strlen("MINGW")) == 0) {
		memset(set_env_buf, 0x0, sizeof(set_env_buf));
		sprintf(set_env_buf, "/home/%s", username);
		path_buf = strstr(pwd_path, set_env_buf);
		if (path_buf == NULL) {
			get_value = getenv("PWD");
			sprintf(*value," %s ",get_value);
			return 0;
		}
		len = strlen(pwd_path) - strlen(path_buf) + strlen(set_env_buf);
		memset(set_env_buf, 0x0, sizeof(set_env_buf));
		snprintf(set_env_buf, len, "%s",pwd_path);
		// printf("%s\n", set_env_buf);
		// putenv(set_env_buf);
	// }

	if (strncmp(pwd_path, set_env_buf, strlen(set_env_buf)) == 0) {
		sprintf(*value," ~%s ",pwd_path + strlen(set_env_buf));
	} else {
		sprintf(*value," %s ",pwd_path);
	}
#endif
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


