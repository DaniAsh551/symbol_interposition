# Symbol Interposition / Function Interception Introduction and Demo

## Overview

This project aims to demonstrate the concept of "symbol interposition" or "function interception" in the context of C programming. Symbol interposition is a technique that allows developers to intercept or replace symbols (functions or variables) with custom implementations at runtime.

## Goal

The primary goal of this project is to teach developers about the concept of symbol interposition through a practical example. The project includes two systems (system_a and system_b) with variations in the shared library `libsmallmath`. The `smallmathtest` binary, compiled against `libsmallmath` on system_a, is used to showcase how to make it compatible with the different implementations of `libsmallmath` on system_b.

## Use Case Examples in realworld

### 1. Compatibility Example: gcompat

    Scenario:
        Description: The gcompat project aims to provide compatibility libraries for games and applications that rely on specific versions of the GNU C Library (glibc).
        Use Case: Imagine you have a game binary compiled on a system with a certain glibc version. When you try to run the game on a system with a different glibc version, you may encounter compatibility issues due to changes in function signatures or missing functions.
        Solution: gcompat can provide a compatibility layer by intercepting and redirecting certain functions to equivalent versions in the system's glibc, ensuring the smooth execution of the game.

### 2. Compatibility Example: virgl in Virtualization

    Scenario:
        Description: The virgl project is related to graphics virtualization in virtual machines (VMs). It provides a virtual 3D GPU for virtual machines to enable accelerated graphics rendering.
        Use Case: Consider a virtualized environment where a VM is running a graphics-intensive application. To achieve optimal performance, the VM may need to interact with a specialized graphics library. However, the host system might have a different graphics stack.
        Solution: virgl can use symbol interposition to intercept graphics-related function calls from the VM and translate them into compatible calls that work with the host system's graphics stack.

### 3. Instrumentation Example: LD_PRELOAD for Profiling

    Scenario:
        Description: In software development, profiling tools are used to analyze the runtime behavior of programs and identify performance bottlenecks.
        Use Case: You want to profile a complex application without modifying its source code to insert profiling calls.
        Solution: Using LD_PRELOAD, you can load a shared library that intercepts specific functions and adds profiling code. This allows you to instrument the application with profiling logic without changing the original code.

### 4. Security Example: Function Hooking for Security Checks

    Scenario:
        Description: In cybersecurity, function hooking is a technique used for security monitoring and intrusion detection.
        Use Case: Suppose you want to monitor network-related functions in a program to detect suspicious activity.
        Solution: By using function hooking, you can intercept calls to network-related functions and add security checks or logging. This enables the detection of unusual network behavior without modifying the original program.

## Project Structure

The project consists of two systems:

- **System_a:**
  - `libsmallmath`: Shared library with a set of functions (e.g., add, sub, mult, div, pow).
  - `smallmathtest`: Binary compiled against `libsmallmath` on system_a.

- **System_b:**
  - `libsmallmath`: Shared library with a subset of functions (e.g., add, sub).
  - `libfakesmallmath`: Shared library providing missing functions for compatibility.
  - `smallmathtest`: Binary designed to run on system_a but made compatible with `libsmallmath` on system_b using `libfakesmallmath`.

## How to Use

1. **Build Libraries and Binary:**
   - Run `make all` to build the libraries and the `smallmathtest` binary.

2. **Run Test without Fake Library:**
   - Run `make run` to execute `smallmathtest` on system_a.

3. **Run Test with Fake Library (System_b Compatibility):**
   - Run `make run_fake` to execute `smallmathtest` on system_b with symbol interposition.

4. **Clean Project:**
   - Run `make clean` to remove generated files.

## Important Notes

- The `libsmallmath` on system_a and system_b have different sets of functions.
- The `libfakesmallmath` on system_b provides missing functions for compatibility.
- The `smallmathtest` binary runs successfully on both system_a and system_b after symbol interposition.

## Learn More

To understand the internals and how symbol interposition is achieved, refer to the provided source code, Makefile, and the comments within.

## License

This project is open-source and distributed under the [MIT License](LICENSE).
