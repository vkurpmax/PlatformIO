clear;
clc;

%% MATLAB Program 8-1

% ---------- Unit-step response ----------

num = [30.322 39.418 12.811];
den = [1 6 35.322 39.418 12.811];
step(num, den)
grid
title('Unit-Step Response')