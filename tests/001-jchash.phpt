--TEST--
jchash
--FILE--
<?php
$ret = [];
$ret[] = jchash(1048, 20);
$ret[] = jchash(100, 20);
$ret[] = jchash(401, 20);
$ret[] = jchash(20001, 20);
print_r($ret);
--EXPECT--
Array
(
    [0] => 5
    [1] => 4
    [2] => 12
    [3] => 6
)
