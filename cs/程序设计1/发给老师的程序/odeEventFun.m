function [value,isterminal,direction] = odeEventFun(t,M)
%���㺯��������yΪ0�����������ʱֹͣ
value = M(8);
%���������ֹ
isterminal = 1;
%������ֹʱ�Ĺ��㷽��
direction=-1;     % ������value�ݼ���ʽ��0