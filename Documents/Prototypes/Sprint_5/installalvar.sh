#!/bin/bash

#Install ROS

#Setup your sources.list
sudo sh -c 'echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list'

#Set up your keys
sudo apt-key adv --keyserver hkp://pool.sks-keyservers.net:80 --recv-key 0xB01FA116

#Installation
sudo apt-get update
sudo apt-get install ros-jade-desktop-full

#Initialize rosdep
sudo rosdep init
rosdep update

#ROS Environment setup
echo "source /opt/ros/jade/setup.bash" >> ~/.bashrc
source ~/.bashrc

#Getting rosinstall
sudo apt-get install python-rosinstall

#Install opencv
version="$(wget -q -O - http://sourceforge.net/projects/opencvlibrary/files/opencv-unix | egrep -m1 -o '\"[0-9](\.[0-9]+)+' | cut -c2-)"
echo "Installing OpenCV" $version
mkdir OpenCV
cd OpenCV
echo "Removing any pre-installed ffmpeg and x264"
sudo apt-get -qq remove ffmpeg x264 libx264-dev
echo "Installing Dependenices"
sudo apt-get -qq install libopencv-dev build-essential checkinstall cmake pkg-config yasm libjpeg-dev libjasper-dev libavcodec-dev libavformat-dev libswscale-dev libdc1394-22-dev libxine-dev libgstreamer0.10-dev libgstreamer-plugins-base0.10-dev libv4l-dev python-dev python-numpy libtbb-dev libqt4-dev libgtk2.0-dev libfaac-dev libmp3lame-dev libopencore-amrnb-dev libopencore-amrwb-dev libtheora-dev libvorbis-dev libxvidcore-dev x264 v4l-utils ffmpeg cmake qt5-default checkinstall
echo "Downloading OpenCV" $version
sudo wget -O OpenCV-$version.zip http://sourceforge.net/projects/opencvlibrary/files/opencv-unix/$version/opencv-"$version".zip/download
echo "Installing OpenCV" $version
sudo unzip OpenCV-$version.zip
cd opencv-$version
mkdir build
cd build
sudo cmake -D CMAKE_BUILD_TYPE=RELEASE -D CMAKE_INSTALL_PREFIX=/usr/local -D WITH_TBB=ON -D BUILD_NEW_PYTHON_SUPPORT=ON -D WITH_V4L=ON -D INSTALL_C_EXAMPLES=ON -D INSTALL_PYTHON_EXAMPLES=ON -D BUILD_EXAMPLES=ON -D WITH_QT=ON -D WITH_OPENGL=ON ..
sudo make -j2
sudo checkinstall
sudo sh -c 'echo "/usr/local/lib" > /etc/ld.so.conf.d/opencv.conf'
sudo ldconfig
echo "OpenCV" $version "ready to be used"

# Download and extract alvar-2.0.0-sdk-linux64-gcc44.tar.gz
# Go into the /alvar-2.0.0-sdk-linux64-gcc44/build
sudo apt-get install build-essential cmake
sudo apt-get install freeglut3-dev
sudo apt-get install libopenscenegraph-dev
sudo apt-get install gcc-4.4
sudo apt-get install g++-4.4
sudo apt-get install cmake-qt-gui
chmod +x generate*.sh
sudo ./generate_gcc44.sh
cd build_gcc44_release
sudo make install
