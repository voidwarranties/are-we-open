<?php
if (exec("python2 open.py 2>&1")){
	echo("open");
} else {
	echo("closed");
}

?>
