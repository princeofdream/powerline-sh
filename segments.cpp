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
segments::register_segment(char* item)
{
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
	m_unit[segments_count]->name     = (char*)malloc(strlen(item)+1);
	m_unit[segments_count]->value    = (char*)malloc(MAXLEN);
	m_unit[segments_count]->pvalue   = (char*)malloc(MAXLEN);
	m_unit[segments_count]->index    = segments_count;
	m_unit[segments_count]->leftside = true;

	sprintf(m_unit[segments_count]->name, "%s", item);

	memset(m_unit[segments_count]->value,0x0,MAXLEN);
	memset(m_unit[segments_count]->pvalue,0x0,MAXLEN);

	JCG("============>>> register segment [%s], value: %s, pvalue: %s, side:%s <<<================",
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
segments::get_segment_output_list(char** value_list, segmentaction action)
{
	char* value_list_left;
	char* value_list_right;

	JCG("Enter %s.", __FUNCTION__);

	*value_list = (char*)malloc(MAXLEN*4);
	memset(*value_list, 0x0, MAXLEN*4);

	get_segment_left_list_common(&value_list_left,"output", action);
	get_segment_right_list_common(&value_list_right,"output", action);

	sprintf(*value_list, "%s", value_list_left);
	// sprintf(*value_list, "%s---%s", value_list_left, value_list_right);
	return 0;
}

int
segments::get_segment_by_name(char* name, segment_unit** unit)
{
	int i0 = 0;
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
		else if (strcmp(m_unit[i0]->name, name) == 0)
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
	JCG("Enter %s.", __FUNCTION__);
	current_unit->leftside = leftside;
	return 0;
}

