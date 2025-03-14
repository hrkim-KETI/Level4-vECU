#!/bin/bash

# Renode 실행 스크립트
# 변수 설정
FMI=33303
RESC_PATH="/home/hrkim/project/1_renodeVECU/renode/hrkim/Level4-vECU/script/EXP2/s32k148_exp2_ECU1.resc"

# Renode 명령 실행
echo "Executing Renode with FMI=$FMI and RESC=$RESC_PATH"
renode --fmi $FMI --resc "$RESC_PATH"

# 종료 메시지
echo "Renode execution finished."
