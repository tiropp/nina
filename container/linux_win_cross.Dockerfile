FROM debian:bookworm-slim

RUN \
    apt update && \
    apt install -y \
        build-essential git wget \
        autoconf automake autopoint bison flex libgdk-pixbuf2.0-bin gperf intltool libtool-bin lzip python3-mako ruby unzip p7zip-full \
        python3-minimal python-is-python3 \
        pkgconf libssl-dev libpcre2-dev && \
    rm -rf /var/lib/apt/lists/*

RUN \
    cd / && \
    git clone --branch master --single-branch https://github.com/mxe/mxe.git && \
    cd mxe && \
    make boost -j MXE_TARGETS='x86_64-w64-mingw32.shared' && \
    make qtbase_CONFIGURE_OPTS="-debug-and-release -no-opengl" qtdeclarative qtquickcontrols2 qtsvg -j MXE_TARGETS='x86_64-w64-mingw32.shared'
