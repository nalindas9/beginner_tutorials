/**
 *  Copyright 2020 Nalin Das
 *  @file talker.cpp
 *  @author Nalin Das
 *  @date 11/02/2020
 *
 *  @brief ROS service to add two integers 
 *
 *  @section DESCRIPTION
 *
 *  Source file for ros service to add two integers
 *
 */
#include <sstream>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "beginner_tutorials/AddTwoInts.h"


/**
 * @brief Add two integers function
 * @param req Add two integers request object
 * @param res Add two integers response object
 * @return True once addition completed
 * **/
bool add(beginner_tutorials::AddTwoInts::Request &req,
         beginner_tutorials::AddTwoInts::Response &res) {
    res.sum = req.a + req.b;
    ROS_INFO_STREAM("Request: x = " << (long int)req.a << "y = " << (long int)req.b);
    ROS_INFO_STREAM("Sending back response: " << (long int)res.sum);
    return true;
}

/**
 * @brief Main function
 * @param argc Command line number of arguments
 * @param argv Command line arguments vector
 * @return 0
 * **/
int main(int argc, char **argv) {
  // Initialize ros node
  ros::init(argc, argv, "talker");
  
  // Create ros node handle object
  ros::NodeHandle n;

  // Loop rate frequency set to 10 Hz
  ros::Rate loop_rate(10);

  ROS_DEBUG_STREAM("Talker started ...");

  // Advertise ros service
  ros::ServiceServer service = n.advertiseService("add_two_ints", add);
  ROS_WARN_STREAM("ROS service might take time to start ... ");
  ROS_INFO_STREAM("Ready to add two ints.");
  ros::spin();


  return 0;
}
