# nina
[![Build Windows](https://github.com/tiropp/nina/actions/workflows/build-win.yaml/badge.svg)](https://github.com/tiropp/nina/actions/workflows/build-win.yaml)

A simple invoice creation tool


## Getting started ...

### .. on Linux
Create Makefiles with
```
cmake -S . --preset linux-default
```

This will create the Makefiles for debug configuration in directory `_build/linux/debug` and the release configuration in `_build/linux/release`.

Compile the application with for debug configuration with
```
cmake --build --preset linux-default-debug -- -j
```
and for release configuration with
```
cmake --build --preset linux-default-release -- -j
```

Finally, run the application, compiled for debug configuration with
```
_build/linux/src/ui/nina/Debug/nina
```
and for release configuration with
```
_build/linux/src/ui/nina/Relase/nina
```


### .. on Windows

#### Cross compilation in Linux for Windows with container
The following steps show how to setup an environment to compile the nina application for Windows within Linux using the a build container.

1. Get source code
   ```
   cd ..
   git clone https://github.com/tiropp/nina.git
   cd nina
   ```

2. Get the build container:
   ```
   docker pull ghcr.io/tiropp/nina/build-container-win:latest
   ```

3. Start container with
   ```
   docker run -it --rm --mount type=bind,src=`pwd`,dst=/nina ghcr.io/tiropp/nina/build-container-win:latest
   ```
   and execute the following steps within the container.

4. Create build configuration
   ```
   cd /nina
   cmake -S . --preset win-cross-default -DMXE_DIR=/mxe
   ```

5. Build application
   ```
   cmake --build --preset win-cross-default-release
   ```

6. Create app installer with
   ```
   cpack --preset win-cross-default
   ```

   The installer is to be found at
   ```
   _build/win-linux/nina-0.2.4-win64.exe
   ```

#### Cross compilation in Linux for Windows without container
The following steps show how to setup an environment to compile the nina application for Windows within Linux.

1. Clone [MXE](https://github.com/mxe/mxe) repository:
   ```
   git clone --branch master --single-branch https://github.com/mxe/mxe.git
   ```

2. Build necessary libraries with MXE with
   ```
   cd mxe
   make qtbase_CONFIGURE_OPTS="-debug-and-release -no-opengl" qt5 boost -j MXE_TARGETS='x86_64-w64-mingw32.shared'
   ```
   This will create release and debug libraries for Qt.

   If a release configuration is sufficient one can use instead:
   ```
   make qtbase_CONFIGURE_OPTS="-no-opengl" qt5 boost -j MXE_TARGETS='x86_64-w64-mingw32.shared
   ```

3. Get source code
   ```
   cd ..
   git clone --recurse-submodules https://github.com/tiropp/nina.git
   cd nina
   ```

4. Create build configuration
   ```
   cmake -S . --preset win-cross-default -DMXE_DIR=`pwd`/../mxe
   ```

5. Build application
   ```
   cmake --build --preset win-cross-default-release
   ```

6. Create app installer with
   ```
   cpack --preset win-cross-default
   ```

   The installer is to be found at
   ```
   _build/win-linux/nina-0.2.4-win64.exe
   ```


#### Native compilation on Windows

**WORK IN PROGRESS**

1. Install Mingw-w64 toolchain, see [ Using Mingw-w64 natively on Windows](https://learn.microsoft.com/en-us/vcpkg/users/platforms/mingw#mingw-native).
   The following commands are executed in MSYS2 shell.
2. Install additional tools with:
   ```
   pacman -S --needed cmake ninja
   ```
2. Get source code
   ```
   git clone --recurse-submodules https://github.com/tiropp/nina.git
   cd nina
   ```
3. Setup vcpkg with
   ```
   extern/vcpkg/bootstrap-vcpkg.sh -disableMetrics
   ```
3. Configure project with
   ```
   cmake -S . --preset win-default
   ```

## Dependencies
The application depends on `pdflatex` to create the final document. Please ensure that the `pdflatex` application is installed on the system and can be found by `nina`.

For Windows, one can use e.g. [MiKTex](https://miktex.org/download).
