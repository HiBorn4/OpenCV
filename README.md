# Image Processing Labs in C++ with OpenCV

Welcome to the repository for executing various image processing labs using C++ and OpenCV. This README file provides detailed instructions on how to set up and run each lab. Each lab corresponds to specific image processing tasks, ranging from basic OpenCV functions to advanced techniques like histogram equalization, edge linking, and mathematical morphology.

## Table of Contents

- [Prerequisites](#prerequisites)
- [Installation](#installation)
- [Lab Descriptions and Execution](#lab-descriptions-and-execution)
  - [L2: Learning OpenCV Functions](#l2-learning-opencv-functions)
  - [L3: Learning OpenCV Functions and Animation](#l3-learning-opencv-functions-and-animation)
  - [LS: Annotation Tools](#ls-annotation-tools)
  - [L6: Find All the Connected Components in the Image](#l6-find-all-the-connected-components-in-the-image)
  - [L7: Improvise Your Method for Finding All the Connected Components in an Image](#l7-improvise-your-method-for-finding-all-the-connected-components-in-an-image)
  - [L8: Histogram Equalization](#l8-histogram-equalization)
  - [L9: Histogram Matching](#l9-histogram-matching)
  - [L10: Bilateral Filtering](#l10-bilateral-filtering)
  - [L11: Mathematical Morphology](#l11-mathematical-morphology)
  - [L12: Region Selection Followed by Boundary Detection and Thinning Using Mathematical Morphology](#l12-region-selection-followed-by-boundary-detection-and-thinning-using-mathematical-morphology)
  - [L13: Find Zero Crossings in LoG](#l13-find-zero-crossings-in-log)
  - [L14: Edge Linking](#l14-edge-linking)
  - [R1: Application of Image Processing](#r1-application-of-image-processing)
  - [R2: Improvize the Drawing with Mouse Lab Work](#r2-improvize-the-drawing-with-mouse-lab-work)
  - [R3: Resizing a Given Image](#r3-resizing-a-given-image)
  - [R4: Read Chapter 2 from the Textbook](#r4-read-chapter-2-from-the-textbook)
  - [R5: Read Chapter 3 from the Textbook](#r5-read-chapter-3-from-the-textbook)
  - [R6: OpenCV Function for Image Enhancement](#r6-opencv-function-for-image-enhancement)
- [Contributing](#contributing)
- [License](#license)

## Prerequisites

Before you begin, ensure you have the following software installed:

- **C++ Compiler**: GCC or any other C++ compiler.
- **OpenCV**: Version 4.x or later.
- **CMake**: For building the project.

## Installation

1. **Clone the repository**:
   ```sh
   git clone https://github.com/HiBorn/image-processing-labs.git
   cd image-processing-labs
   ```

2. **Build the project**:
   ```sh
   mkdir build
   cd build
   cmake ..
   make
   ```

## Lab Descriptions and Execution

### L2: Learning OpenCV Functions

Learn basic OpenCV functions such as image loading, displaying, and saving.

**Execution**:
```sh
./build/L2_basic_functions
```

### L3: Learning OpenCV Functions and Animation

Explore additional OpenCV functions and create simple animations.

**Execution**:
```sh
./build/L3_functions_and_animation
```

### LS: Annotation Tools

Implement annotation tools to mark and label images.

**Execution**:
```sh
./build/LS_annotation_tools
```

### L6: Find All the Connected Components in the Image

Find and label all connected components in a binary image.

**Execution**:
```sh
./build/L6_connected_components
```

### L7: Improvise Your Method for Finding All the Connected Components in an Image

Improve the method for detecting connected components for better accuracy and efficiency.

**Execution**:
```sh
./build/L7_improved_connected_components
```

### L8: Histogram Equalization

Enhance the contrast of an image using histogram equalization.

**Execution**:
```sh
./build/L8_histogram_equalization
```

### L9: Histogram Matching

Match the histogram of one image to another for consistent intensity distribution.

**Execution**:
```sh
./build/L9_histogram_matching
```

### L10: Bilateral Filtering

Apply bilateral filtering to reduce noise while preserving edges.

**Execution**:
```sh
./build/L10_bilateral_filtering
```

### L11: Mathematical Morphology

Perform morphological operations like erosion, dilation, opening, and closing.

**Execution**:
```sh
./build/L11_mathematical_morphology
```

### L12: Region Selection Followed by Boundary Detection and Thinning Using Mathematical Morphology

Select regions, detect boundaries, and apply thinning using morphological techniques.

**Execution**:
```sh
./build/L12_region_selection_boundary_thinning
```

### L13: Find Zero Crossings in LoG

Detect edges by finding zero crossings in the Laplacian of Gaussian.

**Execution**:
```sh
./build/L13_zero_crossings_log
```

### L14: Edge Linking

Link edges detected in an image to form continuous boundaries.

**Execution**:
```sh
./build/L14_edge_linking
```

### R1: Application of Image Processing

Explore various applications of image processing techniques.

**Execution**:
```sh
./build/R1_image_processing_applications
```

### R2: Improvize the Drawing with Mouse Lab Work

Enhance the functionality of mouse-based drawing applications.

**Execution**:
```sh
./build/R2_mouse_drawing_improvements
```

### R3: Resizing a Given Image

Implement and test different image resizing techniques.

**Execution**:
```sh
./build/R3_image_resizing
```

### R4: Read Chapter 2 from the Textbook

Read and understand Chapter 2 from the designated textbook.

### R5: Read Chapter 3 from the Textbook

Read and understand Chapter 3 from the designated textbook.

### R6: OpenCV Function for Image Enhancement

Utilize OpenCV functions to enhance image quality and features.

**Execution**:
```sh
./build/R6_image_enhancement
```

## Contributing

Contributions are welcome! Please read the [CONTRIBUTING.md](CONTRIBUTING.md) for guidelines on how to contribute to this project.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.