syms a theta0 w0 y ax ay az v1x v1y v1z R0;
r0 = [0,(R0 + y)*sqrt(3)/2,0];
w = [w0*sin(theta0)*cos(pi/6),w0*sin(pi/6),w0*cos(pi/6)*cos(theta0)];
a1 = [ax,ay,az] - 2*cross(w,[v1x,v1y,v1z]) - cross(w,cross(w,r0))

%以下为上述程序在命令行窗口中的运行结果
a1 =
 
[ ax - v1z*w0 - (3*w0^2*sin(theta0)*(R0 + y))/8 + 3^(1/2)*v1y*w0*cos(theta0), ay + (3*3^(1/2)*w0^2*(R0 + y))/8 - 3^(1/2)*v1x*w0*cos(theta0) , az + v1x*w0 - (3*w0^2*cos(theta0)*(R0 + y))/8 - 3^(1/2)*v1y*w0*sin(theta0)]