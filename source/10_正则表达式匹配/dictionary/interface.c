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
	if (src == 0) { /* src用完但是dst没有用完，说明肯定不行 */
		g_data[s_id][p_id] = FALSE;
		return FALSE;
	}
	if (src == '.') { /* 模糊匹配 */
		mask_flag = 1;
	}
	if (p[p_id+1] == '*') { /* 多次匹配 */
		repeat_flag = 1;
	}
	if (dest == 0) { /* 带校验的数据为空不能直接说明有问题 */
		if (repeat_flag) { /* 有可能是多*=0 */
			rst = isMatch_dic(s, s_id, p, p_id+2);
		    g_data[s_id][p_id] = rst;
			return rst;
		} else {
			g_data[s_id][p_id] = FALSE;
			return FALSE;
		}
	}
	if (repeat_flag == 1) {
		if (mask_flag == 1) { /* 既有模糊匹配，又有多次匹配 */
			rst = isMatch_dic(s, s_id, p, p_id+2) || isMatch_dic(s, s_id+1, p, p_id)
				|| isMatch_dic(s, s_id+1, p, p_id+2);
		    g_data[s_id][p_id] = rst;
			return rst;
		} else { /* 仅有多次匹配 */
			if (src != dest) { /* 如果首字母不同，说明*=0 */
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
		if (mask_flag == 1) { /* 仅有模糊匹配,此时跳过 */
			rst = isMatch_dic(s, s_id+1, p, p_id+1);
			g_data[s_id][p_id] = rst;
			return rst;
		} else { /* 严格匹配, 必须完全相等才能往后走*/
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