param([string]$filename)

$baseName = [System.IO.Path]::GetFileNameWithoutExtension($filename)

g++ -o "$baseName.exe" "$filename" "../RacingUtil.cpp"

if ($LASTEXITCODE -eq 0) {
    & ".\$baseName.exe" > "$baseName.out"
    Write-Host "Success, write to '$baseName.out'" -ForegroundColor Green
} else {
    Write-Host "Compile failed" -ForegroundColor Red
}
