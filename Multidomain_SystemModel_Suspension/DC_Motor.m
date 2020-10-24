

J = 0.01;
b = 0.1;
K = 0.01;
R = 1;
L = 0.5;
s = tf('s');
P_motor = K/((J*s+b)*(L*s+R)+K^2)

A = [-b/J   K/J
    -K/L   -R/L];
B = [0
    1/L];
C = [1   0];
D = 0;
motor_ss = ss(A,B,C,D)

motor_ss = ss(P_motor);

Kp = 75;
Ki = 1;
Kd = 1;
C = pid(Kp,Ki,Kd);
sys_cl = feedback(C*P_motor,1);
step(sys_cl,[0:1:200])
title('PID Control with Small Ki and Small Kd')

%   Kp = 100;
%          Ki = 200;
%          Kd = 1;
%          C = pid(Kp,Ki,Kd);
%          sys_cl = feedback(C*P_motor,1);
%          step(sys_cl, 0:0.01:4)
%          grid
%          title('PID Control with Large Ki and Small Kd')