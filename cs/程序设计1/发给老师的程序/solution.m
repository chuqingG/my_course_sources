function dMdt = solution(t,M)
%M中元素依次为x y z vx vy vz x1 y1 z1 vx1 vy1 vz1
g0 = 9.79;                   %地表处重力加速度大小
w0 = 7.292e-005;             %地球自转角速度
R = 8.31;                    %气体常数
T1 = 293;                    %发射时温度
u = 29;                      %大气近似相对分子质量
rho1 = 1.225;                %地表处大气密度
d = 0.2;                     %弹丸直径
C = 0.3;                     %全程阻力系数平均值
m = 200;                     %弹丸质量
theta0 = 84.823/180*pi;      %目标地相对于发射地的方位角
R0 = 6.371393e+006;          %地球半径
S = 0.25*pi*d^2;             %弹丸横截面积


dMdt = [M(4)
    M(5)
    M(6)
    -rho1*exp(-u*g0*(R0/(R0 + M(2)))^2*M(2)/(R*T1))/2*M(4)^2*S*C/m
    -rho1*exp(-u*g0*(R0/(R0 + M(2)))^2*M(2)/(R*T1))/2*M(5)^2*S*C/m - g0*(R0/(R0 + M(2)))^2
    -rho1*exp(-u*g0*(R0/(R0 + M(2)))^2*M(2)/(R*T1))/2*M(6)^2*S*C/m
    M(10)
    M(11)
    M(12)
    -rho1*exp(-u*g0*(R0/(R0 + M(2)))^2*M(2)/(R*T1))/2*M(4)^2*S*C/m - w0*M(12) - (3*3^(1/2)*w0^2*(R0 + M(2)))*sin(theta0)/8
    -rho1*exp(-u*g0*(R0/(R0 + M(2)))^2*M(2)/(R*T1))/2*M(5)^2*S*C/m - g0*(R0/(R0 + M(2)))^2 + (3*3^(1/2)*w0^2*(R0 + M(2)))/8 - 3^(1/2)*M(10)*w0*cos(theta0)
    -rho1*exp(-u*g0*(R0/(R0 + M(2)))^2*M(2)/(R*T1))/2*M(6)^2*S*C/m + w0*M(10) - (3*3^(1/2)*w0^2*(R0 + M(2)))*cos(theta0)/8 - 3^(1/2)*M(11)*w0*sin(theta0)];
