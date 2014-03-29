# Automatic source archive creator.

VERSION=`cat VERSION`
NAME=QLedIndicator
ARCH=${NAME}-${VERSION}.tar.gz

make distclean
cd ${NAME}Plugin
echo `pwd`
make distclean
cd ../..
echo `pwd`
rm -rf ${NAME}-${VERSION}
cp -r ${NAME} ${NAME}-${VERSION}
tar cfvz ${ARCH} ${NAME}-${VERSION}
