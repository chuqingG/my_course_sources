psi = pi/1440;                     %发射的偏角  
v0 = 1161.8952605;                 %发射的初速度
theta = pi/4;                      %发射的仰角
%M中元素依次为x y z vx vy vz x1 y1 z1 vx1 vy1 vz1
%下面给M赋初值
M0 = [0;0;0;v0*cos(theta)*cos(psi);v0*sin(theta);-v0*cos(theta)*sin(psi);0;0;0;v0*cos(theta)*cos(psi);v0*sin(theta);-v0*cos(theta)*sin(psi)];
tspan = [0 200];                   %大致预测的落地时间范围
%调用options进行过零检查，当y1 = 0，即大炮落地时终止
h = 110;
options = odeset('Events',@(t,M)odeEventFun(t,M,h));
[t,M] = ode15s(@solution,tspan,M0,options);      %求解微分方程

plot(t,M(:,7) - 131312,'r-','LineWidth',1.5);   %x1坐标到目标点距离与时间t的关系
hold on;
plot(t,M(:,8),'g-.','LineWidth',1.5);           %y1坐标与时间的关系
hold on;
plot(t,M(:,9),'b:','LineWidth',1.5);            %z1坐标与时间的关系
legend('x1(t)','y1(t)','z1(t)');
axis([0 250 0 150000]);
grid on;                                        %绘制网格便于观察
title('HFLC在地面非惯性系中的运动描述');