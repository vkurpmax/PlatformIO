clear;
clc;

%% MATLAB Program 8-1

% ---------- Unit-step response ----------

num = [6.3223 18 12.811];
den = [1 6 11.3223 18 12.811];
step(num, den)
grid
title('Unit-Step Response')