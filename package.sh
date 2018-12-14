#!/bin/bash

VERSION=$1
echo ${VERSION}
TARGET=PowerSlider.${VERSION}

cp -R trunk/ ${TARGET}

rm -rf ${TARGET}/debug/
rm -rf ${TARGET}/release/
rm -rf ${TARGET}/lib/
rm -rf ${TARGET}/plugin/
rm -rf ${TARGET}/.svn/

tar -jcvf ${TARGET}.tar.bz2 ${TARGET}/
rm -rf ${TARGET}
rsync -avP -e ssh  ${TARGET}.tar.bz2 dlyr@frs.sourceforge.net:uploads/
