clear;
clc;

%% MATLAB Program 8-1

% ---------- Unit-step response ----------

num = [13.846 18 5.849];
den = [1 6 18.846 18 5.849];
step(num, den)
grid
title('Unit-Step Response')