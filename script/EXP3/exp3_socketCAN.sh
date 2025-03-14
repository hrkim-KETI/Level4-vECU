#!/bin/bash

# Renode 인스턴스를 두 개 실행하여 각각의 vECU를 실행
renode -e "i @/home/hrkim/project/1_renodeVECU/renode/hrkim/Level4-vECU/script/EXP3/s32k148_exp3_ECU3_vcan.resc" & 
renode -e "i @/home/hrkim/project/1_renodeVECU/renode/hrkim/Level4-vECU/script/EXP3/s32k148_exp3_ECU4_vcan.resc" &