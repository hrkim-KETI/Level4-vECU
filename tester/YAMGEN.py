import random
import sys

output_dir = "generated_tests"
max_tests = 4096

# 명령행 인자에서 total_tests 받아오기
if len(sys.argv) != 2:
    print(f"Usage: python {sys.argv[0]} <total_tests>")
    sys.exit(1)

total_tests = int(sys.argv[1])

if total_tests > max_tests or total_tests <= 0:
    print(f"Error: total_tests must be between 1 and {max_tests}")
    sys.exit(1)

# Create a list of all possible test cases
all_test_cases = list(range(max_tests))

# Randomly select the specified number of test cases
selected_test_cases = random.sample(all_test_cases, total_tests)

# Write the selected test cases to the yaml file
with open('adc_led_test.yaml', 'w') as yaml_file:
    for i in selected_test_cases:
        yaml_file.write(f'- {output_dir}/test_{i}.robot\n')
