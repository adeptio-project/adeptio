#!/usr/bin/env sh
#:: Adeptio dev team 2018
set -e
srcdir="$(dirname $0)"
cd "$srcdir"
if [ -z ${LIBTOOLIZE} ] && GLIBTOOLIZE="`which glibtoolize 2>/dev/null`"; then
  LIBTOOLIZE="${GLIBTOOLIZE}"
  export LIBTOOLIZE
fi
which autoreconf >/dev/null || \
   (echo "configuration failed, please install autoconf first" && exit 1)
/usr/bin/autoreconf --install --force --warnings=all 
#end
