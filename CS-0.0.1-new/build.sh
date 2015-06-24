#!/bin/sh

set -x

SOURCE_DIR=`pwd`
BUILD_DIR=${BUILD_DIR:-./build}
BUILD_TYPE=${BUILD_TYPE:-debug}
INSTALL_DIR=${INSTALL_DIR:-./install}

mkdir $BUILD_DIR\
  && cd $BUILD_DIR\
  && cmake \
           -DCMAKE_BUILD_TYPE=$BUILD_TYPE\
           -DCMAKE_INSTALL_PREFIX=$INSTALL_DIR \
           $SOURCE_DIR \
  && make $*\
  && make install
