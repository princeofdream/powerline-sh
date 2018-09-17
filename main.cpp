/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  main
 *
 *        Version:  1.0
 *        Created:  05/07/2018 03:56:38 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  James Lee (JamesL), princeofdream@outlook.com
 *   Organization:  BookCL
 *
 * =====================================================================================
 */

#include <main.h>

common_share m_share;

int main(int argc, char *argv[])
{
	int i0 = 0, i1 = 0;
	char string_content[1024];
	int style;
	true_color fg;
	true_color bg;
	segment_unit *cwd_unit;
	char* segment_list = NULL;
	unsigned int color_value;
	unsigned int color_fg;
	unsigned int color_bg;
	segment_color s_color;
	int pre_process_stat = 0;

	memset(string_content,0x0,sizeof(string_content));
	style = 38;
	// sprintf(string_content,"\e[%d;%d;%dm=======\n",i0,5,48);
	// printf("\e[38;5;%dm\e[48;5;240m test[%d] \e[48;5;166m\e[38;5;%dm\n",i0,i0,i0);

	m_colortheme = new colortheme();
	// m_colortheme->show_256color_map();
	m_colortheme->get_color_theme(NULL);

	if (argc >= 2) {
		pre_process_stat = atoi(argv[1]);
	}

	m_sgmgr = new common_segment_manager();

	m_share.init_segment_color(&s_color);
	m_colortheme->get_color_by_name("USERNAME_FG",(unsigned short*)&color_fg);
	m_colortheme->get_color_by_name("USERNAME_BG",(unsigned short*)&color_bg);
	s_color.fg_color[SEGMENT_ACTION_NORMAL].red = color_fg;
	s_color.bg_color[SEGMENT_ACTION_NORMAL].red = color_bg;
	m_sgmgr->register_segment("user", &s_color);
	// m_sgmgr->segment_get_color(NULL,&s_color);

	m_colortheme->get_color_by_name("SSH_FG",(unsigned short*)&color_fg);
	m_colortheme->get_color_by_name("SSH_BG",(unsigned short*)&color_bg);
	s_color.fg_color[SEGMENT_ACTION_NORMAL].red = color_fg;
	s_color.bg_color[SEGMENT_ACTION_NORMAL].red = color_bg;
	m_sgmgr->register_segment("ssh", &s_color);

	/* ************************************** */
	// m_host = new host_segment();
	// m_host->register_segment("host");

	/* ************************************** */
	m_cwd = new cwd_segment();
	m_colortheme->get_color_by_name("PATH_FG",(unsigned short*)&color_fg);
	m_colortheme->get_color_by_name("PATH_BG",(unsigned short*)&color_bg);
	s_color.fg_color[SEGMENT_ACTION_NORMAL].red = color_fg;
	s_color.bg_color[SEGMENT_ACTION_NORMAL].red = color_bg;
	m_cwd->register_segment("cwd", &s_color);

	m_colortheme->get_color_by_name("PATH_STAT_FG",(unsigned short*)&color_fg);
	m_colortheme->get_color_by_name("PATH_STAT_BG",(unsigned short*)&color_bg);
	s_color.fg_color[SEGMENT_ACTION_NORMAL].red = color_fg;
	s_color.bg_color[SEGMENT_ACTION_NORMAL].red = color_bg;
	m_sgmgr->register_segment("path_stat", &s_color);

	/* ************************************** */

	if (pre_process_stat != 0)
	{
		m_colortheme->get_color_by_name("CMD_FAILED_FG",(unsigned short*)&color_fg);
		m_colortheme->get_color_by_name("CMD_FAILED_BG",(unsigned short*)&color_bg);
	}
	else
	{
		m_colortheme->get_color_by_name("CMD_PASSED_FG",(unsigned short*)&color_fg);
		m_colortheme->get_color_by_name("CMD_PASSED_BG",(unsigned short*)&color_bg);
	}
	s_color.fg_color[SEGMENT_ACTION_NORMAL].red = color_fg;
	s_color.bg_color[SEGMENT_ACTION_NORMAL].red = color_bg;
	m_sgmgr->register_segment("prompt", &s_color);

	m_colortheme->get_color_by_name("JOBS_FG",(unsigned short*)&color_fg);
	m_colortheme->get_color_by_name("JOBS_BG",(unsigned short*)&color_bg);
	s_color.fg_color[SEGMENT_ACTION_NORMAL].red = color_fg;
	s_color.bg_color[SEGMENT_ACTION_NORMAL].red = color_bg;
	m_sgmgr->register_segment("jobs", &s_color);

	m_colortheme->get_color_by_name("REPO_CLEAN_FG",(unsigned short*)&color_fg);
	m_colortheme->get_color_by_name("REPO_CLEAN_BG",(unsigned short*)&color_bg);
	s_color.fg_color[SEGMENT_ACTION_NORMAL].red = color_fg;
	s_color.bg_color[SEGMENT_ACTION_NORMAL].red = color_bg;
	m_sgmgr->register_segment("git", &s_color);

	m_colortheme->get_color_by_name("ANDROID_ENV_FG",(unsigned short*)&color_fg);
	m_colortheme->get_color_by_name("ANDROID_ENV_BG",(unsigned short*)&color_bg);
	s_color.fg_color[SEGMENT_ACTION_NORMAL].red = color_fg;
	s_color.bg_color[SEGMENT_ACTION_NORMAL].red = color_bg;
	m_sgmgr->register_segment("android_env", &s_color);

	m_colortheme->get_color_by_name("TIME_FG",(unsigned short*)&color_fg);
	m_colortheme->get_color_by_name("TIME_BG",(unsigned short*)&color_bg);
	s_color.fg_color[SEGMENT_ACTION_NORMAL].red = color_fg;
	s_color.bg_color[SEGMENT_ACTION_NORMAL].red = color_bg;
	// m_sgmgr->register_segment("time", &s_color);

	m_colortheme->get_color_by_name("PATH_FG",(unsigned short*)&color_fg);
	m_colortheme->get_color_by_name("PATH_BG",(unsigned short*)&color_bg);
	s_color.fg_color[SEGMENT_ACTION_NORMAL].red = color_fg;
	s_color.bg_color[SEGMENT_ACTION_NORMAL].red = color_bg;
	m_sgmgr->register_segment("newline", NULL);

	// m_sgmgr->get_segment_list(&segment_list);
	// JCG("segments list: %s",segment_list);
	if (segment_list!=NULL)
	{
		free(segment_list);
		segment_list = NULL;
	}
	m_sgmgr->get_segment_value_list(&segment_list);
	JCG("segments list: %s",segment_list);
	if (segment_list!=NULL)
	{
		free(segment_list);
		segment_list = NULL;
	}
	m_sgmgr->get_segment_color_list(&segment_list, SEGMENT_ACTION_NORMAL);
	JCG("segments list: %s",segment_list);
	if (segment_list!=NULL)
	{
		free(segment_list);
		segment_list = NULL;
	}

	m_sgmgr->get_segment_output_list(&segment_list, SEGMENT_ACTION_NORMAL);
	JCG("segments list: %s",segment_list);
	printf("%s\n",segment_list);
	// printf("-12345-\n");
	printf("%s%s%s%s%s%s",
		   SHELL_FG_BG_END, SHELL_COLOR_END,
		   SHELL_FG_BG_END, SHELL_COLOR_END,
		   SHELL_FG_BG_END, SHELL_COLOR_END);
	if (segment_list!=NULL)
	{
		free(segment_list);
		segment_list = NULL;
	}

	m_sgmgr->get_segment_pvalue_list(&segment_list);
	JCG("segments list: %s",segment_list);

	m_colortheme->get_color_by_name("TIME_BG", (unsigned short*)&color_value);
	JCG("get theme value: %d", color_value);

	if (segment_list!=NULL)
	{
		free(segment_list);
		segment_list = NULL;
	}
	if (m_colortheme != NULL)
	{
		free(m_colortheme);
		m_colortheme = NULL;
	}
	if (m_cwd != NULL)
	{
		free(m_cwd);
		m_cwd = NULL;
	}
	if (m_host != NULL)
	{
		free(m_host);
		m_host = NULL;
	}
	if (m_sgmgr != NULL)
	{
		free(m_sgmgr);
		m_sgmgr = NULL;
	}
	return 0;
}


