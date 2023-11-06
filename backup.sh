#!/bin/bash
# Get the current date and time
datetime=$(powershell.exe -Command "(Get-Date).ToString('HH:mm | yyyy-MM-dd')")

# Combine them into the desired format
backup_string="Backup - $datetime"

git add -A
git commit -a -m "$backup_string"
git push -vf
