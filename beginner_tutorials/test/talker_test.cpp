/**
 *  Copyright 2020 Nalin Das
 *  @file talker_test.cpp
 *  @author Nalin Das
 *  @date 11/06/2020
 * 
 *  @brief Unit tests for talker node
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
 *  Source file containing unit tests for talker node
 *
 */
#include <gtest/gtest.h>
#include <ros/ros.h>
#include <ros/service_client.h>
#include "beginner_tutorials/AddTwoInts.h"

/**
 * @brief Tests the AddTwoInts service output
 * @param TestTalkerNode Test name 
 * @param TestServiceOutput Unit test name
 */
TEST (TestTalkerNode, TestServiceOutput) {
  // Create a ROS node handle
  ros::NodeHandle node;
  // Create a ROS service client
  ros::ServiceClient client = node.serviceClient<beginner_tutorials::AddTwoInts>("add_two_ints");
  
  beginner_tutorials::AddTwoInts srv;
  srv.request.a = 3;
  srv.request.b = 9;

  // Call ROS Service
  client.call(srv);

  EXPECT_EQ(12, srv.response.sum);
}
