
$rootDirectory = "C:\CodeX\Marlin\Masters\Kobra_Go-master"
$outputfile = "C:\CodeX\Marlin\Masters\Kobra_Go-master\group-dirs.txt"


function Format-DirectoryName {
    param(
        [string]$DirectoryName,
        [int]$Depth
    )

    if ($Depth -eq 1) {
        return $DirectoryName.ToLower()
    } else {
        $truncatedName = if ($DirectoryName.Length -gt 5) {
            $DirectoryName.Substring(0, 5)
        } else {
            $DirectoryName
        }

        return "_$($truncatedName.ToLower())"
    }
}

function Get-forDirNames {
    param(
        [string]$RootPath
    )

    $allDirs = Get-ChildItem -Path $RootPath -Recurse -Directory | Select-Object -ExpandProperty FullName
    $formattedNames = @{}

    foreach ($dir in $allDirs) {
        $relativePath = $dir.Substring($RootPath.Length).TrimStart('\')
        $depth = ($relativePath -split '\\').Count
        $name = Split-Path $relativePath -Leaf
        $formattedName = Format-DirectoryName -DirectoryName $name -Depth $depth

        if ($depth -eq 1) {
            $formattedNames[$formattedName] = $formattedName
        } else {
            $parentPath = Split-Path $relativePath -Parent
            $parentFormatted = $formattedNames[$parentPath]
            $fullFormattedName = "$parentFormatted$formattedName"
            $formattedNames[$relativePath] = $fullFormattedName
        }
    }

    $formattedNames.Values | Sort-Object | Get-Unique
}

$forDirNames = Get-forDirNames -RootPath $rootDirectory
$forDirNames | Out-File -FilePath $outputfile