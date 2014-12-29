unixtime-0.99
=============

Converter for Unix Epoch Time. Gives standard date time for Unix Epoch Time.

See INSTALL file for instruction on how to compile unixtime

This utility is a patent-free, Open Source/Free Software tool. It is intended
to allow the user to easily determine to what date a particular value of unix
epoch time resolves. Usage is: 'unixtime <unixtime in decimal seconds>'

Unix Epoch Time is the elapsed time, in seconds, from midnight, January 1st, 
1970 (00:00:00). This utility will take a decimal number representing the Unix
Epoch Time, e.g. '1419889962' and convert this to a 'standard' date time, e.g.
'Sat Nov 21 11:21:00 2015'

This tool can be used to illustrate the 2038 problem. Since unix epoch time is
often stored as a 32 bit unsigned integer on most platforms, when the unix 
epoch time value passes roll over for a signed integer, e.g. 0xFFFFFFFF, 
it is possible that the system will not understand this and start seeing dates
that are in the past. The date that this will occur for 32 bit unix times is 
sometime in the year 2038.

e.g. For a unixtime value of 0xFFFFFFFF (4294967295 decimal)

kodetroll@host:$ ./unixtime 4294967295
Date-Time for (2147483647) unix seconds is: Mon Jan 18 21:14:07 2038

