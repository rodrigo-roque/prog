# Image Processor (Scrim)

![C++](https://img.shields.io/badge/C++17-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![CMake](https://img.shields.io/badge/CMake-064F8C?style=for-the-badge&logo=cmake&logoColor=white)
![Grade](https://img.shields.io/badge/Grade-19.8%2F20.0-success?style=for-the-badge)

This project consists of an image processor built in C++ (C++17). The program reads and executes script files (`.scrim`), which contain a sequence of image editing commands to apply successive transformations (a pipeline).

## Project Structure

*   **`src/` and `include/`**: C++ source code and headers.
    *   **Main classes**: `Image` (matrix representation of pixels), `Color` (RGB values), `Scrim` (command pipeline), and `ScrimParser` (script file reader).
    *   **`Command/`**: Implementation of the various image operations, utilizing the object-oriented *Command* design pattern.
*   **`main/`**: Program entry points.
    *   **`RunScrim.cpp`**: Main executable to run `.scrim` scripts.
    *   **`Tester.cpp`**: Automated testing tool.
*   **`scrims/`**: Directory containing script files (`.scrim`) for examples or testing.
*   **`input/`**: Initial or secondary images that scripts can load (PNG format).
*   **`output/`**: Destination folder for images generated after command execution.
*   **`expected/`**: "Template" images with the correct results for automated validation in the testing system.

## How to Build

The project uses **CMake** for configuration and compilation. You must have CMake installed (minimum version 3.15) and a compiler with C++17 support.

```bash
mkdir build
cd build
cmake ..
make
```

This process will generate two executables in the `build/` folder: `runscrim` and `tester`.

## How to Run

### 1. Running Scripts (RunScrim)

To execute `.scrim` instruction files, use `runscrim` passing the files as arguments:

```bash
./build/runscrim scrims/file1.scrim scrims/file2.scrim
```

### 2. Testing the Code (Tester)

The `tester` executable reads the test files in the `scrims/` folder, executes them, generates images in the `output/` directory, and finally compares them automatically with the images present in `expected/`.

```bash
# Run all tests
./build/tester

# Run only a specific group of tests (e.g., tests containing "chain" in their name)
./build/tester chain
```

## Scrim Language (Supported Commands)

A `.scrim` file contains plain text where each operation is defined by its name followed by its arguments (separated by spaces or line breaks).

### Basic Operations
*   `blank <w> <h> <r> <g> <b>`: Creates a new blank image with dimensions `<w> <h>`, filled with the RGB color `<r> <g> <b>`.
*   `open <filename>`: Opens an image saved in the file system (e.g., `input/image.png`).
*   `save <filename>`: Saves the current state of the image to the specified path (e.g., `output/result.png`).

### Drawing and Editing
*   `fill <x> <y> <w> <h> <r> <g> <b>`: Draws a rectangle starting from the coordinate `<x> <y>` with dimensions `<w> <h>`, using the specified color.
*   `replace <r1> <g1> <b1> <r2> <g2> <b2>`: Globally replaces all pixels that have the base RGB color 1 with the new RGB color 2.
*   `add <filename> <r_transp> <g_transp> <b_transp> <x> <y>`: Pastes the specified image over the current image at the coordinate `<x> <y>`. The color indicated by the `transp` parameters is treated as a transparent background.

### Color Effects
*   `invert`: Inverts all colors of the image (creates a negative effect).
*   `to_gray_scale`: Converts the color image to grayscale.

### Geometry and Transformations
*   `crop <x> <y> <w> <h>`: Crops the image by limiting it to the specified rectangle.
*   `resize <x> <y> <w> <h>`: Resizes an area/image.
*   `scaleup <factor_x> <factor_y>`: Scales up the image by multiplying its original dimensions by the provided factors.
*   `h_mirror`: Mirrors the image horizontally.
*   `v_mirror`: Mirrors the image vertically.
*   `rotate_left`: Rotates the image 90º to the left (counter-clockwise).
*   `rotate_right`: Rotates the image 90º to the right (clockwise).
*   `move <x> <y>`: Moves the visual content of the image.
*   `slide <x> <y>`: Applies the content shift with a cyclic behavior at the edges.

### Execution Control
*   `chain`: Allows reading and executing commands from other `.scrim` files. File names must be listed line by line, and the list ends with the word `end`. Example:
    ```
    chain
    scrims/extra1.scrim
    scrims/extra2.scrim
    end
    ```
