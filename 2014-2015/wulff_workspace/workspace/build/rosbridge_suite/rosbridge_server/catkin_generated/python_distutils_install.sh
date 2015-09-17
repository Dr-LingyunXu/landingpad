#!/bin/sh -x

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
    DESTDIR_ARG="--root=$DESTDIR"
fi

cd "/home/cracker/workspace/src/rosbridge_suite/rosbridge_server"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
/usr/bin/env \
    PYTHONPATH="/home/cracker/workspace/install/lib/python2.7/dist-packages:/home/cracker/workspace/build/lib/python2.7/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/cracker/workspace/build" \
    "/usr/bin/python" \
    "/home/cracker/workspace/src/rosbridge_suite/rosbridge_server/setup.py" \
    build --build-base "/home/cracker/workspace/build/rosbridge_suite/rosbridge_server" \
    install \
    $DESTDIR_ARG \
    --install-layout=deb --prefix="/home/cracker/workspace/install" --install-scripts="/home/cracker/workspace/install/bin"
