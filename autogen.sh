#!/usr/bin/env sh
#:: Adeptio dev team 2018
set -e
srcdir="$(dirname $0)"
cd "$srcdir"
if [ -z ${LIBTOOLIZE} ] && GLIBTOOLIZE="`which glibtoolize 2>/dev/null`"; then
  LIBTOOLIZE="${GLIBTOOLIZE}"
  export LIBTOOLIZE
fi
/usr/bin/autoreconf --install --force --warnings=all 
#end
