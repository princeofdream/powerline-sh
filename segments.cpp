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
	m_unit[segments_count] = (segment_unit*)malloc(sizeof(segment_unit));
	m_unit[segments_count]->name = (char*)malloc(strlen(item)+1);
	m_unit[segments_count]->value = (char*)malloc(MAXLEN);
	m_unit[segments_count]->pvalue = (char*)malloc(MAXLEN);
	m_unit[segments_count]->index = segments_count;
	sprintf(m_unit[segments_count]->name, "%s", item);
	JCG("segment [%s] address: 0x%x, name address: 0x%x, value: 0x%x",m_unit[segments_count]->name, m_unit[segments_count], m_unit[segments_count]->name, m_unit[segments_count]->value);
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
segments::get_segment_list_common(char** value_list, char* type, segmentaction action)
{
	int i0 = 0;
	int line_count = 0;
	char item_value[MAXLEN];

	*value_list = (char*)malloc(MAXLEN*2);
	memset(*value_list, 0x0, MAXLEN*2);

	JCG();
	if (type == NULL)
	{
		JEG("get list type can not be NULL");
		return -1;
	}

	while( i0 < segments_count )
	{
		if (strlen(m_unit[i0]->value) == 0) {
			i0++;
			continue;
		}

		if (strcmp(type, "output") == 0 && m_unit[i0]->pvalue != NULL && i0 != (segments_count -1))
			line_count = i0;
		i0++;
	}

	JJG("line end count is: %d, count from 0\n",line_count);

	i0 = 0;
	while( i0 < segments_count )
	{
		memset(item_value, 0x0, sizeof(item_value));
		JCG("type:%s. m_unit[%d] name: %s, value: %s",type, i0,m_unit[i0]->name,m_unit[i0]->value);
		if (strcmp(type, "name") == 0 && m_unit[i0]->name != NULL)
		{
				JJG("--------->><%s:%d>[%d:%d]value_list:%s\n",__FILE__,__LINE__,i0,segments_count,*value_list);
			sprintf(item_value,"%s",m_unit[i0]->name);
		}
		else if (strcmp(type, "value") == 0 && m_unit[i0]->value != NULL)
		{
				JJG("--------->><%s:%d>[%d:%d]value_list:%s\n",__FILE__,__LINE__,i0,segments_count,*value_list);
			sprintf(item_value,"%s",m_unit[i0]->value);
		}
		else if (strcmp(type, "pvalue") == 0 && m_unit[i0]->pvalue != NULL)
		{
				JJG("--------->><%s:%d>[%d:%d]value_list:%s\n",__FILE__,__LINE__,i0,segments_count,*value_list);
			sprintf(item_value,"%s",m_unit[i0]->pvalue);
		}
		else if (strcmp(type, "color") == 0 && m_unit[i0]->pvalue != NULL)
		{
				JJG("--------->><%s:%d>[%d:%d]value_list:%s\n",__FILE__,__LINE__,i0,segments_count,*value_list);
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
				JJG("%s\n",m_unit[i0]->name);
				JJG("--------->><%s:%d>[%d:%d]value_list:%s\n",__FILE__,__LINE__,i0,segments_count,*value_list);
				sprintf(item_value,"%s", color_str);
			}

			if (color_seperate_prebg != NULL && i0 != line_count && strcmp(m_unit[i0]->name, "newline") != 0)
			{
				JJG("[%d:%d]list:%s-------%s\n",i0,segments_count,item_value,color_seperate_prebg);
				sprintf(item_value,"%s%s", item_value, color_seperate_prebg);
			}
			else if (color_seperate_prebg != NULL && i0 == line_count)
			{
				JJG("--------->><%s:%d>[%d:%d]value_list:%s\n",__FILE__,__LINE__,i0,segments_count,*value_list);
				sprintf(item_value,"%s%s%s%s%s%s%s%s%s", item_value,
						SHELL_FG_BG_END, SHELL_COLOR_END,
						color_seperate_prebg,SEPERATE_SYMBOL,
						SHELL_FG_BG_END, SHELL_COLOR_END,
						SHELL_FG_BG_END, SHELL_COLOR_END);
			}

			if (strlen(*value_list) <= 0)
			{
				JJG("--------->><%s:%d>[%d:%d]value_list:%s\n",__FILE__,__LINE__,i0,segments_count,*value_list);
				sprintf(*value_list,"%s",item_value);
				JJG("=========>><%s:%d>[%d:%d]value_list:%s\n",__FILE__,__LINE__,i0,segments_count,*value_list);
			}
			else if (strlen(item_value) > 0 && i0 != segments_count - 1 && i0 != line_count)
			{
				JJG("--------->><%s:%d>[%d:%d]value_list:%s\n",__FILE__,__LINE__,i0,segments_count,*value_list);
				sprintf(*value_list,"%s%s%s%s%s%s",*value_list,color_seperate_bg, SEPERATE_SYMBOL, color_end,color_end, item_value);
				JJG("=========>><%s:%d>[%d:%d]value_list:%s\n",__FILE__,__LINE__,i0,segments_count,*value_list);
			}
			else if (strlen(item_value) > 0 && i0 != segments_count - 1 && i0 == line_count)
			{
				JJG("--------->><%s:%d>[%d:%d]value_list:%s\n",__FILE__,__LINE__,i0,segments_count,*value_list);
				// sprintf(*value_list,"%s%s%s%s%s%s",*value_list,color_seperate_bg, SEPERATE_SYMBOL, color_end,color_end, item_value);
				sprintf(*value_list,"%s%s%s%s",*value_list,color_seperate_bg, SEPERATE_SYMBOL, item_value);
				JJG("=========>><%s:%d>[%d:%d]value_list:%s\n",__FILE__,__LINE__,i0,segments_count,*value_list);
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
			JJG("--[%s:%d]--%d--\n",__FILE__,__LINE__,i0);
			sprintf(*value_list,"%s",item_value);
		}
		// else if (strlen(item_value) > 0)
			// sprintf(*value_list,"%s%s",*value_list,item_value);
		else if (strlen(item_value) > 0 && i0 != line_count)
		{
			JJG("--[%s:%d]--%d--\n",__FILE__,__LINE__,i0);
			sprintf(*value_list,"%s%s%s",*value_list,SEPERATE_SYMBOL,item_value);
		}
		else if (strlen(item_value) > 0 && i0 == line_count)
		{
			JJG("--[%s:%d]--%d--\n",__FILE__,__LINE__,i0);
			sprintf(*value_list,"%s%s%s%s%s%s",
					*value_list,SEPERATE_SYMBOL,
					SHELL_FG_BG_END, SHELL_COLOR_END,
					SHELL_FG_BG_END, SHELL_COLOR_END);
		}
		i0++;
	}
	return 0;
}

int
segments::get_segment_list(char** value_list)
{
	get_segment_list_common(value_list,"name", SEGMENT_ACTION_NORMAL);
	return 0;
}

int
segments::get_segment_value_list(char** value_list)
{
	get_segment_list_common(value_list,"value", SEGMENT_ACTION_NORMAL);
	return 0;
}

int
segments::get_segment_pvalue_list(char** value_list)
{
	get_segment_list_common(value_list,"pvalue", SEGMENT_ACTION_NORMAL);
}

int
segments::get_segment_color_list(char** value_list, segmentaction SEGMENT_ACTION_NORMAL)
{
	get_segment_list_common(value_list,"color", SEGMENT_ACTION_NORMAL);
	return 0;
}

int
segments::get_segment_output_list(char** value_list, segmentaction action)
{
	get_segment_list_common(value_list,"output", action);
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
	return 0;
}

int
segments::segment_get_foreground(char* name, segment_color** fg_color)
{
	return 0;
}

int
segments::segment_get_background(char* name, segment_color** bg_color)
{
	return 0;
}

int
segments::segment_set_color(segment_color* s_color)
{
	if (s_color != NULL)
		current_unit->color = *s_color;
	return 0;
}


