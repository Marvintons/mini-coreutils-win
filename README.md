Winux-Tools

Linux-style CLI commands for Windows CMD and PowerShell.

Winux-Tools brings the power and familiarity of Linux commands to Windows, allowing you to run ls, mv, rm, nano, cp, grep, wc, and more directly in CMD or PowerShell. Perfect for developers, students, or anyone who loves Linux commands but works on Windows.

Features

File and Directory Management

ls, mv, cp, rm, rm_r, mkdir, rmdir, touch

File Viewing and Editing

cat, head, tail, nano (opens Notepad)

System Commands

pwd, uptime, whoami, date, clear

Text Processing

grep, wc

Directory Utilities

tree

Utilities

echo, openpwd (opens the current folder in File Explorer)

All commands are compiled for Windows CMD and designed to feel familiar to Linux users.




Usage Examples
# List files in current directory
ls

# Show current directory path
pwd

# Open current folder in File Explorer
openpwd

# Edit or create a file
nano notes.txt

# Copy a file
cp notes.txt backup.txt

# Delete a file
rm backup.txt

# Recursively remove a directory
rm_r old_folder

# View first 10 lines of a file
head log.txt

# View last 10 lines of a file
tail log.txt

# Search for text in a file
grep "error" log.txt

# Count lines, words, characters in a file
wc log.txt

# Show directory tree
tree
