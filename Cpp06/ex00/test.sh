#!/bin/bash

# Define test cases
declare -A test_cases=(
    ["'a'"]="char: 'a'"
    ["42"]="int: 42"
    ["-42"]="int: -42"
    ["4.2f"]="float: 4.2f"
    ["4.2"]="double: 4.2"
    ["nan"]="double: nan"
    ["-inff"]="float: -inff"
    ["2147483648"]="int: impossible"
    ["'\\n'"]="char: Non displayable"
    ["abc"]="Error: invalid literal"
)

# Path to the executable
EXECUTABLE="./ConversionOfScalarTypes"

# Check if the program exists
if [[ ! -x $EXECUTABLE ]]; then
    echo "Error: $EXECUTABLE not found or not executable!"
    exit 1
fi

# Run tests
echo "Running tests..."
pass_count=0
fail_count=0

for input in "${!test_cases[@]}"; do
    expected_output="${test_cases[$input]}"
    output=$($EXECUTABLE "$input" 2>&1)  # Capture both stdout and stderr

    if echo "$output" | grep -q "$expected_output"; then
        echo "[PASS] Input: $input -> Expected: $expected_output"
        ((pass_count++))
    else
        echo "[FAIL] Input: $input"
        echo "       Expected: $expected_output"
        echo "       Got: $output"
        ((fail_count++))
    fi
done

# Print summary
echo "--------------------------------"
echo "Total Passed: $pass_count"
echo "Total Failed: $fail_count"

if [[ $fail_count -eq 0 ]]; then
    echo "✅ All tests passed!"
else
    echo "❌ Some tests failed."
fi

exit $fail_count  # Exit with the number of failed tests
