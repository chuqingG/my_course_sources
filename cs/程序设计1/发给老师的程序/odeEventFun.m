function [value,isterminal,direction] = odeEventFun(t,M)
%过零函数，控制y为0，即大炮落地时停止
value = M(8);
%命令过程终止
isterminal = 1;
%定义终止时的过零方向
direction=-1;     % 负方向，value递减方式过0