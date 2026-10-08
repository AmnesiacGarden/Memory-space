@echo off
chcp 65001 > nul
setlocal enabledelayedexpansion

echo 正在获取所有已保存的Wi-Fi配置文件...
echo.

REM 将临时文件路径设置为桌面
set "tempfile=%userprofile%\Desktop\wifi_temp.txt"
set "outputfile=%userprofile%\Desktop\WiFi密码.txt"

REM 先尝试使用英文关键词 "Key Content"
echo [Info] 正在尝试使用关键词 'Key Content' 进行搜索...
(
    for /f "skip=3 tokens=2 delims=:" %%i in ('netsh wlan show profiles') do (
        set "ssid=%%i"
        set "ssid=!ssid:~1!"
        if not "!ssid!"=="" (
            netsh wlan show profile name^="!ssid!" key^=clear > "%tempfile%"
            set "found=0"
            for /f "tokens=*" %%p in ('findstr /C:"Key Content" "%tempfile%"') do (
                set "pass=%%p"
                set "pass=!pass:*Key Content=!"
                set "pass=!pass:~1!"
                echo SSID: !ssid! , Password: !pass!
                set found=1
            )
            if !found!==0 (
                for /f "tokens=*" %%p in ('findstr /C:"关键内容" "%tempfile%"') do (
                    set "pass=%%p"
                    set "pass=!pass:*关键内容=!"
                    set "pass=!pass:~1!"
                    echo SSID: !ssid! , Password: !pass!
                    set found=1
                )
            )
            if !found!==0 echo SSID: !ssid! , Password: [Not Found/Open Network]
        )
    )
) > "%outputfile%" 2>&1

REM 删除临时文件
if exist "%tempfile%" del "%tempfile%"

echo.
echo 操作完成！
echo 所有Wi-Fi名称和密码已导出到桌面 [WiFi密码.txt] 文件中。
echo 如果密码显示为 [Not Found/Open Network]，则表示该网络为开放网络或无密码，或关键词匹配失败。
pause