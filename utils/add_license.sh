#!/bin/bash

# Define the license header (exactly 2 lines)
LICENSE_HEADER="// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later"

# Check if file exists
if [ ! -f "$1" ]; then
    echo "Error: File $1 does not exist" >&2
    exit 1
fi

# Check if header already exists
if grep -q "SPDX-License-Identifier: GPL-3.0-or-later" "$1"; then
    exit 0
fi

# Create temp file
TMP_FILE=$(mktemp)

# Insert exactly 2 lines
echo "$LICENSE_HEADER" > "$TMP_FILE"

# Append original content directly (no blank line added)
cat "$1" >> "$TMP_FILE"

# Preserve original permissions
PERMS=$(stat -c "%a" "$1")
chmod "$PERMS" "$TMP_FILE"

# Replace original file
mv -f "$TMP_FILE" "$1"

echo "  updated file: $1"
exit 0