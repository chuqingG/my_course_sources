psi = pi/1440;                     %�����ƫ��  
v0 = 1161.8952605;                 %����ĳ��ٶ�
theta = pi/4;                      %���������
%M��Ԫ������Ϊx y z vx vy vz x1 y1 z1 vx1 vy1 vz1
%�����M����ֵ
M0 = [0;0;0;v0*cos(theta)*cos(psi);v0*sin(theta);-v0*cos(theta)*sin(psi);0;0;0;v0*cos(theta)*cos(psi);v0*sin(theta);-v0*cos(theta)*sin(psi)];
tspan = [0 200];                   %����Ԥ������ʱ�䷶Χ
%����options���й����飬��y1 = 0�����������ʱ��ֹ
h = 110;
options = odeset('Events',@(t,M)odeEventFun(t,M,h));
[t,M] = ode15s(@solution,tspan,M0,options);      %���΢�ַ���

plot(t,M(:,7) - 131312,'r-','LineWidth',1.5);   %x1���굽Ŀ��������ʱ��t�Ĺ�ϵ
hold on;
plot(t,M(:,8),'g-.','LineWidth',1.5);           %y1������ʱ��Ĺ�ϵ
hold on;
plot(t,M(:,9),'b:','LineWidth',1.5);            %z1������ʱ��Ĺ�ϵ
legend('x1(t)','y1(t)','z1(t)');
axis([0 250 0 150000]);
grid on;                                        %����������ڹ۲�
title('HFLC�ڵ���ǹ���ϵ�е��˶�����');