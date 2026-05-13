# 将脚本保存为文件，或直接粘贴到终端
cat << 'EOF' > rename_preview.sh
#!/bin/bash
# 预览模式，只显示会如何重命名
dry_run=true

rename_dir() {
    local old="$1"
    local new="$2"
    if [ -d "$old" ]; then
        if $dry_run; then
            echo "[预览] 将把 '$old' 重命名为 '$new'"
        else
            mv "$old" "$new"
            echo "[执行] '$old' -> '$new'"
        fi
    fi
}

# ---- 情况 A：数字开头的文件夹，如 "1.文件一" "10.文件二" ----
for dir in [0-9].*/ [0-9][0-9].*/ ; do
    # 只匹配以数字+点号开头的目录
    [ -d "$dir" ] || continue
    base=$(basename "$dir")
    num=${base%%.*}
    rest=${base#*.}
    # 判断最大编号决定宽度，这里默认补到2位（如果你的编号>=100，可手动改为printf "%03d"）
    newnum=$(printf "%02d" "$num")
    newname="${newnum}.$rest"
    rename_dir "$dir" "$newname"
done

# ---- 情况 B："practice" 后跟数字 ----
for dir in practice[0-9]*/ ; do
    [ -d "$dir" ] || continue
    base=$(basename "$dir")
    prefix="practice"
    # 提取数字部分（直接从practice后面截取，假设后面全是数字）
    num=${base#$prefix}
    # 如果数字后面可能还有其他字符，这里会一并保留；但你给的样例是纯数字结尾，直接补零即可
    newnum=$(printf "%02d" "$num")
    newname="${prefix}${newnum}"
    rename_dir "$dir" "$newname"
done

# ---- 情况 C："day" 后跟数字 ----
for dir in day[0-9]*/ ; do
    [ -d "$dir" ] || continue
    base=$(basename "$dir")
    prefix="day"
    num=${base#$prefix}
    newnum=$(printf "%02d" "$num")
    newname="${prefix}${newnum}"
    rename_dir "$dir" "$newname"
done

echo "预览完毕，确认无误后，将脚本中的 dry_run=true 改成 dry_run=false 再执行一次。"
EOF
bash rename_preview.sh