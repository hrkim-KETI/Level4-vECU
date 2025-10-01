# Level4-vECU

Virtual ECU (Electronic Control Unit) implementation for Renode with FMI (Functional Mock-up Interface) integration.

## Overview

This project provides custom peripheral implementations for the S32K148 microcontroller platform in Renode, with FMI co-simulation support. It enables virtual ECU testing and development using hardware-in-the-loop (HIL) simulation through FMI integration.

## Features

- **S32K148 Peripheral Models** - Custom C# peripherals for Renode emulation
- **FMI Integration** - Co-simulation with MATLAB/Simulink FMU models
- **CAN Bus Support** - FlexCAN peripheral with FMI bridge
- **Multi-ECU Simulation** - Support for up to 80 vECU instances
- **Automated Deployment** - Scripts for copying peripherals to Renode installation

## Project Structure

```
Level4-vECU/
├── src/                    # C# peripheral implementations
│   ├── Analog/            # ADC peripherals
│   ├── CAN/               # FlexCAN controllers
│   ├── Timers/            # Timer peripherals
│   ├── Miscellaneous/     # Clock, SIM, PCC, etc.
│   ├── Extensions/        # FMIHandler.cs
│   ├── Network/           # FMICANReceiver.cs
│   └── Peripherals.csproj
│
├── fmi/                    # FMI co-simulation resources
│   ├── fmu/               # 81 FMU files (canBusModel, vECUcontroller_1-80)
│   ├── msim/              # Multi-Simulation experiments
│   ├── simulink/          # Simulink models
│   └── src/               # FMU source code
│
├── script/                 # Renode test scripts
├── tester/                 # Test utilities
├── copy.sh                 # Deploy peripherals to Renode
└── init.sh                 # Initialization script
```

## Implemented Peripherals

### Analog
- **S32K148_ADC**: Analog-to-Digital Converter

### CAN
- **S32K1XX_FlexCAN**: FlexCAN controller with FMI integration
- **FMICANReceiver**: FMI-based CAN message receiver

### Timers
- **S32K148_FTM**: FlexTimer Module
- **S32K148_LPIT**: Low Power Periodic Interrupt Timer

### Miscellaneous
- **S32K148_SCG**: System Clock Generator
- **S32K148_PCC**: Peripheral Clock Controller
- **S32K148_SIM**: System Integration Module
- **S32K148_RPC**: Reset and Power Control
- **S32K148_FTFC**: Flash Memory Controller
- **S32K148_DMATCD**: DMA Transfer Control Descriptor
- **LED**: Simple LED peripheral

### Extensions
- **FMIHandler**: FMI co-simulation handler

## Setup

### Prerequisites

- Renode emulator installed
- RENODE_HOME environment variable set
- .NET SDK (for building C# peripherals)
- MATLAB/Simulink with FMI Toolbox (optional, for FMU generation)

### Installation

1. **Set Renode path**:
```bash
export RENODE_HOME=/path/to/renode
```

2. **Deploy peripherals to Renode**:
```bash
./copy.sh
```

This script copies all peripheral implementations to your Renode installation:
- Timers → `${RENODE_HOME}/src/Infrastructure/src/Emulator/Peripherals/Peripherals/Timers/`
- Analog → `${RENODE_HOME}/src/Infrastructure/src/Emulator/Peripherals/Peripherals/Analog/`
- CAN → `${RENODE_HOME}/src/Infrastructure/src/Emulator/Peripherals/Peripherals/CAN/`
- And so on...

3. **Rebuild Renode** (if needed):
```bash
cd ${RENODE_HOME}
./build.sh
```

## FMI Co-Simulation

### FMU Models

The project includes 81 pre-built FMU files:
- **canBusModel.fmu**: CAN bus simulation model
- **vECUcontroller_1.fmu ~ vECUcontroller_80.fmu**: Individual vECU controller models

### Running Multi-Simulation

Example with 8 ECUs:
```bash
cd fmi/msim/EXP2
./exp2.sh
```

This launches a co-simulation with:
- 1 CAN bus model
- 8 vECU controller instances
- Synchronized execution through FMI

### Simulink Integration

The `fmi/simulink/` directory contains source models for FMU generation:
- vECU controller model
- CAN bus model
- Build scripts for FMU export

## Usage

### Running a Virtual ECU in Renode

1. Start Renode
2. Load your platform description (`.repl` file)
3. Execute test scripts from `script/` directory

Example:
```
(monitor) include @script/your_test_script.robot
```

### FMI-enabled CAN Communication

The FMIHandler extension enables bidirectional communication between Renode and FMU models:
- Renode → FMU: CAN TX messages
- FMU → Renode: CAN RX messages via FMICANReceiver

## Development

### Building Peripherals

```bash
cd src
dotnet build Peripherals.csproj
```

### Adding New Peripherals

1. Create new `.cs` file in appropriate `src/` subdirectory
2. Implement peripheral inheriting from Renode base classes
3. Update `copy.sh` to include new files
4. Run `./copy.sh` to deploy

### Generating New FMUs

1. Open Simulink models in `fmi/simulink/`
2. Modify as needed
3. Use FMI Toolbox to export FMU
4. Copy to `fmi/fmu/`

## Testing

Test scripts in `script/` directory use Robot Framework syntax for Renode testing.

Example test structure:
```robot
*** Keywords ***
Setup
    Create Machine
    Execute Command    sysbus LoadELF @path/to/firmware.elf

*** Test Cases ***
Should Run Test
    Setup
    Start Emulation
    # Test assertions...
```

## Technical Details

### FMI Integration Architecture

```
┌─────────────────┐
│  Renode vECU    │
│  (C# Peripherals)│
└────────┬────────┘
         │ FMIHandler
         ↓
┌─────────────────┐
│  FMU Models     │
│  (Simulink)     │
└─────────────────┘
```

- **FMIHandler.cs**: Manages FMI slave instances, coordinates time stepping
- **FMICANReceiver.cs**: Receives CAN messages from FMU and injects into Renode CAN bus
- **S32K1XX_FlexCAN**: Extended to support FMI output for transmitted messages

### Multi-ECU Synchronization

- Master simulation coordinator (msim)
- Synchronized time stepping across all FMU instances
- Event-based communication through CAN bus model

## Known Issues

- FMI time synchronization may drift in long-running simulations
- Some S32K148 peripherals are simplified models (not all registers implemented)

## Contributing

When adding new features:
1. Follow existing C# coding style
2. Update `copy.sh` if adding new files
3. Document new peripherals in README
4. Test with actual firmware before committing

## License

MIT

## References

- [Renode Documentation](https://renode.readthedocs.io/)
- [FMI Standard](https://fmi-standard.org/)
- [S32K1xx Reference Manual](https://www.nxp.com/docs/en/reference-manual/S32K1XXRM.pdf)

### Related Publications

- Kim, H.; et al. (2024). "Virtual ECU Acceleration Framework Using Multi-Core Architecture for Electronic Controller Development." *Electronics*, 13(18), 3704. https://doi.org/10.3390/electronics13183704
- Kim, H.; et al. (2025). "Framework for Rapid and Cost-Effective Development of Automotive Electronic Controllers." *Electronics*, 14(8), 1690. https://doi.org/10.3390/electronics14081690

## Authors

- Hyeongrae Kim (hn02301@gmail.com, hrsin09@keti.re.kr)
