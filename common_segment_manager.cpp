/*
 * =====================================================================================
 *
 *       Filename:  common_segment_manager.cpp
 *
 *    Description:  common_segment_manager
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

#include <common_segment_manager.h>

common_segment_manager::common_segment_manager ()
{
	JCG("%s",__FUNCTION__);
}


common_segment_manager::~common_segment_manager ()
{
	JCG("%s",__FUNCTION__);
}

int
common_segment_manager::segment_get_foreground(char* name, segment_color** value)
{
	return 0;
}

int
common_segment_manager::segment_get_background(char* name, segment_color** value)
{
	return 0;
}

int
common_segment_manager::segment_get_value(char* name, char** value)
{
	char common_value[MAXLEN];
	char* get_value;

	JCG("%s",__FUNCTION__);

	memset(common_value,0x0,sizeof(common_value));
	if (strcmp(name,"cwd") == 0)
	{
		getcwd(common_value,MAXLEN);
	}
	else if (strcmp(name,"ssh") == 0)
	{
		get_value = getenv("SSH_CLIENT");
		// sprintf(common_value, "%s", get_value);
		if (strlen(get_value) > 0)
		{
			sprintf(common_value, "%s", "⌁");
		}
	}
	else if (strcmp(name,"user") == 0)
	{
		get_value = getenv("USER");
		if (strlen(get_value) > 0)
		{
			sprintf(common_value, "%s", get_value);
		}
	}
	else if (strcmp(name,"prompt") == 0)
	{
		get_value = getenv("USER");
		if (strcmp(get_value,"root") == 0)
			sprintf(common_value, " %s ", "#");
		else
			sprintf(common_value, " %s ", "$");
	}
	else if (strcmp(name,"jobs") == 0)
	{
	}
	else if (strcmp(name,"android_env") == 0)
	{
		get_value = getenv("TARGET_PRODUCT");
		if (get_value == NULL)
			return 0;
		sprintf(common_value, " %s", get_value);
		get_value = getenv("TARGET_BUILD_VARIANT");
		sprintf(common_value, "%s-%s ", common_value,get_value);
	}
	else if (strcmp(name,"seperate") == 0)
	{
		sprintf(common_value, "%s", SEPERATE_SYMBOL);
	}
	else if (strcmp(name,"git") == 0)
	{
		char* result = NULL;
		char cmd[MAXLEN];
		common_share m_share;
		char branch[MAXLEN];
		int i0;

		memset(cmd,0x0,sizeof(cmd));
		sprintf(cmd, "%s", "git branch");
		// m_share.run_cmd(cmd, &result);
		m_share.command_stream(cmd, &result);

		i0 = 0;
		memset(branch,0x0,sizeof(branch));
		while(i0 < strlen(result))
		{
			sprintf(branch,"%s%c",branch,result[i0]);
			if (result[i0] == '\n')
			{
				branch[strlen(branch) -1] = '\0';
				if (branch[0] == '*') {
					sprintf(branch, "%s",branch + 2);
					break;
				}
				memset(branch,0x0,sizeof(branch));
			}
			i0++;
		}
		if (strlen(branch) > 0) {
			sprintf(common_value, " %s ", branch);
		} else {
			sprintf(common_value, "%s", branch);
		}
		if (result != NULL) {
			free(result);
		}
	}
	else if (strcmp(name,"newline") == 0)
	{
		sprintf(common_value, "%s", "\n");
	}

	if (common_value!= NULL && strlen(common_value) > 0)
	{
#if 1
		*value = (char*)malloc(MAXLEN);
		sprintf(*value,"%s",common_value);
		JCG("value:%s",*value);
#else
		segment_set_value(common_value);
#endif
	}

	return 0;


}

int
common_segment_manager::segment_get_color(char* fg_color_name, char* bg_color_name, segment_color* value)
{
	return 0;
}


