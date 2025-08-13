
clear all;

save_directory_path = './fmu/';

% Delete existing FMU files
delete([save_directory_path, '*.fmu']);

% Define fixed step value and other parameters
FixedStepVal = '0.001'; 
CanSpeed_bps_Val = 500000;
CanFDSpeed_bps_Val = 5000000;

% Initial port value and the number of FMUs to generate
portVal = int32(33300);
numCopies = 80; % Number of FMUs to generate


% Define additional variables used in the model
fmuNum = int32(0); % Initialize fmuNum
stepSize = str2double(FixedStepVal); % Calculate step size
assignin('base', 'fmuNum', fmuNum);
assignin('base', 'stepSize', stepSize);

% Load and configure the vECUcontroller model
load_system('./simulink/vECUcontroller.slx');
set_param('vECUcontroller', 'FixedStep', FixedStepVal);

for i = 1:numCopies
% Update portVal and fmuNum for each FMU generation
currentPortVal = portVal + 1;
fmuNum = i; % Update fmuNum for this iteration
% Assign updated values to the base workspace
assignin('base', 'portVal', int32(currentPortVal));  
assignin('base', 'fmuNum', int32(fmuNum));

% Export the FMU with a unique name
fmuName = sprintf('vECUcontroller_%d.fmu', i);
exportToFMU2CS('vECUcontroller', 'AddIcon', 'off', 'SaveSourceCodeToFMU', 'on', 'SaveDirectory', save_directory_path, 'FMUName', fmuName);
end

save_system;

% Load and configure the canBusModel
load_system('./simulink/canBusModel.slx');
set_param('canBusModel', 'FixedStep', FixedStepVal);
FixedStep_us = 1000000 * str2double(get_param('canBusModel', 'FixedStep'));
CanSpeed_bps = CanSpeed_bps_Val;
CanFDSpeed_bps = CanFDSpeed_bps_Val;

assignin('base', 'FixedStep_us', FixedStep_us);
assignin('base', 'CanSpeed_bps', CanSpeed_bps);
assignin('base', 'CanFDSpeed_bps', CanFDSpeed_bps);

exportToFMU2CS('canBusModel', 'AddIcon', 'off', 'SaveSourceCodeToFMU', 'on', 'SaveDirectory', save_directory_path);
save_system;

% Clean up generated temporary files
delete(['./', '*.slxc']);

disp(newline + "Export FMUs complete" + newline);
