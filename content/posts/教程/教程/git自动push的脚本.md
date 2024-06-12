---
title: git自动push的脚本
categories:
  - 教程
tags:
  - 教程
date: 2024-06-02
updated: 2024-06-05
published: true
---
L如果你害怕失敗，那你很有可能會失敗。
If you're afraid to fail, then you're probably going to fail.
<!-- more -->
# git自动push的脚本

```shell
#!/bin/bash


# 保存当前目录
ORIGINAL_DIR=$(pwd)

# 配置部分
REPO_PATH="/Users/qiansu/githubRepo/yakutsukuriyuu.github.io"   # 替换为你的Git仓库路径
COMMIT_MESSAGE="Auto commit"     # 提交信息，可以根据需要修改
BRANCH="main"                    # 需要推送的分支，默认为main

# 进入仓库目录
cd $REPO_PATH || { echo "仓库路径无效: $REPO_PATH"; exit 1; }

# 确认是一个Git仓库
if [ ! -d .git ]; then
  echo "当前目录不是一个Git仓库: $REPO_PATH"
  exit 1
fi

# 添加所有更改到暂存区
git add .

# 检查是否有更改
if git diff-index --quiet HEAD --; then
  echo "没有要提交的更改"
else
  # 提交更改
  git commit -m "$COMMIT_MESSAGE"

  # 推送到GitHub仓库
  git push origin $BRANCH

  # 检查是否推送成功
  if [ $? -eq 0 ]; then
    echo "代码成功推送到GitHub仓库"
  else
    echo "推送代码到GitHub仓库失败"
    exit 1
  fi
fi


# 返回原来的目录
cd $ORIGINAL_DIR
```

## 更新

```shell
######################################################
# 获取目录路径
DIRECTORY="/Users/qiansu/githubRepo/yakutsukuriyuu.github.io/考研/数据结构"

# 检查目录是否存在
if [ ! -d "$DIRECTORY" ]; then
    echo "Directory $DIRECTORY does not exist."
    exit 1
fi

# 查找并删除非 .h 和 .cpp 文件，输出删除的文件信息
find "$DIRECTORY" -type f ! -name "*.h" ! -name "*.cpp" -print -exec rm -v {} \;

echo "Deletion completed."

######################################################
```

合并后 git脚本

```cpp
#!/bin/bash


# 保存当前目录
ORIGINAL_DIR=$(pwd)

# 配置部分
REPO_PATH="/Users/qiansu/githubRepo/yakutsukuriyuu.github.io"   # 替换为你的Git仓库路径
COMMIT_MESSAGE="Auto commit"     # 提交信息，可以根据需要修改
BRANCH="main"                    # 需要推送的分支，默认为main

# 进入仓库目录
cd $REPO_PATH || { echo "仓库路径无效: $REPO_PATH"; exit 1; }

# 确认是一个Git仓库
if [ ! -d .git ]; then
  echo "当前目录不是一个Git仓库: $REPO_PATH"
  exit 1
fi


######################################################
# 获取目录路径
DIRECTORY="/Users/qiansu/githubRepo/yakutsukuriyuu.github.io/考研/数据结构"

# 检查目录是否存在
if [ ! -d "$DIRECTORY" ]; then
    echo "Directory $DIRECTORY does not exist."
    exit 1
fi

# 查找并删除非 .h 和 .cpp 文件，输出删除的文件信息
find "$DIRECTORY" -type f ! -name "*.h" ! -name "*.cpp" -print -exec rm -v {} \;

echo "Deletion completed."

######################################################


# 添加所有更改到暂存区
git add .

# 检查是否有更改
if git diff-index --quiet HEAD --; then
  echo "没有要提交的更改"
else
  # 提交更改
  git commit -m "$COMMIT_MESSAGE"

  # 推送到GitHub仓库
  git push origin $BRANCH

  # 检查是否推送成功
  if [ $? -eq 0 ]; then
    echo "代码成功推送到GitHub仓库"
  else
    echo "推送代码到GitHub仓库失败"
    exit 1
  fi
fi


# 返回原来的目录
cd $ORIGINAL_DIR
```

