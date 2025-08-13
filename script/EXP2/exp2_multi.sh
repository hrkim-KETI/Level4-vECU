#!/bin/sh

# 기본 설정
FMU_COUNT=80
START_PORT=33301
RESC_PATH="/home/hrkim/project/1_renodeVECU/renode/hrkim/Level4-vECU/script/EXP2/s32k148_exp2_ECU1.resc"
RENODE_PATH="renode"
MASTER_LOG="master.log"
LOG_DIR="log"

# 로그 디렉토리 생성
[ ! -d "$LOG_DIR" ] && mkdir -p "$LOG_DIR"


# FMU 실행 루프
i=1
while [ "$i" -le "$FMU_COUNT" ]; do
  PORT=`expr "$START_PORT" + "$i" - 1`
  LOGFILE="$LOG_DIR/vECU_${i}.log"


  echo "[INFO] Launching vECU $i on port $PORT..."
  (
    echo "Executing Renode with FMI=$PORT and RESC=$RESC_PATH"
    "$RENODE_PATH" --fmi "$PORT" --resc "$RESC_PATH"
    echo "Renode execution finished for FMI=$PORT"
  ) > "$LOGFILE" 2>&1 &

  i=`expr "$i" + 1`
  echo "[INFO] Waiting ~3s for next FMU to be ready..."
  sleep 2.5  # 보수적으로 기다려줌
done

# 모든 FMU 실행 후 메시지 출력 및 마스터 대기
echo "[INFO] All vECU processes launched."

