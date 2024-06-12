---
title: 生成hexo用md脚本
categories:
  - 教程
tags:
  - 教程
date: 2024-06-02
updated: 2024-06-02
published: true
---
L如果你害怕失敗，那你很有可能會失敗。
If you're afraid to fail, then you're probably going to fail.
<!-- more -->
# 生成hexo用md脚本

```shell
#!/bin/bash

if [ "$#" -gt 4 ]; then
  echo "使用方法: $0 [标题] [类别] [标签] [地址]"
  echo "类别,标签,地址是可选参数。如果未提供，将使用默认值。"
  echo "建议不输入地址"
  exit 1
fi
# 默认值

DEFAULT_categories="算法"
DEFAULT_tags="算法模版"
DEFAULT_OUTPUT_DIR="/Users/qiansu/githubRepo/yakutsukuriyuu.github.io/source/_posts" 

# 获取标题参数
TITLE="$1"
#如果未提供则使用默认值
categories="${2:-$DEFAULT_categories}"
tags="${3:-$DEFAULT_tags}"
OUTPUT_DIR="${4:-$DEFAULT_OUTPUT_DIR}"



# 将标题转换为适合文件名的格式
# 替换空格为下划线，并删除特殊字符
#FILENAME=$(echo "$TITLE" | tr ' ' '_' | tr -cd '[:alnum:]_')

# 带中文
FILENAME=$(echo "$TITLE" )

# 添加文件扩展名
OUTPUT_FILE="$OUTPUT_DIR/$FILENAME.md"

# 获取当前日期
DATE=$(date +%Y-%m-%d)



# 创建并写入Markdown文件
cat <<EOL > $OUTPUT_FILE
---
title: $TITLE
categories:
  - $categories
tags:
  - $tags
date: $DATE
updated: $DATE
published: true
---
L如果你害怕失敗，那你很有可能會失敗。
If you're afraid to fail, then you're probably going to fail.
<!-- more -->
# $TITLE
EOL
# 输出生成文件的信息
echo "Markdown文件已生成: $OUTPUT_FILE"

```

