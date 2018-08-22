/*
 * =====================================================================================
 *
 *       Filename:  common_share.cpp
 *
 *    Description:  common share
 *
 *        Version:  1.0
 *        Created:  05/23/2018 11:51:53 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  James Lee (JamesL), princeofdream@outlook.com
 *   Organization:  BookCL
 *
 * =====================================================================================
 */

#include <basic.h>
#include <common_share.h>

char* config_path[] = {
	".",
	"$HOME",
};

common_share::common_share()
{
}

common_share::~common_share()
{
}

int
common_share::get_config_file(int* fd, char* name, char* extern_path)
{
	int i0;
	char config_file[MAXLEN];
	char config_name[MAXLEN];
	char* m_path;
	int fd0 = -1;

	memset(config_name,0x0,sizeof(config_name));
	if (name == NULL)
		sprintf(config_name, "%s", DEFAULT_THEME_CONFIG_FILE_NAME);
	else
		sprintf(config_name, "%s", name);

	if (extern_path != NULL)
	{
		memset(config_file,0x0,sizeof(config_file));
		sprintf(config_file, "%s/%s",extern_path, config_name);
		fd0 = open(config_file,O_RDWR);
		if (fd0 < 0)
		{
			memset(config_file,0x0,sizeof(config_file));
			sprintf(config_file, "%s",extern_path);
			fd0 = open(config_file,O_RDWR);
		}
	}

	if (fd0 < 0)
	{
		i0 = 0;
		m_path = getenv("HOME");
		while(i0 < sizeof(config_path)/sizeof(config_path[0]))
		{
			memset(config_file,0x0,sizeof(config_file));

			if (strcmp("$HOME",config_path[i0]) == 0)
				sprintf(config_file, "%s/%s",m_path,config_name);
			else
				sprintf(config_file, "%s/%s",config_path[i0],config_name);
			fd0 = open(config_file,O_RDWR);
			JCG("load config from: %s",config_file);
			if (fd0 > 0)
			{
				JCG("get config: %s", config_file);
				break;
			}
			i0++;
		}
	}

	*fd = fd0;

	// if (fd0 > 0)
		// close(fd0);

	return 0;
}

int
common_share::init_segment_color(segment_color* s_color)
{
	(s_color)->fg_color[SEGMENT_ACTION_NORMAL].red     = 244;
	(s_color)->fg_color[SEGMENT_ACTION_NORMAL].blue    = 0;
	(s_color)->fg_color[SEGMENT_ACTION_NORMAL].green   = 0;
	(s_color)->fg_color[SEGMENT_ACTION_ACTIVE].red     = 245;
	(s_color)->fg_color[SEGMENT_ACTION_ACTIVE].blue    = 0;
	(s_color)->fg_color[SEGMENT_ACTION_ACTIVE].green   = 0;
	(s_color)->fg_color[SEGMENT_ACTION_DEACTIVE].red   = 246;
	(s_color)->fg_color[SEGMENT_ACTION_DEACTIVE].blue  = 0;
	(s_color)->fg_color[SEGMENT_ACTION_DEACTIVE].green = 0;
	(s_color)->fg_color[SEGMENT_ACTION_WARNING].red    = 247;
	(s_color)->fg_color[SEGMENT_ACTION_WARNING].blue   = 0;
	(s_color)->fg_color[SEGMENT_ACTION_WARNING].green  = 0;
	(s_color)->fg_color[SEGMENT_ACTION_ERROR].red      = 248;
	(s_color)->fg_color[SEGMENT_ACTION_ERROR].blue     = 0;
	(s_color)->fg_color[SEGMENT_ACTION_ERROR].green    = 0;

	(s_color)->bg_color[SEGMENT_ACTION_NORMAL].red     = 244;
	(s_color)->bg_color[SEGMENT_ACTION_NORMAL].blue    = 0;
	(s_color)->bg_color[SEGMENT_ACTION_NORMAL].green   = 0;
	(s_color)->bg_color[SEGMENT_ACTION_ACTIVE].red     = 245;
	(s_color)->bg_color[SEGMENT_ACTION_ACTIVE].blue    = 0;
	(s_color)->bg_color[SEGMENT_ACTION_ACTIVE].green   = 0;
	(s_color)->bg_color[SEGMENT_ACTION_DEACTIVE].red   = 246;
	(s_color)->bg_color[SEGMENT_ACTION_DEACTIVE].blue  = 0;
	(s_color)->bg_color[SEGMENT_ACTION_DEACTIVE].green = 0;
	(s_color)->bg_color[SEGMENT_ACTION_WARNING].red    = 247;
	(s_color)->bg_color[SEGMENT_ACTION_WARNING].blue   = 0;
	(s_color)->bg_color[SEGMENT_ACTION_WARNING].green  = 0;
	(s_color)->bg_color[SEGMENT_ACTION_ERROR].red      = 248;
	(s_color)->bg_color[SEGMENT_ACTION_ERROR].blue     = 0;
	(s_color)->bg_color[SEGMENT_ACTION_ERROR].green    = 0;


	return 0;
}

int
common_share::run_cmd(char* cmd, char** result)
{
	pid_t m_pid;
	int i0 = 0;
	int ret;
	char* rt_cmd[8];
	char buf[MAXLEN];
	int cmd_pipe_fd0[2];
	int read_byte;

	if (*result == NULL) {
		*result = (char*)malloc(MAXLEN);
		memset(*result,0x0,MAXLEN);
	}

	JCG("size: %d",sizeof(rt_cmd)/sizeof(rt_cmd[0]));
	while(i0 < sizeof(rt_cmd)/sizeof(rt_cmd[0]))
	{
		rt_cmd[i0] = (char*)malloc(MAXLEN);
		memset(rt_cmd[i0],0x0,MAXLEN);
		i0++;
	}

	sscanf(cmd,"%s %s %s %s %s %s %s %s",\
		   rt_cmd[0],rt_cmd[1],rt_cmd[2],rt_cmd[3],\
		   rt_cmd[4],rt_cmd[5],rt_cmd[6],rt_cmd[7]);
	JCG("run command: \"[0]%s [1]%s [2]%s [3]%s [4]%s [5]%s [6]%s [7]%s\"",\
		rt_cmd[0],rt_cmd[1],rt_cmd[2],rt_cmd[3],\
		rt_cmd[4],rt_cmd[5],rt_cmd[6],rt_cmd[7]);

	pipe(cmd_pipe_fd0);

	m_pid = fork();
	if (m_pid > 0) {
		JCG("fork success!");
		close(cmd_pipe_fd0[1]);
		while(1)
		{
			memset(buf,0x0,sizeof(buf));
			read_byte = read(cmd_pipe_fd0[0],buf,sizeof(buf));
			JCG("buf: %s",buf);
			if(read_byte == 0)
				break;
		}

	} else if (m_pid == 0) {
		close(cmd_pipe_fd0[0]);
		dup2(cmd_pipe_fd0[1], STDOUT_FILENO);
		memset(buf,0x0,sizeof(buf));
		ret = execvp(rt_cmd[0], rt_cmd);
		sprintf(buf,"%s",strerror(errno));
		JCG("Error: %s",buf);
		// write(cmd_pipe_fd1[1],buf,strlen(buf));
	} else {
	}
	wait(NULL);

	sprintf(*result, "%s", "11234");
	i0 = 0;
	while(i0 < sizeof(rt_cmd)/sizeof(rt_cmd[0]))
	{
		JCG("free %d", i0);
		free(rt_cmd[i0]);
		i0++;
	}
	JCG();
	close(cmd_pipe_fd0[0]);
	close(cmd_pipe_fd0[1]);
	return 0;
}


int
common_share::command_stream(char* cmd, char** result)
{
	char buf[MAXLEN];
	char m_val[MAXLEN];
	FILE *cmd_stream;
	unsigned int buf_len;
	unsigned int read_byte;
	bool end_of_file;
	int rc;
	char full_cmd[MAXLEN];

	if (*result == NULL) {
		*result = (char*)malloc(MAXLEN);
		memset(*result,0x0,MAXLEN);
	}

	memset(full_cmd,0x0, sizeof(full_cmd));
	sprintf(full_cmd,"%s 2>/dev/null",cmd);
	JCG("command: %s", cmd);
	close(STDERR_FILENO);
	cmd_stream = popen(full_cmd,"r");
	/* if(cmd_stream == NULL) */
	JCG("by James %s",strerror(errno));
	while(1)
	{
		memset(m_val,0x0,sizeof(m_val));
		buf_len = 0;
		end_of_file = false;
		while(1)
		{
			memset(buf,0x0,sizeof(buf));
			/* read_byte = fread(buf, sizeof(char), 16, cmd_stream); */
			read_byte = fread(buf, sizeof(char), sizeof(buf) - 2, cmd_stream);
			if(read_byte <= 0)
			{
				JCG("by James %s",strerror(errno));
				JCG("finish");
				end_of_file = true;
				break;
			}
			buf_len+= read_byte;
			sprintf(m_val,"%s%s",m_val,buf);
			if(buf_len >= MAXLEN - 16)
				break;
		}
		JCG("%s",m_val);
		sprintf(*result,"%s%s",*result,m_val);
		if(end_of_file)
			break;
	}
	pclose(cmd_stream);
	return NULL;
}

int
common_share::GetLocalTime(char** value)
{
	int m_sec  = 0;
	int m_min  = 0;
	int m_hour = 0;
	int m_day  = 0;
	int m_year = 0;

	struct tm *m_tm;
	struct tm *r_tm;
	time_t m_time;
	struct timeval d_tv;
	char* to_str = NULL;

	time(&m_time);
	//r_tm = localtime_r(&m_time, m_tm);
	r_tm = localtime(&m_time);
	gettimeofday(&d_tv,NULL);

	m_sec = d_tv.tv_sec;
	m_min = m_sec/60;
	m_hour = m_min/60;
	m_day = m_hour/24;
	m_year = m_day/365;

	JCG();

	if (*value == NULL) {
		*value = (char*)malloc(MAXLEN);
		memset(*value,0x0,MAXLEN);
	} else {
		return -1;
	}

	JCG();
	Conv_Time_Set_to_String(r_tm, &to_str);
	JCG("current time: %s",to_str);
	sprintf(*value, "%s", to_str);

	if (to_str != NULL) {
		free(to_str);
		to_str = NULL;
	}
	JCG();
	return 0;
}

int
common_share::Conv_Time_Set_to_String(struct tm *m_tm, char** value)
{
	char m_time_str[MAXLEN];
	memset(m_time_str,0x0,sizeof(m_time_str));
	// sprintf(m_time_str,"%d/%d/%d %d:%d:%d weekday:%d yearday:%d dst:%d \n",
		// (*m_tm).tm_year+1900,(*m_tm).tm_mon+1,(*m_tm).tm_mday,
		// (*m_tm).tm_hour,(*m_tm).tm_min,(*m_tm).tm_sec,
		// (*m_tm).tm_wday+1,(*m_tm).tm_yday,(*m_tm).tm_isdst);

	sprintf(m_time_str,"%d-%d-%d %d:%d:%d",
		(*m_tm).tm_year+1900,(*m_tm).tm_mon+1,(*m_tm).tm_mday,
		(*m_tm).tm_hour,(*m_tm).tm_min,(*m_tm).tm_sec);

	if (*value == NULL) {
		*value = (char*)malloc(MAXLEN);
		memset(*value,0x0,MAXLEN);
	} else {
		return -1;
	}

	sprintf(*value, "%s", m_time_str);
	JCG("%s",m_time_str);

	return	0;
}


