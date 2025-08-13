#!/bin/bash

# 변수 설정
YAML_FILE="adc_led_test.yaml"
JOBS=64
TOTAL_TESTS=128

# 실행
# YAMGEN.py $TOTAL_TESTS
time renode-test -t "$YAML_FILE" -j "$JOBS"
# time renode-test -t "$YAML_FILE"
