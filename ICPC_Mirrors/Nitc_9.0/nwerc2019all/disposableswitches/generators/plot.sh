#!/usr/bin/env bash

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"

make -C "$DIR" >/dev/null 2>&1
$DIR/plot < $1 | sfdp -Tpdf

