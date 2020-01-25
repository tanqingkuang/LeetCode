#include "../../../project/common.h"

bool isMatch(char * s, char * p)
{
	char src = *p;
	char dest = *s;
	uint32 mask_flag = 0;
	uint32 repeat_flag = 0;
	if (dest == 0 && src == 0) {
		return TRUE;
	}
	if (src == 0) { /* src用完但是dst没有用完，说明肯定不行 */
		return FALSE;
	}
	if (src == '.') { /* 模糊匹配 */
		mask_flag = 1;
	}
	if (p[1] == '*') { /* 多次匹配 */
		repeat_flag = 1;
	}
	if (dest == 0) { /* 带校验的数据为空不能直接说明有问题 */
		if (repeat_flag) { /* 有可能是多*=0 */
			return isMatch(s, p+2);
		} else {
			return FALSE;
		}
	}
	if (repeat_flag == 1) {
		if (mask_flag == 1) { /* 既有模糊匹配，又有多次匹配 */
			return isMatch(s, p+2) || isMatch(s+1, p) || isMatch(s+1, p+2);
		} else { /* 仅有多次匹配 */
			if (src != dest) { /* 如果首字母不同，说明*=0 */
				return isMatch(s, p+2);
			} else {
				return isMatch(s, p+2) || isMatch(s+1, p) || isMatch(s+1, p+2); /* 从左至右依次为*=0,*>1,*=1 */
			}
		}
	} else {
		if (mask_flag == 1) { /* 仅有模糊匹配,此时跳过 */
			return isMatch(s+1, p+1);
		} else { /* 严格匹配, 必须完全相等才能往后走*/
			if (src == dest) {
				return isMatch(s+1, p+1);
			} else {
				return FALSE;
			}
		}
	}
}