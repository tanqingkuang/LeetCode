#include "../../../project/common.h"

char g_data[100][100] = {{0}};
bool isMatch_dic(char *s, int s_id, char *p, int p_id)
{
	char src = p[p_id];
	char dest = s[s_id];
	uint32 mask_flag = 0;
	uint32 repeat_flag = 0;
	bool rst;
	if (g_data[s_id][p_id] != -1) {
		return g_data[s_id][p_id];
	}
	if (dest == 0 && src == 0) {
		g_data[s_id][p_id] = TRUE;
		return TRUE;
	}
	if (src == 0) { /* src���굫��dstû�����꣬˵���϶����� */
		g_data[s_id][p_id] = FALSE;
		return FALSE;
	}
	if (src == '.') { /* ģ��ƥ�� */
		mask_flag = 1;
	}
	if (p[p_id+1] == '*') { /* ���ƥ�� */
		repeat_flag = 1;
	}
	if (dest == 0) { /* ��У�������Ϊ�ղ���ֱ��˵�������� */
		if (repeat_flag) { /* �п����Ƕ�*=0 */
			rst = isMatch_dic(s, s_id, p, p_id+2);
		    g_data[s_id][p_id] = rst;
			return rst;
		} else {
			g_data[s_id][p_id] = FALSE;
			return FALSE;
		}
	}
	if (repeat_flag == 1) {
		if (mask_flag == 1) { /* ����ģ��ƥ�䣬���ж��ƥ�� */
			rst = isMatch_dic(s, s_id, p, p_id+2) || isMatch_dic(s, s_id+1, p, p_id)
				|| isMatch_dic(s, s_id+1, p, p_id+2);
		    g_data[s_id][p_id] = rst;
			return rst;
		} else { /* ���ж��ƥ�� */
			if (src != dest) { /* �������ĸ��ͬ��˵��*=0 */
				rst = isMatch_dic(s, s_id, p, p_id+2);
				g_data[s_id][p_id] = rst;
				return rst;
			} else {
				rst = isMatch_dic(s, s_id, p, p_id+2) || isMatch_dic(s, s_id+1, p, p_id)
					|| isMatch_dic(s, s_id+1, p, p_id+2);
				g_data[s_id][p_id] = rst;
				return rst;
			}
		}
	} else {
		if (mask_flag == 1) { /* ����ģ��ƥ��,��ʱ���� */
			rst = isMatch_dic(s, s_id+1, p, p_id+1);
			g_data[s_id][p_id] = rst;
			return rst;
		} else { /* �ϸ�ƥ��, ������ȫ��Ȳ���������*/
			if (src == dest) {
				rst = isMatch_dic(s, s_id+1, p, p_id+1);
				g_data[s_id][p_id] = rst;
				return rst;
			} else {
				g_data[s_id][p_id] = FALSE;
				return FALSE;
			}
		}
	}
}

bool isMatch(char * s, char * p)
{
	memset(g_data, -1, sizeof(g_data));
	return isMatch_dic(s, 0, p, 0);
	
}