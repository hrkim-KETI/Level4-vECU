clear all;

save_directory_path = './fmu/';

delete([save_directory_path, '*.fmu']);

FixedStepVal = '0.00001'; 
CanSpeed_bps_Val = 500000;
CanFDSpeed_bps_Val = 5000000;

fmuNum = int32(0);
portVal = int32(7780);
stepSize = str2double(FixedStepVal);
%FixedStep_us = 1000000 * stepSize;

load_system('./simulink/vECUcontroller.slx');
set_param('vECUcontroller', 'FixedStep', FixedStepVal);
exportToFMU2CS('vECUcontroller','AddIcon','off','SaveSourceCodeToFMU','on','SaveDirectory',save_directory_path);
%exportToFMU2CS('fmu_can','AddIcon','off','SaveDirectory',save_directory_path);
save_system;

load_system('./simulink/canBusModel.slx');
set_param('canBusModel','FixedStep',FixedStepVal);
FixedStep_us = 1000000*str2double(get_param('canBusModel', 'FixedStep'));
CanSpeed_bps = CanSpeed_bps_Val;
CanFDSpeed_bps = CanFDSpeed_bps_Val;
exportToFMU2CS('canBusModel','AddIcon','off','SaveSourceCodeToFMU','on','SaveDirectory',save_directory_path);
% exportToFMU2CS('fmu_can_bus','AddIcon','off','SaveDirectory',save_directory_path);
save_system;

delete(['./', '*.slxc']);

disp(newline + "Export FMUs complete" + newline)

% Copy vECUcontroller.fmu to multiple files with numbered names
source_fmu = fullfile(save_directory_path, 'vECUcontroller.fmu');
num_copies = 5; % Number of copies to create

for i = 1:num_copies
    destination_fmu = fullfile(save_directory_path, sprintf('vECUcontroller_%d.fmu', i));
    copyfile(source_fmu, destination_fmu);
end