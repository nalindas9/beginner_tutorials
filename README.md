# beginner_tutorials

## Overview

This package demonstrates the usage of a ROS service, client, publisher, subscriber and ROS TF.
Refer to the following tutorials for more details:-

http://wiki.ros.org/ROS/Tutorials/NavigatingTheWiki (Links to an external site.)

http://wiki.ros.org/ROS/Tutorials/NavigatingTheFilesystem (Links to an external site.)

http://wiki.ros.org/ROS/Tutorials/CreatingPackage (Links to an external site.)

http://wiki.ros.org/ROS/Tutorials/BuildingPackages (Links to an external site.)

http://wiki.ros.org/ROS/Tutorials/UnderstandingNodes (Links to an external site.)

http://wiki.ros.org/ROS/Tutorials/UnderstandingTopics (Links to an external site.)

http://wiki.ros.org/ROS/Tutorials/WritingPublisherSubscriber%28c%2B%2B%29 (Links to an external site.)

http://wiki.ros.org/ROS/Tutorials/ExaminingPublisherSubscriber

http://wiki.ros.org/ROS/Tutorials/Getting%20started%20with%20roswtf (Links to an external site.)

http://wiki.ros.org/ROS/Tutorials/UnderstandingServicesParams (Links to an external site.)

http://wiki.ros.org/ROS/Tutorials/UsingRqtconsoleRoslaunch

http://wiki.ros.org/rostest/Writing (Links to an external site.)

http://wiki.ros.org/gtest (Links to an external site.)

http://wiki.ros.org/ROS/Tutorials/Recording%20and%20playing%20back%20data (Links to an external site.)

http://wiki.ros.org/tf/Tutorials/Introduction%20to%20tf (Links to an external site.)

http://wiki.ros.org/tf/Tutorials/Writing%20a%20tf%20broadcaster%20%28C%2B%2B%29 (Links to an external site.)

http://wiki.ros.org/tf/Tutorials/Writing%20a%20tf%20listener%20%28C%2B%2B%29 (Links to an external site.)

http://wiki.ros.org/tf/Tutorials/Adding%20a%20frame%20%28C%2B%2B%29 (Links to an external site.)

http://wiki.ros.org/tf/Tutorials/tf%20and%20Time%20%28C%2B%2B%29 (Links to an external site.)

http://wiki.ros.org/tf/Tutorials/Time%20travel%20with%20tf%20%28C%2B%2B%29

## Dependencies

The following dependencies are required to run this package:

- ROS Melodic
- Catkin
- Ubuntu 18.04 

## Standard install via command-line
```
cd ~/catkin_ws/src
git clone --recursive https://github.com/nalindas9/beginner_tutorials.git
cd ..
catkin_make
```
Open the following terminals and run the following commands in them:

Terminal 1:
```
roscore
```

Terminal 2:
```
cd catkin_ws
source devel/setup.bash
rosrun beginner_tutorials talker
```

Terminal 3:
```
cd catkin_ws
source devel/setup.bash
rosrun beginner_tutorials listener
```
## Calling rosservice with command line tools
Terminal 3:
```
rosservice call /add_two_ints 1 4
```

## Running launch file
```
roslaunch beginner_tutorials addtwoints.launch a:=4 b:=5
```
## Inspect tf frames
```
cd catkin_ws
source devel/setup.bash
rosrun rqt_tf_tree rqt_tf_tree
```
## Running rostest
```
cd catkin_ws
source devel/setup.bash
roslaunch talker_test.launch a:=2 b:=5
```
## Recording rosbag
```
cd catkin_ws
source devel/setup.bash
roslaunch addTwoInts.launch record:=true
```
## Inspecting rosbag file
```
cd catkin_ws/src/beginner_tutorials/results
rosbag info beginner_tutorials.bag
```
## Playback rosbag file with listener node
Terminal 1
```
cd catkin_ws/src/beginner_tutorials/results
rosbag play beginner_tutorials.bag
```
Terminal 2
```
cd catkin_ws
source devel/setup.bash
rosrun beginner_tutorials listener
```
