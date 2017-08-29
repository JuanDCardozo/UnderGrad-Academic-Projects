#!/bin/csh -f

set keep = 0
if ($#argv == 3 && x$3 == x-k) set keep = 1

if ($#argv != 2 && $keep != 1) then
	echo Usage: $0 oldfile newfile
	echo '    shows diffs and computes words of difference.'
	echo '    THE LAST LINE HAS THE COUNT.'
	exit $#argv
	endif

set oldfile = $1
set newfile = $2
set pid = $$

if (! -r $oldfile) then
	echo $oldfile 'not found or unreadable'
	echo 999999
	exit 1
	endif
if (! -r $newfile) then
	echo $newfile 'not found or unreadable'
	echo 999999
	exit 2
	endif

diff $oldfile $newfile > /tmp/diffs-${pid}.txt
set st = $status
if ($st < 0 && $keep == 0) then
	/bin/rm /tmp/diffs-${pid}.txt
	endif
if ($st < 0) then
	echo diff error $st
	echo 999999
	exit 3
	endif

cat /tmp/diffs-${pid}.txt | egrep '^[<>] ' |\
  sed -e 's/^[<>]//' |\
  tr '\041-\057\072-\100\133-\136\140\173-\177' ' ' |\
  cat > /tmp/dwords-${pid}.txt

cat /tmp/diffs-${pid}.txt
echo ''
echo ''
cat /tmp/dwords-${pid}.txt | wc -w

if ($keep == 0) then
	/bin/rm /tmp/diffs-${pid}.txt /tmp/dwords-${pid}.txt
	endif

exit 0


