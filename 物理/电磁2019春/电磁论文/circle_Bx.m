function Bx = circle_Bx(u0,x,z)
dBx =@(psi)(5*u0*z.*cos(psi))/sqrt((4*pi*(x.^2 +4- 4*x.*cos(psi))^3));
step = pi/20;
Bx = 0;
last = dBx(0);