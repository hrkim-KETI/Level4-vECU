#!/bin/sh

FMU_COUNT=80
FMU_DIR="../../fmu"
OUTPUT="exp2.msim"

# 색상 목록 (공백으로 구분된 문자열로 저장)
COLORS="#ffd700 #20b2aa #a0522d #ffd700 #008000 #ffd700 #ffd700 #4682b4"

# 색상 배열을 문자열로 변환
get_color() {
  idx=$1
  n=1
  for color in $COLORS; do
    if [ "$n" -eq "$idx" ]; then
      echo "$color"
      return
    fi
    n=`expr $n + 1`
  done
  # 색상이 부족하면 처음 색상 사용
  echo "#cccccc"
}

# 헤더 작성
echo "# Auto-generated: `date`" > "$OUTPUT"
cat >> "$OUTPUT" <<EOF
tStart                   0 s
tEnd                     5 s
hMax                     30 min
hMin                     1e-05 s
hFallBackLimit           0.001 s
hStart                   0.001 s
hOutputMin               0.001 s
outputTimeUnit           s
adjustStepSize           no
preventOversteppingOfEndTime yes
absTol                   1e-06
relTol                   1e-05
MasterMode               GAUSS_JACOBI
ErrorControlMode         NONE
maxIterations            1
writeInternalVariables   no

simulator 0 0 canBusModel #4682b4 "$FMU_DIR/canBusModel.fmu"
EOF

# FMU simulator 추가
i=1
while [ "$i" -le "$FMU_COUNT" ]; do
  color_index=`expr \( \( "$i" - 1 \) % 8 \) + 1`
  color=`get_color "$color_index"`
  echo "simulator $i 0 vECUcontroller_$i $color \"$FMU_DIR/vECUcontroller_$i.fmu\"" >> "$OUTPUT"
  i=`expr "$i" + 1`
done

# graph 연결
i=1
echo "" >> "$OUTPUT"
while [ "$i" -le "$FMU_COUNT" ]; do
  echo "graph vECUcontroller_${i}.Out1 canBusModel.CAN_IN_${i}" >> "$OUTPUT"
  echo "graph canBusModel.CAN_OUT vECUcontroller_${i}.In1" >> "$OUTPUT"
  i=`expr "$i" + 1`
done

# 파라미터 설정
echo "" >> "$OUTPUT"
echo "parameter canBusModel.CanSpeed_bps   500000" >> "$OUTPUT"

echo "[✔] $OUTPUT 파일이 생성되었습니다 (sh compatible)."
