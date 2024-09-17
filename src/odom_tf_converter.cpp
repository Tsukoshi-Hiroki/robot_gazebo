#include <ros/ros.h>
#include <nav_msgs/Odometry.h>
#include <tf/transform_broadcaster.h>
#include <string>
#include <math.h>
#include <std_msgs/String.h>

class Converter
{
public:

  std::string pfi="map";
  std::string cfi="odom";

  Converter(void)
  {
    joy_sub_ = nh_.subscribe("/tracker", 100, &Converter::odomCallback, this);
  }
  void odomCallback(const nav_msgs::Odometry& msg)
  {
    tf::Transform transform;
    tf::poseMsgToTF(msg.pose.pose, transform);
    ROS_ERROR_STREAM_THROTTLE(1, "pfi: " << pfi);
    ROS_ERROR_STREAM_THROTTLE(1, "cfi: " << cfi);
    br_.sendTransform(tf::StampedTransform(transform, msg.header.stamp, /*msg.header.frame_id*/ pfi, cfi));
  }
  ros::NodeHandle nh_;
  ros::Subscriber joy_sub_;
  tf::TransformBroadcaster br_;
};

int main(int argc, char** argv)
{
  ros::init(argc, argv, "sim1_odom_tf_converter");

  ros::NodeHandle pnh_1("~");
  std::string parent_frame_id="map";
  pnh_1.getParam("pfi",parent_frame_id);

  ros::NodeHandle pnh_2("~");
  std::string child_frame_id="odom";
  pnh_2.getParam("cfi", child_frame_id);

  Converter converter;

  converter.pfi=parent_frame_id;
  converter.cfi=child_frame_id;

  ros::spin();
  return 0;
}
