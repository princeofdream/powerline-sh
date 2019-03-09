/*
 * =====================================================================================
 *
 *       Filename:  segments.cpp
 *
 *    Description:  segments
 *
 *        Version:  1.0
 *        Created:  05/07/2018 04:09:45 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  James Lee (JamesL), princeofdream@outlook.com
 *   Organization:  BookCL
 *
 * =====================================================================================
 */

#include <segments.h>

class segments m_segments;

segments::segments()
{
	JCG("%s",__FUNCTION__);
	segments_count = 0;
	segments_list = (char**)malloc(MAX_SEGMENTS);
#if 1
	m_unit = (segment_unit**)malloc(MAX_SEGMENTS);
#endif
	JCG("segment unit size:%d",sizeof(segment_unit));
}

segments::~segments()
{
	int i0 = 0;
	JCG("%s",__FUNCTION__);
	free(segments_list);
#if 1
	while(i0 < segments_count)
	{
		if (m_unit != NULL)
			free(m_unit[i0]);
		i0++;
	}
#endif
}


int
segments::register_segment(char* item, void* param)
{
	segment_extra_param *mparam = (segment_extra_param*)param;

	if (item == NULL)
	{
		JEG("item is null, will not add to list!");
		return -1;
	}
	else if (strlen(item) > SEGMENT_NAME_MAX_LEN) {
		JEG("item name too long! will not add to list!");
		return -2;
	}

#if 1
	// JCG("segment [%s] address: 0x%x, name address: 0x%x, value: 0x%x",m_unit[segments_count]->name, m_unit[segments_count], m_unit[segments_count]->name, m_unit[segments_count]->value);
	m_unit[segments_count]           = (segment_unit*)malloc(sizeof(segment_unit));
	m_unit[segments_count]->name     = (char*)malloc(strlen(item) + 16);
	m_unit[segments_count]->value    = (char*)malloc(MAXLEN);
	m_unit[segments_count]->pvalue   = (char*)malloc(MAXLEN);
	m_unit[segments_count]->index    = segments_count;
	m_unit[segments_count]->leftside = true;

	if (mparam != NULL)
	{
		if (mparam->leftside == false)
		{
			m_unit[segments_count]->leftside = false;
			sprintf(m_unit[segments_count]->name,"%s_rside", item);
		}
		else
			sprintf(m_unit[segments_count]->name, "%s", item);
	}
	else
		sprintf(m_unit[segments_count]->name, "%s", item);

	memset(m_unit[segments_count]->value,0x0,MAXLEN);
	memset(m_unit[segments_count]->pvalue,0x0,MAXLEN);

	JCG("============>>> register segment <%d> [%s], value: %s, pvalue: %s, side:%s <<<================",
		m_unit[segments_count]->index,
		m_unit[segments_count]->name,
		m_unit[segments_count]->value,
		m_unit[segments_count]->pvalue,
		m_unit[segments_count]->leftside?"left":"right");
#else
	segments_list[segments_count] = (char*)malloc(SEGMENT_NAME_MAX_LEN);
	memset(segments_list[segments_count], 0x0, sizeof(SEGMENT_NAME_MAX_LEN));
	sprintf(segments_list[segments_count], "%s", item);

#if 0
	m_unit[segments_count].name = (char*)malloc(strlen(item)+1);
	m_unit[segments_count].index = 0;
	memset(m_unit[segments_count].name,0x0,strlen(item)+1);
	sprintf(m_unit[segments_count].name,"%s",item);
#endif
#endif
	segments_count++;
	current_unit = m_unit[segments_count -1];
	return 0;
}

int
segments::get_segment_left_list_common(char** value_list, char* type, segmentaction action)
{
	int i0 = 0;
	int line_count = 0;
	char item_value[MAXLEN];

	*value_list = (char*)malloc(MAXLEN*2);
	memset(*value_list, 0x0, MAXLEN*2);

	if (type == NULL)
	{
		JEG("get list type can not be NULL");
		return -1;
	}

	while( i0 < segments_count )
	{
		if (strlen(m_unit[i0]->value) == 0 || m_unit[i0]->leftside == false) {
			i0++;
			continue;
		}

		if (strcmp(type, "output") == 0 && m_unit[i0]->pvalue != NULL && i0 != (segments_count -1))
			line_count = i0;
		i0++;
	}

	i0 = 0;
	while( i0 < segments_count )
	{
		memset(item_value, 0x0, sizeof(item_value));
		if ( m_unit[i0]->leftside == false) {
			i0++;
			continue;
		}
		JCG("type:%s. m_unit[%d] name: %s,\tvalue: %s,\t\tpvalue: %s",type, i0,m_unit[i0]->name,m_unit[i0]->value, m_unit[i0]->pvalue);
		if (strcmp(type, "name") == 0 && m_unit[i0]->name != NULL)
		{
			sprintf(item_value,"%s",m_unit[i0]->name);
		}
		else if (strcmp(type, "value") == 0 && m_unit[i0]->value != NULL)
		{
			sprintf(item_value,"%s",m_unit[i0]->value);
		}
		else if (strcmp(type, "pvalue") == 0 && m_unit[i0]->pvalue != NULL)
		{
			sprintf(item_value,"%s",m_unit[i0]->pvalue);
		}
		else if (strcmp(type, "color") == 0 && m_unit[i0]->pvalue != NULL)
		{
			sprintf(item_value,"<%d:%d>",m_unit[i0]->color.fg_color[SEGMENT_ACTION_NORMAL].red, m_unit[i0]->color.bg_color[SEGMENT_ACTION_NORMAL].red);
		}
		else if (strcmp(type, "output") == 0 && m_unit[i0]->pvalue != NULL)
		{
			char* color_str = NULL;
			char* color_seperate_fg = NULL;
			char* color_seperate_bg = NULL;
			char* color_seperate_prebg = NULL;
			char* color_end = NULL;
			colortheme m_theme;
			int style = 5;

			if (strlen(m_unit[i0]->value) == 0) {
				i0++;
				continue;
			}

			m_theme.display_256color(DISP_BOTH, style, \
					m_unit[i0]->color.fg_color[SEGMENT_ACTION_NORMAL], \
					m_unit[i0]->color.bg_color[SEGMENT_ACTION_NORMAL], \
					m_unit[i0]->value, &color_str);
			m_theme.display_256color(DISP_FOREGROUND_PART, style, \
					m_unit[i0]->color.fg_color[SEGMENT_ACTION_NORMAL], \
					m_unit[i0]->color.bg_color[SEGMENT_ACTION_NORMAL], \
					NULL, &color_seperate_fg);
			//get current background color and set as pre background
			m_theme.display_256color(DISP_BACKGROUND_PART, style, \
					m_unit[i0]->color.bg_color[SEGMENT_ACTION_NORMAL], \
					m_unit[i0]->color.bg_color[SEGMENT_ACTION_NORMAL], \
					NULL, &color_seperate_bg);
			//get current background color and set as next foreground
			m_theme.display_256color(DISP_FOREGROUND_PART, style, \
					m_unit[i0]->color.bg_color[SEGMENT_ACTION_NORMAL], \
					m_unit[i0]->color.bg_color[SEGMENT_ACTION_NORMAL], \
					NULL, &color_seperate_prebg);
			m_theme.display_256color(DISP_END, style, \
					m_unit[i0]->color.fg_color[SEGMENT_ACTION_NORMAL], \
					m_unit[i0]->color.bg_color[SEGMENT_ACTION_NORMAL], \
					NULL, &color_end);

			if (color_str != NULL && strcmp (m_unit[i0]->name, "newline" ) != 0)
			{
				sprintf(item_value,"%s", color_str);
			}

			if (color_seperate_prebg != NULL && i0 != line_count && strcmp(m_unit[i0]->name, "newline") != 0)
			{
				sprintf(item_value,"%s%s", item_value, color_seperate_prebg);
			}
			else if (color_seperate_prebg != NULL && i0 == line_count)
			{
				sprintf(item_value,"%s%s%s%s%s%s%s%s%s", item_value,
						SHELL_FG_BG_END, SHELL_COLOR_END,
						color_seperate_prebg,SEPERATE_SYMBOL,
						SHELL_FG_BG_END, SHELL_COLOR_END,
						SHELL_FG_BG_END, SHELL_COLOR_END);
			}

			if (strlen(*value_list) <= 0)
			{
				sprintf(*value_list,"%s",item_value);
			}
			else if (strlen(item_value) > 0 && i0 != segments_count - 1 && i0 != line_count)
			{
				sprintf(*value_list,"%s%s%s%s%s%s",*value_list,color_seperate_bg, SEPERATE_SYMBOL, color_end,color_end, item_value);
			}
			else if (strlen(item_value) > 0 && i0 != segments_count - 1 && i0 == line_count)
			{
				// sprintf(*value_list,"%s%s%s%s%s%s",*value_list,color_seperate_bg, SEPERATE_SYMBOL, color_end,color_end, item_value);
				sprintf(*value_list,"%s%s%s%s",*value_list,color_seperate_bg, SEPERATE_SYMBOL, item_value);
			}
			else if (strlen(item_value) > 0 && i0 == segments_count - 1)
			{
				JJG("<%s:%d>[%d:%d]value_list:%s\n",__FILE__,__LINE__,i0,segments_count,*value_list);
				sprintf(*value_list,"%s%s%s%s%s%s%s",*value_list,color_seperate_bg, SEPERATE_SYMBOL, color_end,color_end, item_value,color_end);
			}

			if (color_str != NULL)
				free(color_str);
			if (color_seperate_fg != NULL)
				free(color_seperate_fg);
			if (color_seperate_bg != NULL)
				free(color_seperate_bg);
			if (color_seperate_prebg != NULL)
				free(color_seperate_prebg);
			if (color_end != NULL)
				free(color_end);

			JCG("value_list output:\n%s", *value_list);
			i0++;
			continue;
		}
		else
		{
			i0++;
			continue;
		}

		if (strlen(*value_list) <= 0)
		{
			sprintf(*value_list,"%s",item_value);
		}
		else if (strlen(item_value) > 0 && i0 != line_count)
		{
			sprintf(*value_list,"%s%s%s",*value_list,SEPERATE_SYMBOL,item_value);
		}
		else if (strlen(item_value) > 0 && i0 == line_count)
		{
			sprintf(*value_list,"%s%s%s%s%s%s",
					*value_list,SEPERATE_SYMBOL,
					SHELL_FG_BG_END, SHELL_COLOR_END,
					SHELL_FG_BG_END, SHELL_COLOR_END);
		}
		JCG("value_list output:\n%s", *value_list);
		i0++;
	}
	return 0;
}

int
segments::get_segment_right_list_common(char** value_list, char* type, segmentaction action)
{
	int i0 = 0;
	int line_count = 0;
	char item_value[MAXLEN];

	*value_list = (char*)malloc(MAXLEN*2);
	memset(*value_list, 0x0, MAXLEN*2);

	if (type == NULL)
	{
		JEG("get list type can not be NULL");
		return -1;
	}

	while( i0 < segments_count )
	{
		if (strlen(m_unit[i0]->value) == 0 || m_unit[i0]->leftside == true) {
			i0++;
			continue;
		}

		if (strcmp(type, "output") == 0 && m_unit[i0]->pvalue != NULL && i0 != (segments_count -1))
			line_count = i0;
		i0++;
	}

	i0 = 0;
	while( i0 < segments_count )
	{
		memset(item_value, 0x0, sizeof(item_value));
		if ( m_unit[i0]->leftside == true) {
			i0++;
			continue;
		}
		JCG("type:%s. m_unit[%d] name: %s,\tvalue: %s,\t\tpvalue: %s",type, i0,m_unit[i0]->name,m_unit[i0]->value, m_unit[i0]->pvalue);
		if (strcmp(type, "name") == 0 && m_unit[i0]->name != NULL)
		{
			sprintf(item_value,"%s",m_unit[i0]->name);
		}
		else if (strcmp(type, "value") == 0 && m_unit[i0]->value != NULL)
		{
			sprintf(item_value,"%s",m_unit[i0]->value);
		}
		else if (strcmp(type, "pvalue") == 0 && m_unit[i0]->pvalue != NULL)
		{
			sprintf(item_value,"%s",m_unit[i0]->pvalue);
		}
		else if (strcmp(type, "color") == 0 && m_unit[i0]->pvalue != NULL)
		{
			sprintf(item_value,"<%d:%d>",m_unit[i0]->color.fg_color[SEGMENT_ACTION_NORMAL].red, m_unit[i0]->color.bg_color[SEGMENT_ACTION_NORMAL].red);
		}
		else if (strcmp(type, "output") == 0 && m_unit[i0]->pvalue != NULL)
		{
			char* color_str            = NULL;
			char* color_seperate_fg    = NULL;
			char* color_seperate_bg    = NULL;
			char* color_seperate_prebg = NULL;
			char* color_end            = NULL;
			char* color_bg             = NULL;
			char* color_fg             = NULL;

			colortheme m_theme;
			int style = 5;

			if (strlen(m_unit[i0]->value) == 0) {
				i0++;
				continue;
			}

			m_theme.display_256color(DISP_BOTH, style, \
					m_unit[i0]->color.fg_color[SEGMENT_ACTION_NORMAL], \
					m_unit[i0]->color.bg_color[SEGMENT_ACTION_NORMAL], \
					m_unit[i0]->value, &color_str);
			m_theme.display_256color(DISP_FOREGROUND_PART, style, \
					m_unit[i0]->color.fg_color[SEGMENT_ACTION_NORMAL], \
					m_unit[i0]->color.bg_color[SEGMENT_ACTION_NORMAL], \
					NULL, &color_seperate_fg);
			//get current background color and set as pre background
			m_theme.display_256color(DISP_BACKGROUND_PART, style, \
					m_unit[i0]->color.bg_color[SEGMENT_ACTION_NORMAL], \
					m_unit[i0]->color.bg_color[SEGMENT_ACTION_NORMAL], \
					NULL, &color_seperate_bg);
			//get current background color and set as next foreground
			m_theme.display_256color(DISP_BACKGROUND_PART, style, \
					m_unit[i0]->color.bg_color[SEGMENT_ACTION_NORMAL], \
					m_unit[i0]->color.bg_color[SEGMENT_ACTION_NORMAL], \
					NULL, &color_seperate_prebg);
			m_theme.display_256color(DISP_END, style, \
					m_unit[i0]->color.fg_color[SEGMENT_ACTION_NORMAL], \
					m_unit[i0]->color.bg_color[SEGMENT_ACTION_NORMAL], \
					NULL, &color_end);
			m_theme.display_256color(DISP_FOREGROUND, style, \
					m_unit[i0]->color.bg_color[SEGMENT_ACTION_NORMAL], \
					m_unit[i0]->color.fg_color[SEGMENT_ACTION_NORMAL], \
					NULL, &color_fg);
			m_theme.display_256color(DISP_BACKGROUND, style, \
					m_unit[i0]->color.bg_color[SEGMENT_ACTION_NORMAL], \
					m_unit[i0]->color.fg_color[SEGMENT_ACTION_NORMAL], \
					NULL, &color_bg);

			if (color_str != NULL && strcmp (m_unit[i0]->name, "newline" ) != 0)
			{
				sprintf(item_value,"%s", color_str);
			}

			if (strlen(*value_list) <= 0)
			{
				sprintf(*value_list,"%s%s%s%s",color_end,color_fg,SEPERATE_RSIDE_SYMBOL,item_value);
			}
			else if (strlen(item_value) > 0 && i0 != segments_count - 1 && i0 != line_count)
			{
				sprintf(*value_list,"%s%s%s%s",*value_list,color_fg,SEPERATE_RSIDE_SYMBOL, item_value);
			}
			else if (strlen(item_value) > 0 && i0 != segments_count - 1 && i0 == line_count)
			{
				sprintf(*value_list,"%s%s%s%s",*value_list, color_fg,SEPERATE_RSIDE_SYMBOL, item_value);
				sprintf(*value_list,"%s%s%s%s%s",*value_list, SHELL_FG_BG_END,BASH_COLOR_END,SHELL_FG_BG_END, BASH_COLOR_END);
			}
			else if (strlen(item_value) > 0 && i0 == segments_count - 1)
			{
				sprintf(*value_list,"%s%s%s%s%s",*value_list, color_fg,SEPERATE_RSIDE_SYMBOL,  item_value,color_end);
			}

			if (color_str != NULL)
				free(color_str);
			if (color_seperate_fg != NULL)
				free(color_seperate_fg);
			if (color_seperate_bg != NULL)
				free(color_seperate_bg);
			if (color_seperate_prebg != NULL)
				free(color_seperate_prebg);
			if (color_end != NULL)
				free(color_end);
			if (color_bg != NULL)
				free(color_bg);
			if (color_fg != NULL)
				free(color_fg);

			JCG("value_list output:\n%s\n\n", *value_list);
			i0++;
			continue;
		}
		else
		{
			i0++;
			continue;
		}

		if (strlen(*value_list) <= 0)
		{
			sprintf(*value_list,"%s",item_value);
		}
		else if (strlen(item_value) > 0 && i0 != line_count)
		{
			sprintf(*value_list,"%s%s%s",*value_list,SEPERATE_RSIDE_SYMBOL,item_value);
		}
		else if (strlen(item_value) > 0 && i0 == line_count)
		{
			sprintf(*value_list,"%s%s%s%s%s%s",
					*value_list,SEPERATE_RSIDE_SYMBOL,
					SHELL_FG_BG_END, SHELL_COLOR_END,
					SHELL_FG_BG_END, SHELL_COLOR_END);
		}
		JCG("value_list output:\n%s", *value_list);
		i0++;
	}
	return 0;
}

int
segments::get_segment_list(char** value_list)
{
	JCG("Enter %s.", __FUNCTION__);
	get_segment_left_list_common(value_list,"name", SEGMENT_ACTION_NORMAL);
	return 0;
}

int
segments::get_segment_value_list(char** value_list)
{
	JCG("Enter %s.", __FUNCTION__);
	get_segment_left_list_common(value_list,"value", SEGMENT_ACTION_NORMAL);
	return 0;
}

int
segments::get_segment_left_value_list(char** value_list)
{
	JCG("Enter %s.", __FUNCTION__);
	get_segment_left_list_common(value_list,"value", SEGMENT_ACTION_NORMAL);
	return 0;
}

int
segments::get_segment_right_value_list(char** value_list)
{
	JCG("Enter %s.", __FUNCTION__);
	get_segment_right_list_common(value_list,"value", SEGMENT_ACTION_NORMAL);
	return 0;
}

int
segments::get_segment_pvalue_list(char** value_list)
{
	JCG("Enter %s.", __FUNCTION__);
	get_segment_left_list_common(value_list,"pvalue", SEGMENT_ACTION_NORMAL);
}

int
segments::get_segment_color_list(char** value_list, segmentaction SEGMENT_ACTION_NORMAL)
{
	JCG("Enter %s.", __FUNCTION__);
	get_segment_left_list_common(value_list,"color", SEGMENT_ACTION_NORMAL);
	return 0;
}

int
segments::combile_to_one_line(char** value_list, char* val_left, char* val_right, bool with_space){
	common_share mshare;
	char* result = NULL;
	int row = 0, colum = 0;
	char mspace[MAXLEN];
	int i0 = 0;
	bool isUTF8 = false;
	char length_cmd[MAXLEN];

	int   left_size       = 0;
	char* left_size_str   = NULL;
	char* left_value_list = NULL;

	int   right_size       = 0;
	char* right_size_str   = NULL;
	char* right_value_list = NULL;

	char* get_home_path;
	char get_length_script[MAXLEN];


	memset(mspace,0x0,sizeof(mspace));
	memset(length_cmd,0x0,sizeof(length_cmd));
	memset(get_length_script,0x0,sizeof(get_length_script));

	get_home_path = getenv("HOME");
	sprintf(get_length_script, "%s/.env_tools.sh", get_home_path);

	if (!with_space) {
		JCG("no space, just combile");
		sprintf(*value_list, "%s%s", val_left, val_right);
		return 0;
	}

	get_segment_left_value_list(&left_value_list);
	get_segment_right_value_list(&right_value_list);


	mshare.command_stream("stty size", &result);
	sscanf(result,"%d %d", &row,&colum);

#if 1
	if (access(get_length_script, F_OK) != 0) {
		JCG("--->%s--->%d<---", get_length_script,access(get_length_script, X_OK));
		left_size = -1;
		right_size = 0;
	} else {
		sprintf(length_cmd,"%s -l \"%s\"", get_length_script, left_value_list);
		mshare.command_stream(length_cmd, &left_size_str);
		sscanf(left_size_str,"%d", &left_size);

		memset(length_cmd,0x0,sizeof(length_cmd));
		sprintf(length_cmd,"%s -l \"%s\"", get_length_script, right_value_list);
		mshare.command_stream(length_cmd, &right_size_str);
		sscanf(right_size_str,"%d", &right_size);
	}
#else
	// This use sh instead bash to echo, so length is incorrect
	// sprintf(length_cmd,"TMP_POWERLINE_SH=\"%s\" && bash echo ${#TMP_POWERLINE_SH} && bash echo \"--->${TMP_POWERLINE_SH}<---\"", left_value_list);
	sprintf(length_cmd,"source %s/.common.sh && get_message_length \"%s\"", get_home_path, left_value_list);
	mshare.command_stream(length_cmd, &left_size_str);
	JCG("--->>>%s",left_size_str);
	// sscanf(left_size_str,"%d", &left_size);
#endif

	if (colum > left_size+right_size)
	{
		while(i0 < colum - left_size - right_size && left_size >= 0)
		{
			sprintf(mspace,"%s%s", mspace, " ");
			i0++;
		}
	}
	else
	{
		while(i0 < colum + colum - left_size - right_size && left_size -1 >= 0)
		{
			sprintf(mspace,"%s%s", mspace, " ");
			i0++;
		}
	}

	sprintf(*value_list, "%s%s%s", val_left, mspace, val_right);
	// sprintf(*value_list, "%s", val_left);
	JCG("tty size is: <%d - %d>, left size: %d.\n%s%s%s\n",row ,colum, left_size,left_value_list,mspace,right_value_list);

	if (left_size_str != NULL)
		free(left_size_str);
	if (right_size_str != NULL)
		free(right_size_str);
	if (left_value_list != NULL)
		free(left_value_list);
	if (right_value_list != NULL)
		free(right_value_list);
	return 0;
}

int
segments::get_segment_output_list(char** value_list, segmentaction action)
{
	char* value_list_left;
	char* value_list_right;

	JCG("Enter %s.", __FUNCTION__);

	*value_list = (char*)malloc(MAXLEN*4);
	memset(*value_list, 0x0, MAXLEN*4);

	get_segment_left_list_common(&value_list_left,"output", action);
	get_segment_right_list_common(&value_list_right,"output", action);

	// sprintf(*value_list, "%s", value_list_left);
	// sprintf(*value_list, "%s%s", value_list_left, value_list_right);
#if 1
	combile_to_one_line(value_list, value_list_left, value_list_right, true);
#else
	combile_to_one_line(value_list, value_list_left, "", false);
#endif
	return 0;
}

int
segments::get_segment_by_name(char* name, segment_unit** unit, void* param)
{
	int i0 = 0;
	segment_extra_param *mparam = (segment_extra_param*)param;
	char mname[MAXLEN];

	memset(mname,0x0,sizeof(mname));
	if (mparam != NULL)
	{
		if (mparam->leftside == false)
			sprintf(mname, "%s_rside", name);
		else
			sprintf(mname, "%s", name);
	}
	else
		sprintf(mname, "%s", name);

	while( i0 < segments_count )
	{
		// JCG("segments[%d] name:%s",i0,m_unit[i0]->name);
		/* *unit = (segment_unit*)malloc(sizeof(segment_unit)); */
		// memcpy(*unit,m_unit[i0],sizeof(segment_unit));
		// JCG("segment [%s] address: 0x%x, name address: 0x%x, value: 0x%x",m_unit[i0]->name, m_unit[i0], m_unit[i0]->name, m_unit[i0]->value);
		if(name == NULL)
		{
			JCG("segments[%d] name:%s",i0,m_unit[i0]->name);
		}
		else if (strcmp(m_unit[i0]->name, mname) == 0)
		{
			*unit = m_unit[i0];
			current_unit = m_unit[i0];
			break;
		}
		i0++;
	}
	return 0;
}

int
segments::get_segment_by_order(unsigned int index)
{
	JCG("Enter %s.", __FUNCTION__);
	return 0;
}

int
segments::segment_get_foreground(char* name, segment_color** fg_color)
{
	JCG("Enter %s.", __FUNCTION__);
	return 0;
}

int
segments::segment_get_background(char* name, segment_color** bg_color)
{
	JCG("Enter %s.", __FUNCTION__);
	return 0;
}

int
segments::segment_set_color(segment_color* s_color)
{
	JCG("Enter %s.", __FUNCTION__);
	if (s_color != NULL)
		current_unit->color = *s_color;
	return 0;
}

int
segments::segment_set_side(bool leftside)
{
	int current_name_len = 0;
	char* check_type;

	JCG("Enter %s.", __FUNCTION__);

	current_unit->leftside = leftside;

	current_name_len = strlen(current_unit->name);
	check_type = strstr(current_unit->name, "_rside");
	if (check_type == NULL) {
		// memset(current_unit->name, 0x0, check_type + 1);
		sprintf(current_unit->name, "%s_rside", current_unit->name);
	}

	return 0;
}

