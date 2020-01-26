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
	if (src == 0) { /* src���굫��dstû�����꣬˵���϶����� */
		return FALSE;
	}
	if (src == '.') { /* ģ��ƥ�� */
		mask_flag = 1;
	}
	if (p[1] == '*') { /* ���ƥ�� */
		repeat_flag = 1;
	}
	if (dest == 0) { /* ��У�������Ϊ�ղ���ֱ��˵�������� */
		if (repeat_flag) { /* �п����Ƕ�*=0 */
			return isMatch(s, p+2);
		} else {
			return FALSE;
		}
	}
	if (repeat_flag == 1) {
		if (mask_flag == 1) { /* ����ģ��ƥ�䣬���ж��ƥ�� */
			return isMatch(s, p+2) || isMatch(s+1, p) || isMatch(s+1, p+2);
		} else { /* ���ж��ƥ�� */
			if (src != dest) { /* �������ĸ��ͬ��˵��*=0 */
				return isMatch(s, p+2);
			} else {
				return isMatch(s, p+2) || isMatch(s+1, p) || isMatch(s+1, p+2); /* ������������Ϊ*=0,*>1,*=1 */
			}
		}
	} else {
		if (mask_flag == 1) { /* ����ģ��ƥ��,��ʱ���� */
			return isMatch(s+1, p+1);
		} else { /* �ϸ�ƥ��, ������ȫ��Ȳ���������*/
			if (src == dest) {
				return isMatch(s+1, p+1);
			} else {
				return FALSE;
			}
		}
	}
}