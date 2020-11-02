/**
 *  Copyright 2020 Nalin Das
 *  @file listener.cpp
 *  @author Nalin Das
 *  @date 11/02/2020
 *
 *  @brief ROS client 
 *
 *  @section DESCRIPTION
 *
 *  Source file for ros client to add two integers
 *
 */

#include "ros/ros.h"
#include "std_msgs/String.h"
#include "beginner_tutorials/AddTwoInts.h"

/**
 * @brief Main function
 * @param argc Command line number of arguments
 * @param argv Command line arguments vector
 * @return 0
 * **/
int main(int argc, char **argv) {

  // Initialize ros node
  ros::init(argc, argv, "listener");

  // Check length of argument vector
  if (argc != 3) {
    ROS_INFO_STREAM("Usage: add_two_ints_client X Y");
    return 1;
  }

  // Create ROS nodehandle object
  ros::NodeHandle n;

  // Service client
  ros::ServiceClient client = n.serviceClient<beginner_tutorials::AddTwoInts>("add_two_ints");
  beginner_tutorials::AddTwoInts srv;
  srv.request.a = atoll(argv[1]);
  srv.request.b = atoll(argv[2]);
  // If call to service successfull then displace sum
  if (client.call(srv)) {
    ROS_INFO_STREAM("Sum: " << (long int)srv.response.sum);
  } else {
    ROS_ERROR_STREAM("Failed to call service add_two_ints");
    ROS_FATAL_STREAM("Failed to call service add_two_ints!!");
    return 1;
  }

  return 0;
}