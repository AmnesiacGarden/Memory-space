<# :
cls
@echo off
rem ��ȡ���txt�ı��ļ������ַ����
cd /d "%~dp0"
powershell -NoProfile -ExecutionPolicy bypass "Invoke-Command -ScriptBlock ([ScriptBlock]::Create([IO.File]::ReadAllText('%~f0',[Text.Encoding]::Default))) -Args '%~dp0'"
pause
exit
#>
  
$folder='.';
$outfile='.\result.txt';
  
[System.Collections.ArrayList]$s=@();
$files=@(dir -liter $folder|?{('.txt' -eq $_.Extension) -and ($_ -is [System.IO.FileInfo])});
for($i=0;$i -lt $files.length;$i++){
    write-host $files[$i].Name;
    $text=[IO.File]::ReadAllText($files[$i].FullName, [Text.Encoding]::Default);
    $m=[regex]::matches($text,'https?:[^\r\n]+=h5');
    foreach($it in $m){
        $line=$it.groups[0].value+$addstring;
        [void]$s.add($line);
    };
};
$newtext=$s -join "`r`n";
[IO.File]::WriteAllText($outfile, $newtext, [Text.Encoding]::Default);