<?php 


if ( isset($_GET['status']) )
{
	/* Open the file */
	$myfile = fopen ("status.txt","w");
	
	if ( $_GET['status'] == 'on' )
	{
		fwrite($myfile, '1');
		header ("Location: on.html");
	}
	elseif ( $_GET['status'] == 'off')
	{
		fwrite($myfile, '0');
		header ("Location: off.html");
	}
	
	/* Close */
	fclose($myfile);
	
}	 









?>