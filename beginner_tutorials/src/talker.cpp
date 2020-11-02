/**
 *  Copyright 2020 Nalin Das
 *  @file talker.cpp
 *  @author Nalin Das
 *  @date 11/02/2020
 * 
 *  @brief ROS service to add two integers 
 *
 *  @section LICENSE
 *  
 * MIT License
 * Copyright (c) 2020 Nalin Das
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
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
