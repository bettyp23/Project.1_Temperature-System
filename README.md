# Temperature Class Assignment

## Objective
This assignment provides practice with implementing classes in C++. You will create and use objects that store temperature data, which can be useful for applications like weather forecasting programs. The `Temperature` class should be portable and work with any up-to-date C++ compiler.

## Program Details and Requirements

### Class Overview
The `Temperature` class represents a temperature in terms of degrees (with decimal precision using `double`) and a scale (Celsius, Fahrenheit, or Kelvin). The class should ensure valid temperature values, such as preventing temperatures below 0 Kelvin. Additionally, the class allows multiple formats for displaying temperatures.

### Conversion Formulas
- Celsius = (Fahrenheit - 32) × (5/9)
- Fahrenheit = (Celsius × 9/5) + 32
- Celsius = Kelvin - 273.15

### Features and Functions

1. **Constructors**
   - Initialize a `Temperature` object with specified degrees and scale.
   - Invalid temperatures (e.g., below 0 Kelvin or invalid scales) will default to 0°C.

2. **Input Function**: `void Input()`
   - Prompts the user for temperature input in the format `degrees scale`.
   - Validates input and asks for re-entry on invalid values.
   
3. **Show Function**: `void Show()`
   - Displays the temperature in one of three formats:
     - **Default**: Degrees with default precision, and scale as uppercase letter.
     - **Precision-1**: Degrees with 1 decimal place and scale as uppercase letter.
     - **Long**: Degrees with default precision and scale as a full word (Celsius, Fahrenheit, or Kelvin).
   - Example: 50.4°C or 50.4316 Fahrenheit.

4. **Set Function**: `bool Set(double degrees, char scale)`
   - Sets the temperature to the provided degrees and scale if valid.
   - Returns `true` if successful, `false` otherwise.

5. **Accessor Functions**
   - `double GetDegrees()`: Returns the temperature in degrees.
   - `char GetScale()`: Returns the scale (C, F, K).

6. **Set Format Function**: `bool SetFormat(char format)`
   - Changes the display format based on the provided format code ('D', 'P', 'L').
   - Returns `true` if successful, `false` otherwise.

7. **Convert Function**: `bool Convert(char newScale)`
   - Converts the temperature to the specified new scale.
   - Returns `true` if successful, `false` otherwise.

8. **Compare Function**: `int Compare(const Temperature& other)`
   - Compares two `Temperature` objects:
     - Returns `-1` if the calling object is lower.
     - Returns `0` if the objects represent the same temperature.
     - Returns `1` if the parameter object is lower.

