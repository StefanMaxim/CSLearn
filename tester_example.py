import pytest
from unittest.mock import patch
import py2_ind_1_username  # Make sure this is your script's name without .py

# Define test cases as tuples: (temperature, pressure, expected_output_lines)
test_cases = [
    (314.15, 120.3, [
        "Temperature is within safe operating conditions.",
        "Pressure is within safe operating conditions."
    ]),
    (-3, 120.3, [
        "Error: Please enter a valid temperature."
    ]),
    (320, -5, [
        "Error: Please enter a valid pressure."
    ]),
    (304.2, 73.8, [
        "CO2 is at the critical point."
    ]),
    (315, 140, [
        "Temperature is within safe operating conditions.",
        "Warning! Reduce the pressure!",
        "Decrease the pressure by at least 9.85 bar."
    ]),
    (299, 80.5, [
        "CO2 is below the critical temperature.",
        "Increase the temperature by at least 5.20 Kelvin.",
        "Pressure is within safe operating conditions."
    ]),
    (349.3, 71.5, [
        "Warning! Reduce the temperature!",
        "Decrease the temperature by at least 22.37 Kelvin.",
        "CO2 is below the critical pressure.",
        "Increase the pressure by at least 2.30 bar."
    ])
]

@pytest.mark.parametrize("temperature, pressure, expected_lines", test_cases)
def test_co2_conditions(temperature, pressure, expected_lines):
    with patch("builtins.input", side_effect=[str(temperature), str(pressure)]), \
         patch("builtins.print") as mock_print:
        py2_ind_1_username.main()  # assuming your script has a main() function
        # Flatten all printed messages into a list of strings
        printed = [args[0] for args, _ in mock_print.call_args_list]
        for line in expected_lines:
            assert line in printed
