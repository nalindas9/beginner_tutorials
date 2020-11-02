# beginner_tutorials

## Overview

This package demonstrates the usage of a ROS service and client.
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
