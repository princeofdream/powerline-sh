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

	memset(string_content,0x0,sizeof(string_content));
	style = 38;
	// sprintf(string_content,"\e[%d;%d;%dm=======\n",i0,5,48);
	// printf("\e[38;5;%dm\e[48;5;240m test[%d] \e[48;5;166m\e[38;5;%dm\n",i0,i0,i0);

	m_colortheme = new colortheme();
	// m_colortheme->show_256color_map();
	m_colortheme->get_color_theme(NULL);



	m_sgmgr = new common_segment_manager();
	m_sgmgr->register_segment("user");
	m_sgmgr->register_segment("ssh");

	/* ************************************** */
	// m_host = new host_segment();
	// m_host->register_segment("host");

	/* ************************************** */
	m_cwd = new cwd_segment();
	m_cwd->register_segment("cwd");

	/* ************************************** */
	m_sgmgr->register_segment("git");
	m_sgmgr->register_segment("prompt");

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
		delete(m_colortheme);
		m_colortheme = NULL;
	}
	if (m_cwd != NULL)
	{
		delete(m_cwd);
		m_cwd = NULL;
	}
	if (m_host != NULL)
	{
		delete(m_host);
		m_host = NULL;
	}
	if (m_sgmgr != NULL)
	{
		delete(m_sgmgr);
		m_sgmgr = NULL;
	}
	return 0;
}


