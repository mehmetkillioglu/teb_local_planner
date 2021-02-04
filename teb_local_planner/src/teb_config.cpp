/*********************************************************************
 *
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2016,
 *  TU Dortmund - Institute of Control Theory and Systems Engineering.
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of the institute nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *
 * Author: Christoph Rösmann
 *********************************************************************/
#include <functional>
<<<<<<< HEAD

#include "nav2_util/node_utils.hpp"
#include "teb_local_planner/teb_config.hpp"
=======
#include "nav2_util/node_utils.hpp"
#include "teb_local_planner/teb_config.h"
>>>>>>> d6865b419ba70bf637f5125317c380e00f7944c3


namespace teb_local_planner
{
void TebConfig::declareParameters(
  const nav2_util::LifecycleNode::SharedPtr nh, const std::string name)
{
  const std::string nd = name + ".";  // nd is short for name plus dot
  using Dv = rclcpp::ParameterValue;  // Dv is short for default value
  constexpr auto para_ = nav2_util::declare_parameter_if_not_declared<decltype(nh)>;
  using namespace std::placeholders;
  const auto e = rcl_interfaces::msg::ParameterDescriptor();
  const auto para = std::bind(
    para_, nh, _1, _2, e);  // use function para to declare parameters and their default value

  // Global
  para(nd + "odom_topic", Dv(odom_topic));
  para(nd + "global_frame", Dv(global_frame));
  para(nd + "controller_frequency", Dv(controller_frequency));

<<<<<<< HEAD
=======
void TebConfig::declareParameters(const nav2_util::LifecycleNode::SharedPtr nh, const std::string name) {
  const std::string nd = name + "."; // nd is short for name plus dot
  using Dv = rclcpp::ParameterValue; // Dv is short for default value
  constexpr auto para_ = nav2_util::declare_parameter_if_not_declared<decltype(nh)>;
  using namespace std::placeholders; 
  const auto e = rcl_interfaces::msg::ParameterDescriptor();
  const auto para = std::bind(para_, nh, _1,  _2, e); // use function para to declare parameters and their default value

  // Global
  para(nd + "odom_topic", Dv("odom_topic"));
  para(nd + "map_frame", Dv("map_frame"));

>>>>>>> d6865b419ba70bf637f5125317c380e00f7944c3
  // Trajectory
  para(nd + "teb_autosize", Dv(trajectory.teb_autosize));
  para(nd + "dt_ref", Dv(trajectory.dt_ref));
  para(nd + "dt_hysteresis", Dv(trajectory.dt_hysteresis));
  para(nd + "min_samples", Dv(trajectory.min_samples));
  para(nd + "max_samples", Dv(trajectory.max_samples));
  para(nd + "global_plan_overwrite_orientation", Dv(trajectory.global_plan_overwrite_orientation));
  para(nd + "allow_init_with_backwards_motion", Dv(trajectory.allow_init_with_backwards_motion));
  para(nd + "global_plan_viapoint_sep", Dv(trajectory.global_plan_viapoint_sep));
  para(nd + "via_points_ordered", Dv(trajectory.via_points_ordered));
  para(nd + "max_global_plan_lookahead_dist", Dv(trajectory.max_global_plan_lookahead_dist));
  para(nd + "global_plan_prune_distance", Dv(trajectory.global_plan_prune_distance));
  para(nd + "exact_arc_length", Dv(trajectory.exact_arc_length));
  para(nd + "force_reinit_new_goal_dist", Dv(trajectory.force_reinit_new_goal_dist));
  para(nd + "force_reinit_new_goal_angular", Dv(trajectory.force_reinit_new_goal_angular));
  para(nd + "feasibility_check_no_poses", Dv(trajectory.feasibility_check_no_poses));
  para(nd + "publish_feedback", Dv(trajectory.publish_feedback));
<<<<<<< HEAD
  para(
    nd + "min_resolution_collision_check_angular",
    Dv(trajectory.min_resolution_collision_check_angular));
=======
  para(nd + "min_resolution_collision_check_angular", Dv(trajectory.min_resolution_collision_check_angular));
>>>>>>> d6865b419ba70bf637f5125317c380e00f7944c3
  para(nd + "control_look_ahead_poses", Dv(trajectory.control_look_ahead_poses));

  // Robot
  para(nd + "max_vel_x", Dv(robot.max_vel_x));
  para(nd + "max_vel_x_backwards", Dv(robot.max_vel_x_backwards));
  para(nd + "max_vel_y", Dv(robot.max_vel_y));
  para(nd + "max_vel_theta", Dv(robot.max_vel_theta));
  para(nd + "acc_lim_x", Dv(robot.acc_lim_x));
  para(nd + "acc_lim_y", Dv(robot.acc_lim_y));
  para(nd + "acc_lim_theta", Dv(robot.acc_lim_theta));
  para(nd + "min_turning_radius", Dv(robot.min_turning_radius));
  para(nd + "wheelbase", Dv(robot.wheelbase));
  para(nd + "cmd_angle_instead_rotvel", Dv(robot.cmd_angle_instead_rotvel));
  para(nd + "is_footprint_dynamic", Dv(robot.is_footprint_dynamic));
<<<<<<< HEAD
  para(nd + "use_proportional_saturation", Dv(robot.use_proportional_saturation));
  para(nd + "transform_tolerance", Dv(robot.transform_tolerance));

=======
  
>>>>>>> d6865b419ba70bf637f5125317c380e00f7944c3
  // GoalTolerance
  para(nd + "xy_goal_tolerance", Dv(goal_tolerance.xy_goal_tolerance));
  para(nd + "yaw_goal_tolerance", Dv(goal_tolerance.yaw_goal_tolerance));
  para(nd + "free_goal_vel", Dv(goal_tolerance.free_goal_vel));
  para(nd + "complete_global_plan", Dv(goal_tolerance.complete_global_plan));

  // Obstacles
  para(nd + "min_obstacle_dist", Dv(obstacles.min_obstacle_dist));
  para(nd + "inflation_dist", Dv(obstacles.inflation_dist));
  para(nd + "dynamic_obstacle_inflation_dist", Dv(obstacles.dynamic_obstacle_inflation_dist));
  para(nd + "include_dynamic_obstacles", Dv(obstacles.include_dynamic_obstacles));
  para(nd + "include_costmap_obstacles", Dv(obstacles.include_costmap_obstacles));
<<<<<<< HEAD
  para(
    nd + "costmap_obstacles_behind_robot_dist", Dv(obstacles.costmap_obstacles_behind_robot_dist));
  para(nd + "obstacle_poses_affected", Dv(obstacles.obstacle_poses_affected));
  para(nd + "legacy_obstacle_association", Dv(obstacles.legacy_obstacle_association));
  para(
    nd + "obstacle_association_force_inclusion_factor",
    Dv(obstacles.obstacle_association_force_inclusion_factor));
=======
  para(nd + "costmap_obstacles_behind_robot_dist", Dv(obstacles.costmap_obstacles_behind_robot_dist));
  para(nd + "obstacle_poses_affected", Dv(obstacles.obstacle_poses_affected));
  para(nd + "legacy_obstacle_association", Dv(obstacles.legacy_obstacle_association));
  para(nd + "obstacle_association_force_inclusion_factor", Dv(obstacles.obstacle_association_force_inclusion_factor));
>>>>>>> d6865b419ba70bf637f5125317c380e00f7944c3
  para(nd + "obstacle_association_cutoff_factor", Dv(obstacles.obstacle_association_cutoff_factor));
  para(nd + "costmap_converter_plugin", Dv(obstacles.costmap_converter_plugin));
  para(nd + "costmap_converter_spin_thread", Dv(obstacles.costmap_converter_spin_thread));
  para(nd + "costmap_converter_rate", Dv(obstacles.costmap_converter_rate));
<<<<<<< HEAD
  para(nd + "obstacle_proximity_ratio_max_vel", Dv(obstacles.obstacle_proximity_ratio_max_vel));
  para(nd + "obstacle_proximity_lower_bound", Dv(obstacles.obstacle_proximity_lower_bound));
  para(nd + "obstacle_proximity_upper_bound", Dv(obstacles.obstacle_proximity_upper_bound));
=======
>>>>>>> d6865b419ba70bf637f5125317c380e00f7944c3

  // Optimization
  para(nd + "no_inner_iterations", Dv(optim.no_inner_iterations));
  para(nd + "no_outer_iterations", Dv(optim.no_outer_iterations));
  para(nd + "optimization_activate", Dv(optim.optimization_activate));
  para(nd + "optimization_verbose", Dv(optim.optimization_verbose));
  para(nd + "penalty_epsilon", Dv(optim.penalty_epsilon));
  para(nd + "weight_max_vel_x", Dv(optim.weight_max_vel_x));
  para(nd + "weight_max_vel_y", Dv(optim.weight_max_vel_y));
  para(nd + "weight_max_vel_theta", Dv(optim.weight_max_vel_theta));
  para(nd + "weight_acc_lim_x", Dv(optim.weight_acc_lim_x));
  para(nd + "weight_acc_lim_y", Dv(optim.weight_acc_lim_y));
  para(nd + "weight_acc_lim_theta", Dv(optim.weight_acc_lim_theta));
  para(nd + "weight_kinematics_nh", Dv(optim.weight_kinematics_nh));
  para(nd + "weight_kinematics_forward_drive", Dv(optim.weight_kinematics_forward_drive));
  para(nd + "weight_kinematics_turning_radius", Dv(optim.weight_kinematics_turning_radius));
  para(nd + "weight_optimaltime", Dv(optim.weight_optimaltime));
  para(nd + "weight_shortest_path", Dv(optim.weight_shortest_path));
  para(nd + "weight_obstacle", Dv(optim.weight_obstacle));
  para(nd + "weight_inflation", Dv(optim.weight_inflation));
  para(nd + "weight_dynamic_obstacle", Dv(optim.weight_dynamic_obstacle));
<<<<<<< HEAD
  para(nd + "weight_dynamic_obstacle_inflation", Dv(optim.weight_dynamic_obstacle_inflation));
  para(nd + "weight_velocity_obstacle_ratio", Dv(optim.weight_velocity_obstacle_ratio));
=======
>>>>>>> d6865b419ba70bf637f5125317c380e00f7944c3
  para(nd + "weight_viapoint", Dv(optim.weight_viapoint));
  para(nd + "weight_prefer_rotdir", Dv(optim.weight_prefer_rotdir));
  para(nd + "weight_adapt_factor", Dv(optim.weight_adapt_factor));
  para(nd + "obstacle_cost_exponent", Dv(optim.obstacle_cost_exponent));

  // Homotopy Class Planner
  para(nd + "enable_homotopy_class_planning", Dv(hcp.enable_homotopy_class_planning));
  para(nd + "enable_multithreading", Dv(hcp.enable_multithreading));
  para(nd + "simple_exploration", Dv(hcp.simple_exploration));
  para(nd + "max_number_classes", Dv(hcp.max_number_classes));
<<<<<<< HEAD
  para(nd + "max_number_plans_in_current_class", Dv(hcp.max_number_plans_in_current_class));
=======
>>>>>>> d6865b419ba70bf637f5125317c380e00f7944c3
  para(nd + "selection_cost_hysteresis", Dv(hcp.selection_cost_hysteresis));
  para(nd + "selection_prefer_initial_plan", Dv(hcp.selection_prefer_initial_plan));
  para(nd + "selection_obst_cost_scale", Dv(hcp.selection_obst_cost_scale));
  para(nd + "selection_viapoint_cost_scale", Dv(hcp.selection_viapoint_cost_scale));
  para(nd + "selection_alternative_time_cost", Dv(hcp.selection_alternative_time_cost));
<<<<<<< HEAD
  para(nd + "selection_dropping_probability", Dv(hcp.selection_dropping_probability));
  para(nd + "switching_blocking_period", Dv(hcp.switching_blocking_period));
=======
  para(nd + "obstacle_keypoint_offset", Dv(hcp.obstacle_keypoint_offset));
  para(nd + "obstacle_heading_threshold", Dv(hcp.obstacle_heading_threshold));
>>>>>>> d6865b419ba70bf637f5125317c380e00f7944c3
  para(nd + "roadmap_graph_no_samples", Dv(hcp.roadmap_graph_no_samples));
  para(nd + "roadmap_graph_area_width", Dv(hcp.roadmap_graph_area_width));
  para(nd + "roadmap_graph_area_length_scale", Dv(hcp.roadmap_graph_area_length_scale));
  para(nd + "h_signature_prescaler", Dv(hcp.h_signature_prescaler));
  para(nd + "h_signature_threshold", Dv(hcp.h_signature_threshold));
<<<<<<< HEAD
  para(nd + "obstacle_keypoint_offset", Dv(hcp.obstacle_keypoint_offset));
  para(nd + "obstacle_heading_threshold", Dv(hcp.obstacle_heading_threshold));
=======
  para(nd + "switching_blocking_period", Dv(hcp.switching_blocking_period));
>>>>>>> d6865b419ba70bf637f5125317c380e00f7944c3
  para(nd + "viapoints_all_candidates", Dv(hcp.viapoints_all_candidates));
  para(nd + "visualize_hc_graph", Dv(hcp.visualize_hc_graph));
  para(nd + "visualize_with_time_as_z_axis_scale", Dv(hcp.visualize_with_time_as_z_axis_scale));
  para(nd + "delete_detours_backwards", Dv(hcp.delete_detours_backwards));
  para(nd + "detours_orientation_tolerance", Dv(hcp.detours_orientation_tolerance));
  para(nd + "length_start_orientation_vector", Dv(hcp.length_start_orientation_vector));
<<<<<<< HEAD
  para(
    nd + "max_ratio_detours_duration_best_duration",
    Dv(hcp.max_ratio_detours_duration_best_duration));

  // Recovery
  para(nd + "shrink_horizon_backup", Dv(recovery.shrink_horizon_backup));
  para(nd + "shrink_horizon_min_duration", Dv(recovery.shrink_horizon_min_duration));
  para(nd + "oscillation_recovery", Dv(recovery.oscillation_recovery));
  para(nd + "oscillation_v_eps", Dv(recovery.oscillation_v_eps));
  para(nd + "oscillation_omega_eps", Dv(recovery.oscillation_omega_eps));
  para(nd + "oscillation_recovery_min_duration", Dv(recovery.oscillation_recovery_min_duration));
  para(nd + "oscillation_filter_duration", Dv(recovery.oscillation_filter_duration));
  para(nd + "divergence_detection_enable", Dv(recovery.divergence_detection_enable));
  para(
    nd + "divergence_detection_max_chi_squared", Dv(recovery.divergence_detection_max_chi_squared));
=======
  para(nd + "max_ratio_detours_duration_best_duration", Dv(hcp.max_ratio_detours_duration_best_duration));

  // Recovery
  para(nd + "shrink_horizon_backup", Dv(recovery.shrink_horizon_backup));  
  para(nd + "shrink_horizon_min_duration", Dv(recovery.shrink_horizon_min_duration));  
  para(nd + "oscillation_recovery", Dv(recovery.oscillation_recovery));  
  para(nd + "oscillation_v_eps", Dv(recovery.oscillation_v_eps));  
  para(nd + "oscillation_omega_eps", Dv(recovery.oscillation_omega_eps));  
  para(nd + "oscillation_recovery_min_duration", Dv(recovery.oscillation_recovery_min_duration));  
  para(nd + "oscillation_filter_duration", Dv(recovery.oscillation_filter_duration));  
>>>>>>> d6865b419ba70bf637f5125317c380e00f7944c3
}

void TebConfig::loadRosParamFromNodeHandle(
  const nav2_util::LifecycleNode::SharedPtr nh, const std::string name)
{
  const std::string nd = name + ".";  // nd is short for name plus dot

  nh->get_parameter_or(nd + "odom_topic", odom_topic, odom_topic);
  nh->get_parameter_or(nd + "global_frame", global_frame, global_frame);
  nh->get_parameter_or(nd + "controller_frequency", controller_frequency, controller_frequency);

  // Trajectory
  nh->get_parameter_or(nd + "teb_autosize", trajectory.teb_autosize, trajectory.teb_autosize);
  nh->get_parameter_or(nd + "dt_ref", trajectory.dt_ref, trajectory.dt_ref);
  nh->get_parameter_or(nd + "dt_hysteresis", trajectory.dt_hysteresis, trajectory.dt_hysteresis);
  nh->get_parameter_or(nd + "min_samples", trajectory.min_samples, trajectory.min_samples);
  nh->get_parameter_or(nd + "max_samples", trajectory.max_samples, trajectory.max_samples);
  nh->get_parameter_or(
    nd + "global_plan_overwrite_orientation", trajectory.global_plan_overwrite_orientation,
    trajectory.global_plan_overwrite_orientation);
  nh->get_parameter_or(
    nd + "allow_init_with_backwards_motion", trajectory.allow_init_with_backwards_motion,
    trajectory.allow_init_with_backwards_motion);
  nh->get_parameter_or(
    nd + "global_plan_viapoint_sep", trajectory.global_plan_viapoint_sep,
    trajectory.global_plan_viapoint_sep);
  nh->get_parameter_or(
    nd + "via_points_ordered", trajectory.via_points_ordered, trajectory.via_points_ordered);
  nh->get_parameter_or(
    nd + "max_global_plan_lookahead_dist", trajectory.max_global_plan_lookahead_dist,
    trajectory.max_global_plan_lookahead_dist);
  nh->get_parameter_or(
    nd + "global_plan_prune_distance", trajectory.global_plan_prune_distance,
    trajectory.global_plan_prune_distance);
  nh->get_parameter_or(
    nd + "exact_arc_length", trajectory.exact_arc_length, trajectory.exact_arc_length);
  nh->get_parameter_or(
    nd + "force_reinit_new_goal_dist", trajectory.force_reinit_new_goal_dist,
    trajectory.force_reinit_new_goal_dist);
  nh->get_parameter_or(
    nd + "force_reinit_new_goal_angular", trajectory.force_reinit_new_goal_angular,
    trajectory.force_reinit_new_goal_angular);
  nh->get_parameter_or(
    nd + "feasibility_check_no_poses", trajectory.feasibility_check_no_poses,
    trajectory.feasibility_check_no_poses);
  nh->get_parameter_or(
    nd + "publish_feedback", trajectory.publish_feedback, trajectory.publish_feedback);
  nh->get_parameter_or(
    nd + "min_resolution_collision_check_angular",
    trajectory.min_resolution_collision_check_angular,
    trajectory.min_resolution_collision_check_angular);
  nh->get_parameter_or(
    nd + "control_look_ahead_poses", trajectory.control_look_ahead_poses,
    trajectory.control_look_ahead_poses);

  // Robot
  nh->get_parameter_or(nd + "max_vel_x", robot.max_vel_x, robot.max_vel_x);
  nh->get_parameter_or(
    nd + "max_vel_x_backwards", robot.max_vel_x_backwards, robot.max_vel_x_backwards);
  nh->get_parameter_or(nd + "max_vel_y", robot.max_vel_y, robot.max_vel_y);
  nh->get_parameter_or(nd + "max_vel_theta", robot.max_vel_theta, robot.max_vel_theta);
  nh->get_parameter_or(nd + "acc_lim_x", robot.acc_lim_x, robot.acc_lim_x);
  nh->get_parameter_or(nd + "acc_lim_y", robot.acc_lim_y, robot.acc_lim_y);
  nh->get_parameter_or(nd + "acc_lim_theta", robot.acc_lim_theta, robot.acc_lim_theta);
  nh->get_parameter_or(
    nd + "min_turning_radius", robot.min_turning_radius, robot.min_turning_radius);
  nh->get_parameter_or(nd + "wheelbase", robot.wheelbase, robot.wheelbase);
  nh->get_parameter_or(
    nd + "cmd_angle_instead_rotvel", robot.cmd_angle_instead_rotvel,
    robot.cmd_angle_instead_rotvel);
  nh->get_parameter_or(
    nd + "is_footprint_dynamic", robot.is_footprint_dynamic, robot.is_footprint_dynamic);
  nh->get_parameter_or(
    nd + "use_proportional_saturation", robot.use_proportional_saturation,
    robot.use_proportional_saturation);
  nh->get_parameter_or(
    nd + "transform_tolerance", robot.transform_tolerance, robot.transform_tolerance);

  // GoalTolerance
  nh->get_parameter_or(
    nd + "yaw_goal_tolerance", goal_tolerance.yaw_goal_tolerance,
    goal_tolerance.yaw_goal_tolerance);
  nh->get_parameter_or(
    nd + "xy_goal_tolerance", goal_tolerance.xy_goal_tolerance, goal_tolerance.xy_goal_tolerance);
  nh->get_parameter_or(
    nd + "free_goal_vel", goal_tolerance.free_goal_vel, goal_tolerance.free_goal_vel);
  nh->get_parameter_or(
    nd + "complete_global_plan", goal_tolerance.complete_global_plan,
    goal_tolerance.complete_global_plan);

  // Obstacles
  nh->get_parameter_or(
    nd + "min_obstacle_dist", obstacles.min_obstacle_dist, obstacles.min_obstacle_dist);
  nh->get_parameter_or(nd + "inflation_dist", obstacles.inflation_dist, obstacles.inflation_dist);
  nh->get_parameter_or(
    nd + "dynamic_obstacle_inflation_dist", obstacles.dynamic_obstacle_inflation_dist,
    obstacles.dynamic_obstacle_inflation_dist);
  nh->get_parameter_or(
    nd + "include_dynamic_obstacles", obstacles.include_dynamic_obstacles,
    obstacles.include_dynamic_obstacles);
  nh->get_parameter_or(
    nd + "include_costmap_obstacles", obstacles.include_costmap_obstacles,
    obstacles.include_costmap_obstacles);
  nh->get_parameter_or(
    nd + "costmap_obstacles_behind_robot_dist", obstacles.costmap_obstacles_behind_robot_dist,
    obstacles.costmap_obstacles_behind_robot_dist);
  nh->get_parameter_or(
    nd + "obstacle_poses_affected", obstacles.obstacle_poses_affected,
    obstacles.obstacle_poses_affected);
  nh->get_parameter_or(
    nd + "legacy_obstacle_association", obstacles.legacy_obstacle_association,
    obstacles.legacy_obstacle_association);
  nh->get_parameter_or(
    nd + "obstacle_association_force_inclusion_factor",
    obstacles.obstacle_association_force_inclusion_factor,
    obstacles.obstacle_association_force_inclusion_factor);
  nh->get_parameter_or(
    nd + "obstacle_association_cutoff_factor", obstacles.obstacle_association_cutoff_factor,
    obstacles.obstacle_association_cutoff_factor);
  nh->get_parameter_or(
    nd + "costmap_converter_plugin", obstacles.costmap_converter_plugin,
    obstacles.costmap_converter_plugin);
  nh->get_parameter_or(
    nd + "costmap_converter_spin_thread", obstacles.costmap_converter_spin_thread,
    obstacles.costmap_converter_spin_thread);
  nh->get_parameter_or(
    nd + "costmap_converter_rate", obstacles.costmap_converter_rate,
    obstacles.costmap_converter_rate);
  nh->get_parameter_or(
    nd + "obstacle_proximity_ratio_max_vel", obstacles.obstacle_proximity_ratio_max_vel,
    obstacles.obstacle_proximity_ratio_max_vel);
  nh->get_parameter_or(
    nd + "obstacle_proximity_lower_bound", obstacles.obstacle_proximity_lower_bound,
    obstacles.obstacle_proximity_lower_bound);
  nh->get_parameter_or(
    nd + "obstacle_proximity_upper_bound", obstacles.obstacle_proximity_upper_bound,
    obstacles.obstacle_proximity_upper_bound);

  // Optimization
  nh->get_parameter_or(
    nd + "no_inner_iterations", optim.no_inner_iterations, optim.no_inner_iterations);
  nh->get_parameter_or(
    nd + "no_outer_iterations", optim.no_outer_iterations, optim.no_outer_iterations);
  nh->get_parameter_or(
    nd + "optimization_activate", optim.optimization_activate, optim.optimization_activate);
  nh->get_parameter_or(
    nd + "optimization_verbose", optim.optimization_verbose, optim.optimization_verbose);
  nh->get_parameter_or(nd + "penalty_epsilon", optim.penalty_epsilon, optim.penalty_epsilon);
  nh->get_parameter_or(nd + "weight_max_vel_x", optim.weight_max_vel_x, optim.weight_max_vel_x);
  nh->get_parameter_or(nd + "weight_max_vel_y", optim.weight_max_vel_y, optim.weight_max_vel_y);
  nh->get_parameter_or(
    nd + "weight_max_vel_theta", optim.weight_max_vel_theta, optim.weight_max_vel_theta);
  nh->get_parameter_or(nd + "weight_acc_lim_x", optim.weight_acc_lim_x, optim.weight_acc_lim_x);
  nh->get_parameter_or(nd + "weight_acc_lim_y", optim.weight_acc_lim_y, optim.weight_acc_lim_y);
  nh->get_parameter_or(
    nd + "weight_acc_lim_theta", optim.weight_acc_lim_theta, optim.weight_acc_lim_theta);
  nh->get_parameter_or(
    nd + "weight_kinematics_nh", optim.weight_kinematics_nh, optim.weight_kinematics_nh);
  nh->get_parameter_or(
    nd + "weight_kinematics_forward_drive", optim.weight_kinematics_forward_drive,
    optim.weight_kinematics_forward_drive);
  nh->get_parameter_or(
    nd + "weight_kinematics_turning_radius", optim.weight_kinematics_turning_radius,
    optim.weight_kinematics_turning_radius);
  nh->get_parameter_or(
    nd + "weight_optimaltime", optim.weight_optimaltime, optim.weight_optimaltime);
  nh->get_parameter_or(
    nd + "weight_shortest_path", optim.weight_shortest_path, optim.weight_shortest_path);
  nh->get_parameter_or(nd + "weight_obstacle", optim.weight_obstacle, optim.weight_obstacle);
  nh->get_parameter_or(nd + "weight_inflation", optim.weight_inflation, optim.weight_inflation);
  nh->get_parameter_or(
    nd + "weight_dynamic_obstacle", optim.weight_dynamic_obstacle, optim.weight_dynamic_obstacle);
  nh->get_parameter_or(
    nd + "weight_dynamic_obstacle_inflation", optim.weight_dynamic_obstacle_inflation,
    optim.weight_dynamic_obstacle_inflation);
  nh->get_parameter_or(
    nd + "weight_velocity_obstacle_ratio", optim.weight_velocity_obstacle_ratio,
    optim.weight_velocity_obstacle_ratio);
  nh->get_parameter_or(nd + "weight_viapoint", optim.weight_viapoint, optim.weight_viapoint);
  nh->get_parameter_or(
    nd + "weight_prefer_rotdir", optim.weight_prefer_rotdir, optim.weight_prefer_rotdir);
  nh->get_parameter_or(
    nd + "weight_adapt_factor", optim.weight_adapt_factor, optim.weight_adapt_factor);
  nh->get_parameter_or(
    nd + "obstacle_cost_exponent", optim.obstacle_cost_exponent, optim.obstacle_cost_exponent);

  // Homotopy Class Planner
  nh->get_parameter_or(
    nd + "enable_homotopy_class_planning", hcp.enable_homotopy_class_planning,
    hcp.enable_homotopy_class_planning);
  nh->get_parameter_or(
    nd + "enable_multithreading", hcp.enable_multithreading, hcp.enable_multithreading);
  nh->get_parameter_or(nd + "simple_exploration", hcp.simple_exploration, hcp.simple_exploration);
  nh->get_parameter_or(nd + "max_number_classes", hcp.max_number_classes, hcp.max_number_classes);
  nh->get_parameter_or(
    nd + "max_number_plans_in_current_class", hcp.max_number_plans_in_current_class,
    hcp.max_number_plans_in_current_class);
  nh->get_parameter_or(
    nd + "selection_cost_hysteresis", hcp.selection_cost_hysteresis, hcp.selection_cost_hysteresis);
  nh->get_parameter_or(
    nd + "selection_prefer_initial_plan", hcp.selection_prefer_initial_plan,
    hcp.selection_prefer_initial_plan);
  nh->get_parameter_or(
    nd + "selection_obst_cost_scale", hcp.selection_obst_cost_scale, hcp.selection_obst_cost_scale);
  nh->get_parameter_or(
    nd + "selection_viapoint_cost_scale", hcp.selection_viapoint_cost_scale,
    hcp.selection_viapoint_cost_scale);
  nh->get_parameter_or(
    nd + "selection_alternative_time_cost", hcp.selection_alternative_time_cost,
    hcp.selection_alternative_time_cost);
  nh->get_parameter_or(
    nd + "selection_dropping_probability", hcp.selection_dropping_probability,
    hcp.selection_dropping_probability);
  nh->get_parameter_or(
    nd + "switching_blocking_period", hcp.switching_blocking_period, hcp.switching_blocking_period);
  nh->get_parameter_or(
    nd + "roadmap_graph_samples", hcp.roadmap_graph_no_samples, hcp.roadmap_graph_no_samples);
  nh->get_parameter_or(
    nd + "roadmap_graph_area_width", hcp.roadmap_graph_area_width, hcp.roadmap_graph_area_width);
  nh->get_parameter_or(
    nd + "roadmap_graph_area_length_scale", hcp.roadmap_graph_area_length_scale,
    hcp.roadmap_graph_area_length_scale);
  nh->get_parameter_or(
    nd + "h_signature_prescaler", hcp.h_signature_prescaler, hcp.h_signature_prescaler);
  nh->get_parameter_or(
    nd + "h_signature_threshold", hcp.h_signature_threshold, hcp.h_signature_threshold);
  nh->get_parameter_or(
    nd + "obstacle_keypoint_offset", hcp.obstacle_keypoint_offset, hcp.obstacle_keypoint_offset);
  nh->get_parameter_or(
    nd + "obstacle_heading_threshold", hcp.obstacle_heading_threshold,
    hcp.obstacle_heading_threshold);
  nh->get_parameter_or(
    nd + "viapoints_all_candidates", hcp.viapoints_all_candidates, hcp.viapoints_all_candidates);
  nh->get_parameter_or(nd + "visualize_hc_graph", hcp.visualize_hc_graph, hcp.visualize_hc_graph);
  nh->get_parameter_or(
    nd + "visualize_with_time_as_z_axis_scale", hcp.visualize_with_time_as_z_axis_scale,
    hcp.visualize_with_time_as_z_axis_scale);
  nh->get_parameter_or(
    nd + "delete_detours_backwards", hcp.delete_detours_backwards, hcp.delete_detours_backwards);
  nh->get_parameter_or(
    nd + "detours_orientation_tolerance", hcp.detours_orientation_tolerance,
    hcp.detours_orientation_tolerance);
  nh->get_parameter_or(
    nd + "length_start_orientation_vector", hcp.length_start_orientation_vector,
    hcp.length_start_orientation_vector);
  nh->get_parameter_or(
    nd + "max_ratio_detours_duration_best_duration", hcp.max_ratio_detours_duration_best_duration,
    hcp.max_ratio_detours_duration_best_duration);

  // Recovery

  nh->get_parameter_or(
    nd + "shrink_horizon_backup", recovery.shrink_horizon_backup, recovery.shrink_horizon_backup);
  nh->get_parameter_or(
    nd + "shrink_horizon_min_duration", recovery.shrink_horizon_min_duration,
    recovery.shrink_horizon_min_duration);
  nh->get_parameter_or(
    nd + "oscillation_recovery", recovery.oscillation_recovery, recovery.oscillation_recovery);
  nh->get_parameter_or(
    nd + "oscillation_v_eps", recovery.oscillation_v_eps, recovery.oscillation_v_eps);
  nh->get_parameter_or(
    nd + "oscillation_omega_eps", recovery.oscillation_omega_eps, recovery.oscillation_omega_eps);
  nh->get_parameter_or(
    nd + "oscillation_recovery_min_duration", recovery.oscillation_recovery_min_duration,
    recovery.oscillation_recovery_min_duration);
  nh->get_parameter_or(
    nd + "oscillation_filter_duration", recovery.oscillation_filter_duration,
    recovery.oscillation_filter_duration);
  nh->get_parameter_or(
    nd + "divergence_detection_enable", recovery.divergence_detection_enable,
    recovery.divergence_detection_enable);
  nh->get_parameter_or(
    nd + "divergence_detection_max_chi_squared", recovery.divergence_detection_max_chi_squared,
    recovery.divergence_detection_max_chi_squared);

  checkParameters(nh);
  checkDeprecated(nh, name);
}

void TebConfig::checkParameters(const nav2_util::LifecycleNode::SharedPtr nh) const
{
  // positive backward velocity?
  if (robot.max_vel_x_backwards <= 0)
    RCLCPP_WARN(
      nh->get_logger(),
      "TebLocalPlannerROS() Param Warning: Do not choose max_vel_x_backwards to be <=0. Disable "
      "backwards driving by increasing the optimization weight for penalyzing backwards driving.");

  // bounds smaller than penalty epsilon
  if (robot.max_vel_x <= optim.penalty_epsilon)
    RCLCPP_WARN(
      nh->get_logger(),
      "TebLocalPlannerROS() Param Warning: max_vel_x <= penalty_epsilon. The resulting bound is "
      "negative. Undefined behavior... Change at least one of them!");

  if (robot.max_vel_x_backwards <= optim.penalty_epsilon)
    RCLCPP_WARN(
      nh->get_logger(),
      "TebLocalPlannerROS() Param Warning: max_vel_x_backwards <= penalty_epsilon. The resulting "
      "bound is negative. Undefined behavior... Change at least one of them!");

  if (robot.max_vel_theta <= optim.penalty_epsilon)
    RCLCPP_WARN(
      nh->get_logger(),
      "TebLocalPlannerROS() Param Warning: max_vel_theta <= penalty_epsilon. The resulting bound "
      "is negative. Undefined behavior... Change at least one of them!");

  if (robot.acc_lim_x <= optim.penalty_epsilon)
    RCLCPP_WARN(
      nh->get_logger(),
      "TebLocalPlannerROS() Param Warning: acc_lim_x <= penalty_epsilon. The resulting bound is "
      "negative. Undefined behavior... Change at least one of them!");

  if (robot.acc_lim_theta <= optim.penalty_epsilon)
    RCLCPP_WARN(
      nh->get_logger(),
      "TebLocalPlannerROS() Param Warning: acc_lim_theta <= penalty_epsilon. The resulting bound "
      "is negative. Undefined behavior... Change at least one of them!");

  // dt_ref and dt_hyst
  if (trajectory.dt_ref <= trajectory.dt_hysteresis)
    RCLCPP_WARN(
      nh->get_logger(),
      "TebLocalPlannerROS() Param Warning: dt_ref <= dt_hysteresis. The hysteresis is not allowed "
      "to be greater or equal!. Undefined behavior... Change at least one of them!");

  // min number of samples
  if (trajectory.min_samples < 3)
    RCLCPP_WARN(
      nh->get_logger(),
      "TebLocalPlannerROS() Param Warning: parameter min_samples is smaller than 3! Sorry, I "
      "haven't enough degrees of freedom to plan a trajectory for you. Please increase ...");

  // costmap obstacle behind robot
  if (obstacles.costmap_obstacles_behind_robot_dist < 0)
    RCLCPP_WARN(
      nh->get_logger(),
      "TebLocalPlannerROS() Param Warning: parameter 'costmap_obstacles_behind_robot_dist' should "
      "be positive or zero.");

  // hcp: obstacle heading threshold
  if (hcp.obstacle_keypoint_offset >= 1 || hcp.obstacle_keypoint_offset <= 0)
    RCLCPP_WARN(
      nh->get_logger(),
      "TebLocalPlannerROS() Param Warning: parameter obstacle_heading_threshold must be in the "
      "interval ]0,1[. 0=0deg opening angle, 1=90deg opening angle.");

  // carlike
  if (robot.cmd_angle_instead_rotvel && robot.wheelbase == 0)
    RCLCPP_WARN(
      nh->get_logger(),
      "TebLocalPlannerROS() Param Warning: parameter cmd_angle_instead_rotvel is non-zero but "
      "wheelbase is set to zero: undesired behavior.");

  if (robot.cmd_angle_instead_rotvel && robot.min_turning_radius == 0)
    RCLCPP_WARN(
      nh->get_logger(),
      "TebLocalPlannerROS() Param Warning: parameter cmd_angle_instead_rotvel is non-zero but "
      "min_turning_radius is set to zero: undesired behavior. You are mixing a carlike and a "
      "diffdrive robot");

  // positive weight_adapt_factor
  if (optim.weight_adapt_factor < 1.0)
    RCLCPP_WARN(
      nh->get_logger(),
      "TebLocalPlannerROS() Param Warning: parameter weight_adapt_factor shoud be >= 1.0");

  if (recovery.oscillation_filter_duration < 0)
    RCLCPP_WARN(
      nh->get_logger(),
      "TebLocalPlannerROS() Param Warning: parameter oscillation_filter_duration must be >= 0");

  if (optim.weight_optimaltime <= 0)
    RCLCPP_WARN(
      nh->get_logger(),
      "TebLocalPlannerROS() Param Warning: parameter weight_optimaltime shoud be > 0 (even if "
      "weight_shortest_path is in use)");
}

void TebConfig::checkDeprecated(
  const nav2_util::LifecycleNode::SharedPtr nh, const std::string name) const
{
  rclcpp::Parameter dummy;

  if (
    nh->get_parameter(name + "." + "line_obstacle_poses_affected", dummy) ||
    nh->get_parameter(name + "." + "polygon_obstacle_poses_affected", dummy))
    RCLCPP_WARN(
      nh->get_logger(),
      "TebLocalPlannerROS() Param Warning: 'line_obstacle_poses_affected' and "
      "'polygon_obstacle_poses_affected' are deprecated. They share now the common parameter "
      "'obstacle_poses_affected'.");

  if (
    nh->get_parameter(name + "." + "weight_point_obstacle", dummy) ||
    nh->get_parameter(name + "." + "weight_line_obstacle", dummy) ||
    nh->get_parameter(name + "." + "weight_poly_obstacle", dummy))
    RCLCPP_WARN(
      nh->get_logger(),
      "TebLocalPlannerROS() Param Warning: 'weight_point_obstacle', 'weight_line_obstacle' and "
      "'weight_poly_obstacle' are deprecated. They are replaced by the single param "
      "'weight_obstacle'.");

  if (nh->get_parameter(name + "." + "costmap_obstacles_front_only", dummy))
    RCLCPP_WARN(
      nh->get_logger(),
      "TebLocalPlannerROS() Param Warning: 'costmap_obstacles_front_only' is deprecated. It is "
      "replaced by 'costmap_obstacles_behind_robot_dist' to define the actual area taken into "
      "account.");

  if (nh->get_parameter(name + "." + "costmap_emergency_stop_dist", dummy))
    RCLCPP_WARN(
      nh->get_logger(),
      "TebLocalPlannerROS() Param Warning: 'costmap_emergency_stop_dist' is deprecated. You can "
      "safely remove it from your parameter config.");

  if (nh->get_parameter(name + "." + "alternative_time_cost", dummy))
    RCLCPP_WARN(
      nh->get_logger(),
      "TebLocalPlannerROS() Param Warning: 'alternative_time_cost' is deprecated. It has been "
      "replaced by 'selection_alternative_time_cost'.");

  if (nh->get_parameter(name + "." + "global_plan_via_point_sep", dummy))
    RCLCPP_WARN(
      nh->get_logger(),
      "TebLocalPlannerROS() Param Warning: 'global_plan_via_point_sep' is deprecated. It has been "
      "replaced by 'global_plan_viapoint_sep' due to consistency reasons.");
}

}  // namespace teb_local_planner
