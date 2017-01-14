--TEST--
jchash with string key
--FILE--
<?php
$ret = [];
$ret[] = jchash("node1", 500000);
$ret[] = jchash("node2", 500000);
print_r($ret);
--EXPECT--
Array
(
    [0] => 441401
    [1] => 132855
)
