#!/bin/bash

# 絶対パスで指定するディレクトリ名
ABSOLUTE_PATH="/home/user/pcd/gazebo/kobuki_1"

# 既存のディレクトリがある場合は削除
if [ -d "$ABSOLUTE_PATH" ]; then
  echo "ディレクトリ '$ABSOLUTE_PATH' は既に存在します。削除します..."
  rm -rf "$ABSOLUTE_PATH"
fi

# 新しいディレクトリを作成
mkdir -p "$ABSOLUTE_PATH"
echo "ディレクトリ '$ABSOLUTE_PATH' を作成しました。"



# 絶対パスで指定するディレクトリ名
ABSOLUTE_PATH="/home/user/pcd/gazebo/kobuki_2"

# 既存のディレクトリがある場合は削除
if [ -d "$ABSOLUTE_PATH" ]; then
  echo "ディレクトリ '$ABSOLUTE_PATH' は既に存在します。削除します..."
  rm -rf "$ABSOLUTE_PATH"
fi

# 新しいディレクトリを作成
mkdir -p "$ABSOLUTE_PATH"
echo "ディレクトリ '$ABSOLUTE_PATH' を作成しました。"


# ROSのlaunchファイルを実行
roslaunch robot_gazebo multi_turtlebot_world.launch

